#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tamAlunos 10
#define tamProfessores 10
//Struct alunos
typedef struct cadastroAluno
    {
        char nome[50];
        char cpf[16];
        char dataNascimento[11]; 
        char sexo;
        char matricula[15];

    } aluno;
aluno cadastroAlunos[]; //tamAlunos
//Struct professores
typedef struct dadosProfessores
    {
        char nome[50];
        char matricula[15];
        char nascimento[11];
        char sexo;
        char cpf[16];
    } professor;
professor cadProf[]; //tamProfessor



int main(){
    setlocale(LC_ALL,"Portuguese"); 
    int opcao, opcaoCad, opcaoList;
    int a, p, d;
    opcao = 1; 
    a = 0;
    p = 0;
    d = 0;
    do{
        system("cls || clear");
        opcao = menuPrincipal();
        switch (opcao)
        {
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
                    cadastroAluno(a);
                    a++; 
                    break;
                case 2:
                    cadastroProfessor(p);
                    p++; 
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
                    listandoAlunos(a); 
                    break;
                case 2:
                    listandoProfessores(p);
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
int cadastroAluno(int a)
{
    printf("==============================\n");
    printf("||Cadastro do(a) %d° aluno(a)||\n", a + 1);
    printf("==============================\n");
    printf("\n");
    printf("Nome: ");
    fgets(cadastroAlunos[a].nome, 50, stdin);
    printf("Matrícula: ");
    fgets(cadastroAlunos[a].matricula, 15, stdin);
    printf("Data de nascimento: ");
    fgets(cadastroAlunos[a].dataNascimento, 11, stdin);
    getchar();
    printf("Sexo: ");
    scanf("%c", &cadastroAlunos[a].sexo);
    getchar();
    printf("CPF: ");
    fgets(cadastroAlunos[a].cpf, 16, stdin);
    printf("\n");
    system("cls || clear"); 
}

int cadastroProfessor(int p)
{
    printf("==================================\n");
    printf("||Cadastro do(a) %d° professor(a)||\n", p + 1);
    printf("==================================\n");
    printf("\n");
    printf("Nome do Professor: ");
    fgets(cadProf[p].nome, 50, stdin);
    printf("Matrícula: ");
    fgets(cadProf[p].matricula, 15, stdin);
    printf("Data de nascimento: ");
    fgets(cadProf[p].nascimento, 11, stdin);
    getchar();
    printf("Sexo: ");
    scanf("%c", &cadProf[p].sexo);
    getchar();
    printf("CPF: ");
    fgets(cadProf[p].cpf, 16, stdin);
    printf("\n");
    system("cls || clear");
}
//Listagens
int listandoAlunos(int a){
    int j; 
    printf("======================\n");
    printf("||Alunos cadastrados||\n");
    printf("======================\n");
    for (j = 0; j < a; j++){
        printf("\n");
        printf("Nome: %s", cadastroAlunos[j].nome);
        printf("Matrícula: %s", cadastroAlunos[j].matricula);
        printf("Data de nascimento: %s\n", cadastroAlunos[j].dataNascimento);
        printf("Sexo: %c\n", cadastroAlunos[j].sexo);
        printf("CPF: %s", cadastroAlunos[j].cpf);
        printf("=======================================\n");
    }
    printf("Pressione para voltar...");
    getchar(); 
    system("cls || clear");
}

int listandoProfessores(int p){
    int j;
    printf("===========================\n");
    printf("||Professores cadastrados||\n");
    printf("===========================\n");
    for (j = 0; j < p; j++){
        printf("\n");
        printf("Nome: %s", cadProf[j].nome);
        printf("Matrícula: %s", cadProf[j].matricula);
        printf("Data de nascimento: %s\n", cadProf[j].nascimento);
        printf("Sexo: %c\n", cadProf[j].sexo);
        printf("CPF: %s\n", cadProf[j].cpf);
        printf("=======================================\n");
    }
    printf("Pressione para voltar...");
    getchar(); 
    system("cls || clear");
}