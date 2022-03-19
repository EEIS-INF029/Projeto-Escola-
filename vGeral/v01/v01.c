#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamAlunos 2
#define tamProfessores 2

/*Use o comando abaixo para compilar o código*/
/*gcc v01.c -o v01 -Wno-unused-result*/

// Struct de dados para data de nascimento
typedef struct Nascimento_Alunoimento
{
  int dia;
  int mes;
  int ano;
} data;
// Struct de dados de alunos
typedef struct cadastroAluno
{
  char nome[50];
  int matricula;
  char cpf[16];
  data Nascimento_Aluno;
  char sexo;
} aluno;

// Struct de dados professores
typedef struct dadosProfessores
{
  char nome[50];
  int matricula;
  data Nascimento_Prof;
  char sexo;
  char cpf[16];
} professor;

// Prototipos das funcoes
int menuPrincipal();
int menuAluno();
int menuProfessor();
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno);
int cadastrarProfessor(professor lista_de_professores[], int qtd_professor);
int listarAlunos(aluno lista_de_alunos[], int qtd_aluno);
int listarProfessores(professor lista_de_professores[], int qtd_professor);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  aluno lista_de_alunos[tamAlunos]; //Vetor que guarda os alunos cadastrados         
  professor lista_de_professores[tamProfessores]; //Vetor que guardar os professores cadastrados
  int opcaoPrincipal, opcaoCad, opcaoList;
  int qtd_aluno, qtd_professor, qtd_disciplina;
  
  //Iniciando os contadores dos cadastros
  qtd_aluno = 0;
  qtd_professor = 0;
  qtd_disciplina = 0;

  /*Tudo o que estiver dentro da estrutura de repetição, será executado enquanto a var opcao for diferente de 0*/
  do
  {
    system("cls || clear");
    /*A var opcaoPrincipal recebe o número digitado pelo usuário na funcao menuPrincipal*/
    opcaoPrincipal = menuPrincipal();
    /*Será executado o case correspondente ao número da var opcaoPrincipal*/
    switch (opcaoPrincipal)
    {
    case 0:
      printf("Encerrando o programa...");
      break;
    case 1:
      do
      {
        opcaoCad = menuAluno();
        switch (opcaoCad)
        {
        case 0:
          break;
        case 1:
          if (qtd_aluno < tamAlunos)
          {
            cadastrarAluno(lista_de_alunos, qtd_aluno);
            qtd_aluno++;
          }
          else
          {
            printf("\nLista de Alunos cheia\n");
          }
          break;
        case 2:
          listarAlunos(lista_de_alunos, qtd_aluno);
          break;
        case 3:
          printf("Campo em construção\n");
          printf("Pressione qualquer tecla para voltar...");
          getchar();
          system("cls || clear");
          break;
        default:
          printf("Opção invalida");
          break;
        }
      } while (opcaoCad != 0);
      break;
    case 2:
      do
      {
        opcaoList = menuProfessor();
        switch (opcaoList)
        {
        case 0:
          break;
        case 1:
          if (qtd_professor < tamProfessores)
          {
            cadastrarProfessor(lista_de_professores, qtd_professor);
            qtd_professor++;
          }
          else
          {
            printf("\nLista de professores cheia\n");
          }
          break;
        case 2:
          listarProfessores(lista_de_professores, qtd_professor);
          break;
        case 3:
          printf("Campo em construção\n");
          printf("Pressione qualquer tecla para voltar...");
          getchar();
          system("cls || clear");
          break;
        default:
          printf("Opção invalida");
          break;
        }
      } while (opcaoList != 0);
    default:
      printf("Opção invalida");
      break;
    }
  } while (opcaoPrincipal != 0);
}

// Menus
int menuPrincipal()
{
  int opcao;
  printf("INSIRA A OPÇÃO DESEJADA\n");
  printf("1 - Alunos\n");
  printf("2 - Professores\n");
  printf("0 - Sair\n");
  scanf("%d", &opcao);
  getchar();
  system("cls || clear");
  return opcao;
}

int menuAluno()
{
  int opcaoCad;
  printf("INSIRA A OPÇÃO DESEJADA\n");
  printf("1 - Cadastrar aluno\n");
  printf("2 - Listar aluno\n");
  printf("0 - Voltar\n");
  scanf("%d", &opcaoCad);
  getchar();
  system("cls || clear");
  return opcaoCad;
}

