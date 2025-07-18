#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char ch[100];

    fp = fopen("vetorTeste.txt", "r");

    if(fp == NULL){
        printf("Erro: arquivo nao pode ser aberto!");
        exit(1);
    }

    while(fgets(ch, sizeof(ch), fp) != NULL){
        for(int i = 0; ch[i] != '\0'; i++){
            if(ch[i] == ','){
                printf(" ");
                continue;
            }
                printf("%c", ch[i]);
        }
    }

    fclose(fp);

    return 0;
}
