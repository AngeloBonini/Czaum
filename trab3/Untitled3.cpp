#include <stdio.h>
#include <stdlib.h>
 
// VARI�VEIS GLOBAIS
#define tamanho_tabuleiro 4 // Define o tamanho do tabuleiro = 10 casas
int TABULEIRO[tamanho_tabuleiro][tamanho_tabuleiro] = {0}; // Cria um tabuleiro com o tamanho definido anteriormente e inicia
                                                           // todas as casas com o valor 0 (Zero)
int NAVIOS = 0; //Vari�vel que controla quantas posi��es de navios existem
int ACERTOS = 0; // V�riavel que controla quantos acertos o jogador possui (usada para acabar o jogo)
// --
 
void imprime_tabuleiro_sem_jogar() { // Esta fun��o APENAS IMPRIME o tabuleiro na tela quando o usu�rio est� POSICIONANDO OS ITENS
     
     system("cls"); // Apaga tudo que est� impresso na tela (deixa mais bonito o programa :D )
     
     for(int i = 0; i<tamanho_tabuleiro; i++) { // a vari�vel i percorre as LINHAS (eixo X) do tabuleiro
             for(int j = 0; j<tamanho_tabuleiro; j++) { // a vari�vel j percorre as COLUNAS (eixo Y) do tabuleiro
                     
                     if(TABULEIRO[i][j] == 0) { // Se nessa posi��o o valor for zero, quer dizer que n�o tem nada
                                        printf("- ");
                     }
                     else if(TABULEIRO[i][j] == 1) { // Se o valor for 1, tem um navio nessa posi��o
                       printf("x ");
                     }
                     
             }
             printf("\n"); // quebra a linha da tela depois de imprimir uma linha do tabuleiro
     }
}
// --
 
void imprime_tabuleiro_jogando() { // Esta fun��o APENAS IMPRIME o tabuleiro na tela quando est� JOGANDO
     
     system("cls"); // Apaga tudo que est� impresso na tela (deixa mais bonito o programa :D )
     printf("x = Acertou a posicao\n");
     printf("o = Errou a posicao\n");
     printf("- = Posicao ainda nao selecionada\n\n");
     
     for(int i = 0; i<tamanho_tabuleiro; i++) { // a vari�vel i percorre as LINHAS (eixo X) do tabuleiro
             for(int j = 0; j<tamanho_tabuleiro; j++) { // a vari�vel j percorre as COLUNAS (eixo Y) do tabuleiro
                     
                     if(TABULEIRO[i][j] == 2) { // Se nessa posi��o o valor for dois, quer dizer que o jogador acertou o navio
                                        printf("x ");
                     }
                     else if(TABULEIRO[i][j] == 3) { // Se o valor for 3, o jogador errou o navio
                       printf("o ");
                     } else { // Se for diferente disso, apenas exibe o tra�o dizendo que o campo n�o foi selecionado pelo jogador
                       printf("- ");
                     }
                     
             }
             printf("\n"); // quebra a linha da tela depois de imprimir uma linha do tabuleiro
     }
}
// --
 
bool posiciona_barcos() { // Esta fun��o PREENCHE O TABULEIRO com os barcos da batalha naval
     int x = 0; // inicializa a variavel x com zero cada vez que a fun��o � chamada
     int y = 0;// inicializa a variavel y com zero cada vez que a fun��o � chamada
     imprime_tabuleiro_sem_jogar();// imprime na tela o tabuleiro para o usu�rio ver o estado do jogo
     
     printf("\n====\n\nDIGITE 999 PARA FINALIZAR O POSICIONAMENTO DOS NAVIOS\n\n====\n\n");
       
     do {
         printf("\n\n DIGITE A COORDENADA X DO NAVIO: ");
         scanf("%d", &x);
         
         if(x == 999) { // Se digitar 999, quer dizer que j� terminou de posicionar os navios
              return false;
         } else if(x < 0 || x >= tamanho_tabuleiro) {
              printf("\n O valor digitado para a coordenada X eh invalido!!!\n");// Exibe a mensagem de erro
         }
         
     } while(x < 0 || x >= tamanho_tabuleiro);// Se o X for menor que 0 e maior igual ao tamanho_tabuleiro, � inv�lido e pede
                                                 // pra digitar novamente o valor.
     
     do {
         printf("\n\n DIGITE A COORDENADA Y DO NAVIO: ");
         scanf("%d", &y);
         
         if(y == 999) { // Se digitar 999, quer dizer que j� terminou de posicionar os navios
              return false;
         } else if(y < 0 || y >= tamanho_tabuleiro) { // Exibe a mensagem de erro
              printf("\n O valor digitado para a coordenada Y eh invalido!!!\n");
         }
     } while(y < 0 || y >= tamanho_tabuleiro);// Se o Y for menor que 0 e maior igual ao tamanho_tabuleiro, � inv�lido e pede
                                                 // pra digitar novamente o valor.
     
     if(TABULEIRO[x][y] != 1) {// Se for diferente de 1 (nesse caso vai ser zero)
                               // quer dizer que n�o tem nada e vai posicionar o navio
                        TABULEIRO[x][y] = 1; // preenche com o valor 1 a posi��o que o usu�rio escolheu (1 quer dizer que t� ocupado o espa�o)
                        NAVIOS++; // Incrementa a variavel NAVIOS, dizendo que mais uma posi��o foi preenchida
     }
     return true;
}
// --
 
