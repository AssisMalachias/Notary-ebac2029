#include <stdio.h> //biblioteca de comunica��o em com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respos�vel por cuidar das string

int registro() // Fun��o resposavel por  cadastrar os usu�rios no sistema
{
    //inicio cria��o de vari�veis/string
       char arquivo[50];
       char cpf[40];
       char nome[40];
       char sobrenome[40];
       char cargo[40];
   //Final da cria��o de vari�veis/string

       printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
       scanf("%s",&cpf); //%s refere-se a string

       strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

       FILE *file; // cria o arquivo
       file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
       fprintf(file,cpf); // salvo o valor da variavel
       fclose(file); // fecha o arquivo

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,","); // Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

       printf("Digite o nome a ser cadastrado: "); // coletando informa��o do usuario com nome
       scanf("%s",&nome); //%s refere-se a string nome

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,nome);// Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

       file = fopen(arquivo, "a");// cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,","); // Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

      printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do usuario com sobrenome
      scanf("%s",&sobrenome); //%s refere-se a string sobrenome

       file = fopen(arquivo, "a") ;// cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,sobrenome);// salvo o valor da variavel
       fclose(file);// fecha o arquivo

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,","); // Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

      printf("Digite o cargo a ser cadastrado: "); // cria o arquivo e o "a" significa procura lista de arquivo
      scanf("%s",&cargo); //%s refere-se a string cargo

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,cargo); // salvo o valor da variavel
       fclose(file); // fecha o arquivo

}
int consulta()
{
   char cpf[40]; // S�o Variavel CPF quantidade caractere
   char conteudo[200]; // S�o Variavel Conteudo quantidade caractere

   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

   printf("Digite o CPF a ser consultado: "); // coletando informa��o CPF do usuario com consultado mostra lista dados
   scanf("%s",cpf); //%s refere-se a string nome

   FILE *file; // Ele dizer crir arquivos dentros
   file = fopen(cpf,"r"); // Ele fala dentros arquivos lista informa��o CPF

   // Ser arquivo false mostra menssagem na tela para usuario.
   if(file ==  NULL)
   {
       printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");// Messagem
   }
   while(fgets(conteudo, 200, file) != NULL)
   {
       printf("\nEssas s�o as informa��es do usu�rio: "); //Mostra informa��o Essas s�o as informa�oes do usuario
       printf("%s",conteudo); // salvo o valor da variavel
       printf("\n\n"); // vai pula dois casa para baixo
   }
   system("pause");
}
int deletar()
{
    char cpf[40]; // S�o Variavel CPF quantidade caractere

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    printf("\nDigite o CPF do usu�rio a ser deletado: ");//Mostra informa��o Essas s�o as informa�oes do usuario vai ser deletado ou Excluida
    scanf("%s",cpf);// salvo o valor da variavel

    remove(cpf); // remove lista banco dados

    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // Ele fala dentros arquivos lista informa��o CPF

    if(file == NULL)
    {
        printf("O usu�rio n�o se encontra no sistema!./n"); // usu�rio n�o se encontra no sistema Messagem tem arquivo
        system("pause"); // Ele fazer pause da pesquisa
        printf("\n\n"); // vai pula dois casa para baixo
    }
}

int main()
{
     int opcao = 0; //Definindo vari�veis
     int laco = 1;
     char senhadigitada[10]="a";

     printf("### Cart�rio da EBAC ###\n\n");
     printf("Login de adminstrador!\n\nDigite a sua senha: ");
     scanf("%s",senhadigitada);

     if(senhadigitada[10] == "admin")
     {

       for(int laco=1;laco=10;)
     {
         system("cls");//inicio da sele��o

         setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

           printf("---------------- cart�rio da EBAC ----------------\n\n"); //Inicio Selec�o
           printf("Escolha a op��o desejada do menu:\n\n");//Inicio menu
           printf("\t1 - Registrar Nomes:\n");
           printf("\t2 - Consultar Nomes:\n");
           printf("\t3 - Deletar   Nomes;\n");
           printf("\t4 - Sair do sistemas;\n"); //Fim do menu

           printf("Op��o: ");//armazenando a escolha do menu
           scanf("%d",&opcao);

          system("cls");//inicio da sele��o responsavel limpa tela

           switch(opcao)
           {
               case 1:
                registro(); // chamada  de fun��es
               break;
               case 2:
                 consulta(); // chamada  de  consulta
               break;
               case 3:
                 deletar(); //  Deletar chamada
               break;
               case 4:
                  printf("Obrigado por utilizar o sistema!\n");
                  return 0;
               break;
               default:
                   printf("Essa op��o n�o est� disponivel!\n"); // As Menssagem mostra disponivel
                   system("pause");
               break;
           }
      }
    }
    else
      printf("Senha icorreta!\n");
      printf("--------------------------------------------------------\n");//fim selec�o
 return 0;
}
