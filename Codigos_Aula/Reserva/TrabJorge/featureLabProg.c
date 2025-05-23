//DECLARAÇÕES
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#define TAM_ALUNO 5
#define TAM_PROFESSOR 5
#define TAM_DISCIPLINA 5
#define CAD_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define EXCLUSAO_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define SEXO_INVALIDO -6


typedef struct dt {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct alu{
    int matricula;
    char sexo;
    char nome[40];
    DataNascimento nascimento;
    char cpf[12];
    int ativo;
 } Aluno;


typedef struct pro{
    int matricula;
    char sexo;
    char nome[40];
    DataNascimento nascimento;
    char cpf[12];
    int ativo;
 } Professor;


typedef struct dis{
    char nome[40];
    char codigo[6];
    int semestre;
    int professor;
    int alunos[TAM_ALUNO];
    int ativo;
 } Disciplina;

//--Assinatura das funções----

int menuRelatorio();
int menuGeral();
int menuAluno();
int menuProfessor();
int menuDisciplina();
bool validarData(DataNascimento data);
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);
void listarAluno(Aluno listaAluno[], int qtdAluno);
int atualizarAluno(Aluno listaAluno[], int qtdAluno);
int excluirAluno(Aluno listaAluno[], int qtdAluno);
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);
int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina);
int menuRelatorioAluno();
void ListarAlunoPorNome(Aluno listaAlunos[],int qtdAlunos);

void ListarAlunoPorSexo(Aluno listaAluno[], int qtdAluno);

void listarProfessorNome(Professor listarProfessor[], int qtdProfessor);



