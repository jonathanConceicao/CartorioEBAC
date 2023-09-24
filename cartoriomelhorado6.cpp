#include <stdio.h> //biblioteca de cominucação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h>//bliblioteca responsavel por  cuidar das string



int registro()  //função responsalvel por cadastras os usuario no sistema
{
	//inicio criaçao de variaveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final da criação de variaveis/string
  
  printf("Digite o cpf a ser cadastrado");  //coletando informaçao do usuario
  scanf("%s", cpf);//%s refere-se a string
  
  strcpy(arquivo, cpf);  //responsavel por copiar os valores das string
  
  FILE *file;  //cria o arquivo
  file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
  fprintf(file,cpf);  //salvar o valor da variavel
  fclose(file); // fechar o arquivo
  
  
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  printf("Digite o nome a ser cadastrado: ");
  scanf("%s",nome);
  
  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose (file);
  
  printf ("Digite o o sobrenome a ser cadastrado : ");
  scanf("%s",sobrenome);
  
  file = fopen(arquivo, "a");
  fprintf(file,sobrenome);
  fclose(file);
  
  file = fopen(arquivo, "a");
  fprintf(file, ",");
  fclose(file);
  
  printf("Digite o cargo a ser cadastrado : ");
  scanf("%s" ,cargo);
  
  file = fopen(arquivo, "a");
  fprintf(file,cargo);
  fclose(file);
  
  system("pause");
  
     
}
int consulta()
{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi posivel abrir o arquivo, não localizado!./n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas sao as informação do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
	
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuario nao se encontra no sistema!. \n");
		system("pause");
	}
}



int main()
   {
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
 	 system("cls");
 	 
     setlocale (LC_ALL, "portuguese"); // definindo a linguagem
   
   
     printf("### cartorio da EBA ###\n\n"); // inicio do menu
     printf("Escolha a opção desejada do menu:\n\n");	
     printf("\t1 - registra nome \n");
     printf("\t2 - consultar nome \n");
     printf("\t3 - deletar nome \n\n");
     printf("\t4 - sair do sistema\n\n");
     printf("opçao: "); // fim do menu
         
           
        scanf("%d" , &opcao);// armazenando a escolha do usuario
   
        system("cls"); //resposavel por limpa a tela
        
        switch(opcao) //inicio da seleçao do menu
        {
         case 1:
         registro();// chamada de função
         break;
         
         case 2:
         consulta();
         break;
         
         case 3:
         deletar();
         break;
         
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;	
				  
		  default:
		  printf("essa opçao nao estar disponivel!\n");
   		  system("pause");
		  break;	 	
   	   	  //fim do seleção
		}
        
    }      
   
}
