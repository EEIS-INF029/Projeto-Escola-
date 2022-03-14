#include <stdio.h>
#include <string.h>
#define TAM 2

int main()
{
    typedef struct dma{
      int dia;
      int mes; 
      int ano;
    }  data;
  
    typedef struct dados_aluno {
        char nome_aluno[51];
        char matricula_aluno[12];
        char sexo_aluno;
        data nascimento_aluno;
        char CPF_aluno;
        char data_nasc_aluno[11];
    } aluno;
    
    typedef struct dados_prof {
        char nome_prof[51];
        char matricula_prof[12];
        char sexo_prof;
        data nascimento_prof;
        char CPF_prof;
        char data_nasc_prof[11];
    } professor;
    
    int qtd_aluno, qtd_prof, contador;
    int variavel, i, fim;
    
    printf ("Digite o número de alunos: ");
    scanf ("%d", &qtd_aluno);
    getchar ();
    printf ("Digite o número de professores: ");
    scanf ("%d", &qtd_prof);
    getchar ();
    
    
    aluno discente[qtd_aluno];
    professor docente[qtd_prof];
    
  //ALUNO
    for (contador = 0; contador < qtd_aluno; contador++){
        printf ("** Cadastro de aluno **\n");
        printf ("Digite seu nome: ");
        fgets (discente[contador].nome_aluno, 51, stdin);
        size_t ln = strlen (discente[contador].nome_aluno) - 1;
        if (discente[contador].nome_aluno[ln] = '\n')
            discente[contador].nome_aluno[ln] = '\0';
            
        printf ("Digite sua matrícula:");
        fgets (discente[contador].matricula_aluno, 51, stdin);
        ln = strlen (discente[contador].matricula_aluno) - 1;
        if (discente[contador].matricula_aluno[ln] = '\n')
            discente[contador].matricula_aluno[ln] = '\0';
   
        printf ("Digite seu sexo (M - masculino e F - feminino): ");
        scanf ("%c", &discente[contador].sexo_aluno);

        printf ("Digite o dia de nascimento: \n");
        scanf ("%d", &discente[contador].nascimento_aluno.dia);
        getchar ();
        printf ("Digite o mês de nascimento: \n");
        scanf ("%d", &discente[contador].nascimento_aluno.mes);
        getchar ();
        printf ("Digite o ano de nascimento: \n");
        scanf ("%d", &discente[contador].nascimento_aluno.ano);
        getchar ();
        
    }

  //PROFESSOR 
    for (contador = 0; contador < qtd_prof; contador++){
        printf ("** Cadastro de professor **\n");
        printf ("Digite seu nome: ");
        fgets (docente[contador].nome_prof, 51, stdin);
        size_t ln = strlen (docente[contador].nome_prof) - 1;
        if (docente[contador].nome_prof[ln] = '\n')
            docente[contador].nome_prof[ln] = '\0';
            
        printf ("Digite sua matrícula:");
        fgets (docente[contador].matricula_prof, 51, stdin);
        ln = strlen (docente[contador].matricula_prof) - 1;
        if (docente[contador].matricula_prof[ln] = '\n')
            docente[contador].matricula_prof[ln] = '\0';
   
        printf ("Digite seu sexo (M - masculino e F - feminino): ");
        scanf ("%c", &docente[contador].sexo_prof);
      
        printf ("Digite o dia de nascimento: \n");
        scanf ("%d", &docente[contador].nascimento_prof.dia);
        getchar ();
        printf ("Digite o mês de nascimento: \n");
        scanf ("%d", &docente[contador].nascimento_prof.mes);
        getchar ();
        printf ("Digite o ano de nascimento: \n");
        scanf ("%d", &docente[contador].nascimento_prof.ano);
        getchar ();
        
    }

       
// RELATÓRIOS
  
  printf("Você deseja imprimir algum relatório? Digite 1 para sim e 2 para não.\n");
  scanf ("%d", &variavel);
  getchar ();
  if (variavel == 1){
    printf("Digite o número correspondente a ação que deseja realizar:\n 1 - Listar alunos\n 2 - Listar professores\n 3 - Listar disciplinas\n 4 - Listar uma disciplina\n 5 - Listar alunos por sexo\n 6 - Listar alunos ordenados por nome\n 7 - Listar alunos ordenados por data de nascimento\n  8 - Listar professores por sexo\n 9 - Listar professores ordenados por data de nascimento\n 10 - Aniversariantes do mês\n 11 - Listar por busca \n 12 - Lista de alunos matriculados em pelo menos 3 disciplinas\n 13 - Lista de disciplinas, com nome do professor, que extrapolam 40 vagas\n");
      
    scanf("%d", &variavel);
    getchar ();
    
    switch (variavel){
      // ESTAREI SEPARANDO OS CASOS COM ASTERISCO PARA 
      // FACILITAR A VISUALIZAÇÃO
      case 1 : printf(" ##Lista de Alunos ##\n");
      for(contador = 0, i = 1; contador < qtd_aluno; i++, contador++){
        printf (" %d - %s\n", i, discente[contador].nome_aluno);
      }
      break;
      
      /*****************************/
      case 2 : printf(" ##Lista de Professores ##\n");
      for(contador = 0, i = 1; contador < qtd_prof; i++, contador++){
        printf (" %d - %s\n", i,docente[contador].nome_prof);
      } 
        break;

      /*****************************/
      case 3 :break;

      /*****************************/
      case 4 : break;

      /*****************************/
      case 5 : printf ("##Discentes (Homens) ##\n"); 
        for (contador = 0, i = 1; contador<qtd_aluno; contador++){
          if (discente[contador].sexo_aluno == 'M'){
            printf("%s\n", discente[contador].nome_aluno);
            
          } 
        } 
        printf ("##Discentes (Mulheres) ##\n");
        for (contador = 0, i = 1; contador<qtd_aluno; contador++){
          if (discente[contador].sexo_aluno == 'F'){
            printf("%s\n", discente[contador].nome_aluno);
            
          } 
        }    
        
        break;

      /*****************************/
      case 6 : 
      break;
      
      /*****************************/
      case 7 : break;

      /*****************************/
      case 8 : printf ("##Docentes (Homens) ##\n"); 
        for (contador = 0; contador<qtd_prof; contador++){
          if (docente[contador].sexo_prof == 'M'){
            printf("%c\n", docente[contador].sexo_prof);
            
          } 
        } 
        printf ("##Docentes (Mulheres) ##\n");
        for (contador = 0; contador<qtd_prof; contador++){
          if (docente[contador].sexo_prof == 'F'){
            printf("%c\n", docente[contador].sexo_prof);
            
          } 
        }    
        
      break;

      /*****************************/
      case 9 : break;

      /*****************************/
      case 10 :   printf("Digite o mês: ");
      scanf ("%d", &variavel);
      getchar ();
      printf("Aniversariantes do Mês - Alunos\n");
      for (contador = 0; contador<qtd_aluno; contador++){
          if (discente[contador].nascimento_aluno.mes == variavel)
            printf("%s\n", discente[contador].nome_aluno); 
        } 
        printf ("Aniversariantes do Mês - Professores\n");
        for (contador = 0; contador<qtd_prof; contador++){
          if (docente[contador].nascimento_prof.mes == variavel){
            printf("%s\n", docente[contador].nome_prof);
            
          } 
        } 
        
      break;

      /*****************************/
      case 11 : break;

      /*****************************/
      case 12 : break;

      /*****************************/
      case 13 : break;
    }
  }

  else {
    printf ("O programa encerrou!");
  }
       
    

}