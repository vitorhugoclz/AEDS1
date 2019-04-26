/* Numa fabrica trabalham homens e mulheres divididos em 3 classes:

	A -> os que fazem até 30 peças por mês
	B -> os que fazem de 31 a 35 peças por mês
	c -> os que fazem mais de 35 peças por mês

A classe A, recebe salário minimo.
A classe B, recebe salário mínimo mais 3% do salário mínimo por peça, acima dos 30 iniciais.
A classe C, recebe salário mínimo e mais 5% do salário minimo por peças acima das 30 iniciais.

Faça um algoritmo que:
	
	A) Leia as várias linhas contendo uma:

		-O número do empregado.
		-O número de peças fabricadas por mês
		-O sexo do empregado
	B) Calcule e escreva:
		-O salário de cada empregado
		-O total da folha mensal do pagamento
		-O número total de peças fabricadas por mês
		-A média de peças fabricadas por homens e por mulheres
		-O número de operários(a) de maior salário. */

#include <stdio.h>
#include <stdlib.h>
#define minimo 1000
#define max 4
void main()
{
	int id[max], pecas[max];
	int i,controle_10 = 0,controle_20 = 0, codigo_masculino = 0, codigo_feminino = 0,pecas_homens=0,homens = 0, media_homem;
	int controle = 0;
	char sexo[max];
	float salario[max];
	float salario_total = 0.0, pecas_total = 0.0, media_pecas, media_salario;
	float maior_masculino = 0, maior_feminino = 0;
	system("clear");	
	for(i=0;i<max;i++)
	{
		printf("Digite o ID: ");
		scanf(" %d", &id[i]);
		while(id[i]<0)				//verificação de ID somente se pode digitar ID positivo
		{
			printf("Valor de ID inválido.\nDigite um valor válido: ");
			scanf(" %d", &id[i]);
		}
		
		printf("Digite a quantidade de peças produdizadas por este funcionario: ");
		scanf(" %d", &pecas[i]);
		while(pecas[i]<0)			//verificação de peças para haver apenas valores maiores que 0
		{
			printf("Valor de peças inválido.\nDigite um valor válido: ");
			scanf(" %d", &pecas[i]);
		}
				
		printf("Digite o sexo deste funcionario (M/F): ");
		scanf(" %c", &sexo[i]);
		while(sexo[i]!='m' && sexo[i]!='M' && sexo[i]!='f' && sexo[i]!='F')
		{
			printf("Digite um valor para sexo válido.\nDigite(M/F): ");
			scanf(" %c", &sexo[i]);
		}
	}
	system("clear");
	for(i=0;i<max;i++)
	{
		if(pecas[i]<31)
			salario[i]=minimo;
		else
		{
			if(pecas[i]<36)
				salario[i] = minimo + (minimo * 0.03 * (pecas[i] - 30));
			else
				salario[i] = minimo + (minimo * 0.05 * (pecas[i] - 30));
		}
	}
	for(i=0;i<max;i++)
	{
		salario_total = salario_total + salario[i];
		pecas_total = pecas_total + pecas[i];
	}

	//bloco de calculo da media de salario e peças produzidas por todos os funcionario
	media_pecas = pecas_total/max;
	media_salario = salario_total/max;
	printf("Media de salario do total de funcionários: %.2f.\nMedia de peças produziadas por todos os funcionarios: %.2f",media_salario,media_pecas);

//bloco que calcula a produção dos funcuionarios
	printf("\nLista de funcionarios que produziram 10%% a mais que a média de funcionarios\n:");
	for(i=0;i<max;i++)
	{
		if(pecas[i] >= media_pecas*1.1)
		{
			printf("ID: %d\n",id[i]);
			controle_10 = 1;
		}		
	}
	if(controle_10 == 0)
		printf("\nNinguem produziu 10%% a mais que a média (parametros entre 10%% a 19%%");
	printf("\n\n\n");
	printf("\nLista de funcionarios que produziram 20%% a menos que a média de funcionarios\n:");
	for(i=0;i<max;i++)
	{
		if(pecas[i] <= media_pecas*1.2)
			printf("ID: %d\n",id[i]);
	}

//bloco que calcula o homem e a mulher que mais produziram
	for(i=0;i<max;i++)
	{
		if(pecas[i] > maior_masculino && (sexo[i]=='m' || sexo[i]=='M'))
		{
			maior_masculino = pecas[i];
			codigo_masculino = id[i];
		}
		if(pecas[i] > maior_feminino && ( sexo[i] == 'f' || sexo[i] == 'F'))
		{
			codigo_feminino = id[i];
			maior_feminino = pecas[i];
		}
	}
	printf("O homem que mais produziu peças tem ID: %d.\nA mulher que mais produziu peças tem ID: %d\n",codigo_masculino,codigo_feminino);

//bloco que calcula a media de peças produzidas por homens e as mulheres que produziram mais que essa media
	for(i=0;i<max;i++)
	{
		if(sexo[i]=='m' || sexo[i]=='M')
		{
			pecas_homens = pecas_homens + pecas[i];
			homens++;
		}
	}
	media_homem = pecas_homens/homens;
	printf("ID de mulheres que fabricaram mais que a média de homens: \n");
	for(i=0;i<max;i++)
	{
		if(sexo[i]=='f' || sexo[i]=='F')
		{
			if(pecas[i] > media_homem)
			{
				printf("ID: %d\n",id[i]);
				controle=1;
			}
		}

	}
	if(controle==0)
		printf("\nNão ouveram mulheres que produziram mais que a média dos homens\n\n");	
}
	
