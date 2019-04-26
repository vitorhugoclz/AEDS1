/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 12 de Junho de 2018, 17:26
 */


/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define max 20
int main(void)
{
    int inteiros[max],repetidos[max/5],testados[max];
    int i,j,k,aux;
    char receptor[max];
    
    FILE *valor;   //busca por ponteiro os valores no arquivo
    valor=fopen("valores.txt","r"); //recebe o arquivo no codigo atribuindo ao ponteiro
    if(!valor) printf("Erro de leitura do arquivo!!");
    else
    {
        for(i=0;fscanf(valor, "%s\n", receptor)!= EOF;i++)inteiros[i]=atoi(receptor);
        for(i=0;i<max;i++)
            printf("%d", inteiros[i]);
    }
    return 0;
}