int main() {
    setlocale(LC_ALL, "Portuguese");

    Aluno listaAluno[TAM_ALUNO] = {0}; // Inicializar a lista de alunos
    Professor listaProfessor[TAM_PROFESSOR] = {0}; // Inicializar a lista de professores
    Disciplina listaDisciplina[TAM_DISCIPLINA] = {0}; // Inicializar a lista de disciplinas
    int opcao, opcaoAluno, opcaoProfessor, opcaoDisciplina, opcaoRelatorio, sair = 0;
    int qtdAluno = 0; // Inicializar a quantidade de alunos
    int qtdProfessor = 0;
    int qtdDisciplina = 0;

    while (!sair) {
        opcao = menuGeral();
        switch (opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                int sairAluno = 0;

                while (!sairAluno) {
                    opcaoAluno = menuAluno();
                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarAluno(listaAluno, qtdAluno);
                            if (retorno == LISTA_CHEIA){ printf("Lista de alunos cheia!\n"); }
                            else if (retorno == MATRICULA_INVALIDA) { printf("Matrícula Inválida!\n"); }
                            else { printf("Cadastrado com sucesso!\n");
                            qtdAluno++;
                            }
                            break;
                        }
                        case 2: {
                            listarAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 3: {
                            atualizarAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 4: {
                            int retorno = excluirAluno(listaAluno, qtdAluno);
                                if (retorno == EXCLUSAO_SUCESSO) {  printf("Aluno excluído com sucesso\n");
                                qtdAluno--;
                                }
                                else { printf("Matrícula inexistente!\n"); }
                            break;
                        }
                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    } // fim do switch Aluno
                } // fim do while Aluno
                break;
            }
            case 2: {
                int sairProfessor = 0;

                while (!sairProfessor) {
                    opcaoProfessor = menuProfessor();
                    switch (opcaoProfessor) {
                        case 0: {
                            sairProfessor = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
                            if (retorno == LISTA_CHEIA){ printf("Lista de professores cheia!\n"); }
                            else if (retorno == MATRICULA_INVALIDA) { printf("Matrícula Inválida!\n"); }
                            else { printf("Cadastrado com sucesso!\n");
                            qtdProfessor++;
                            }
                            break;
                        }
                        case 2: {
                            listarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 3: {
                            atualizarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 4: {
                            int retorno = excluirProfessor(listaProfessor, qtdProfessor);
                                if (retorno == EXCLUSAO_SUCESSO) {  printf("Professor excluído com sucesso\n");
                                qtdAluno--;
                                }
                                else { printf("Matrícula inexistente!\n"); }
                            break;
                        }
                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    } // fim do switch Aluno
                } // fim do while Aluno
                break;
            }
            case 3: {
                int sairDisciplina = 0;

                while(!sairDisciplina){
                    opcaoDisciplina = menuDisciplina();
                    switch (opcaoDisciplina){
                        case 0: {
                            sairDisciplina = 1;
                            break;
                        }
                        case 1: {
                            int retorno = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
                            if (retorno == LISTA_CHEIA){
                                printf("Lista de disciplinas cheia!\n");
                                break;
                            }
                            if (retorno == CAD_SUCESSO) {
                                printf("Disciplina cadastrada com sucesso!\n");
                                qtdDisciplina++;
                            }
                            break;
                        }
                        case 2: {
                            listarDisciplina(listaDisciplina, qtdDisciplina);
                            break;
                        }
                        case 3: {
                            atualizarDisciplina(listaDisciplina, qtdDisciplina);
                            break;
                        }
                        case 4: {
                            int retorno;
                            retorno = (excluirDisciplina(listaDisciplina, qtdDisciplina));
                            if (retorno == EXCLUSAO_SUCESSO) {
                                printf("Disciplina excluída com sucesso!\n");
                                break;
                            }
                            else {
                                printf("Matrícula não localizada ou inexistente!\n");
                                break;
                            }
                        }
                        default: {
                            printf("Opção Inválida\n");
                            break;
                        }
                    }
                    break;
                }
            }
            case 4: {
                int sairRelatorio = 0;
                while (!sairRelatorio){
                    opcaoRelatorio = menuRelatorio();
                    switch (opcaoRelatorio){
                        case 0: {
                            sairRelatorio = 1;
                            break;
                        }
                        case 1: {
                            break;
                        }
                        case 2:{
                            break;
                        }
                        case 3:{
                            break;
                        }
                        case 4:{
                            break;
                        }
                        case 5:{
                            break;
                        }
                        case 6:{
                            break;
                        }
                        case 7:{
                            listarProfessorNome(listarProfessor, qtdProfessor);
                            break;
                        }
                        case 8:{

                            break;
                        }

                    }
                }
                break;
            }

            default: {
                printf("Opção inválida!\n");
                break;

            }
        }
    }
    return 0;
}






//FUNCÕES DE VALIDAÇÃO
bool validarData(DataNascimento data) {
    int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o ano é bissexto
    bool bissexto = (data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0);
    if (bissexto) {
        diasNoMes[1] = 29; // Fevereiro tem 29 dias em anos bissextos
    }

    // Verifica se o mês está dentro do intervalo válido (1 a 12)
    if (data.mes < 1 || data.mes > 12) {
        return false;
    }

    // Verifica se o dia está dentro do intervalo válido para o mês
    if (data.dia < 1 || data.dia > diasNoMes[data.mes - 1]) {
        return false;
    }

    return true;
}

//FUNÇÕES ALUNO
int menuGeral(){
    int opcao;
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Relatórios\n\n");
    scanf("%d", &opcao);
    return opcao;
}

int menuAluno(){
    int opcaoAluno;
    printf("Módulo Aluno\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
    int matricula;
    printf("Cadastrar Aluno\n");

    if (qtdAluno >= TAM_ALUNO) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite a matrícula: ");
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        else {
            listaAluno[qtdAluno].matricula = matricula;

            printf("Digite o nome: ");
            getchar();
            fgets(listaAluno[qtdAluno].nome, sizeof(listaAluno[qtdAluno].nome), stdin);
            listaAluno[qtdAluno].nome[strcspn(listaAluno[qtdAluno].nome, "\n")] = 0;

            printf("Digite o sexo (M/F): ");
            char sexo[3];
            fgets(sexo, sizeof(sexo), stdin);
            sexo[strcspn(sexo, "\n")] = 0;
            sexo[0] = toupper(sexo[0]);

            if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                return SEXO_INVALIDO;
            }
            listaAluno[qtdAluno].sexo = sexo[0];
            bool retorno;

            do {

                printf("Digite o dia de nascimento: ");
                scanf("%d", &listaAluno[qtdAluno].nascimento.dia);
                printf("Digite o mes de nascimento: ");
                scanf("%d", &listaAluno[qtdAluno].nascimento.mes);
                printf("Digite o ano de nascimento: ");
                scanf("%d]", &listaAluno[qtdAluno].nascimento.ano);
                retorno = validarData(listaAluno[qtdAluno].nascimento);
                if (!retorno){
                    printf("Digite a data novamente, dados inválidos!\n");
                }
            } while (!retorno);

            printf("Digite o cpf: ");
            scanf(" %[^\n]", listaAluno[qtdAluno].cpf);

            listaAluno[qtdAluno].ativo = 1;
            return CAD_SUCESSO;
        }
    }
}

