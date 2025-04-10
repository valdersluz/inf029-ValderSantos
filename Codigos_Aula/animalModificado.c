#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 3

typedef struct {
    int dia;
    int mes;
    int ano;
}DataNascimento;

typedef struct
{
    int idade;
    char sexo;
    char nome[20];
    DataNascimento data;

} Animal;

int main(){
    Animal listaAnimais[TAM];


    int sair = 0;
    int opcao;
    int qtd = 0;

    while (!sair){    //sair == 0    OU    sair != 1
        printf("Opções\n");
        printf("1 - Cadastrar\n");
        printf("2 - Imprimir todos\n");
        printf("3 - Imprimir maiores que a média\n");
        printf("4 - Excluir animal\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                // fazendo a leitura dos dados
                if (qtd < TAM){
                    printf("Digite o nome: ");
                    scanf("%s", &listaAnimais[qtd].nome);
                    getchar();

                    printf("Digite a idade: ");
                    scanf("%d", &listaAnimais[qtd].idade);
                    getchar();

                    printf("Digite a sexo: ");
                    scanf("%c", &listaAnimais[qtd].sexo);
                    getchar();

                    printf("Digite dia nascimento: ");
                    scanf("%d", &listaAnimais[qtd].data.dia);
                    getchar();

                    printf("Digite mes nascimento: ");
                    scanf("%d", &listaAnimais[qtd].data.mes);
                    getchar();

                    printf("Digite ano nascimento: ");
                    scanf("%d", &listaAnimais[qtd].data.ano);
                    qtd ++;
                }else{
                    printf("PET cheio");
                }

                break;
            }
            case 2:{
                 //imprimindo todos
                printf("#### Todos animais\n");
                for (int i = 0; i < qtd; i++){
                    printf("Nome: %s - Data de Nascimento: %d / %d / %d", listaAnimais[i].nome, listaAnimais[i].data.dia, listaAnimais[i].data.mes, listaAnimais[i].data.ano);
                    printf("\nIdade: %d - Sexo: %c\n", listaAnimais[i].idade, listaAnimais[i].sexo);
                }
                break;
            }
            case 3:{
                // calcular a média
                int soma = 0;
                for (int i = 0; i < qtd; i++){
                    soma += listaAnimais[i].idade;
                }
                int media = soma / qtd;

                //imprimindo maiores que a média
                printf("#### Animais com idade acima da média\n");
                for (int i = 0; i < qtd; i++){
                    if (listaAnimais[i].idade > media)
                        printf("Idade: %d - Sexo: %c\n", listaAnimais[i].idade, listaAnimais[i].sexo);
                }
                break;
            }
            case 4:{
                //excluir animal
                int nome_animal[20];
                printf("Digite o nome do animal para excluir: ");
                scanf("%s", nome_animal);

                for(int i = 0; i < qtd; i++){
                    if(strcmp(listaAnimais[i].nome, nome_animal) == 0){
                        // excluir

                        for(int j = 0; j < qtd; j++){

                            listaAnimais[j].idade = listaAnimais[j+1].idade;
                            listaAnimais[j].sexo = listaAnimais[j+1].sexo;
                            listaAnimais[j].data.dia = listaAnimais[j+1].data.dia;
                            listaAnimais[j].data.mes = listaAnimais[j+1].data.mes;
                            listaAnimais[j].data.ano = listaAnimais[j+1].data.ano;
                            strcpy(listaAnimais[j].nome, listaAnimais[j+1].nome);
                        }

                    }else{
                        //nome inválido
                        printf("Nome do animal não existe no pet!");
                    }

                }
                break;
            }
            case 5:{
                //atualizar ou editar animal



                printf("Deseja mudar o nome: S/N ?");
                char letra;
                scanf("%c", &letra);

                letra = toupper(letra);
                if(letra == 'S'){

                    int nome_animal[20];
                    printf("Digite o nome do animal que quer modificar: ");
                    fgets(listaAnimais[i].nome, 20, stdin);
                    size_t ln = strlen(listaAnimais[i].nome) - 1;
                    if(listaAnimais[i].nome[ln] == '\n')
                        listaAnimais[i].nome[ln] = '\0';

                }



                break;
            }
            case 0:{
                sair = 1;
                break;
            }
            default:
                printf("Opção inválida\n");
        }

    }






}
