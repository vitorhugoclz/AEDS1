/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 28 de Junho de 2018, 14:11
 */

#include <stdio.h>
#include <stdlib.h>
#define null 0
/*
 * arquivo que trabalha vetor de caracteres
 */
int main(void)
{
    /*char c[30]="Vitor Hugo da Costa Luz";
    int i;
    /*no final da cadeia de caractere existe um " \0 ", que sinaliza o final da cadeia de string 
    printf("\n\t%s\n\n",c);
    
    for(i = 0; c[i] != 0; i++)
        printf("c[%d]: %c \n", i, c[i]); 
    Exercicio:
       1) coloque numa outra variavel de caracteres somente os caracteres maisculos
       2) coloque numa outra variavel somente o nome da pessoa
       3) coloque numa outra variavel somente o sobre nome da pessoa
       4) coloque numa outra variavel as letras maisculas
       5) coloque numa outra variavel os caracteres do nome completo sem vogais */
    
    char maisculas[30], minusculas[30], p_nome[15], sobrenome[15], caixa_alta[30];
    char sobre_invert[15];
    char nome[30]="Vitor Hugo da Costa Luz";
    char sem_vogais[30];
    char aux;
    int i, j = 0;
    //coloca apenas as letras maisculas em uma variavel.
    for (i = 0; nome[i] != null; i++)
    {
        if(nome[i] >= 65 && nome[i] <= 90)
        {
            maisculas[j] = nome[i];
            j++;
        }
    }
    printf("\nLetras maisculas digitadas no nome: %s",maisculas);
    //coloca somente o nome da pessoa
    
    for(i = 0; nome[i] != 32; i++)
        p_nome[i] = nome[i];
    printf("\nPrimeiro nome da pessoa: %s", p_nome);
    
    //somente o sobre nome da pessoa
    aux = 0;
    j = 0;
    for(i = 0; nome[i] != null; i++)
    {
        if (nome[i] == 32)
            aux = 1;
        if (aux == 1)
        {
            sobrenome[j] = nome[i + 1];
            j++;
        }
    }
    printf("\nO sobrenome da pessoa: %s", sobrenome);
    
    //colocar todas a letras do nome em maisculas
    j = 0;
    for (i = 0; nome[i] != null; i++)
    {
        if( (nome[i] >= 65 && nome[i] <= 90 ) || nome[i] == 32)
        {
            caixa_alta[j] = nome[i];
            j++;
        }
        else
        {
            caixa_alta[j] = nome[i] - 32;
            j++;
        }
    }
    printf("\nNome em caixa alta: %s", caixa_alta);
    //nome sem vogais
    j = 0;
    for (i = 0; nome[i] != null; i++)
    {
        if(nome[i] != 65 && nome[i] != 69 && nome[i] != 73 && nome[i] != 79 && nome[i] != 85
           && nome[i] != 97 && nome[i] != 101 && nome[i] != 105 && nome[i] != 111 && nome[i] != 117)
        {
            sem_vogais[j] = nome[i];
            j++;
        }
    }
    printf("\nNome sem vogais: %s", sem_vogais);
    
    return (EXIT_SUCCESS);
}

