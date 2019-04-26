/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 7 de Junho de 2018, 14:45
 */

#include <stdio.h>
#include <stdlib.h>
#define max 100
/*
 Faça um programa que, tendo lido um vetor de 100 inteiros quaisquer, coloque em um outro vetor
 somente os valores positivos
 */
int main(void)
{
    int inteiros[max],i,positivos[max],k=0,j;
    for(i=0;i<max;i++)
    {
        scanf(" %d", &inteiros[i]);
    }
    for(i=0;i<max;i++)
    {
        if(inteiros[i] > 0)
        {
            positivos[k]=inteiros[i];
            k++;
        }
    }
    for(j=0;j<k;j++)
    {
        printf(" %d", positivos[j]);
    }
    return (EXIT_SUCCESS);
}

