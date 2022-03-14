#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    typedef struct {
        int ano;
        short mes;
        short dia;
    } DtNasc;
   
    struct baseAluno {
        long int alu_matricula;
        char alu_nome[100];
        char alu_sexo[15];
        DtNasc alu_datanasc;
        char alu_cpf[9];
    };
   
    struct baseAluno cadAluno;

    struct baseProf {
        long int prof_matricula;
        char prof_nome[100];
        char prof_sexo[15];
        DtNasc prof_datanasc;
        char prof_cpf[9];
    };
   
    struct baseProf cadProf;


    struct baseDisc {
        int disc_codigo;
        char disc_nome[50];
        int disc_semestre;
        long int prof_matricula;
    };
   
    struct baseDisc cadDisc;
    return 0;
}