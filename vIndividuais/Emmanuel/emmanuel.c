#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM_MAX_ALUNO 3
#define TAM_MAX_PROFESSOR 1

// definicção de tamanho de vetor de cadastro de alunos
typedef struct {
int dia;
int mes;
int ano;
} dtNascimento; //Struct Data de Nascimento

typedef struct {
char nome[40];
int matricula;
char sexo;
dtNascimento dataDeNascimento;
int cpf;
} Aluno; // criação de struct com informações de alunos

Aluno cadastroAluno[TAM_MAX_ALUNO];//vetor de cadastro de alunos
typedef struct {
char nome[40];
int matricula;
char sexo;
dtNascimento dataDeNascimento;
int cpf;
} Professor; // criação de struct com informações de Professor

//Professor cadastroProfessor[TAM_MAX_ALUNO]; //vetor de cadastro de alunos



// função de cadastro de alunos
int cadastrandoAluno(void){
  for (int i=0; i<TAM_MAX_ALUNO;i++){
    setbuf(stdin, NULL); //limpar BUFFER do teclado

    printf("\n******************************\n");   
    printf("* Efetuando cadastro aluno %d *\n",i);
    printf("******************************\n\n");
    
    printf("Digite o nome do aluno:");
    fgets(cadastroAluno[i].nome, 40, stdin);
    
    printf("Digite a matricula do aluno:");
    scanf("%d",&cadastroAluno[i].matricula);
    
    printf("Digite a data de nascimento do aluno ex(01 03 1999):");            
    scanf("\n%d%d%d",&cadastroAluno[i].dataDeNascimento.dia
                  ,&cadastroAluno[i].dataDeNascimento.mes
                  ,&cadastroAluno[i].dataDeNascimento.ano);
    
    printf("Digite o sexo do aluno ('F = feminino, M=masculino'):");
    scanf("\n%c",&cadastroAluno[i].sexo);

    printf("Digite o CPF do aluno:");
    scanf("%d",&cadastroAluno[i].cpf);
    }
  


// Listando Alunos
void listandoAluno(void){
  for (int i=0; i<TAM_MAX_ALUNO;i++){
    printf("\nlistando alunos\n");
    printf("********************");
    if((cadastroAluno[i].sexo == "F" || cadastroAluno[i].sexo == "f")){
      printf("%c",cadastroAluno[i].nome);
   // printf("%s",cadastroAluno[i].nome);
   // printf("%d",cadastroAluno[i].matricula);  
   // printf("%d/%d/%d",cadastroAluno[i].dataDeNascimento.dia                 
   //                  ,cadastroAluno[i].dataDeNascimento.mes
   //                  ,cadastroAluno[i].dataDeNascimento.ano);
  //  printf("%c",cadastroAluno[i].sexo);
  //  printf("%d",cadastroAluno[i].cpf);
  }
}




int main(){
  cadastrandoAluno();
  listandoAluno();
  return 0;
}