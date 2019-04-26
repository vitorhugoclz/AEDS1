/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vitor
 *
 * Created on 3 de Julho de 2018, 14:10
 */

/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define max 10
FILE *arq;
typedef struct registro{
    int codigo;
    int quantidade;
    char descricao[30];
    char data[10];
    float custo;
} tproduto;
void inserir_produto(tproduto prod[max], int qtde)
{
    
}
void excluir_produto()
{
    
}
void busca_produto()
{
    
}
void printar_produtos(tproduto prod[max], int qtde)
{
    int i;
    for(i = 0; i < qtde; i++)
    {
        printf("\nIdentificação: %d\n",prod[i].codigo);
        printf("Quantidade de produtos: %d\n", prod[i].quantidade);
        printf("Descrição: %s\n", prod[i].descricao);
        printf("Data da compra: %s\n", prod[i].data);
        printf("Custo: %.2f\n", prod[i].custo);
    }  
}
int main(int argc, char** argv) {
    tproduto prod[max];
    int qtde=0, opcao;
    // abarindo arquivo para leitura
    arq = fopen("estoque.txt","r");
    printf("\nArquivo aberto\n");
    
    while (!feof(arq))
    {
        //lendo informações do arquivo
        fscanf(arq," %d", &prod[qtde].codigo);
        fscanf(arq," %d", &prod[qtde].quantidade);
        fscanf(arq," %s", prod[qtde].descricao);
        fscanf(arq," %s", prod[qtde].data);
        fscanf(arq," %f", &prod[qtde].custo);
        qtde++;
    }
    fclose(arq);
            
    do
    {
        puts("-----------------------------");
        puts("| Menu principal            |");
        puts("| [1] printar produtos      |");
        puts("| [2] Excluir um produto    |");
        puts("| [3] Buscar um produto     |");
        puts("| [4] Printar Produtos      |");
        puts("| [5] Sair                  |");
        puts("-----------------------------");
        scanf(" %d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("Digite a identificação do novo produto: ");
                scanf(" %d", &prod[qtde].codigo);
                inserir_produto(prod, qtde);
                break;
            case 2:
                printf("Digite o produto que deseja excluir");
                excluir_produto();
                break;
            case 3:
                printf("Digite o produto que deseja buscar");
                busca_produto();
                break;
            case 4: printar_produtos(prod, qtde);
                break;
            case 5: printf("Fim\n");
                break;
            default: printf("Opção inválida");
        }
        
    }while (opcao != 5);
    return 0;
}

