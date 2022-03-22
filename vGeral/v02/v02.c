#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamAlunos 4
#define tamProfessores 2

/**/
/*Comando para copiar o código*/
/*gcc v02.c -o v02 -Wno-unused-result*/
// Struct de data
typedef struct dataNascimento
{
  int dia;
  int mes;
  int ano;
} data;
// Struct alunos
typedef struct cadastroAluno
{
  char nome[50];
  char cpf[16];
  data dataNasc;
  char sexo;
  char matricula[15];
} aluno;

// Struct professores
typedef struct dadosProfessores
{
  char nome[50];
  char matricula[15];
  char nascimento[11];
  char sexo;
  char cpf[16];
} professor;

// Prototipos das funcoes
int menu_principal();
int menu_discentes();
int menu_docentes();
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno);
int cadastrarProfessor(professor lisda_de_professores[], int qtd_professor);
int listarAlunos(aluno lista_de_alunos[], int qtd_aluno);
int listarAlunoSexo(aluno lista_de_alunos[], int qtd_aluno);
int validaData(aluno lista_de_alunos[], int qtd_aluno);
int validarSexo(aluno lista_de_alunos[], int qtd_aluno);
/*int menuPrincipal();
int menuCadastro();
int menuListagem();
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno);
int cadastrarProfessor(professor lista_de_professores[], int qtd_professor);
int listarProfessores(professor lista_de_professores[], int qtd_professor);
*/

int main()
{
  setlocale(LC_ALL, "Portuguese");
  aluno lista_de_alunos[tamAlunos];
  professor lista_de_professores[tamProfessores];
  int opcao_principal;
  int opcao_aluno = -1;
  int opcao_prof = -1; 
  int qtd_aluno, qtd_professor, qtd_disciplina;
  int menu_aluno;
  qtd_aluno = 0;
  qtd_professor = 0;
  qtd_disciplina = 0;

  do
  {
    system("cls || clear");
    opcao_principal = menu_principal();
    switch (opcao_principal)
    {
    case 0:
      printf("O sistema foi encerrado!");
      break;

    case 1:
      do
      {
        opcao_aluno = menu_discentes();
        switch (opcao_aluno)
        {
        case 0:
          // Case para voltar ao menu principal
          break;
        case 1:
          if (qtd_aluno < tamAlunos)
          {
            cadastrarAluno(lista_de_alunos, qtd_aluno);
            qtd_aluno++;
          }
          else
          {
            printf("Lista de alunos cheia\n");
            printf("Pressione uma tecla para voltar...");
            getchar();
            system("cls || clear");
          }
            break;
        case 2:
          listarAlunos(lista_de_alunos, qtd_aluno);
          int listarAlunos(aluno lista_de_alunos[], int qtd_aluno);
          break;
        case 3:
          listarAlunoSexo(lista_de_alunos, qtd_aluno);
          printf("Pressione uma tecla para voltar...");
          getchar();
          system("cls || clear");
          break;
        default:
          printf("Insira uma opção valida");
          printf("Pressione uma tecla para voltar...");
          getchar();
          system("cls || clear");
          break;
        }
      } while (opcao_aluno != 0);
    case 2:
      do{
        opcao_prof = menu_docentes();
        switch (opcao_prof)
        {
        case 0:
          // Case para voltar ao menu principal
          break;
        case 1:
          if (qtd_professor < tamProfessores)
          {
            cadastrarProfessor(lista_de_professores, qtd_professor);
            qtd_professor++;
          }
          else
          {
            printf("Lista de docentes cheia\n");
            printf("Pressione uma tecla para voltar...");
            getchar();
            system("cls || clear");
            break;
          }
        case 2:
          break;
        case 3:
          break; 
        default:
          printf("Insira uma opção valida");
          printf("Pressione uma tecla para voltar...");
          getchar();
          system("cls || clear");
          break;
        }  
      }while(opcao_prof != 0); 
      break; 
    }

  } while (opcao_principal != 0);
}

// Menus

int menu_principal()
{
  int opcao_principal;
  printf("INSIRA A OPÇÃO DESEJADA\n");
  printf("1 - Dados dos discentes\n");
  printf("2 - Dados dos docentes\n");
  printf("3 - Dados das disciplinas\n");
  printf("0 - Sair\n");
  scanf("%d", &opcao_principal);
  getchar();
  system("cls || clear");
  return opcao_principal;
}

