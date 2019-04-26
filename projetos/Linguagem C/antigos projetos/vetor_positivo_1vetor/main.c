/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 7 de Junho de 2018, 15:03
 */

#include <stdio.h>
#include <stdlib.h>
#define max 10
/*
 Repita o exercico 2 sem o 2º vetor, apenas exclua os valores negativos e não deixe "burracos"
 */
int main(void)
{
    int inteiros[max],i,j=0;
    
    for(i=0;i<max;i++)
    {
        scanf(" %d", &inteiros[i]);
    }
    for(i=0;i<max;i++)
    {
        if(inteiros[i]>=0)
        {
            inteiros[j]=inteiros[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
        printf("%d ",inteiros[i]);
    return (EXIT_SUCCESS);
}

