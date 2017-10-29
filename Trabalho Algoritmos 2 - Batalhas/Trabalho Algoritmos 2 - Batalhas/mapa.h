#pragma once
#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <string>
#include "auxiliar.h"

#define TAMANHO_MAPA_X 5
#define TAMANHO_MAPA_Y 5
#define QUANTIDADE_INIMIGOS 4
using namespace std;

struct Mapa {
	int ocupadorPosicao;
	/*
	0 - Vazio
	1 - Jogador
	2 - Inimigo
	*/
	int identificadorInimigo;
	//-1 Vazio
};

void mapa_exibirMapa(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	for (int k = 0; k < TAMANHO_MAPA_X; k++)
	{
		if (k == 0)
		{
			cout << "+---------------+";
		}
		else {
			cout << "---------------+";
		}
		
	}
	//cout << "----------------+---------------+---------------+---------------+---------------+";
	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		cout << endl;
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (mapa[i][j].ocupadorPosicao == 0)
			{
				if (j == 0)
				{
					cout << "|\t\t|";
				}
				else {
					cout << "\t\t|";
				}
			}
			else if (mapa[i][j].ocupadorPosicao == 1)
			{
				if (j == 0)
				{
					cout << "|\tP\t|";
				}
				else {
					cout << "\tP\t|";
				}
			}
			else if (mapa[i][j].ocupadorPosicao == 2)
			{
				if (j == 0)
				{
					cout << "|\tI" << mapa[i][j].identificadorInimigo << "\t|";
				}
				else {
					cout << "\tI" << mapa[i][j].identificadorInimigo << "\t|";
				}
			}
			
		}
		cout << endl;
		for (int k = 0; k < TAMANHO_MAPA_X; k++)
		{
			if (k == 0)
			{
				cout << "+---------------+";
			}
			else {
				cout << "---------------+";
			}

		}
		//cout << endl << "----------------+---------------+---------------+---------------+---------------+";
	}
	cout << endl;
}

void mapa_gerarMapa(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	int medianaX = mediana(TAMANHO_MAPA_X), 
		medianaY = mediana(TAMANHO_MAPA_Y);

	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (i == medianaX && j == medianaY)
			{
				mapa[i][j].ocupadorPosicao = 1;
			}
			else {
				mapa[i][j].ocupadorPosicao = 0;
			}
			mapa[i][j].identificadorInimigo = -1;
		}
	}
}

void mapa_posicaoJogador(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y],int &posi, int &posj)
{
	posi = -1;
	posj = -1;
	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (mapa[i][j].ocupadorPosicao == 1)
			{
				posi = i;
				posj = j;
				i = TAMANHO_MAPA_X;
				j = TAMANHO_MAPA_Y;
			}
		}
	}
}

bool validaPosicaoInicialInimigos(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int posicao, string &erro)
{
	int posicaoJogador = -1;
	int i = -1, j = -1;
	int posJogI = -1, posJogJ = -1;
	if (posicao != 0) posicao--;

	converteIJ(posicao, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, i, j);

	mapa_posicaoJogador(mapa, posJogI, posJogJ);
	posicaoJogador = convertePosicao(posJogI, posJogJ, TAMANHO_MAPA_X-1);

	if (posJogI == -1 && posJogJ == -1)
	{
		erro = "É necessário um jogador no mapa.";
		return false;
	}

	if (posicao > 24 || posicao < 0)
	{
		erro = "Posição inválida";
		return false;
	}

	if (mapa[i][j].ocupadorPosicao != 0)
	{
		erro = "A posição já está ocupada.";
		return false;
	}
	
	if ((posicao == (posicaoJogador - 1)) || (posicao == (posicaoJogador + 1)) || (posicao == (posicaoJogador + TAMANHO_MAPA_X)) || (posicao == (posicaoJogador - TAMANHO_MAPA_X)) || (posicao == (posicaoJogador + TAMANHO_MAPA_X + 1)) || (posicao == (posicaoJogador + TAMANHO_MAPA_X - 1)) || (posicao == (posicaoJogador - TAMANHO_MAPA_X + 1)) || (posicao == (posicaoJogador - TAMANHO_MAPA_X - 1)))
	{
		erro = "O inimigo não pode iniciar do lado do jogador.";
		return false;
	}
	return true;
}

void mapa_posicionarInimigos(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	int indicadorInimigo = 0;
	string erro = "";
	//gerarNumerosAleatorios(posicaoAleatoria, QUANTIDADE_INIMIGOS, 0, TAMANHO_MAPA_X*TAMANHO_MAPA_Y);

	for (int i = 1; i <= QUANTIDADE_INIMIGOS; i++)
	{
		int x = numeroAleatoio(0, TAMANHO_MAPA_X - 1),
			y = numeroAleatoio(0, TAMANHO_MAPA_Y-1),
			posicao = convertePosicao(x, y, TAMANHO_MAPA_X-1);

		while (!validaPosicaoInicialInimigos(mapa, posicao, erro))
		{
			x = numeroAleatoio(0, TAMANHO_MAPA_X-1);
			y = numeroAleatoio(0, TAMANHO_MAPA_Y-1);
			posicao = convertePosicao(x, y, TAMANHO_MAPA_X-1);
			//cout << erro << endl;
		}
		mapa[x][y].ocupadorPosicao = 2;
		mapa[x][y].identificadorInimigo = i;
	}
}

#endif