#include <cstdio> // scanf e printf

int main(){
	
	// declaro e leio os valores de "a", "b", "c" e "d"
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	// se as condi��es do problema forem atendidas, imprima o caractere 'S'
	if(a==b+c+d && b+c==d && b==c) printf("S\n");
	
	// caso contr�rio, imprima uma linha com o caractere 'N'
	else printf("N\n");
	
	return 0;
}
