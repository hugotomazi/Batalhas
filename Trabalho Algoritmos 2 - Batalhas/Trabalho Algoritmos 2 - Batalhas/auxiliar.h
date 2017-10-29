#pragma once
#ifndef AUXILIAL_H
#define AUXILIAR_H


#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include "mapa.h"
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

int convertePosicao(int i, int j, int tamanhoLinha)
{
	return (i*tamanhoLinha) + j;
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
#endif