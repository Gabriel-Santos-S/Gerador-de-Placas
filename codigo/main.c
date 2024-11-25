#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char criar_placa(char placa[8]){
	
    for (int i = 0; i < 3; i++) {
        placa[i] = 'A' + (rand() % 26); 
    }
    for (int i = 3; i < 7; i++) {
        placa[i] = '0' + (rand() % 10); 
    }
    placa [7]='\0';

    return placa[8];
}


int verificacao_de_placas(char lista_placas[][8], char placa[8], int quantidade_placas){
	
    for (int i = 0; i < quantidade_placas; i++){
        if (strcmp(lista_placas[i], placa) == 0){
            return 1; 
        }}
    return 0;  
}



int main() {
	const int limite_de_placas = 10;
    char lista_placas[limite_de_placas][8], placa_criada[8];
    int quantidade_placas = 0, escolha, verificacao_de_placa2;
   
   
    srand(time(NULL));

    do {
    	printf("-------------------------------");
        printf("\nCriacao de placas");
        printf("\n1) Criar placa");
        printf("\n2) Lista das placas");
        printf("\n3) Encerrar");
        printf("\nEscolha a acao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (quantidade_placas >= limite_de_placas){
                    printf("A lista de placas está cheia!\n");
                } 
				else{
                    
                    do {
                    	criar_placa(placa_criada);
                    	verificacao_de_placa2 = verificacao_de_placas(lista_placas, placa_criada, quantidade_placas);
                
                    } while (verificacao_de_placa2 != 0);

                    
                    strcpy(lista_placas[quantidade_placas], placa_criada);
                    quantidade_placas++;
                    printf("A placa criada e %s\n", placa_criada);
                }
                break;

            case 2:
                if (quantidade_placas == 0) {
                    printf("Nenhuma placa criada.\n");
                } 
				else{
                    printf("\nLista de placas :\n");
                    for (int i = 0; i < quantidade_placas; i++){
                        printf("%s\n", lista_placas[i]);
                    }}
                break;

            case 3:
            	printf("_______________________\n");
                printf("Codigo finalizado\n");
                break;

            default:
                printf("O numero escolhido nao existe\n");
                break;
        }
    } while (escolha != 3);
    
    
    
    	printf("As placas criadas forma essas abaixo:\n");
    	for (int i = 0; i < quantidade_placas; i++){
            printf("%s\n", lista_placas[i]);
    	}

    return 0;
}