void listarAluno(Aluno listaAluno[], int qtdAluno){
    int achou=0;
    printf("Listar Aluno\n");
    if (qtdAluno==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (listaAluno[i].ativo == 1) {
            printf("Matrícula: %d\n", listaAluno[i].matricula);
            printf("Nome: %s\n", listaAluno[i].nome);
            printf("Sexo: %c\n", listaAluno[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].nascimento.dia, listaAluno[i].nascimento.mes, listaAluno[i].nascimento.ano);
            printf("CPF: %s\n", listaAluno[i].cpf);
            printf("--------------------------------------\n");
            achou++;}
            }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno){
    printf("Atualizar Aluno\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaAluno[i].matricula && listaAluno[i].ativo){ //atualização

                printf("Aluno Encontrado!\n");
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome atual: %s\n", listaAluno[i].nome);
                printf("Sexo atual: %c\n", listaAluno[i].sexo);
                printf("Data de Nascimento: %d/%d/%d\n", listaAluno[i].nascimento.dia, listaAluno[i].nascimento.mes, listaAluno[i].nascimento.ano);
                printf("CPF atual: %s\n", listaAluno[i].cpf);

                printf("Digite o novo nome: ");
                getchar();
                fgets(listaAluno[i].nome, sizeof(listaAluno[i].nome), stdin);
                listaAluno[i].nome[strcspn(listaAluno[i].nome, "\n")] = 0;

                printf("Digite o sexo atualizado: ");
                char sexo[3];
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = 0;
                sexo[0] = toupper(sexo[0]);

                if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                    printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                    return SEXO_INVALIDO; // Defina essa constante
                }
                listaAluno[i].sexo = toupper(sexo[0]);

                bool retorno;

                do {
                    printf("Digite o novo dia de nascimento: ");
                    scanf(" %d", listaAluno[qtdAluno].nascimento.dia);
                    printf("Digite o novo mes de nascimento: ");
                    scanf(" %d", listaAluno[qtdAluno].nascimento.mes);
                    printf("Digite o novo ano de nascimento: ");
                    scanf(" %d", listaAluno[qtdAluno].nascimento.ano);
                    retorno = validarData(listaAluno[qtdAluno].nascimento);
                    if (!retorno){
                        printf("Digite a data novamente, dados inválidos!\n");
                    }
                } while (!retorno);

                printf("Digite o novo cpf (000.000.000-00): ");
                scanf(" %[^\n]", listaAluno[i].cpf);

                achou =1;
                break;
            }
        }
        if (achou) {
            printf("Aluno atualizado com sucesso!\n"); }
        else { printf("Matrícula inexistente!\n"); }
    }
}

int excluirAluno(Aluno listaAluno[], int qtdAluno){
    printf("Excluir Aluno\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdAluno; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaAluno[i].matricula){
                //exclusão lógica
                listaAluno[i].ativo = 0;
                for (int j = i; j < qtdAluno -1; j++){                      //SHIFT
                    listaAluno[j].matricula = listaAluno[j+1].matricula;    //SHIFT
                    listaAluno[j].sexo = listaAluno[j+1].sexo;              //SHIFT
                    listaAluno[j].ativo = listaAluno[j+1].ativo;            //SHIFT
                }
                achou =1;
                break;
            }
        }
        if (achou) { return EXCLUSAO_SUCESSO; }
        else { return MATRICULA_INEXISTENTE; }
    }
}