void jogar() { // Esta fun��o le as posi��es do jogador e vai efetuando o jogo 
               //(Ela faz uma jogada por vez, ou seja, cada vez que � chamada, uma jogada � realizada)
     int x = 0; // inicializa a variavel x com zero cada vez que a fun��o � chamada
     int y = 0;// inicializa a variavel y com zero cada vez que a fun��o � chamada
     imprime_tabuleiro_jogando();// imprime na tela o tabuleiro para o usu�rio ver o estado do jogo
       
     do {
         printf("\n\n DIGITE A COORDENADA X: ");
         scanf("%d", &x);
         
         if(x < 0 || x >= tamanho_tabuleiro) {
              printf("\n O valor digitado para a coordenada X e invalido!!!\n");// Exibe a mensagem de erro
         }
         
     } while(x < 0 || x >= tamanho_tabuleiro);// Se o X for menor que 0 e maior igual ao tamanho_tabuleiro, � inv�lido e pede
                                                 // pra digitar novamente o valor.
     
     do {
         printf("\n\n DIGITE A COORDENADA Y: ");
         scanf("%d", &y);
         
         if(y < 0 || y >= tamanho_tabuleiro) { // Exibe a mensagem de erro
              printf("\n O valor digitado para a coordenada Y e invalido!!!\n");
         }
     } while(y < 0 || y >= tamanho_tabuleiro);// Se o Y for menor que 0 e maior igual ao tamanho_tabuleiro, � inv�lido e pede
                                                 // pra digitar novamente o valor.
     
     if(TABULEIRO[x][y] == 0) {// Se o tabuleiro estiver com valor 0, quer dizer que n�o tem nada, ent�o ERROU o palpite
          TABULEIRO[x][y] = 3;    
     } else if (TABULEIRO[x][y] == 1) {// Se o tabuleiro tem valor 1, quer dizer que tem um navio e o jogador ACERTOU o palpite
          TABULEIRO[x][y] = 2;
          ACERTOS++; // Incrementa a variavel ACERTOS, dizendo que o usu�rio acertou um palpite.
     } else { // Se n�o possuir os valores acima, o jogador ja marcou essa posi��o, ent�o � INVALIDO!!!
       printf("\n Esta posicao ja foi utilizada. Tente novamente!!!\n");
     }
}
// --
 
main() {
       // POSICIONA OS ITENS NO TABULEIRO
       bool auxiliar = true; // vari�vel booleana (Recebe apenas TRUE ou FALSE) para controlar o preenchimento do tabuleiro
       
       do {
           auxiliar = posiciona_barcos(); // a fun��o retorna um valor (true se n�o preencheu todos os campos/false se j� preencheu)
       } while(auxiliar != false);// Enquanto a v�riavel for diferente de false, repete a fun��o;
        
        
       // COMECA O JOGO
       do {
           jogar(); // chama a fun��o que come�a a jogar
       } while(NAVIOS != ACERTOS);// Enquanto a variavel NAVIOS for diferente de 
                                  // ACERTOS (o que quer dizer que o jogador n�o 
                                  // acertou todos os navios ainda), executa a 
                                  // repeti��o e vai fazendo as jogadas.
 
       // A repeti��o acima acaba quando acerta tudo, ent�o exibe a mensagem abaixo e acaba o jogo
       system("cls");
       printf("=====\n\nVOCE ACERTOU TODOS OS NAVIOS. PARABENS!!!\n\n=====\n\n\n");
       system("pause");
}
