#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamAlunos 2
#define tamProfessores 10

//Struct de data
typedef struct dataNascimento{
    int dia;
    int mes;
    int ano;
}data;
//Struct alunos
typedef struct cadastroAluno
{
  char nome[50];
  char cpf[16];
  data dataNasc; 
  char sexo;
  char matricula[15];
} aluno;

//Struct professores
typedef struct dadosProfessores
{
  char nome[50];
  char matricula[15];
  char nascimento[11];
  char sexo;
  char cpf[16];
} professor;

//Prototipos das funcoes
int menuPrincipal();
int menuCadastro();
int menuListagem();
int cadastrarAluno(aluno lista_de_alunos[], int qtd_aluno);
int cadastrarProfessor(professor lista_de_professores[], int qtd_professor);
int listarAlunos(aluno lista_de_alunos[], int qtd_aluno);
int listarProfessores(professor lista_de_professores[], int qtd_professor);


int main(){
    setlocale(LC_ALL,"Portuguese"); 
    aluno lista_de_alunos[tamAlunos]; //tamAlunos
    professor lista_de_professores[tamProfessores]; //tamProfessor
    int opcao, opcaoCad, opcaoList;
    int qtd_aluno, qtd_professor, qtd_disciplina;
    opcao = 1; 
    qtd_aluno = 0;
    qtd_professor = 0;
    qtd_disciplina = 0;
    do{
        system("cls || clear");
        opcao = menuPrincipal();
        switch (opcao){
          case 0:
            printf("Encerrando o programa..."); 
            break;
          case 1:
            do{
                opcaoCad = menuCadastro();
                switch (opcaoCad)
                {
                  case 0:
                    break;
                  case 1:
                    if (qtd_aluno < tamAlunos){
                      cadastrarAluno(lista_de_alunos, qtd_aluno);
                      qtd_aluno++; 
                    }else{
                      printf("\nLista de Alunos cheia\n");
                    }
                    break;
                  case 2:
                    cadastrarProfessor(lista_de_professores, qtd_professor);
                    qtd_professor++; 
                    break;
                  case 3:
                    printf("Campo em construção\n");
                    printf("Pressione qualquer tecla para voltar...");
                    getchar(); 
                    system("cls"); 
                    break;
                  default:
                    printf("Opção invalida");
                    break;
                } 
            }while(opcaoCad != 0); 
            break; 
          case 2:
            do{
                opcaoList = menuListagem(); 
                switch (opcaoList)
                {
                case 0:
                    break;
                case 1:
                    listarAlunos(lista_de_alunos, qtd_aluno); 
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
            }while(opcaoList != 0); 
          default:
            printf("Opção invalida"); 
            break;
        }
    }while(opcao != 0); 
}

//Menus
int menuPrincipal(){
    int opcao; 
    printf("INSIRA A OPÇÃO DESEJADA\n");
    printf("1 - Cadastros\n");
    printf("2 - Listagens\n"); 
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    getchar();  
    system("cls || clear");
    return opcao;
}

int menuCadastro(){
    int opcaoCad;
    printf("INSIRA A OPÇÃO DESEJADA\n");
    printf("1 - Cadastrar aluno\n");  
    printf("2 - Cadastrar professor\n"); 
    printf("3 - Cadastrar disciplina\n"); 
    printf("0 - Voltar\n");    
    scanf("%d", &opcaoCad);
    getchar(); 
    system("cls || clear");
    return opcaoCad; 
} 

int menuListagem(){
    int opcaoList;
    printf("INSIRA A OPÇÃO DESEJADA\n");
    printf("1 - Lista de alunos\n");  
    printf("2 - Lista de professores\n"); 
    printf("3 - Lista de disciplinas\n"); 
    printf("0 - Voltar\n");    
    scanf("%d", &opcaoList);
    getchar(); 
    system("cls || clear");
    return opcaoList; 
} 
//Cadastros

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
    printf("Insira a data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.dia); 
    printf("Mês: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.mes);
    printf("Ano: ");
    scanf("%d", &lista_de_alunos[qtd_aluno].dataNasc.ano); 
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
//Listagens

int listarAlunos(aluno lista_de_alunos[], int qtd_aluno){
    int j; 
    printf("======================\n");
    printf("||Alunos cadastrados||\n");
    printf("======================\n");
    for (j = 0; j < qtd_aluno; j++){
        printf("\n");
        printf("Nome: %s", lista_de_alunos[j].nome);
        printf("Matrícula: %s", lista_de_alunos[j].matricula);
        printf("Data de nascimento: %d/%d/%d\n",lista_de_alunos[j].dataNasc.dia,
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

int listarProfessores(professor lista_de_professores[], int qtd_professor){
    int j;
    printf("===========================\n");
    printf("||Professores cadastrados||\n");
    printf("===========================\n");
    for (j = 0; j < qtd_professor; j++){
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