//FUNÇÕES PROFESSOR
int menuProfessor(){
    int opcaoProfessor;
    printf("Módulo Professor\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    scanf("%d", &opcaoProfessor);
    return opcaoProfessor;
}

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor){
    int matricula;
    printf("Cadastrar Professor\n");

    if (qtdProfessor >= TAM_PROFESSOR) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite a matrícula: ");
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        else {
            listaProfessor[qtdProfessor].matricula = matricula;

            printf("Digite o nome: ");
            getchar();
            fgets(listaProfessor[qtdProfessor].nome, sizeof(listaProfessor[qtdProfessor].nome), stdin);
            listaProfessor[qtdProfessor].nome[strcspn(listaProfessor[qtdProfessor].nome, "\n")] = 0;

            //printf("Digite o sexo (M/F): ");
            //char sexo;

            printf("Digite o sexo (M/F): ");
            char sexo;
            scanf(" %c", &sexo);  // Usa-se &sexo para ler o caractere
            sexo = toupper(sexo);

            //fgets(sexo, sizeof(sexo), stdin);
            //sexo[strcspn(sexo, "\n")] = 0;
            //sexo = toupper(sexo);

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                return SEXO_INVALIDO; // Defina essa constante
            }
            listaProfessor[qtdProfessor].sexo = sexo;

            bool retorno;
            do {
                printf("Digite o novo dia de nascimento: ");
                scanf(" %d", &listaProfessor[qtdProfessor].nascimento.dia);
                printf("Digite o novo mes de nascimento: ");
                scanf(" %d", &listaProfessor[qtdProfessor].nascimento.mes);
                printf("Digite o novo ano de nascimento: ");
                scanf(" %d", &listaProfessor[qtdProfessor].nascimento.ano);
                if (!retorno){
                    printf("Digite a data novamente, dados inválidos!\n");
                }
            } while (!retorno);


            printf("Digite o cpf: ");
            scanf(" %[^\n]", listaProfessor[qtdProfessor].cpf);

            listaProfessor[qtdProfessor].ativo = 1;
            return CAD_SUCESSO;
        }
    }
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor){
    int achou=0;
    printf("Listar Professor\n");
    if (qtdProfessor==0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (listaProfessor[i].ativo == 1) {
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("Sexo: %c\n", listaProfessor[i].sexo);
                printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].nascimento.dia, listaProfessor[i].nascimento.mes, listaProfessor[i].nascimento.ano);
                printf("CPF: %s\n", listaProfessor[i].cpf);
                printf("--------------------------------------\n");
                achou++;
            }
        }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarProfessor(Professor listaProfessor[], int qtdProfessor){

    printf("Atualizar Professor!\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo){ //atualização
                printf("Professor Encontrado!\n");
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome atual: %s\n", listaProfessor[i].nome);
                printf("Sexo atual: %c\n", listaProfessor[i].sexo);
                printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].nascimento.dia, listaProfessor[i].nascimento.mes, listaProfessor[i].nascimento.ano);
                printf("CPF atual: %s\n", listaProfessor[i].cpf);

                printf("Digite o novo nome: ");
                getchar();
                fgets(listaProfessor[i].nome, sizeof(listaProfessor[i].nome), stdin);
                listaProfessor[i].nome[strcspn(listaProfessor[i].nome, "\n")] = 0;

                printf("Digite o sexo atualizado: ");
                char sexo[3];
                fgets(sexo, sizeof(sexo), stdin);
                sexo[strcspn(sexo, "\n")] = 0;
                sexo[0] = toupper(sexo[0]);

                if (strlen(sexo) == 0 || (sexo[0] != 'M' && sexo[0] != 'F')) {
                    printf("Sexo inválido! Por favor insira 'M' ou 'F'.\n");
                    return SEXO_INVALIDO; // Defina essa constante
                }
                listaProfessor[i].sexo = toupper(sexo[0]);

                bool retorno;
                do {
                    printf("Digite o novo dia de nascimento: ");
                    scanf(" %d", listaProfessor[qtdProfessor].nascimento.dia);
                    printf("Digite o novo mes de nascimento: ");
                    scanf(" %d", listaProfessor[qtdProfessor].nascimento.mes);
                    printf("Digite o novo ano de nascimento: ");
                    scanf(" %d", listaProfessor[qtdProfessor].nascimento.ano);
                    if (!retorno){
                        printf("Digite a data novamente, dados inválidos!\n");
                    }
                } while (!retorno);

                printf("Digite o novo cpf (000.000.000-00): ");
                scanf(" %[^\n]", listaProfessor[i].cpf);

                achou =1;
                break;
            }
        }
        if (achou) {
            printf("Professor atualizado com sucesso!\n"); }
        else { printf("Matrícula inexistente!\n"); }
    }
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor){
    printf("Excluir Professor\n");
    printf("Digite a matrícula: ");
    int matricula;
    scanf("%d", &matricula);
    int achou = 0;
    if (matricula < 0) {
        printf("Matrícula Inválida!\n");
    }
    else{
        for (int i = 0; i < qtdProfessor; i++) { // Exibir apenas os alunos cadastrados
            if (matricula == listaProfessor[i].matricula){
                //exclusão lógica
                listaProfessor[i].ativo = 0;
                for (int j = i; j < qtdProfessor -1; j++){                      //SHIFT
                    listaProfessor[j].matricula = listaProfessor[j+1].matricula;    //SHIFT
                    listaProfessor[j].sexo = listaProfessor[j+1].sexo;              //SHIFT
                    listaProfessor[j].ativo = listaProfessor[j+1].ativo;            //SHIFT
                }
                achou =1;
                break;
            }
        }
        if (achou) { return EXCLUSAO_SUCESSO; }
        else { return MATRICULA_INEXISTENTE; }
    }
}

