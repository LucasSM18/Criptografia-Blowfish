#include <stdio.h>
#include <stdlib.h>
#include "blowfish.h"

// Testando Commits

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
    char Cr, M, Arq;
    int result;
    BLOWFISH_CTX ctx;
    FILE *fp;
    	
	printf("Digite se voce quer criptografar (C) ou descriptografar (D) uma mensagem:");
	scanf("%S", &Cr);
	
	if((Cr = "C") || (Cr = "c")){
		
		printf("\nDigite aqui a mensagem que deseja criptografar:\n\n");
		scanf("%S", &M);
	
		Blowfish_Init (&ctx, (unsigned char*)"TESTKEY", 7);
                Blowfish_Encrypt(&M);
		
		printf("%08lX %08lX\n", M);
		
	}else if((Cr = "D") || (Cr = "d")){
	
		printf("\nDigite aqui o nome do arquivo em bloco de notas que possui a mensagem criptografada:\n\n");
		scanf("%S", &Arq);
	 	   	fp = fopen ("F:/%S.txt", "w"), Arq;
		
	}else{
		
		printf("\nInvalido!\n\n");
		result = system("main.exe");
	}
	
	
	system("PAUSE");
	return 0;
}
