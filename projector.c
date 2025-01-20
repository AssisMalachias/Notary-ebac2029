#include <stdio.h> //biblioteca de comunicação em com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposável por cuidar das string

int registro() // Função resposavel por  cadastrar os usuários no sistema
{
    //inicio criação de variáveis/string
       char arquivo[50];
       char cpf[40];
       char nome[40];
       char sobrenome[40];
       char cargo[40];
   //Final da criação de variáveis/string

       printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
       scanf("%s",&cpf); //%s refere-se a string

       strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

       FILE *file; // cria o arquivo
       file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
       fprintf(file,cpf); // salvo o valor da variavel
       fclose(file); // fecha o arquivo

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,","); // Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

       printf("Digite o nome a ser cadastrado: "); // coletando informação do usuario com nome
       scanf("%s",&nome); //%s refere-se a string nome

       file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,nome);// Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

       file = fopen(arquivo, "a");// cria o arquivo e o "a" significa procura lista de arquivo
       fprintf(file,","); // Ser para lista pela um vigula
       fclose(file); // fecha o arquivo

      printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do usuario com sobrenome
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
   char cpf[40]; // São Variavel CPF quantidade caractere
   char conteudo[200]; // São Variavel Conteudo quantidade caractere

   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

   printf("Digite o CPF a ser consultado: "); // coletando informação CPF do usuario com consultado mostra lista dados
   scanf("%s",cpf); //%s refere-se a string nome

   FILE *file; // Ele dizer crir arquivos dentros
   file = fopen(cpf,"r"); // Ele fala dentros arquivos lista informação CPF

   // Ser arquivo false mostra menssagem na tela para usuario.
   if(file ==  NULL)
   {
       printf("Não foi possivel abrir o arquivo, não localizado!\n");// Messagem
   }
   while(fgets(conteudo, 200, file) != NULL)
   {
       printf("\nEssas são as informações do usuário: "); //Mostra informação Essas são as informaçoes do usuario
       printf("%s",conteudo); // salvo o valor da variavel
       printf("\n\n"); // vai pula dois casa para baixo
   }
   system("pause");
}
int deletar()
{
    char cpf[40]; // São Variavel CPF quantidade caractere

    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

    printf("\nDigite o CPF do usuário a ser deletado: ");//Mostra informação Essas são as informaçoes do usuario vai ser deletado ou Excluida
    scanf("%s",cpf);// salvo o valor da variavel

    remove(cpf); // remove lista banco dados

    FILE *file; // cria o arquivo
    file = fopen(cpf,"r"); // Ele fala dentros arquivos lista informação CPF

    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!./n"); // usuário não se encontra no sistema Messagem tem arquivo
        system("pause"); // Ele fazer pause da pesquisa
        printf("\n\n"); // vai pula dois casa para baixo
    }
}

int main()
{
     int opcao = 0; //Definindo variáveis
     int laco = 1;
     char senhadigitada[10]="a";

     printf("### Cartório da EBAC ###\n\n");
     printf("Login de adminstrador!\n\nDigite a sua senha: ");
     scanf("%s",senhadigitada);

     if(senhadigitada[10] == "admin")
     {

       for(int laco=1;laco=10;)
     {
         system("cls");//inicio da seleção

         setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

           printf("---------------- cartório da EBAC ----------------\n\n"); //Inicio Selecão
           printf("Escolha a opção desejada do menu:\n\n");//Inicio menu
           printf("\t1 - Registrar Nomes:\n");
           printf("\t2 - Consultar Nomes:\n");
           printf("\t3 - Deletar   Nomes;\n");
           printf("\t4 - Sair do sistemas;\n"); //Fim do menu

           printf("Opção: ");//armazenando a escolha do menu
           scanf("%d",&opcao);

          system("cls");//inicio da seleção responsavel limpa tela

           switch(opcao)
           {
               case 1:
                registro(); // chamada  de funções
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
                   printf("Essa opção não está disponivel!\n"); // As Menssagem mostra disponivel
                   system("pause");
               break;
           }
      }
    }
    else
      printf("Senha icorreta!\n");
      printf("--------------------------------------------------------\n");//fim selecão
 return 0;
}
