/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 26 de Junho de 2018, 15:31
 */


/*
 - encontre a quantidade de produtos vendidos em cada mês;
 - encontre a quantidade de cada produto vendido no ano;
 - encontre a quantidade total de produtos vendidos no ano;
 - encontre os produtos mais e menos vendidos no ano;
 - encontre qual o melhor e qual o pior mês de venda;
 - dado o vetor 'porcvenda.txt' de cada produto, encontre os produtos de maior e menor lucro;
 - dado um vetor 'custo2017.txt', onde cada elemento é a média do custo do produto no último ano,
calcular a inflação dos produtos neste ano.
 */
#include <stdio.h>
#include <stdlib.h>
#define linhas 10 //numero de linhas dos arquivos
#define colunas 12 //numero de colunas dos arquivos
#define TRUE 1
#define FALSE 0
FILE *arq1;
FILE *arq2;
FILE *arq3;
FILE *arq4;
//entes projeto foi feito em SO Windows 7, sendo necessario a mudança de nome de alguns arquivos
int main(void) {

    
    int custos[linhas][colunas], vendas[linhas][colunas], total_meses[colunas], produtos[linhas];
    int porcvenda[linhas], custo2017[linhas];;
    int i, j;
    int aux = 0, total_ano = 0, menos_vendido, mais_vendido = 0,n_mais,n_menos = 0;
    int melhor_mes = 0, pior_mes = 0, n_melhor, n_pior, menor_porc = 0, maior_porc = 0;
    int nporc_menor, nporc_maior;
    int flag = TRUE;
    
    float inflacao[linhas],media_custo2018[linhas]; //vetores que recebem os valores calculados
    //cada indice do vetor representa um produto em ordem
    
    //abertura dos arquivos
    arq1 = fopen("custos", "r");
    arq2 = fopen("vendas", "r");
    arq3 = fopen("porcvenda", "r");
    arq4 = fopen("custo2017", "r");
    
    //leitura dos valores do arquivo "custos"
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            fscanf(arq1, "%d", &custos[i][j]);
    
    //leitura dos valores do arquivo "vendas"
    for(i = 0; i < linhas; i++)
        for(j = 0; j < colunas; j++)
            fscanf(arq2, "%d", &vendas[i][j]);
    
    //leitura dos valores do arquivo "porcvenda"
    for(i = 0; i < linhas; i++)
        fscanf(arq3," %d", &porcvenda[i]);
    
    //leitura dos valores do arquivo "custo2017"
    for (i = 0; i < linhas; i++)
        fscanf(arq4,"%d", &custo2017[i]);
    
    //encontra a quantidade de produtos vendidos em cada mês e os coloca em um vetor
    printf("\nQuantide de produtos vendidos por mes: ");
    for(i = 0; i < colunas; i++)
    {
        aux = 0;
        for(j = 0; j < linhas; j++)
            aux = aux + vendas[j][i];
        total_meses[i] = aux; //guarda em vetor a venda dos meses
        printf("\nMes[%d]:%d",i+1,total_meses[i]);
    }
    
    //encontra a quantidade de cada produto vendido no ano
    printf("\nQuantidade de produtos vendidos no ano: ");
    for(i = 0;i < linhas; i++)
    {
        aux = 0;
        for(j = 0; j < colunas; j++)
            aux = aux + vendas[i][j];
        produtos[i] = aux;
        total_ano = total_ano + aux;
        printf("\nProduto[%d]: %d",i+1,produtos[i]);
    }
    printf("\nVendas totais no ano: %d",total_ano);
    
    for (i = 0; i < linhas; i++)
    {
        if (flag == TRUE) //condção para garantir um passagem 
        {                 //de pelo menos um produto como menos venda
            menos_vendido = produtos[i];
            flag = FALSE;
        }
        if (produtos[i] < menos_vendido && flag == FALSE) //verifica outras ocorrencias
        {
            menos_vendido = produtos[i];
            n_menos = i;
        }
        if (produtos[i] > mais_vendido) //verifica o produto mais vendido
        {
            mais_vendido = produtos[i];
            n_mais = i;
        }
    }
    printf("\nProduto menos vendido: Produto[%d]: %d",n_menos + 1,menos_vendido);
    printf("\nProduto mais vendido: Produto[%d]: %d",n_mais + 1,mais_vendido);

    //encontra qual o melhor de pior mes de venda
    flag = TRUE;
    for(i = 0; i < colunas; i++)
    {
        if (flag == TRUE)
        {
            pior_mes = total_meses[i];
            flag = FALSE;
        }
        if (total_meses[i] < pior_mes)
        {
            pior_mes = total_meses[i];
            n_pior = i;
        }
        if (total_meses[i] > melhor_mes)
        {
            melhor_mes = total_meses[i];
            n_melhor = i;
        }
    }
    printf("\nMelhor mês de venda, mês[%d]: %d",n_melhor + 1,melhor_mes);
    printf("\nPior mês de venda, mês[%d]: %d",n_pior + 1, pior_mes);
    flag = TRUE;
    for(i = 0; i < linhas; i++)
    {
        if (flag == TRUE)
        {
            menor_porc = porcvenda[i];
            flag = FALSE;
        }
        if (porcvenda[i] < menor_porc)
        {
            menor_porc = porcvenda[i];
            nporc_menor = i;
        }
        if (porcvenda[i] > maior_porc)
        {
            maior_porc = porcvenda[i];
            nporc_maior = i;
        }
        
    }
    printf("\nMaior porcentagem de lucro, Produto[%d]: %d",nporc_maior + 1, maior_porc);
    printf("\nMenor porcentagem de lucro, Produto[%d]: %d",nporc_menor + 1, menor_porc);
    
    //calculando a media de custo em 2018
    for(i = 0; i < linhas; i++)
    {
        aux = 0;
        for(j = 0; j < colunas; j++)
            aux = aux + custos[i][j];
        media_custo2018[i] = aux / 12.0;
    }
    //calculo da inflação
    printf("\nValores de inflação para cada produto: ");
    for(i = 0; i < linhas; i++)
    {
        inflacao[i] = ( media_custo2018[i] - custo2017[i] ) / media_custo2018[i] * 100;
        if (inflacao[i] > 0)
           printf("\nProduto[%d] aumento o preço de um ano para o outro em: %.2f", i + 1, inflacao[i]); 
        else
        {
            if(inflacao[i] == 0)
                printf("\nProduto[%d] manteve o preço;", i + 1);
            else
                printf("\nProduto[%d] reduziu o preço de um ano para outro em: %.2f", i + 1, inflacao [i]);
        }
    }
    //fechamento dos arquivos
    fclose(arq1); fclose(arq2);
    fclose(arq3); fclose(arq4);
}

