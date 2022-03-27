#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamAlunos 6
#define tamProfessores 4
#define tamDisciplinas 5
/**/
/*Comando para copiar o código*/
/*gcc v05.c -o v05 -Wno-unused-result*/
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
  int matricula;
} aluno;

// Struct professores
typedef struct dadosProfessores
{
  char nome[50];
  int matricula;
  data dataNasc;
  char sexo;
  char cpf[16];
} professor;

//Cadastro disciplinas(Nome, código, Semestre, Professor)
typedef struct materias{
  char nome[50];
  char codigo[50];
  int semestre;
  /*professor docente;*/

} disciplina;

// Prototipos das funcoes
int menu_principal();
int menu_discentes();
int menu_docentes();
int menu_disciplinas(); 
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno);
int cadastrarProfessor(professor lista_de_professores[], int qtd_professor);
int listarAlunos(aluno lista_de_alunos[], int qtd_aluno);
int listarAlunoSexo(aluno lista_de_alunos[], int qtd_aluno);
int listarProfSexo(professor lista_de_professores[], int qtd_professor);
int cadastroDisciplina(disciplina lista_de_disciplinas[], int qtd_disciplinas);
void validaDataAluno(aluno lista_de_alunos[], int qtd_aluno);
int validarSexoAluno(aluno lista_de_alunos[], int qtd_aluno);
int validarSexoProf(professor lista_de_professores[], int qtd_professor);
int excluirDiscente(aluno lista_de_alunos[], int qtd_aluno); 
int validaDataProf(professor lista_de_professores[], int qtd_professor);
void ordem_alfabetica_prof (professor lista_de_professores[], int qtd_professor);
int cadastrarDisciplina(disciplina lista_de_disciplinas[], int qtd_disciplina);
int listarDisciplinas(disciplina lista_de_disciplinas[], int qtd_disciplina);

int main()
{
  setlocale(LC_ALL, "Portuguese");
  aluno lista_de_alunos[tamAlunos];
  professor lista_de_professores[tamProfessores];
  disciplina lista_de_disciplinas[tamDisciplinas]; 
  int opcao_principal;
  int opcao_aluno = -1;
  int opcao_prof = -1; 
  int opcao_disciplina = -1; 
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
        case 6:
          qtd_aluno = excluirDiscente(lista_de_alunos, qtd_aluno);
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
          listarProfSexo(lista_de_professores, qtd_professor);
          printf("Pressione uma tecla para voltar...");
          getchar();
          system("cls || clear");
          break; 
        case 4:
          ordem_alfabetica_prof(lista_de_professores,  qtd_professor);  
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
      }while(opcao_prof != 0); 
      //break; 
      case 3:   
        do{
          opcao_disciplina = menu_disciplinas();
          switch (opcao_disciplina){
            //Cadastrar disciplina
            case 1:
              cadastrarDisciplina(lista_de_disciplinas, qtd_disciplina);
            break;

            case 2:
              listarDisciplinas(lista_de_disciplinas, qtd_disciplina); 
              printf("Pressione uma tecla para voltar...");
              getchar();
              system("cls || clear");
              break; 
            }
        } while (opcao_disciplina!=0);
      }  
  } while(opcao_principal != 0);

}

/*===================================FUNÇÕES GERAIS===================================*/
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

/*===================================FUNÇÕES DISPLINAS===================================*/

int menu_disciplinas(){
  int opcao_disciplinas;
  printf("INSIRA A OPÇÃO DESEJADA\n");
  printf("1 - Cadastrar disciplina\n");
  printf("2 - Listar disciplinas (Listar os dados das disciplinas sem os alunos)\n");
  printf("3 - Listar uma disciplinas (dados da disciplinas e os alunos)\n");
  printf("0 - Sair\n");
  scanf("%d", &opcao_disciplinas);
  getchar();
  system("cls || clear");
  return opcao_disciplinas;
}
//Cadastro disciplinas(Nome, código, Semestre, Professor)
int cadastrarDisciplina(disciplina lista_de_disciplinas[], int qtd_disciplina)
{
  printf("==============================\n");
  printf("||Cadastro do(a) %d° disciplina||\n", qtd_disciplina + 1);
  printf("==============================\n");
  printf("\n");
  printf("Nome: ");
  fgets(lista_de_disciplinas[qtd_disciplina].nome, 50, stdin); 
  printf("Código: ");
  fgets(lista_de_disciplinas[qtd_disciplina].codigo, 50, stdin);
  printf("Semestre: ");
  scanf ("%d", &lista_de_disciplinas[qtd_disciplina].semestre);
  getchar();
  /*printf("Professor: %s", lista_de_disciplinas[qtd_disciplina].docente);*/
  system("cls || clear");
  return 0;
}