//FUNÇÕES DISCIPLINA
int menuDisciplina(){
    int opcaoDisciplina;
    printf("Módulo Disciplina\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplina\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    scanf("%d", &opcaoDisciplina);
    return opcaoDisciplina;
}

int cadastrarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    int codigo;
    printf("Cadastrar Disciplina!\n");

    if (qtdDisciplina >= TAM_DISCIPLINA) {
        return LISTA_CHEIA;
    }
    else {
        printf("Digite o nome da disciplina:");
        getchar();
        fgets(listaDisciplina[qtdDisciplina].nome, sizeof(listaDisciplina[qtdDisciplina].nome), stdin);
        listaDisciplina[qtdDisciplina].nome[strcspn(listaDisciplina[qtdDisciplina].nome, "\n")] = 0;

        printf("Digite o código da disciplina:");
        getchar();
        fgets(listaDisciplina[qtdDisciplina].codigo, sizeof(listaDisciplina[qtdDisciplina].codigo), stdin);
        listaDisciplina[qtdDisciplina].codigo[strcspn(listaDisciplina[qtdDisciplina].codigo, "\n")] = 0;

        printf("Digite a qual semestre ela pertence: \n");
        scanf(" %d", &listaDisciplina[qtdDisciplina].semestre);

        printf("Qual a matricula do professor que a leciona: \n");
        scanf(" %d", &listaDisciplina[qtdDisciplina].professor);

        listaDisciplina[qtdDisciplina].ativo = 1;

        return CAD_SUCESSO;
    }

}

void listarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    int achou = 0;
    printf("Listar Disciplinas\n");
    if (qtdDisciplina == 0){
        printf("Lista vazia!\n");
    }
    else{
        for (int i = 0; i < qtdDisciplina; i++){
            if (listaDisciplina[i].ativo == 1){
                printf("Nome: %s\n", listaDisciplina[i].nome);
                printf("Código: %s\n", listaDisciplina[i].codigo);
                printf("Semestre: %d\n", listaDisciplina[i].semestre);
                printf("Professor: %d\n", listaDisciplina[i].professor);
                printf("--------------------------------------\n");
                achou++;
            }
        }
        if (achou==0) { printf("Lista vazia!\n"); }
    }
}

int atualizarDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    char codigoAtualizar[6];
    printf("Atualizar Disciplina!\n");
    printf("Digite o código da disciplina que deseja atualizar: ");
    scanf("%s", codigoAtualizar);
    int achou = 0;

    for (int i = 0; i < qtdDisciplina; i++) {
        if (strcmp(listaDisciplina[i].codigo, codigoAtualizar) == 0 && listaDisciplina[i].ativo == 1) {
            // Exibe os dados atuais da disciplina
            printf("\nDisciplina Encontrada!\n");
            printf("Nome atual: %s\n", listaDisciplina[i].nome);
            printf("Código: %s\n", listaDisciplina[i].codigo);
            printf("Semestre atual: %d\n", listaDisciplina[i].semestre);
            printf("Professor atual: %d\n", listaDisciplina[i].professor);

            // Solicita e atualiza os novos dados da disciplina
            printf("Digite o novo nome da disciplina: ");
            getchar(); // Limpa o buffer de entrada
            fgets(listaDisciplina[i].nome, sizeof(listaDisciplina[i].nome), stdin);
            listaDisciplina[i].nome[strcspn(listaDisciplina[i].nome, "\n")] = 0;

            printf("Digite o novo código da disciplina: ");
            fgets(listaDisciplina[i].codigo, sizeof(listaDisciplina[i].codigo), stdin);
            listaDisciplina[i].codigo[strcspn(listaDisciplina[i].codigo, "\n")] = 0;

            printf("Digite o novo semestre da disciplina: ");
            scanf("%d", &listaDisciplina[i].semestre);

            printf("Digite o novo código do professor para a disciplina: ");
            scanf("%d", &listaDisciplina[i].professor);

            achou = 1;
            break;
        }
    }

    if (achou) {
        printf("Disciplina atualizada com sucesso!\n");
    } else {
        printf("Código de disciplina inexistente ou disciplina não está ativa.\n");
    }

}

int excluirDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
    char codigoExcluir;
    int achou = 0;
    printf("Excluir Disciplina\n");
    printf("Digite o código da disciplina a ser excluida: ");
    scanf("%s", codigoExcluir);
    if (codigoExcluir == "") { printf("Disciplina Inválida"); }
    else {
        for (int i = 0; i<qtdDisciplina;i++){
            printf("%c", strcmp(listaDisciplina[qtdDisciplina].codigo, codigoExcluir));
            /*if (){
                listaDisciplina[i].ativo = 0;
                for (int j = i; j < qtdDisciplina -1; j++){                                 //SHIFT
                    listaDisciplina[j].semestre = listaDisciplina[j+1].semestre;
                    listaDisciplina[j].professor = listaDisciplina[j+1].professor;
                    listaDisciplina[j].ativo = listaDisciplina[j+1].ativo;
                }
                achou = 1;
                break;
            }*/
        }
        if (achou) { return EXCLUSAO_SUCESSO; }
    }

}


void ListarAlunoPorNome(Aluno listaAlunos[],int qtdAlunos){
    for (char i = 'A'; i <= 'Z'; i++){
        for (int j = 0; j < qtdAlunos; j++){
            if (listaAlunos[j].nome[0] == i){
                puts(listaAlunos[j].nome);
            }
        }
    }
}


int menuRelatorioAluno(){
    int opcao;
    printf("Menu Relatório de Alunos\n");
    printf("0 - Sair\n");
    printf("1 - Listar por Sexo\n");
    printf("2 - Listar Por Nome\n");
    printf("3 - Listar por Data de Nacimento\n");
    printf("4 - Listar Alunos em Menos de 3 Matérias\n");
    printf("Digite sua opção:");
    scanf("%d",&opcao);
    return opcao;
}

//--------------------------------- valder ------------------------------------

void listarProfessorNome(Professor listarProfessor[], int qtdProfessor){
    printf("Professor por ordem alfabetica\n");

    if(qtdProfessor == 0){
        printf("Lista de Professor vazia\n");
    }else{
        for(char i = 'A'; i <= 'Z'; i++){
            for(int j = 0; j < qtdProfessor; j++){
                if(listarProfessor[j].ativo == 1){
                    printf("%s", listarProfessor[i].nome);
                }
            }
        }
    }
}

void listarProfessorSexo(Professor listarProfessor[], int qtdProfessor){
    printf("Professor por sexo\n");

    if(qtdProfessor == 0){
        printf("Lista de Professor vazia\n");
    }else{
        printf("Escolha o sexo a buscar: (M/F)");
        char escolha;
        scanf("%c", &escolha);
        escolha = toupper(escolha);

        if(escolha == 'M'){
            for(int i = 0; i < qtdProfessor; i++){
                if(listarProfessor[i].sexo == 'M'){
                    printf("%s [%c]", listarProfessor[i].nome, listarProfessor[i].sexo);
                }
            }
        }else if{
            for(int i = 0; i < qtdProfessor; i++){
                if(listarProfessor[i].sexo == 'F'){
                    printf("%s [%c]", listarProfessor[i].nome, listarProfessor[i].sexo);
                }
            }
        }
    }

}

//FUNÇÕES RELATÓRIOS
int menuRelatorio(){
    int opcao;
    printf("Relatórios\n");
    printf("0 - Sair\n");
    printf("1 - Relatórios de Alunos\n");
    printf("2 - Relatórios de Professores\n");
    printf("3 - Relatórios de Disciplina\n");
    printf("4 - Aniversariante do Mês\n");
    printf("5 - Busca por Nome\n");
    printf("6 - Turmas com mais de 40 vagas\n");
    printf("7 - Listar Profesor por nome\n");
    printf("8 - Listar Professor por sexo\n");
    scanf("%d", &opcao);
    return opcao;
}


void ListarAlunoPorSexo(Aluno listaAluno[], int qtdAluno){
    char escolha;
    printf("Digite o sexo: ");
    while(getchar() != '\n');
    scanf("%c",&escolha);
    escolha = toupper(escolha);
    if (escolha != 'F' || escolha != 'M'){
        printf("Opção Invalida");
    }
    else{
        if(escolha == 'M'){
            for(int i = 0; i <qtdAluno;i++){
                if(listaAluno[i].sexo == 'M'){
                    puts(listaAluno[i].nome);

                }
            }
        }
        else{
            for(int i = 0; i <qtdAluno;i++){
                if(listaAluno[i].sexo == 'F'){
                    puts(listaAluno[i].nome);

                }
            }

        }
    }
}
