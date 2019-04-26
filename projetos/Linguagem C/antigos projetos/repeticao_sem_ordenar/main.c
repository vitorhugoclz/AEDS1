/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 12 de Junho de 2018, 15:11
 */



#include <stdio.h>
#include <stdlib.h>
#define max 20
#define TRUE 1
#define FALSE 0
FILE *arq1;
FILE *arq2;
int main(void)
{
    int inteiros[max], vetor5mais[max/5], visitados[max];
    int i, j, tam, tam5mais;
    int tamvisitados, qtde, achei;
    //abre o arquivo onde se concontram os valores.
    arq1 = fopen("valores.txt", "r");
    arq2 = fopen("repetidos", "w");
    //leitura dos valores no arquivo, passando para o vetor inteiros.
    puts("Termos inteiros: \n");
    for(i=0; i < max; i++)
    {
        fscanf(arq1, "%d", &inteiros[i]);
        printf("%d ", inteiros[i]);
    }
    
    //encontrar os elementos que ocerrem 5 vezes ou mais
    tam5mais = 0;
    tamvisitados = 0;
    for (i = 0; i < max; i++)
    {
        achei = FALSE;
        qtde = 1;
        for (j = 0; j < tam5mais; j++) //percorre o "vetor5mais" para ve se o numero ja apareceu
            if (inteiros[i] == vetor5mais[j])
            {
                achei = TRUE;
                break;
            }
        
        if (achei == FALSE)
            for (j = 0; j < tamvisitados; j++) //percorre visitados para ver se o numero ja foi visto
                if (inteiros[i] == visitados[j])
                {
                    achei = TRUE;
                    break;
                }
        
        if (achei == FALSE)
        {
            qtde = 1;
            for (j = i+1; j < max; j++) //percorre o "inteiros" apartir de i + 1 procurando iguais
                if (inteiros[i] == inteiros[j])
                    qtde++;
        }
        
        if (qtde >= 5) //se o numero na posição 1 apareceu mais de 5 vezes
        {
            vetor5mais[tam5mais] = inteiros[i];
            tam5mais++;
        }
        else //se o numero nao repetiu mais de 5 vezes 
        {
            visitados[tamvisitados] = inteiros[i];
            tamvisitados++;
        }
    }
    
    
    //passando informações tamanho do vetor "vetor5mais" para o arquivo "repetidos"
    fprintf(arq2, "%d \n", tam5mais);
    
    //escrevendo os valores do vetor  "vetor5mais" par ao arquivo "repetidos"
    puts("\nValores repetidos: \n");
    for (i=0; i < tam5mais; i++)
    {
        fprintf(arq2, "%d ", vetor5mais[i]);
        printf("%d ", vetor5mais[i]);
    }
    //fechamento dos arquivos e ponteiros.
    fclose(arq1);
    fclose(arq2);
    puts("\nOS arquivos foram fechados com sucesso.");
    return 0;
}
   

