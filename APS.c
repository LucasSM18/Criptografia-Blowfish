#include <stdio.h>
#include <stdlib.h>
#include "blowfish.c"
#include <string.h>
// Testando Commits

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    unsigned long int L = 0, R = 0, i;
    unsigned char Cr, Arq, M[500], V[500];
    BLOWFISH_CTX ctx;
    int result;
    FILE *fp;
      

	printf("Digite se voce quer criptografar (C) ou descriptografar (D) uma mensagem: ");
	scanf("%S", &Cr);
	
	setbuf(stdin, NULL); // Limpa o buffer para que o %[^\n]s não pare o programa, pois ele lê o programa todo


	if((Cr == 'C') || (Cr == 'c')){

    

		printf("\nDigite aqui a mensagem que deseja criptografar:\n");
		scanf("%[^\n]s", &M); // Juntar a mensagem toda até digitar o enter no programa todo
		
		R = 2;
		
		//laço de repetição para contar o numero de caracteres de M
		for(i = 0; M[i]; i++){ 
								
			if(M[i] != ' '){
			
			    V[i] = M[i];
			    L = V[i]; 	        
			
		}else{
			
			L = 0;
			
		}					
				
		Blowfish_Init(&ctx, (unsigned char*)"TESTKEY", 7); // Pega a função do blowfish.c para iniciar a criptografia ,chave de teste tamanho 9
		Blowfish_Encrypt(&ctx, &L, &R); // Encriptando
		
		printf("\n%08lX \t", L); // Imprime o valor criptografado em hexadeximal com 8 caracteres
	    
		/*Descriptogração para teste
		
		Blowfish_Decrypt(&ctx, &L, &R);		 		
		
		printf("%c", L);
		*/		
		}
		printf("\n\n");
			
	}else if((Cr == 'D') || (Cr == 'd')){

		printf("\nDigite aqui o nome do arquivo em bloco de notas que possui a mensagem criptografada:\n\n");
		scanf("%S", &Arq);
		 	   	
	}else{

		printf("\nInvalido!\n\n");
		result = system("main.exe");

	}

	system("PAUSE");
	return 0;

}
