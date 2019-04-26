/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 8 de Junho de 2018, 11:23
 */


#include <stdio.h>
#include <stdlib.h>
#define max 100
int main(void)
{
    int a[max][max],b[max][max],c[max][max];
    int i,j,k;
    int soma;
    int m,n,p;

//leitura das dimenssões    
    printf("Digite o numero de linha da matriz A: ");
    scanf(" %d", &m);
    printf("Digite o numero de colunas da matriz A e linhas da matriz B: ");
    scanf(" %d", &n);
    printf("Digite o numero de colunas da matriz B: ");
    scanf(" %d", &p);
 
//leitura dos valores para matriz A
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("A[%d,%d]:",i+1,j+1);
            scanf(" %d", &a[i][j]);
        }
    }
//Leitura dos valores para matriz B
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            printf("B[%d,%d]:",i+1,j+1);
            scanf(" %d", &b[i][j]);
        }
    }
//calculo dos valores para matriz C=A*B
    for(i = 0;i < m;i++)
    {
        for(j = 0;j < p;j++)
        {
            soma=0;
            for(k = 0;k < n;k++)
                soma = soma + a[i][k] * b[k][j];
            c[i][j] = soma;
        }
    }
    for(i = 0;i < m;i++)
        for(j=0;j<p;j++)
            printf("C[%d,%d]:%d\n",i+1, j+1, c[i][j]);
    return 0;
}
    