int menuProfessor()
{
  int opcaoList;
  printf("INSIRA A OPÇÃO DESEJADA\n");
  printf("1 - Cadastrar professor\n");
  printf("2 - Listar de professores\n");
  printf("0 - Voltar\n");
  scanf("%d", &opcaoList);
  getchar();
  system("cls || clear");
  return opcaoList;
}
// Cadastros

int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno)
{
  printf("==============================\n");
  printf("||Cadastro do(a) %d° aluno(a)||\n", qtd_aluno + 1);
  printf("==============================\n");
  printf("\n");
  printf("Nome: ");
  fgets(lista_de_alunos[qtd_aluno].nome, 50, stdin);
  printf("Matrícula: ");
  scanf("%d", &lista_de_alunos[qtd_aluno].matricula);
  printf("Insira a data de nascimento:\n");
  printf("Dia: ");
  scanf("%d", &lista_de_alunos[qtd_aluno].Nascimento_Aluno.dia);
  printf("Mês: ");
  scanf("%d", &lista_de_alunos[qtd_aluno].Nascimento_Aluno.mes);
  printf("Ano: ");
  scanf("%d", &lista_de_alunos[qtd_aluno].Nascimento_Aluno.ano);
  getchar();
  printf("Sexo: ");
  scanf("%c", &lista_de_alunos[qtd_aluno].sexo);
  getchar();
  printf("CPF: ");
  fgets(lista_de_alunos[qtd_aluno].cpf, 16, stdin);
  printf("\n");
  system("cls || clear");
}

int cadastrarProfessor(professor lista_de_professores[], int qtd_professor)
{
  printf("==================================\n");
  printf("||Cadastro do(a) %d° professor(a)||\n", qtd_professor + 1);
  printf("==================================\n");
  printf("\n");
  printf("Nome do Professor: ");
  fgets(lista_de_professores[qtd_professor].nome, 50, stdin);
  printf("Matrícula: ");
  scanf("%d", &lista_de_professores[qtd_professor].matricula);
  printf("Insira a data de nascimento:\n");
  printf("Dia: ");
  scanf("%d", &lista_de_professores[qtd_professor].Nascimento_Prof.dia);
  printf("Mês: ");
  scanf("%d", &lista_de_professores[qtd_professor].Nascimento_Prof.mes);
  printf("Ano: ");
  scanf("%d", &lista_de_professores[qtd_professor].Nascimento_Prof.ano);
  getchar();
  printf("Sexo: ");
  scanf("%c", &lista_de_professores[qtd_professor].sexo);
  getchar();
  printf("CPF: ");
  fgets(lista_de_professores[qtd_professor].cpf, 16, stdin);
  printf("\n");
  system("cls || clear");
}
// Listagens

int listarAlunos(aluno lista_de_alunos[], int qtd_aluno)
{
  int j;
  printf("======================\n");
  printf("||Alunos cadastrados||\n");
  printf("======================\n");
  for (j = 0; j < qtd_aluno; j++)
  {
    printf("\n");
    printf("Nome: %s", lista_de_alunos[j].nome);
    printf("Matrícula: %d", lista_de_alunos[j].matricula);
    printf("Data de nascimento: %d/%d/%d\n",  lista_de_alunos[j].Nascimento_Aluno.dia,
                                              lista_de_alunos[j].Nascimento_Aluno.mes,
                                              lista_de_alunos[j].Nascimento_Aluno.ano);
    printf("Sexo: %c\n", lista_de_alunos[j].sexo);
    printf("CPF: %s", lista_de_alunos[j].cpf);
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}

int listarProfessores(professor lista_de_professores[], int qtd_professor)
{
  int j;
  printf("===========================\n");
  printf("||Professores cadastrados||\n");
  printf("===========================\n");
  for (j = 0; j < qtd_professor; j++)
  {
    printf("\n");
    printf("Nome: %s", lista_de_professores[j].nome);
    printf("Matrícula: %d", lista_de_professores[j].matricula);
    printf("Data de nascimento: %d/%d/%d\n",  lista_de_professores[j].Nascimento_Prof.dia,
                                              lista_de_professores[j].Nascimento_Prof.mes,
                                              lista_de_professores[j].Nascimento_Prof.ano);
    printf("Sexo: %c\n", lista_de_professores[j].sexo);
    printf("CPF: %s\n", lista_de_professores[j].cpf);
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}