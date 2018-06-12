#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
int main(void){
	struct cadastro {
		char marca[100], modelo[100], cor[100];
		int ano;
		float valor;
	};

	struct cadastro A[20];
	int menu, i=0, x=0, j, posicao;
	char nome[50];
	char consumarca[50]; // Var de consulta //
	int alt; // Var de alteração //
	char excluir[50]; // Var de exclusao //
	char venda[50]; // Var de vendas //
	char texto_str[250]; // Var de leitura de dados //
	char* token; // Var de Leitura de dados //
	FILE *arq;
		
	// ABRINDO ARQUIVO //
	arq = fopen ("cadastro.txt", "r");
	while(fgets(texto_str, 250, arq) != NULL) {
		token = strtok(texto_str, "@");
		while (token != NULL) {
        	if (x == 0)   {
        		strcpy(A[i].marca, token);
        		x++;
      		} else if (x == 1) {
      			strcpy(A[i].modelo, token);
       			 x++;
	  		} else if (x == 2) {
	  			A[i].ano = atoi(token); //convertendo char para inteiro
        		x++;
	  		} else if (x == 3) {
        		sscanf(token, "%f", &A[i].valor); //convertendo char para float
	    		x++;
			} else if (x == 4){
				strcpy(A[i].cor,token);
        		x++;	
			}
        token = strtok(NULL, "@");
       }
     	x=0; // contador de campos
     	i++; // indice geral do vetor
	}
  	fclose(arq); //fechando o arquivo
	
	system ("cls");
	printf("Bem vindo ao GEV - Gerenciador de Estoque de Veiculos\n");
	printf("Por favor, digite o seu nome Vendedor: ");
	scanf("%s", &nome);
	while (menu != 7){
	voltar:
	system ("cls");	
	printf("Ola, vendedor: %s\n", nome);
	printf("MENU DE OPCOES DO GERENCIADOR: \n");
	printf("1 - INSERIR VEICULOS           \n");
	printf("2 - ALTERAR ITEM CADASTRADO    \n");
	printf("3 - EXCLUIR ITEM CADASTRADO    \n");
	printf("4 - CONSULTAR ITEM CADASTRADO  \n");
	printf("5 - VENDA DE VEICULO DO ESTOQUE\n");
	printf("6 - RELATORIO: ESTOQUE VEICULOS\n");
	printf("7 -        SALVAR E SAIR       \n");
	printf("Por favor, digite a opcao desejada: ");
	scanf("%d", &menu);
	system ("cls");
	
	switch (menu){
		case 1: // INSERIR VEICULO//
			printf("Digite a marca do veiculo: ");
			scanf("%s", &A[i].marca);
			printf("Digite o modelo do veiculo: ");
			scanf("%s", &A[i].modelo);
			printf("Digite o Ano de fabricacao do veiculo: ");
			scanf("%d", &A[i].ano);
			printf("Digite o Valor do veiculo: ");
			scanf("%f", &A[i].valor);
			printf("Digite a cor do veiculo: ");
			scanf("%s", &A[i].cor);	
			i++;	
		break;
		case 2: // ALTERAR VEICULO //
			printf("Por favor, digite o CODIGO do veiculo que deseja alterar: ");
			scanf("%d", &alt);
			
			printf("%s - %s - %d - %.2f - %s\n", A[alt].marca, A[alt].modelo, A[alt].ano, A[alt].valor, A[alt].cor);	
    		printf("Por favor altere a marca: ");
			scanf("%s", &A[alt].marca);
    		printf("Por favor altere o modelo: ");
			scanf("%s", &A[alt].modelo);
			printf("Por favor altere o ano: ");
			scanf("%d", &A[alt].ano);
			printf("Por favor altere o valor: "); 
			scanf("%f", &A[alt].valor);
			printf("Por favor altere a cor: \n");
			scanf("%s", &A[alt].cor);
			printf("CADASTRO ALTERADO COM SUCESSO...");
		break;
		case 3: // EXCLUIR VEICULO//
			printf("Por favor, digite a Marca de veiculo que deseja excluir: ");
			scanf("%s", &excluir);
				for(j=0; j<i; j++){
					if(strcmp(excluir, A[j].marca)== 0) {
        				printf("\nRegistro encontrado!");
        				posicao = j;
    				} else {
        				posicao = -1;
    				} 
					if(posicao == -1) {
    					printf("Registro nao encontrado!\n");
					} else {
						while (j<20){
							A[j]=A[j+1];
							j++;
						}
					}
				}
			system ("cls");
			printf("VEICULO RETIRADO DO SISTEMA COM SUCESSO...		\n");
			system ("pause");				
		break;
		case 4: // CONSULTA DE VEICULO CADASTRADO//
			printf("Por favor digite a marca do veiculo: ");
			scanf("%s", consumarca);
			for(j=0; j<i; j++) {
    			if(strcmp(consumarca, A[j].marca)== 0) {
        			printf("Registro encontrado!\n ");
        			posicao = j;
    			} else {
        			posicao = -1;
    			}	
				if(posicao == -1) {
    				printf("Registro nao encontrado! \n");
    				system("cls");
				} else {
    				printf("\nO veiculo de marca: %s ", A[j].marca);
    				printf("\nModelo: %s ", A[j].modelo);
    				printf("\nDe ano: %d ", A[j].ano); 
    				printf("\nCom valor de venda: %.2f", A[j].valor); 
    				printf("\nCor: %s\n", A[j].cor);
    				system("pause");
    				goto voltar;
				}			
			}	
		break;
		case 5: // VENDA DE VEICULO EM ESTOQUE//
			printf("Por favor, digite a Marca de veiculo que deseja vender: ");
			scanf("%s", &venda);
				for(j=0; j<i; j++){
					if(strcmp(venda, A[j].marca)== 0) {
        				printf("Registro encontrado!");
        				posicao = j;
    				} else {
        				posicao = -1;
    				} 
					if(posicao == -1) {
    					printf("Registro nao encontrado!\n");
					} else {
						while (j<20){
							A[j]=A[j+1];
							j++;
						}
					}
				}
			system ("cls");
			printf("VENDA DO VEICULO REALIZADA COM SUCESSO...		\n");
			system ("pause");		
		break;
		case 6: //Relatório de Estoque//
			printf("ESTOQUE DE VEICULOS\n"); //QUANDO REALIZA EXCLUSÃO OU VENDA DA PROBLEMA NO RELATÓRIO //
			for(j=0; j<i; j++){
				printf("Veiculo: %s, Modelo: %s, Ano: %d, Valor: %.2f, Cor: %s\n", A[j].marca, A[j].modelo, A[j].ano, A[j].valor, A[j].cor);
			}			
			system("pause");
			system("cls");
			goto voltar;			
		break;				
		} 
	} 
	printf("DADOS SALVOS E SAINDO...");
		arq = fopen ("cadastro.txt", "w");
		for(j=0; j<i; j++){
				fprintf(arq, "%s@ ", A[j].marca);
				fprintf(arq, "%s@ ", A[j].modelo);
				fprintf(arq, "%d@ ", A[j].ano);
				fprintf(arq, "%.2f@ ", A[j].valor);
				fprintf(arq, "%s@ \n", A[j].cor);
		}
	fclose(arq);
} // fim main string // 

