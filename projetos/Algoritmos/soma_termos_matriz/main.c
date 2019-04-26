/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 8 de Junho de 2018, 11:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(void) 
{
    int matriz[4][5];
    int i,j,somatotal = 0,somalinha;
    //preencher a matriz
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("M[%d,%d]: ",i+1,j+1);
            scanf(" %d", &matriz[i][j]);
        }
    }
    //soma linha e total
    for(i=0;i<4;i++)
    {
        somalinha=0;
        for(j=0;j<5;j++)
            somalinha=somalinha + matriz[i][j];
        printf("A soma da linha %d é %d\n", i+1, somalinha);
        somatotal= somatotal + somalinha;
    }
    printf("A soma total foi de %d", somatotal);
}

