/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 26 de Junho de 2018, 14:24
 */


/*
 * -> Encontrar os produtos mais e menos vendidos no ano.
 * -> encontre qual o melhor e o pior mes de venda
 * - > dado o vetor "porcvenda.txt" de cada produto, encontre os produtos de maior e menor lucro
 * -> dado um vetor "custo2017.txt" onde cada elemento é a média do custo do produtor no último ano
 * calcular a inflação dos produtor neste ano.
 */

#include <stdio.h>
#include <stdlib.h>
FILE *vendas;
FILE *custos;
#define mes 12
#define produtos 10

int main(void) {
    int matriz_vendas[produtos][mes], matriz_custos[10][12];
    int i, j;
    
    vendas = fopen("vendas", "r");
    custos = fopen("custos", "r");
    
    puts("Escrita dos valores de venda:\n");
    for (i = 0; i < produtos; i++)
    {
        printf("| ");
        for( j = 0; j < mes; j++)
        {
            fscanf(vendas, " %d", &matriz_vendas[i][j]);
            printf("%d ", matriz_vendas[i][j]);
        }
        printf(" | \n");
    }
    
    printf("Escrita dos valores de venda:\n");
    for (i = 0; i < produtos; i++)
    {
        for(j = 0; j < mes; i++)
        {
            fscanf(custos," %d", &matriz_custos[i][j]);
            printf("%d", matriz_custos[i][j]);
        }
        printf("\n");
    }
    fclose(vendas);
    fclose(custos);
    return (EXIT_SUCCESS);
}