int listarDisciplinas(disciplina lista_de_disciplinas[], int qtd_disciplina)
{
  int j;
  printf("===========================\n");
  printf("||Disciplinas cadastradas||\n");
  printf("===========================\n");
  for (j = 0; j < qtd_disciplina; j++)
  {
    printf("\n");
    printf("Nome: %s", lista_de_disciplinas[j].nome);
    printf("Código: %s", lista_de_disciplinas[j].codigo);
    printf("Semestre: %d", lista_de_disciplinas[j].semestre);
    /*printf("Professor: %s", lista_de_disciplinas[j].docente);*/ 
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}
/*===================================FUNÇÕES DOS ALUNOS===================================*/

//Menu
int menu_discentes()
{
  int opcao_aluno;
  printf("###########################\n");
  printf("    DADOS DOS DISCENTES    \n");
  printf("###########################\n");
  printf("Insira a opção desejada: \n");
  printf("1 - Cadastrar discente\n");
  printf("2 - Listar discentes\n");
  printf("3 - Listar discentes por sexo\n");
  printf("4 - Listar discentes ordenados por nome\n");
  printf("5 - Listar discentes ordenados por data de nascimento\n");
  printf("6 - Deletar discente\n");
  printf("0 - Voltar\n");
  scanf("%d", &opcao_aluno);
  getchar();
  system("cls || clear");

  return opcao_aluno;
}

//Cadastro
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno)
{
  printf("==============================\n");
  printf("||Cadastro do(a) %d° aluno(a)||\n", qtd_aluno + 1);
  printf("==============================\n");
  printf("\n");
  printf("Nome: ");
  fgets(lista_de_alunos[qtd_aluno].nome, 50, stdin);
  lista_de_alunos[qtd_aluno].matricula = qtd_aluno; 
  printf("Matrícula: %d\n", lista_de_alunos[qtd_aluno].matricula );
  //fgets(lista_de_alunos[qtd_aluno].matricula, 15, stdin);
  validaDataAluno(lista_de_alunos, qtd_aluno);
  getchar();
  validarSexoAluno(lista_de_alunos, qtd_aluno);
  printf("CPF: ");
  fgets(lista_de_alunos[qtd_aluno].cpf, 16, stdin);
  printf("\n");
  system("cls || clear");
  return 0;
}

//Alteração/ Exclusão
int excluirDiscente(aluno lista_de_alunos[], int qtd_aluno){
  int id; 
  int i;
  int qtd;
  printf("Insira o número da matrícula do discente: ");
  scanf("%d", &id);
  if(id == qtd_aluno - 1){
      qtd_aluno--;
  } else{
      for(i = id; i < qtd_aluno - 1 ; i++){
      lista_de_alunos[i] = lista_de_alunos[i + 1];  
      }
      qtd_aluno--;
  }
  qtd = qtd_aluno;
  return qtd; 
}

//Validação
void validaDataAluno(aluno lista_de_alunos[], int qtd_aluno)
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

int validarSexoAluno(aluno lista_de_alunos[], int qtd_aluno)
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

//Listagem
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
    printf("Matrícula: %d\n", lista_de_alunos[j].matricula);
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
      printf("%d - %s", contador, lista_de_alunos[contador].nome);
    }
  }
  printf("## Lista de Alunas##\n");
  for (contador = 0; contador < qtd_aluno; contador++)
  {
    if (lista_de_alunos[contador].sexo == 'F' || lista_de_alunos[contador].sexo == 'f')
    {
      printf("%d - %s", contador, lista_de_alunos[contador].nome);
    }
  }
}


/*===================================FUNÇÕES DOS PROFESSORES===================================*/

