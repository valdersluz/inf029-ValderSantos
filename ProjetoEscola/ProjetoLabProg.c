#include <stdio.h>
#include <string.h>

#define TAM_ALUNO 3
#define TAM_PROF 3

#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3

#define ATUALIZACAO_ALUNO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_ALUNO_SUCESSO -6

#define ATUALIZACAO_PROF_SUCESSO -7
#define EXCLUSAO_PROF_SUCESSO -8
#define CAD_PROF_SUCESSO -9

#define ERRO_CAD_SEXO -10
#define ERRO_CAD_DATA -11

typedef struct dma {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct alu{
    int matricula;
    char nome[50];
    char sexo;
    int ativo;
    char cpf[15];
    Data dataNasc;
} Aluno;

typedef struct prof{
    int matricula;
    char nome[50];
    int sexo;
    int ativo;
    Data dataNasc;
} Professor;

// protótipos das funções
int menu_geral();

int menu_aluno();
int menu_professor();

int cadastrar_aluno(Aluno listarAluno[], int qtdAluno);
void listar_aluno(Aluno listarAluno[], int qtdAluno);
int atualizar_aluno(Aluno listarAluno[], int qtdAluno);
int excluir_aluno(Aluno listarAluno[], int qtdAluno);

int cadastrar_professor(Professor listarProfessor[], int qtdProfessor);
void listar_professor(Professor listarProfessor[], int qtdProfessor);
int atualizar_professor(Professor listarProfessor[], int qtdProfessor);
int excluir_professor(Professor listarProfessor[], int qtdProfessor);

// modularização
// utilizar um gerador automático de matrícula
// inserir novos atributos na struct aluno e fazer a leitura desses atributos
// validações




int main(void){

    Aluno listarAluno[TAM_ALUNO];
    Professor listarProfessor[TAM_PROF];
    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
    int sair = 0;

    while(!sair){

        opcao = menu_geral();

        switch(opcao){
            case 0:{
                sair = 1;
                break;
            }
            case 1:{
                printf("Modulo Aluno\n");
                int sairAluno = 0;
                int opcaoAluno;

                while(!sairAluno){

                    opcaoAluno = menu_aluno();

                    switch(opcaoAluno){
                        case 0:{
                            sairAluno = 1;
                            break;
                        }
                        case 1:{

                            int retorno = cadastrar_aluno(listarAluno, qtdAluno);

                            if(retorno == LISTA_CHEIA){
                                printf("Lista de alunos cheia\n");
                            }else if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula Invalida\n");
                            }else if(retorno == ERRO_CAD_SEXO) {
                                printf("Sexo invalido");
                            }else{
                                printf("Cadastrado com Sucesso\n");
                                qtdAluno++;
                            }

                            break;
                        }
                        case 2:{

                            listar_aluno(listarAluno, qtdAluno);
                            break;

                        }
                        case 3:{

                            int retorno = atualizar_aluno(listarAluno, qtdAluno);

                            switch(retorno){
                                case MATRICULA_INVALIDA:{
                                    printf("Matricula invalida\n");
                                    break;
                                }
                                case MATRICULA_INEXISTENTE:{
                                    printf("Matricula Inexistente\n");
                                    break;
                                }
                                case ATUALIZACAO_ALUNO_SUCESSO:{
                                    printf("Aluno atualizado com sucesso\n");
                                    break;
                                }
                            }

                            break;
                        }
                        case 4:{

                            int retorno = excluir_aluno(listarAluno, qtdAluno);

                            switch(retorno){
                                case MATRICULA_INVALIDA: {
                                    printf("Matricula invalida\n");
                                    break;
                                }
                                case MATRICULA_INEXISTENTE: {
                                    printf("Matricula inexistente\n");
                                    break;
                                }
                                case EXCLUSAO_ALUNO_SUCESSO: {
                                    printf("Aluno excluido com sucesso\n");
                                    qtdAluno--;
                                    break;
                                }
                            }




                            break;
                        }
                        default:{
                            printf("Opcao Invalida\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2:{
                /* Minha parte */
                printf("Modulo Professor\n");
                int sairProfessor = 0;
                int opcaoProfessor;

                while(!sairProfessor){

                    opcaoProfessor = menu_professor();

                    switch(opcaoProfessor){
                        case 0:{
                            sairProfessor = 1;
                            break;
                        }
                        case 1:{
                            // cadastrar
                            int retorno = cadastrar_professor(listarProfessor, qtdProfessor);

                            if(retorno == LISTA_CHEIA){
                                printf("Lista de professores cheia\n");
                            }else if(retorno == MATRICULA_INVALIDA){
                                printf("Matricula Invalida\n");

                            }else{
                                printf("Cadastrado com Sucesso\n");
                                qtdProfessor++;
                            }

                            break;
                        }
                        case 2:{
                            listar_professor(listarProfessor, qtdProfessor);
                            break;
                        }
                        case 3:{
                            // atualizar
                            int retorno = atualizar_professor(listarProfessor, qtdProfessor);
                            switch(retorno){
                                case MATRICULA_INVALIDA:{
                                    printf("Matricula invalida\n");
                                    break;
                                }
                                case MATRICULA_INEXISTENTE:{
                                    printf("Matricula Inexistente\n");
                                    break;
                                }
                                case ATUALIZACAO_PROF_SUCESSO:{
                                    printf("Professor atualizado com sucesso\n");
                                    break;
                                }
                            }

                            break;
                        }
                        case 4:{
                            // excluir

                            int retorno = excluir_professor(listarProfessor, qtdProfessor);

                            switch(retorno){
                                case MATRICULA_INVALIDA: {
                                    printf("Matricula invalida\n");
                                    break;
                                }
                                case MATRICULA_INEXISTENTE: {
                                    printf("Matricula inexistente\n");
                                    break;
                                }
                                case EXCLUSAO_PROF_SUCESSO: {
                                    printf("Professor excluido com sucesso\n");
                                    qtdProfessor--;
                                    break;
                                }
                            }
                            break;

                        }
                        default:{
                            printf("Opcao Invalida\n");
                        }
                    }


                }
                break;
            }
            case 3:{
                printf("Modulo Disciplina\n");
                break;
            }
            default:{
                printf("Opcao Invalida\n");
            }
        }
    }

    return 0;
}



int menu_geral(){
        int opcao;

        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

        return opcao;
}


int menu_aluno(){
    int opcao;

    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");

    scanf("%d", &opcao);

    return opcao;
}


int cadastrar_aluno(Aluno listarAluno[], int qtdAluno){
    printf("Cadastrar Aluno\n");

    if (qtdAluno >= TAM_ALUNO) {
          return LISTA_CHEIA;
    }else{

        printf("Digite a Matricula: \n");
        int matricula;
        scanf("%d", &matricula);
        getchar();
        if ( matricula < 0){
            return MATRICULA_INVALIDA;
        }else{
            listarAluno[qtdAluno].matricula = matricula;
        }

        printf("Digite nome: \n");
        fgets(listarAluno[qtdAluno].nome, 50, stdin);
        size_t ln = strlen(listarAluno[qtdAluno].nome) - 1;
        if(listarAluno[qtdAluno].nome[ln] == '\n')
            listarAluno[qtdAluno].nome[ln] = '\0';

        printf("Digite o sexo: \n");
        scanf("%c", &listarAluno[qtdAluno].sexo);
        listarAluno[qtdAluno].sexo = toupper(listarAluno[qtdAluno].sexo);
        if(listarAluno[qtdAluno].sexo != 'M' && listarAluno[qtdAluno].sexo != 'F'){
            return ERRO_CAD_SEXO;
        }

        printf("Digite o dia de nascimento: \n");
        scanf("%d", &listarAluno[qtdAluno].dataNasc.dia);

        printf("Digite o mês de nascimento: \n");
        scanf("%d", &listarAluno[qtdAluno].dataNasc.mes);

        printf("Digite o ano de nascimento: \n");
        scanf("%d", &listarAluno[qtdAluno].dataNasc.ano);
        getchar();

        printf("Digite o CPF: ");
        fgets(listarAluno[qtdAluno].cpf, 15, stdin);
        ln = strlen(listarAluno[qtdAluno].cpf) - 1;
        if(listarAluno[qtdAluno].cpf[ln] == '\n')
            listarAluno[qtdAluno].cpf[ln] = '\0';
        printf("\n");


        listarAluno[qtdAluno].ativo = 1;

        return CAD_ALUNO_SUCESSO;
    }

}

void listar_aluno(Aluno listarAluno[], int qtdAluno){

    printf("Listar Aluno\n");

    if(qtdAluno == 0){
        printf("Lista de aluno vazia\n");
    }else{
        for(int i = 0; i < qtdAluno; i++){
            if(listarAluno[i].ativo == 1)
            printf("-------------\n");
            printf("Matricula: %d\n", listarAluno[i].matricula);
            printf("Nome: %s\n", listarAluno[i].nome);
            printf("Sexo: %c\n");
            printf("Data Nascimento: %d/%d/%d\n", listarAluno[i].dataNasc.dia, listarAluno[i].dataNasc.mes, listarAluno[i].dataNasc.ano);
            printf("CPF: %s\n", listarAluno[i].cpf);
        }
    }
}

int atualizar_aluno(Aluno listarAluno[], int qtdAluno){

    printf("Atualizar Aluno\n");

    printf("Digite a Matricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if ( matricula < 0){
        return MATRICULA_INVALIDA;
    }else{
        for(int i = 0; i < qtdAluno; i++){
           if (matricula == listarAluno[i].matricula && listarAluno[i].ativo) {
                //Atualização
                printf("Digite a nova matricula\n");
                int novaMatricula;
                scanf("%d", &novaMatricula);
                if(matricula < 0){
                    return MATRICULA_INVALIDA;
                }
                listarAluno[i].matricula = novaMatricula;
                achou = 1;
                break;
           }
        }
        if(achou){
            return ATUALIZACAO_ALUNO_SUCESSO;
        }else {
            return MATRICULA_INEXISTENTE;
        }
    }
}

int excluir_aluno(Aluno listarAluno[], int qtdAluno){
    printf("Excluir Aluno\n");

    printf("Digite a Matricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if ( matricula < 0){
        return MATRICULA_INVALIDA;
    }else{
        for(int i = 0; i < qtdAluno; i++){
            if (matricula == listarAluno[i].matricula) {
                // Exclusão lógica
                listarAluno[i].ativo = -1;

                for(int j = i; j < qtdAluno - 1; j++){ //shift
                    listarAluno[j].matricula = listarAluno[j+1].matricula;
                    listarAluno[j].sexo = listarAluno[j+1].sexo;
                    listarAluno[j].ativo = listarAluno[j+1].ativo;
                }
                achou = 1;
                break;
            }
        }

        if(achou){
            return EXCLUSAO_ALUNO_SUCESSO;
        }else {
            return MATRICULA_INEXISTENTE;
        }

    }
}

/* -------------------------- PROFESSOR -------------------------------------*/

int menu_professor(){
    int opcao;

    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");

    scanf("%d", &opcao);

    return opcao;
}


int cadastrar_professor(Professor listarProfessor[], int qtdProfessor){
    printf("Cadastrar Professor\n");

    if(qtdProfessor >= TAM_PROF){
        return LISTA_CHEIA;
    }else {
        printf("Digite a matricula\n");
        int matricula;

        scanf("%d", &matricula);

        if(matricula < 0){
            return MATRICULA_INVALIDA;
        }else {
            listarProfessor[qtdProfessor].matricula = matricula;
            listarProfessor[qtdProfessor].ativo = 1;
        }

        return CAD_PROF_SUCESSO;
    }

}

void listar_professor(Professor listarProfessor[], int qtdProfessor){
    printf("Listar Professor\n");

    if(qtdProfessor == 0) {
        printf("lista de professor vazia\n");
    }else {

        for(int i = 0; i < qtdProfessor; i++){
            if(listarProfessor[i].ativo == 1){
                printf("matricula: %d\n", listarProfessor[i]);
            }
        }

    }

}


int atualizar_professor(Professor listarProfessor[], int qtdProfessor){
    printf("Atualizar Professor\n");

    printf("Digite a matricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }else {
        for(int i = 0; i < qtdProfessor; i++){
            if(matricula == listarProfessor[i].matricula && listarProfessor[i].ativo){
                printf("digite a nova matricula: \n");
                int novaMatricula;
                scanf("%d", &novaMatricula);
                if(novaMatricula < 0){
                   return MATRICULA_INVALIDA;
                }else {
                    listarProfessor[i].matricula = novaMatricula;
                    achou = 1;
                    break;
                }
            }
        }
        if(achou){
            return ATUALIZACAO_PROF_SUCESSO;
        }else {
            return MATRICULA_INEXISTENTE;
        }
    }

}

int excluir_professor(Professor listarProfessor[], int qtdProfessor){
    printf("Excluir Professor\n");

    printf("digite a matricula: \n");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if(matricula < 0){
        return MATRICULA_INVALIDA;
    }else {
        for(int i = 0; i < qtdProfessor; i++){
            if(matricula == listarProfessor[i].matricula){
                //exclusão lógica
                listarProfessor[i].ativo = -1;

                for(int j = i; j < qtdProfessor - 1; j++){

                    listarProfessor[j].matricula = listarProfessor[j+1].matricula;
                    listarProfessor[j].sexo = listarProfessor[j+1].sexo;
                    listarProfessor[j].ativo = listarProfessor[j+1].ativo;
                }

                achou = 1;
                break;
            }
        }

        if(achou){
            return EXCLUSAO_PROF_SUCESSO;
        }else {
            return MATRICULA_INEXISTENTE;
        }

    }

}


