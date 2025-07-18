#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[] = {1,12,3,4,5,6,7,8,9,52,87,45,36,85,47};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    FILE *fp;

    fp = fopen("vetorTeste.txt", "w");
    if (fp == NULL){
        printf("Erro: arquivo nao pode ser criado!");
        exit(1);
    }

    for(int i = 0; i < tamanho; i++){
        fprintf(fp, "%d,", vetor[i]);
    }

    fclose(fp);
    printf("arquivo criado com sucesso.");

    return 0;
}