//Menu
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
// Cadastro
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
  validaDataProf(lista_de_professores, qtd_professor);
  getchar();
  validarSexoProf(lista_de_professores, qtd_professor);
  printf("CPF: ");
  fgets(lista_de_professores[qtd_professor].cpf, 16, stdin);
  printf("\n");
  system("cls || clear");
}

//Alteração / Exclusão 

// Funções de validação
int validaDataProf(professor lista_de_professores[], int qtd_professor)
{
  int contador, quebra;
  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Insira a data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &lista_de_professores[qtd_professor].dataNasc.dia);
    if (lista_de_professores[qtd_professor].dataNasc.dia >= 01 && lista_de_professores[qtd_professor].dataNasc.dia < 32)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }

  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Mês: ");
    scanf("%d", &lista_de_professores[qtd_professor].dataNasc.mes);
    if (lista_de_professores[qtd_professor].dataNasc.mes >= 01 && lista_de_professores[qtd_professor].dataNasc.mes < 13)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }

  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Ano: ");
    scanf("%d", &lista_de_professores[qtd_professor].dataNasc.ano);
    if (lista_de_professores[qtd_professor].dataNasc.ano >= 1903 && lista_de_professores[qtd_professor].dataNasc.ano < 2022)
      quebra = 0;
    else
      printf("Digite uma data válida!\n");
  }
}
        
int validarSexoProf(professor lista_de_professores[], int qtd_professor)
{
  int contador, quebra;
  for (contador = 0, quebra = 1; contador != quebra;)
  {
    printf("Sexo: ");
    scanf("%c", &lista_de_professores[qtd_professor].sexo);
    getchar();
    if (lista_de_professores[qtd_professor].sexo == 'F' || lista_de_professores[qtd_professor].sexo == 'f' || lista_de_professores[qtd_professor].sexo == 'M' || lista_de_professores[qtd_professor].sexo == 'm')
      quebra = 0;
    else
      printf("Digite um sexo válido\n");
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
    printf("Matrícula: %d", lista_de_professores[j].matricula);
    printf("Data de nascimento: %d/%d/%d\n", lista_de_professores[j].dataNasc.dia,
           lista_de_professores[j].dataNasc.mes,
           lista_de_professores[j].dataNasc.ano);
    printf("Sexo: %c\n", lista_de_professores[j].sexo);
    printf("CPF: %s\n", lista_de_professores[j].cpf);
    printf("=======================================\n");
  }
  printf("Pressione para voltar...");
  getchar();
  system("cls || clear");
}

int listarProfSexo(professor lista_de_professores[], int qtd_professor)
{
  int contador;
  printf("## Lista de Professores##\n");
  for (contador = 0; contador < qtd_professor; contador++)
  {
    if (lista_de_professores[contador].sexo == 'M' || lista_de_professores[contador].sexo == 'm')
    {
      printf("%d - %s", contador, lista_de_professores[contador].nome);
    }
  }
  printf("## Lista de Professoras##\n");
  for (contador = 0; contador < qtd_professor; contador++)
  {
    if (lista_de_professores[contador].sexo == 'F' || lista_de_professores[contador].sexo == 'f')
    {
      printf("%d - %s", contador, lista_de_professores[contador].nome);
    }
  }
}

  //////// LISTAR PROFESSORES EM ORDEM ALFABÉTICA
  void ordem_alfabetica_prof (professor lista_de_professores[], int qtd_professor){
  int contador1, contador2, comparador;
  
  char auxiliar[80];

  for (contador1 = 0; contador1<=qtd_professor; contador1++){
    for (contador2 = contador1 + 1; contador2<=qtd_professor; contador2++){
      comparador = strcmp(lista_de_professores[contador1].nome, lista_de_professores[contador2].nome);
      if (comparador>0){
        strcpy (auxiliar, lista_de_professores[contador2].nome);
        strcpy (lista_de_professores[contador2].nome, lista_de_professores[contador1].nome);
        strcpy (lista_de_professores[contador1].nome,auxiliar);
  
      }
    }
  }
  for (contador1 = 0; contador1<=qtd_professor; contador1++){
    printf ("%s", lista_de_professores[contador1].nome);
  }
    return; 
}

