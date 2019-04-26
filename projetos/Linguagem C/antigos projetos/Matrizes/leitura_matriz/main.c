/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 14 de Junho de 2018, 15:34
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
FILE *arq1;
FILE *arq2;
FILE *arq3;
int main(int argc, char** argv){
    int lin1, col1, lin2, col2, i, j, k, soma, n;
    int matriz1[max][max], matriz2[max][max], matriz3[max][max];
    
    //abrindo para leitura
    arq1 = fopen("matriz1", "r");
    arq2 = fopen("matriz2", "r");
    arq3 = fopen("matriz3", "w");
    //lendo informações das matrizes
    fscanf(arq1," %d", &lin1); //matriz 1
    fscanf(arq1," %d", &col1);
    
    fscanf(arq2," %d", &lin2);// matriz 2
    fscanf(arq2," %d", &col2);

    //leitura dos elementos da matriz 1:
    printf("Matriz 1:\n");
    for(i=0;i < lin1; i++)
    {
        for(j=0;j< col1; j++)
        {
            fscanf(arq1," %d", &matriz1[i][j]);
            printf(" %d", matriz1[i][j]); //apresenta os termos da matriz 1
        }
        printf("\n");
    }
    
    //leitura dos elementos da matriz 2:
    printf("Matriz 2:\n");
    for(i=0; i < lin2; i++)
    {
        for(j=0;j < col2; j++)
        {
            fscanf(arq2," %d", &matriz2[i][j]);
            printf("%d ", matriz2[i][j]); //apresenta os termos da matriz 2
        }
        printf("\n");
    }
    //declara o numero de linhas e colunas da matriz3 no arquuvo matriz 3 :
    fprintf(arq3,"%d", lin1);
    fprintf(arq3,"% d\n", col2);
    //calculo da matriz 3: M3 = M1*M2
    puts("Matriz 3:");
    for (i=0; i < lin1 ;i++)
    {
        for (j=0; j < col2; j++)
        {
            soma=0;
            for (k=0; k < lin2; k++)
                soma = soma + matriz1[i][k]*matriz2[k][j];
            matriz3[i][j] = soma;
            printf("%d ",matriz3[i][j]); //apresenta os termos da matriz 3
            fprintf(arq3,"%d ", matriz3[i][j]);//escreve os valores da matriz3 no arquivo
        }
        printf("\n");
        fprintf(arq3,"\n");//faz a quebra de linhas no arquivo da matriz 3
    }
    //fechamento dos arquivos
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    return (EXIT_SUCCESS);
}