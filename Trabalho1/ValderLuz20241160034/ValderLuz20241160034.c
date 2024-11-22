// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Valder Santos da Luz
//  email: valder.sluz@gmail.com
//  Matrícula: 20241160034
//  Semestre: 2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "ValderLuz20241160034.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return 2; //eh bissexto
    } else {
        return 1; //nao eh
    }
}


int q1(char data[])
{
    DataQuebrada dq = quebraData(data);
    int datavalida;

    //quebrar a string data em strings sDia, sMes, sAno

    if (dq.valido == 0){
        datavalida = 0;
    }


        int aux = bissexto(dq.iAno);

        switch(aux) {
        case 1: {
            // Não é bissexto
            switch(dq.iMes) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if((dq.iDia > 0) && (dq.iDia <= 31)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                case 4: case 6: case 9: case 11:
                    if((dq.iDia > 0) && (dq.iDia <= 30)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                case 2:
                    if((dq.iDia > 0) && (dq.iDia <= 28)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                default:
                    datavalida = 0;
                    break;
            }
            break;
        }

        case 2: {
            // É bissexto
            switch(dq.iMes) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if((dq.iDia > 0) && (dq.iDia <= 31)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                case 4: case 6: case 9: case 11:
                    if((dq.iDia > 0) && (dq.iDia <= 30)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                case 2:
                    if((dq.iDia > 0) && (dq.iDia <= 29)) {
                        datavalida = 1;
                    } else {
                        datavalida = 0;
                    }
                    break;

                default:
                    datavalida = 0;
                    break;
            }
            break;
        }

        default:
            datavalida = 0;
            break;
    }

    if (datavalida)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

 int diasMes(int mes, int ano){
    if(mes == 2){
        return (bissexto(ano) == 2) ? 29 : 28;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    return 31;
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dqinicial = quebraData(datainicial);
    DataQuebrada dqfinal = quebraData(datafinal);

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      //a lógica para saber se data inicial  maior do que data final é aqui mesmo
        if(dqinicial.iAno > dqfinal.iAno){
            dma.retorno = 4;
            return dma;
        }else if (dqinicial.iAno == dqfinal.iAno){
            if (dqinicial.iMes > dqfinal.iMes){
                dma.retorno = 4;
                return dma;
            }else if(dqinicial.iMes == dqfinal.iMes){
                if(dqinicial.iDia > dqfinal.iDia){
                    dma.retorno = 4;
                    return dma;
                }
            }
        }

      //calcule a distancia entre as datas

      dma.qtdDias = (dqfinal.iDia - dqinicial.iDia);
      dma.qtdMeses = (dqfinal.iMes - dqinicial.iMes);
      dma.qtdAnos = (dqfinal.iAno - dqinicial.iAno);

      if( bissexto(dqinicial.iAno) == 2){
         if(dqinicial.iMes > 2 || (dqinicial.iMes == 2 && (dqinicial.iDia >= 27 && dqinicial.iDia <= 29) ) ){
                dma.qtdDias = dma.qtdDias - 1;
         }
      }

      if( bissexto(dqfinal.iAno) == 2){
         if( (dma.qtdDias == 0) && (dma.qtdMeses == 0) && (dma.qtdAnos == 1) ){
                dma.qtdDias = dma.qtdDias;
         } else if  (dqfinal.iMes > 2 || (dqfinal.iMes == 2 && dqfinal.iDia <= 28 ) ){
                dma.qtdDias = dma.qtdDias + 1;
         }
      }

      if(dma.qtdDias < 0){
        dma.qtdDias = dma.qtdDias + (diasMes(dqinicial.iMes, dqinicial.iAno));
        dma.qtdMeses = (dma.qtdMeses - 1);
      }

      if(dma.qtdMeses < 0){
        dma.qtdMeses = (dma.qtdMeses + 12);
        dma.qtdAnos = dma.qtdAnos - 1;
      }

      //se tudo der certo
      dma.retorno = 1;
      return dma;

    }

}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */



int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int len = strlen(texto); // Calcula o tamanho da string

    for (int i = 0; i < len; i++) {
        if (isCaseSensitive) {
            if (c == texto[i]) {
                qtdOcorrencias = qtdOcorrencias + 1;
            }
        } else {
            if (tolower(c) == tolower(texto[i])) {
                qtdOcorrencias = qtdOcorrencias + 1;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente.
    Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias.
    Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera".
    Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
/*
    int qtdOcorrencias = 0;   // Contador de ocorrências
    int i, j;                 // Índices para loops
    int k = 0;                // Índice para o vetor `posicoes`
    int match;                // Variável para verificar correspondência


    for (i = 0; strTexto[i] != '\0'; i++) {
        // Verifica se a substring a partir de i corresponde ao padrão strBusca
        match = 1;  // Assume que há correspondência inicialmente
        for (j = 0; strBusca[j] != '\0'; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                match = 0; // Marca como não correspondente
                break;     // Sai do loop interno
            }
        }

        if (match) {
            posicoes[k++] = i;                     // Posição inicial
            posicoes[k++] = i + strlen(strBusca) - 1; // Posição final
            qtdOcorrencias++;                      // Incrementa o contador
            i += strlen(strBusca) - 1;             // Avança para depois da ocorrência encontrada
        }
        printf("%d,%d[%d,%d][%d,%d]\n", qtdOcorrencias, k, posicoes[0], posicoes[1], posicoes[2], posicoes[3]);
    }
*/

    int qtdOcorrencias = -1;
    int i, j, k, st;
    int aux[50];
    char temp[10];
    for(i = 0; strTexto[i] != '\0'; i++){
        //printf("%s\n", strTexto);
        for(j = 0; strBusca[j] != '\0'; j++){
            //printf("%s\n", strBusca);
            /*
            if(strBusca[j] <0){
                j = strlen(strBusca);
            }
            */

            if(strBusca[j] == strTexto[i] ){
                t[st] = strBusca[j];
                printf("{%d}\n", t);
            }else{
                t[0] = '\0';
                printf("{{%d}}\n", t);
            }

            if(strBusca[j] == strTexto[i]){
                if(strBusca[0] == strTexto[i] && (strlen(strBusca) - 1) == strTexto[i]){

                    aux[k] = strTexto[i];
                    printf("[[%d]]\n", aux[k]);
                    aux[k+1] = strTexto[i];
                    printf("[[[%d]]]\n", aux[k+1]);
                }

            }
        }
    }
    for(i = 0; i < 50; i++){
        printf("[%d]\n", aux[i]);
    }


/*
      for (i = 0; texto[i] != '\0'; i++){
        printf("%c : ", texto[i]);
        printf("%d, %i\n", texto[i], texto[i+1]);

        texto_int[i] = texto[i];
        texto_int[i+1] = texto[i+1];
      }
      printf("Numeros \n");
      for(j = 0; j < i ; j++){
            printf("%i\n", texto_int[j]);
      }

      printf("copia \n");
      int k = 0;
      for(j = 0; j < i ; j++){
            if (texto_int[j] != -61){
                texto_int2[k] = texto_int[j];
                k++;
            }
      }
*/

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    char snum[10];
    char aux[10];
    int i, j;
    sprintf(snum, "%d", num);

    for(i = strlen(snum) - 1, j = 0; i >= 0; i--, j++){
        aux[j] = snum[i];
    }
    aux[j] = '\0';
    num = atoi(aux);

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
    char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;
	/*
	devo validar
	*/

        for (i = 0; data[i] != '/'; i++){
            sDia[i] = data[i];
            if(sDia[i] == '-' || sDia[i] == ' '){
                dq.valido = 0;
                return dq;
            }
        }
        if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
            sDia[i] = '\0';  // coloca o barra zero no final

            for (i = 0; sDia[i] != '\0'; i++){
               if((sDia[i] >= 'a' && sDia[i] <= 'z') || (sDia[i] >= 'A' && sDia[i] <= 'Z')){
                    dq.valido = 0;
                    return dq;
               }
            }
        }else {
            dq.valido = 1;
        }


        int j = i + 1; //anda 1 cada para pular a barra
        i = 0;

        for (; data[j] != '/'; j++){
            if(sMes[i] == '-' || sMes[i] == ' '){
                dq.valido = 0;
                return dq;
            }
            sMes[i] = data[j];
            i++;
        }

        if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
            sMes[i] = '\0';  // coloca o barra zero no final
            for (i = 0; sMes[i] != '\0'; i++){
               if((sMes[i] >= 'a' && sMes[i] <= 'z') || (sMes[i] >= 'A' && sMes[i] <= 'Z')){
                    dq.valido = 0;
                    return dq;
               }
            }
        }else {
            dq.valido = 1;
        }


        j = j + 1; //anda 1 cada para pular a barra
        i = 0;

        for(; data[j] != '\0'; j++){
            if(sAno[i] == '-' || sAno[i] == ' '){
                dq.valido = 0;
                return dq;
            }
            sAno[i] = data[j];
            i++;
        }

        if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
            sAno[i] = '\0';  // coloca o barra zero no final
            for (i = 0; sAno[i] != '\0'; i++){
               if((sAno[i] >= 'a' && sAno[i] <= 'z') || (sAno[i] >= 'A' && sAno[i] <= 'Z')){
                    dq.valido = 0;
                    return dq;
               }
            }
        }else {
            dq.valido = 1;
      }

      dq.iDia = atoi(sDia);
      dq.iMes = atoi(sMes);
      dq.iAno = atoi(sAno);

	  dq.valido = 1;

  return dq;
}
