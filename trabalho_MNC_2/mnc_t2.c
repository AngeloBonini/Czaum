#include "header.h"
#define MAX_GRAU_FUNCAO 3
#define LIN_X 0
#define LIN_Y 1

//Lucas Augusto Ribeiro Massarico
//RA: 191027723

//Angelo Bonini
//RA: 191026077

typedef struct
{
   double coef[MAX_GRAU_FUNCAO + 1]; //coeficiente do termo de grau i, variando de 0 a MAX_GRAU_FUNCAO
} funcao;

void iniciaFuncao(funcao *f, int c0, int c1, int c2, int c3)
{
   (*f).coef[0] = c0;
   (*f).coef[1] = c1;
   (*f).coef[2] = c2;
   (*f).coef[3] = c3;
}
double img(funcao f, double x)
{
   double y = 0;
   for (int i = 0; i <= MAX_GRAU_FUNCAO; i++)
      y += f.coef[i] * pow(x, i);
   return y;
}

double trapezio_1ap(double y0, double y1, double h)
{
   return (h * 1 / 2) * (y0 + y1);
}
double umTercoSimpson_1ap(double y0, double y1, double y2, double h)
{
   return (h * 1 / 3) * (y0 + 4 * y1 + y2);
}
double tresOitavosSimpson_1ap(double y0, double y1, double y2, double y3, double h)
{
   return (h * 3 / 8) * (y0 + 3 * y1 + 3 * y2 + y3);
}

//calcula o vetor y = {f(x), f(x+h), f(x+2h), ... , f(x+n*h)} de tamanho n+1
void calculaY(int n, double h, double x, funcao f, double y[MAX])
{
   for (int i = 0; i <= n; i++)
      y[i] = img(f, x + i * h);
}

void geraSubMatriz(int n, double a[][MAX], int c, double sub[][MAX])
{
   for (int i = 1; i < n; i++)
      for (int j = 0, k = 0; j < n; j++, k++)
      {
         if (j != c)
            sub[i - 1][k] = a[i][j];
         else
            k--;
      }
}
double determinante(int n, double a[][MAX])
{
   double s = 0;
   if (n == 1)
      return a[0][0];
   else
   {
      double sub[MAX][MAX];
      for (int j = 0; j < n; j++)
         if (a[0][j] != 0)
         { //para cada elemento da linha 0 (a[0][j])
            geraSubMatriz(n, a, j, sub);
            s += a[0][j] * pow(-1, j) * determinante(n - 1, sub);
         }
   }
   return s;
}
bool temSubMatrizesNaoSingulares(int n, double a[][MAX])
{
   for (int i = 1; i <= n; i++)
      if (determinante(i, a) == 0)
         return false;
   return true;
}
bool sistemaTriangularSuperior(int n, double a[][MAX], double b[], double x[])
{
   if (determinante(n, a) == 0)
      return false;

   for (int i = n - 1; i >= 0; i--)
   {
      double s = 0;
      for (int j = i + 1; j < n; j++)
         s += a[i][j] * x[j];

      x[i] = (b[i] - s) / a[i][i];
   }
   return true;
}
bool sistemaTriangularInferior(int n, double a[][MAX], double b[], double x[])
{
   if (determinante(n, a) == 0)
      return false;

   for (int i = 0; i < n; i++)
   {
      double s = 0;
      for (int j = 0; j < i; j++)
         s += a[i][j] * x[j];

      x[i] = (b[i] - s) / a[i][i];
   }
   return true;
}
bool decomposicaoLU(int n, double a[][MAX], double b[], double x[])
{
   double u[MAX][MAX], l[MAX][MAX], y[MAX], s;

   if (!temSubMatrizesNaoSingulares(n, a))
      return false; //método não converge

   for (int p = 0; p < n; p++)
   {
      //calcula a linha p de U
      for (int j = p; j < n; j++)
      {
         s = 0;
         for (int k = 0; k < p; k++)
            s += l[p][k] * u[k][j];

         u[p][j] = a[p][j] - s;
      }
      //calcula a coluna p de L
      for (int i = p; i < n; i++)
      {
         s = 0;
         for (int k = 0; k < p; k++)
            s += l[i][k] * u[k][p];

         l[i][p] = (a[i][p] - s) / u[p][p];
      }
   }
   sistemaTriangularInferior(n, l, b, y); //L.y = b
   sistemaTriangularSuperior(n, u, y, x); //U.x = y
   return true;
}

int fat(int n)
{
   int fat = 1;
   for (int i = 2; i <= n; i++)
      fat *= i;
   return fat;
}

