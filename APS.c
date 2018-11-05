#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "blowfish.c"

// Testando Commits

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


unsigned long convtodecnum(char hex[]);

int main(int argc, char *argv[]) {

    unsigned long L = 0, R = 0, i, j;
    unsigned char Cr, Arq, M[500], M2[500], *buff = malloc(500);
    BLOWFISH_CTX ctx;
    int result;
    FILE *fp;
      

	printf("Digite se voce quer criptografar (C) ou descriptografar (D) uma mensagem: ");
	scanf("%S", &Cr);
	
	setbuf(stdin, NULL); // Limpa o buffer para que o %[^\n]s não pare o programa, pois ele lê o programa todo


	if((Cr == 'C') || (Cr == 'c')){

    	printf("\nDigite aqui a mensagem que deseja criptografar:\n");
		scanf("%[^\n]s", &M); // Juntar a mensagem toda até digitar o enter no programa todo
		printf("\n");
		
		R = 2;
		
		//laço de repetição para contar o numero de caracteres de M
		for(i = 0; M[i]; i++){ 
								
			if(M[i] != ' '){
	
	          L = M[i]; 	        
											
		}else{
			
			L = 0;
			
		}					
				
		Blowfish_Init(&ctx, (unsigned char*)"TESTKEY", 7); // Pega a função do blowfish.c para iniciar a criptografia ,chave de teste tamanho 9
		Blowfish_Encrypt(&ctx, &L, &R); // Encriptando
				
		sprintf(buff, "%08lX%08lX\t", L, R); // inserio o valor do printf em uma varialvel (buff)
	    printf("%s", buff); // Imprime o valor criptografado em hexadeximal com 8 caracteres   	
		
    }   
    
     printf("\n\n");

	}else if((Cr == 'D') || (Cr == 'd')){
        
        unsigned long cont = 0, count2 = 0, c1 = 9, decnum;
                            
		/*printf("\nDigite aqui o nome do arquivo em bloco de notas que possui a mensagem criptografada:\n\n");
		scanf("%S", &Arq);*/
		
		        unsigned char M[500] = "C47D77BDEA07E719C5570F987B5FE554E7E95A72A04433C2241F4B6E0171955D186CBB34947055F1C1DE7E16DBDE4EB21A05E655B8EEC8746646654ACA08DE357424FDF252D8E35C9F1A6A130C9815A1292DE6FE";
				unsigned char M2[500] = "0F18CAF689B7B8CC7E7DA610CCD38E5F6A51E48B94D1707143ACE4966C2A4D4F91A68D3221AAC0FD9EEFA415E9939EE0F2833EAC092AEDA4304EB414112BFF8D73160950AAD8F7A2DB400585E0DF7DB7D5C5EBC3";
						        
		        //laço de repetição para contar o numero de caracteres de M
		        for(j = 0; M[j]; j = j + 8){ 
				
				//separação do dos caracteres hex(M) em uma cadeia de 8 elementos
				char hex[c1];
										
			    strncpy(hex, M + cont, 8);
			    hex[8] = '\0';
	            						         
				//conversão do valor hex(M) em dec		   	  	
			   	decnum = convtodecnum(hex);
              	L = decnum;
              	
              	//separação do dos caracteres hex(M2) em uma cadeia de 8 elementos	
				strncpy(hex, M2 + cont, 8);
			    hex[8] = '\0';
				
				//conversão do valor hex(M2) em dec  
				decnum = convtodecnum(hex);
              	R = decnum;
			    
				//Decriptação dos valores R e L			
				Blowfish_Init(&ctx, (unsigned char*)"TESTKEY", 7);  
                Blowfish_Decrypt(&ctx, &L, &R);
				
				printf("%c", L);             											
					              		 						
				cont = cont + 8;
				c1 = c1 + 9;
				
		        
            }
                printf("\n");

              }else{

		printf("\nInvalido!\n\n");
		result = system("main.exe");

	}

	system("PAUSE");
	return 0;

}

unsigned long convtodecnum(char hex[])
{
    char *hexstr;
    int length = 0;
    const int base = 16; // Base of Hexadecimal Number
    unsigned long decnum = 0;
    int i;
    // Find length of Hexadecimal Number
    for (hexstr = hex; *hexstr != '\0'; hexstr++)
    {
	length++;
    }
    // Find Hexadecimal Number
    hexstr = hex;
    for (i = 0; *hexstr != '\0' && i < length; i++, hexstr++)
    {
	// Compare *hexstr with ASCII values
	if (*hexstr >= 48 && *hexstr <= 57)   // is *hexstr Between 0-9
	{
	    decnum += (((int)(*hexstr)) - 48) * pow(base, length - i - 1);
	}
	else if ((*hexstr >= 65 && *hexstr <= 70))   // is *hexstr Between A-F
	{
	    decnum += (((int)(*hexstr)) - 55) * pow(base, length - i - 1);
	}
	else if (*hexstr >= 97 && *hexstr <= 102)   // is *hexstr Between a-f
	{
	    decnum += (((int)(*hexstr)) - 87) * pow(base, length - i - 1);
	}
	else
	{
	    printf(" Invalid Hexadecimal Number \n");

	}
    }
    return decnum;
}