int menu_discentes()
{
  int opcao_aluno;
  printf("###########################\n");
  printf("   DADOS DOS DISCENTES    \n");
  printf("###########################\n");
  printf("Insira a opção desejada: \n");
  printf("1 - Cadastrar discente\n");
  printf("2 - Listar discentes\n");
  printf("3 - Listar discentes por sexo\n");
  printf("4 - Listar discentes ordenados por nome\n");
  printf("5 - Listar discentes ordenados por data de nascimento\n");
  printf("0 - Voltar\n");
  scanf("%d", &opcao_aluno);
  getchar();
  system("cls || clear");

  return opcao_aluno;
}

int menu_docentes(){
  int opcao_prof;
  printf("###########################\n");
  printf("    DADOS DOS DOCENTES     \n");
  printf("###########################\n");
  printf("Insira a opção desejada: \n");
  printf("1 - Cadastrar docentes\n");
  printf("2 - Listar docentes\n");
  printf("3 - Listar docentes por sexo\n");
  printf("4 - Listar docentes ordenados por nome\n");
  printf("5 - Listar docentes ordenados por data de nascimento\n");
  printf("0 - Voltar\n");
  scanf("%d", &opcao_prof);
  getchar();
  system("cls || clear");

  return opcao_prof;
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
  fgets(lista_de_alunos[qtd_aluno].matricula, 15, stdin);
  validaData(lista_de_alunos, qtd_aluno);
  getchar();
  validarSexo(lista_de_alunos, qtd_aluno);
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
  fgets(lista_de_professores[qtd_professor].matricula, 15, stdin);
  printf("Data de nascimento: ");
  fgets(lista_de_professores[qtd_professor].nascimento, 11, stdin);
  getchar();
  printf("Sexo: ");
  scanf("%c", &lista_de_professores[qtd_professor].sexo);
  getchar();
  printf("CPF: ");
  fgets(lista_de_professores[qtd_professor].cpf, 16, stdin);
  printf("\n");
  system("cls || clear");
}
// Funções de validação
int validaData(aluno lista_de_alunos[], int qtd_aluno)
{
  int contador, quebra;
  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Insira a data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.dia);
    if (lista_de_alunos[qtd_aluno].dataNasc.dia >= 01 && lista_de_alunos[qtd_aluno].dataNasc.dia < 32)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }

  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Mês: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.mes);
    if (lista_de_alunos[qtd_aluno].dataNasc.mes >= 01 && lista_de_alunos[qtd_aluno].dataNasc.mes < 13)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }

  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Ano: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.ano);
    if (lista_de_alunos[qtd_aluno].dataNasc.ano >= 1903 && lista_de_alunos[qtd_aluno].dataNasc.ano < 2022)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }
}

int validarSexo(aluno lista_de_alunos[], int qtd_aluno)
{
  int contador, quebra;
  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Sexo: ");
    scanf("%c", &lista_de_alunos[qtd_aluno].sexo);
    getchar();
    if (lista_de_alunos[qtd_aluno].sexo == 'F' || lista_de_alunos[qtd_aluno].sexo == 'f' || lista_de_alunos[qtd_aluno].sexo == 'M' || lista_de_alunos[qtd_aluno].sexo == 'm')
      quebra = 0;
    else
      printf("Digite um sexo válido\n");
  }
}

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
    printf("Matrícula: %s", lista_de_alunos[j].matricula);
    printf("Data de nascimento: %d/%d/%d\n", lista_de_alunos[j].dataNasc.dia,
           lista_de_alunos[j].dataNasc.mes,
           lista_de_alunos[j].dataNasc.ano);
    printf("Sexo: %c\n", lista_de_alunos[j].sexo);
    printf("CPF: %s", lista_de_alunos[j].cpf);
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}

int listarAlunoSexo(aluno lista_de_alunos[], int qtd_aluno)
{
  int contador;
  printf("## Lista de Alunos##\n");
  for (contador = 0; contador < qtd_aluno; contador++)
  {
    if (lista_de_alunos[contador].sexo == 'M' || lista_de_alunos[contador].sexo == 'm')
    {
      printf("%d - %s", contador + 1, lista_de_alunos[contador].nome);
    }
  }
  printf("## Lista de Alunas##\n");
  for (contador = 0; contador < qtd_aluno; contador++)
  {
    if (lista_de_alunos[contador].sexo == 'F' || lista_de_alunos[contador].sexo == 'f')
    {
      printf("%d - %s", contador + 1, lista_de_alunos[contador].nome);
    }
  }
}


// Listagens

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
    printf("Matrícula: %s", lista_de_professores[j].matricula);
    printf("Data de nascimento: %s\n", lista_de_professores[j].nascimento);
    printf("Sexo: %c\n", lista_de_professores[j].sexo);
    printf("CPF: %s\n", lista_de_professores[j].cpf);
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}

////////////
