#pragma once
#ifndef AUXILIAL_H
#define AUXILIAR_H

#include <iostream>
#include <ctime>
#include <random>
#include <string>
using namespace std;

template <typename TipoNumero>
TipoNumero numeroAleatoio(TipoNumero minimo, TipoNumero maximo)
{
	return rand() % (maximo - minimo + 1) + minimo;
}
int mediana(int numero)
{
	return numero / 2;
}
int convertePosicao(int numi, int numj, int tamanhoLinha)
{
	//return (i*tamanhoLinha) + j;
	int posicao = 0;
	for (int i = 0; i < tamanhoLinha; i++)
	{
		for (int j = 0; j < tamanhoLinha; j++)
		{
			if (i != numi || j != numj)
			{
				posicao++;
			}
			else {
				i = tamanhoLinha;
				j = tamanhoLinha;
			}
		}
	}
	return posicao;
}
void converteIJ(int posicao, int tamanhoI, int tamanhoJ, int &varI, int &varJ)
{
	for (int i = 0; i < tamanhoI; i++)
	{
		for (int j = 0; j < tamanhoJ; j++)
		{
			if (convertePosicao(i, j, tamanhoI) == posicao)
			{
				varI = i;
				varJ = j;
				i = tamanhoI;
				j = tamanhoJ;
			}
		}
	}
}
template <typename T>
void ordenaVetor(T vetor[], int tamanhoVetor)
{
	for (int j = 0; j < tamanhoVetor; j++)
	{
		for (int i = 0; i < tamanhoVetor-1; i++)
		{
			if (vetor[i] < vetor[i + 1])
			{
				T temp = vetor[i + 1];
				vetor[i + 1] = vetor[i];
				vetor[i] = temp;
			}
		}
	}
}

#endif