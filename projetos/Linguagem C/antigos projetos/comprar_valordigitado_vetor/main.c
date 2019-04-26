/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 7 de Junho de 2018, 14:22
 */

#include <stdio.h>
#include <stdlib.h>
#define max 100
/*
 Faça um programa que leia um vetor do teclado e responda quantos valores sçao iguais a ele,
 Repita enquanto o usuário quiser 
 */
int main(void)
{
    int vetor[max],i,valor,contador=0;
    char controle='s';
    
    for(i=0;i<max;i++)
    {
        scanf(" %d", &vetor[i]);
    }
    do
    {
        contador=0;
        printf("Digite um valor para ser verificado se ouve a ocorrência do mesmo: ");
        scanf(" %d", &valor);
        for(i=0;i<max;i++)
        {
            if(vetor[i] == valor)
            {
                contador++;
            }
        }
        printf("\nForam encontrador %d valores iguais aos digitados",contador);
        printf("\nDeseja fazer outros teste(s/n): ");
        scanf(" %c", &controle);
        while (controle!='s' && controle!='S' && controle!='n' && controle!='N')
        {
            printf("Valor inválido.\nDigite um valor válido(s/n): ");
            scanf(" %c", &controle);
        }
    }while(controle=='s' || controle=='S');
}