//retorna Pn(x), sendo Pn o polinômio de grau n-1
double newton(double x, int n, double tabela[][MAX])
{
   //difDiv[i][j]: j-ésima diferença dividida de Yi
   double difDiv[MAX][MAX];

   //monta a matriz de diferenças divididas
   for (int i = 0; i < n; i++)
      difDiv[i][0] = tabela[LIN_Y][i];
   for (int j = 1; j < n; j++)
      for (int i = 0; i < n - j; i++)
         difDiv[i][j] = (difDiv[i + 1][j - 1] - difDiv[i][j - 1]) / (tabela[LIN_X][i + j] - tabela[LIN_X][i]);

   //cálcula o valor do polinômio interpolador em x
   double res = 0, tmp;
   for (int j = 0; j < n; j++)
   {
      tmp = difDiv[0][j];
      for (int k = 0; k < j; k++)
         tmp *= x - tabela[LIN_X][k];
      res += tmp;
   }
   return res;
}
//pressupõe-se que os valores de x sejam equidistantes e ordenados
double newtonGregory(double x, int n, double tabela[][MAX])
{
   //difFin[i][j]: j-ésima diferença finita de Yi
   double difFin[MAX][MAX];

   //monta a matriz de diferenças finitas
   for (int i = 0; i < n; i++)
      difFin[i][0] = tabela[LIN_Y][i];
   for (int j = 1; j < n; j++)
      for (int i = 0; i < n - j; i++)
         difFin[i][j] = difFin[i + 1][j - 1] - difFin[i][j - 1];

   //cálcula o valor do polinômio interpolador em x
   double res = 0, h = tabela[LIN_X][1] - tabela[LIN_X][0], tmp;
   for (int j = 0; j < n; j++)
   {
      tmp = difFin[0][j] / (fat(j) * pow(h, j));
      for (int k = 0; k < j; k++)
         tmp *= x - tabela[LIN_X][k];
      res += tmp;
   }
   return res;
}

double coefDeterminacao(int n, double tabela[][MAX], double yAjustado[])
{
   double erro2 = 0, y2 = 0, y = 0; //somatórios

   for (int i = 0; i < n; i++)
   {
      erro2 += pow(tabela[LIN_Y][i] - yAjustado[i], 2);
      y += tabela[LIN_Y][i];
      y2 += pow(tabela[LIN_Y][i], 2);
   }
   return 1 - (n * erro2) / (n * y2 - pow(y, 2));
}

//ajusta os pontos a uma reta do tipo y = a0 + a1.x
void ajusteReta(int n, double tabela[][MAX], double *a0, double *a1, double yAjustado[], double *coefDet)
{
   double xy = 0, x = 0, y = 0, x2 = 0; //somatórios

   for (int j = 0; j < n; j++)
   {
      xy += tabela[LIN_X][j] * tabela[LIN_Y][j];
      x += tabela[LIN_X][j];
      y += tabela[LIN_Y][j];
      x2 += pow(tabela[LIN_X][j], 2);
   }
   *a1 = (n * xy - x * y) / (n * x2 - pow(x, 2));
   *a0 = (y - (*a1) * x) / n;

   for (int i = 0; i < n; i++)
      yAjustado[i] = (*a0) + (*a1) * tabela[LIN_X][i];

   *coefDet = coefDeterminacao(n, tabela, yAjustado);
}

//ajusta os pontos a um polinomio de grau m do tipo y = a[0] + a[1].x + a[2].x^2 + ... + a[m].x^m
void ajustePolinomial(int m, int n, double tabela[][MAX], double a[], double yAjustado[], double *coefDet)
{
   double coef[MAX][MAX], termInd[MAX];

   //calcula matriz dos coeficientes do sistema de ordem m+1
   for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
      {
         coef[i][j] = 0;
         for (int p = 0; p < n; p++) //se i+j = 0, coef[i][j] = n
            coef[i][j] += pow(tabela[LIN_X][p], i + j);
      }

   //calcula termos independentes do sistema de ordem m+1
   for (int i = 0; i <= m; i++)
   {
      termInd[i] = 0;
      for (int p = 0; p < n; p++) //se i = 0, termInd[i] = somatorio de y
         termInd[i] += tabela[LIN_Y][p] * pow(tabela[LIN_X][p], i);
   }
   // impVetor(m+1, termInd);
   decomposicaoLU(m + 1, coef, termInd, a);

   for (int i = 0; i < n; i++)
   {
      yAjustado[i] = 0;
      for (int k = 0; k <= m; k++)
         yAjustado[i] += a[k] * pow(tabela[LIN_X][i], k);
   }
   *coefDet = coefDeterminacao(n, tabela, yAjustado);
}

