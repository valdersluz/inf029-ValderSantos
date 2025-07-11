
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "ValderLuz20241160034.h"

typedef struct vetPrincipal{
    int *vetor;
    int tamVetAux;
    int posicao;
    int posicaoVetAux;
}VetPrincipal;

VetPrincipal *vetorPrincipal[TAM];

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar()
{
    for(int i = 0; i < TAM; i++){

        vetorPrincipal[i] = NULL;

    }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    posicao = posicao - 1;

    if((posicao < 0) || (posicao >= TAM)){
        // se posição é um valor válido {entre 1 e 10}
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao] != NULL){
        // a posicao pode já existir estrutura auxiliar
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    if(tamanho < 1){
        // o tamanho nao pode ser menor que 1
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }


    vetorPrincipal[posicao] = (VetPrincipal *)malloc(sizeof(VetPrincipal));
    if (vetorPrincipal[posicao] == NULL) {
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }


    vetorPrincipal[posicao]->vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetorPrincipal[posicao]->vetor == NULL) {
        free(vetorPrincipal[posicao]);
        vetorPrincipal[posicao] = NULL;


        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao]->tamVetAux = tamanho;
    vetorPrincipal[posicao]->posicao = posicao;
    vetorPrincipal[posicao]->posicaoVetAux = 0;

    retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if((posicao <= 0) || (posicao > 10)){
        posicao_invalida = 1;
    }

    posicao = posicao - 1;

    if (posicao_invalida){
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else
    {
        // testar se existe a estrutura auxiliar
        if(vetorPrincipal[posicao] != NULL){
            existeEstruturaAuxiliar = 1;
        }
        if (existeEstruturaAuxiliar)
        {
            if(vetorPrincipal[posicao]->posicaoVetAux < vetorPrincipal[posicao]->tamVetAux){
                temEspaco = 1;
            }

            if (temEspaco)
            {
                //insere
                vetorPrincipal[posicao]->vetor[vetorPrincipal[posicao]->posicaoVetAux] = valor;
                vetorPrincipal[posicao]->posicaoVetAux++;

                retorno = SUCESSO;
                return retorno;
            }
            else
            {
                retorno = SEM_ESPACO;
                return retorno;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    int retorno = 0;
    int posicaoInvalida = 0;
    int existeEstruturaAuxiliar = 0;

    // Validação da posição
    if (posicao <= 0 || posicao > TAM) {
        posicaoInvalida = 1;
    }

    posicao = posicao - 1;

    if (posicaoInvalida) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    // Verifica se existe estrutura auxiliar na posição
    if (vetorPrincipal[posicao] != NULL) {
        existeEstruturaAuxiliar = 1;
    }

    if (!existeEstruturaAuxiliar) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    // Verifica se a estrutura auxiliar está vazia
    if (vetorPrincipal[posicao]->posicaoVetAux == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    // Reduz o índice lógico do vetor
    vetorPrincipal[posicao]->posicaoVetAux--;

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int posicaoInvalida = 0;
    int existeEstruturaAuxiliar = 0;

    // Validação da posição
    if (posicao <= 0 || posicao > TAM) {
        posicaoInvalida = 1;
    }

    posicao = posicao - 1;

    if (posicaoInvalida) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    // Verifica se existe estrutura auxiliar na posição
    if (vetorPrincipal[posicao] != NULL) {
        existeEstruturaAuxiliar = 1;
    }

    if (!existeEstruturaAuxiliar) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    // Verifica se a estrutura auxiliar está vazia
    if (vetorPrincipal[posicao]->posicaoVetAux == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    int *vetorAux = vetorPrincipal[posicao]->vetor;
    int tamanho = vetorPrincipal[posicao]->posicaoVetAux;
    int encontrado = 0;

    // Procura o valor no vetor auxiliar
    for (int i = 0; i < tamanho; i++) {
        if (vetorAux[i] == valor) {
            encontrado = 1;

            // Remove o valor deslocando os elementos à esquerda
            for (int j = i; j < tamanho - 1; j++) {
                vetorAux[j] = vetorAux[j + 1];
            }

            // Reduz o tamanho lógico do vetor
            vetorPrincipal[posicao]->posicaoVetAux--;
            break;
        }
    }

    if (!encontrado) {
        retorno = NUMERO_INEXISTENTE;
        return retorno;
    }

    retorno = SUCESSO;
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    if (posicao <= 0 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    posicao = posicao - 1;

    if (vetorPrincipal[posicao] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    VetPrincipal *estrutura = vetorPrincipal[posicao];
    for (int i = 0; i < estrutura->posicaoVetAux; i++) {
        vetorAux[i] = estrutura->vetor[i];
    }

    retorno = SUCESSO;
    return retorno;
}

// Função auxiliar para ordenar um vetor
void ordenarVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);

    if (retorno == SUCESSO) {
        VetPrincipal *estrutura = vetorPrincipal[posicao - 1];
        ordenarVetor(vetorAux, estrutura->posicaoVetAux);
    }

    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    int indice = 0;
    int todasVazias = 1;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->posicaoVetAux > 0) {
            todasVazias = 0;
            for (int j = 0; j < vetorPrincipal[i]->posicaoVetAux; j++) {
                vetorAux[indice++] = vetorPrincipal[i]->vetor[j];
            }
        }
    }

    if (todasVazias) {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    } else {
        retorno = SUCESSO;
        return retorno;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;

    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if (retorno == SUCESSO) {
        int totalElementos = 0;
        for (int i = 0; i < TAM; i++) {
            if (vetorPrincipal[i] != NULL) {
                totalElementos += vetorPrincipal[i]->posicaoVetAux;
            }
        }
        ordenarVetor(vetorAux, totalElementos);
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    if (posicao <= 0 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    posicao -= 1;

    if (vetorPrincipal[posicao] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if (novoTamanho < 0 && (vetorPrincipal[posicao]->tamVetAux + novoTamanho) < 1) {
        retorno = NOVO_TAMANHO_INVALIDO;
        return retorno;
    }

    VetPrincipal *estrutura = vetorPrincipal[posicao];
    int novoTamTotal = estrutura->tamVetAux + novoTamanho;

    int *novoVetor = realloc(estrutura->vetor, novoTamTotal * sizeof(int));
    if (novoVetor == NULL) {
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }

    estrutura->vetor = novoVetor;
    estrutura->tamVetAux = novoTamTotal;

    if (estrutura->posicaoVetAux > novoTamTotal) {
        estrutura->posicaoVetAux = novoTamTotal;
    }

    retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;

    if (posicao <= 0 || posicao > TAM) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    posicao = posicao - 1;

    if (vetorPrincipal[posicao] == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    VetPrincipal *estrutura = vetorPrincipal[posicao];

    if (estrutura->posicaoVetAux == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    retorno = estrutura->posicaoVetAux;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cabecote = malloc(sizeof(No));
    if (cabecote == NULL) {
        return NULL;
    }

    cabecote->prox = NULL;
    No *atual = cabecote;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            VetPrincipal *estrutura = vetorPrincipal[i];
            for (int j = 0; j < estrutura->posicaoVetAux; j++) {
                No *novo = malloc(sizeof(No));
                if (novo == NULL) {
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }

                novo->conteudo = estrutura->vetor[j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
            }
        }
    }

    return cabecote;
    // quando retornado null direto não funcionou
    //return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (inicio == NULL || inicio->prox == NULL) {
        return;
    }

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if (inicio == NULL || *inicio == NULL) {
        return;
    }

    No *atual = *inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    *inicio = NULL;
}


/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i = 0; i < TAM; i++){
        if(vetorPrincipal[i] != NULL){
            vetorPrincipal[i] = NULL;
        }
    }
}
