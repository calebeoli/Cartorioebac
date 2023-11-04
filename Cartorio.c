#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria (Variaves, arreys)
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsalvel por salvar strings

int registro(){
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Qual o cpf: ");
	scanf("%s", cpf);// %s refere-se a string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);// salvo valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("nome : ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("sobrenome : ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("cargo : ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta(){
	
	setlocale(LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[40];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n ");
	}
	
	while(fgets(conteudo,200,file) !=NULL){ //Responsavel por buscar as informa�oes do usuario no banco 
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar(){
	
	char cpf [40];
	
	printf("Qual o cpf a ser deletado");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL){
		printf("cpf informado, n�o existe!.\n");
		system("pause");
	}
	
	
		
}

int main(){
	int opcao = 0;
	int laco = 1 ;
	
	for(laco=1;laco=1;){
	
		system("cls");
		
		setlocale(LC_ALL,"portuguese");
		
		printf("------ Cart�rio da EBAC ------ \n\n");
		printf("Escolha uma op��o : \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("op��o: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao){
			case 1:
			registro();
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf ("op��o invalida ! \n");
			system("pause");
			break;
		}
	} 
	
	
}
