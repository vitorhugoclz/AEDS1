/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 7 de Junho de 2018, 15:28
 */
/*
 Faça um programa que tendo lido um vetor de 100 inteiros quaisquer, coloque 
 em um segundo vetor todos os elementos que ocorrem pelo menos 5 vezes
 */
#include <stdio.h>
#include <stdlib.h>
#define max 20
void ordenador(int vet[], int n)
{
    int i, j, aux;
    for(i=0;i < n; i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(vet[j]>vet[j+1])
            {
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
            }
        }
    }
}

int main(void)
{
    int inteiros[max], repetidos[max/5],vet[max];
    int i, j=1, k=0,n;
    int verificador,contador=1;
    char receptor[max];
    FILE *valor;
    valor=fopen("valores.txt","r"); //recebe o arquivo no codigo atribuindo ao ponteiro
    if(!valor) printf("Erro na leitura do arquivo");
    else
    {
        for (i=0;fscanf(valor,"%s\n", receptor)!=EOF;i++) inteiros[i]=atoi(receptor); //entrada por ponteiro para o vetor
        ordenador(inteiros, max); //função para ordenação do vetor
        printf("Vetor Ordenado:\n");
        for(i=0;i<max;i++) //mostra o vetor ordenado
            printf("%d ", inteiros[i]);
        i=0; 
        for(j=1;j<max;j++) //faz a varedura do vetor ordenado
        {
            if(inteiros[i] == inteiros[j]) //compara igualdade dos valores das posições
                contador++;
            if(inteiros[i] != inteiros[j] && contador<5) //compara a diferença dos valores
            {                                            //e contador deve ser menor 5
                i=j;
                contador=1;
            }
            if(inteiros[i] != inteiros[j] && contador>=5)//compara a diferença dos valores
            {                                            //e contador deve ser maior que 5
                repetidos[k]=inteiros[i];
                i=j;
                k++; 
                contador=1;
            }

        }
        if(contador>=5) //condicional para verificar se na ultia contagem ouve um repetição
        {               //maior ou igual a 5
            repetidos[k]=inteiros[i];
            k++;
        }
        printf("\nValores repetidos: ");
        for(i=0;i<k;i++) //printa os valores repetidos que foram para o vetor repetidos[]
            printf("\nR[%d]:%d ",i+1,repetidos[i]);
    }
}