//ajusta os pontos a uma curva do tipo y = a.(b^x)
void ajusteExponencial(int n, double tabela[][MAX], double *a, double *b, double yAjustado[], double *coefDet)
{
   double a0, a1;
   for (int j = 0; j < n; j++)
      tabela[LIN_Y][j] = log(tabela[LIN_Y][j]);

   ajusteReta(n, tabela, &a0, &a1, yAjustado, &(*coefDet));
   printf("a0: %lf\na1: %lf\n", a0, a1);
   *a = pow(M_E, a0);
   *b = pow(M_E, a1);
}

double trapezio(int n, double a, double b, funcao f)
{
   double res = 0, y[MAX];
   double h = (b - a) / n;

   calculaY(n, h, a, f, y);

   //n aplicações
   for (int i = 0; i + 1 <= n; i++)
      res += trapezio_1ap(y[i], y[i + 1], h);

   return res;
}

double umTercoSimpson(int n, double a, double b, funcao f)
{
   double res = 0, y[MAX];
   double h = (b - a) / n;

   calculaY(n, h, a, f, y);

   // n/2 aplicações, logo n precisa ser múltiplo de 2
   for (int i = 0; i + 2 <= n; i += 2)
      res += umTercoSimpson_1ap(y[i], y[i + 1], y[i + 2], h);

   if (n % 2 != 0)
      res += trapezio_1ap(y[n - 1], y[n], h); // faltou 1 intervalo

   return res;
}

double tresOitavosSimpson(int n, double a, double b, funcao f)
{
   double res = 0, y[MAX];
   double h = (b - a) / n;

   calculaY(n, h, a, f, y);

   // n/3 aplicações, logo n precisa ser múltiplo de 3
   for (int i = 0; i + 3 <= n; i += 3)
      res += tresOitavosSimpson_1ap(y[i], y[i + 1], y[i + 2], y[i + 3], h);

   if (n % 3 != 0)
   {
      if (n % 2 == 0)
         res += umTercoSimpson_1ap(y[n - 2], y[n - 1], y[n], h); // faltaram 2 intervalos
      else
         res += trapezio_1ap(y[n - 1], y[n], h); // faltou 1 intervalo
   }

   return res;
}

int menu()
{
   int op;
   printf("   Interpolação Polinomial  \n");
   printf("         Ajuste de Curvas e Integração Numérica        \n");
   printf("..................................\n\n");
   printf("  01 › Rotina de Newton \n\n");
   printf("  02 › Rotina NewtonGregory\n");
   printf("  03 › Rotina CoefDeterminação\n\n");
   printf("     04 › Ajuste de Reta\n");
   printf("     05 › Ajuste de Polinômio\n");
   printf("     06 › Ajuste Exponencial\n");
   printf("     07 › Rotina Trapézio\n\n");
   printf("     08 › Um Terço de Simpson\n");
   printf("     09 › TRes Oitvaos de Simpson\n\n");
   do
   {
      printf("Resposta.: ");
      scanf("%d", &op);
   } while (op < 1 || op > 10);
   printf("\n");
   return op;
}

int main()
{
   funcao f1, f2, f3;
   int op, n, ;
   double a[MAX][MAX], tabela[][MAX], a[], ;
   double x, y[];
   double l, f, h;
   char r;
   bool ok;

   do
   {
      system("clear");
      op = menu();

      printf("Ordem da matriz: ");
      scanf("%d", &n);
      printf("\nCoeficientes da matriz %dx%d:\n", n, n);
      leMatriz(n, a);

      switch (op)
      {
      case 1:
         ok = newton(x, n, b, tabela);
         break;
      case 2:
         ok = newtonGregory(x, n, tabela);
         break;
      case 3:
         ok = coefDeterminacao(n, tabela, y);
         break;
      case 4:
         ok = ajusteReta(n, tabela, *a0, *a1, y, *coefDet);
         break;
      case 5:
         ok = ajustePolinomial(m, n, tabela, a, y, *coefDet);
         break;
      case 6:
         ok = ajusteExponencial(n, tabela, *a, *b, y[], *coefDet);
         break;
      case 7:
         ok = trapezio(n, l, f, f1);
         break;
      case 8:
         ok = umTercoSimpson(n, l, f, f2);
         break;
      case 9:
         ok = tresOitavosSimpson(n, l, f, h, f3);
         break;
      }

      do
      {
         printf("\nRetornar ao menu [s/n]? ");
         fflush(stdin);
         scanf(" %c", &r);
      } while (r != 'n' && r != 's');
   } while (r == 's');
   return 0;
}