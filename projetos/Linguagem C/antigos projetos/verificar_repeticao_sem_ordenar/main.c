/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 12 de Junho de 2018, 15:05
 */

#include <stdio.h>
#include <stdlib.h>
#define max 20
/*
 * 
 */
int main(void)
{
    int inteiros[max],repetidos[max/5], testados[max];
    int i=0,j=0,k=0,aux=0, contador,l=0;   
    char receptor[max];
    
    FILE *valor;
    valor=fopen("valores.txt","r"); //recebe o arquivo no codigo atribuindo ao ponteiro
    if(!valor) printf("Erro na leitura do arquivo");
    else
    {
        for (i=0;fscanf(valor,"%s\n", receptor)!=EOF;i++) inteiros[i]=atoi(receptor);
         puts("Vetor com repetições");
        for(i=0;i<max;i++)
             printf("%d\n", inteiros[i]);     
             puts("mensagem");
    for(i=0;i<max/5;i++)
        printf("%d", repetidos[i]);
    }

    return 0;
}

