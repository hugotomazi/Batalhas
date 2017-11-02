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
	/*
	0 - Vazio
	1 - Jogador
	2 - Inimigo
	*/
	int ocupadorPosicao;

	//-1 Vazio
	int identificadorInimigo;
	
	int posicaoCelula;
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
			mapa[i][j].posicaoCelula = convertePosicao(i, j, TAMANHO_MAPA_X);
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
	posicaoJogador = convertePosicao(posJogI, posJogJ, TAMANHO_MAPA_X);

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
	
	if ((posicao == (convertePosicao(posJogI, posJogJ-1, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI, posJogJ+1, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI-1, posJogJ, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI+1, posJogJ, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI-1, posJogJ-1, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI-1, posJogJ+1, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI+1, posJogJ-1, TAMANHO_MAPA_X))) || (posicao == (convertePosicao(posJogI+1, posJogJ+1, TAMANHO_MAPA_X))))
	{
		erro = "O inimigo não pode iniciar do lado do jogador.";
		return false;
	}
	//cout << endl << posicao << " " << i << " " << j << endl << posicaoJogador << " " << posJogI << " " << posJogJ << endl;
	return true;
}

void mapa_posicionarInimigos(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	string erro = "";
	//gerarNumerosAleatorios(posicaoAleatoria, QUANTIDADE_INIMIGOS, 0, TAMANHO_MAPA_X*TAMANHO_MAPA_Y);

	for (int i = 1; i <= QUANTIDADE_INIMIGOS; i++)
	{
		int x = numeroAleatoio(0, TAMANHO_MAPA_X - 1),
			y = numeroAleatoio(0, TAMANHO_MAPA_Y-1),
			posicao = convertePosicao(x, y, TAMANHO_MAPA_X);

		while (!validaPosicaoInicialInimigos(mapa, posicao, erro) || mapa[x][y].ocupadorPosicao != 0)
		{
			x = numeroAleatoio(0, TAMANHO_MAPA_X-1);
			y = numeroAleatoio(0, TAMANHO_MAPA_Y-1);
			posicao = convertePosicao(x, y, TAMANHO_MAPA_X);
			//cout << erro << endl;
		}
		//cout << endl << x << " " << y;
		mapa[x][y].ocupadorPosicao = 2;
		mapa[x][y].identificadorInimigo = i;
	}
}

int mapa_procuraInimigo(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int identificadorInimigo)
{
	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (mapa[i][j].identificadorInimigo == identificadorInimigo)
			{
				return mapa[i][j].posicaoCelula;
			}
		}
	}
	return -1;
}

int mapa_quantidadeInimigosAtivos(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	int contador = 0;
	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (mapa[i][j].ocupadorPosicao == 2)
				contador++;
		}
	}
	return contador;
}

int mapa_conf_quantidadeInimigos()
{
	return QUANTIDADE_INIMIGOS;
}

void mapa_preparaInicioJogo(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int &posX, int &posY)
{
	mapa_gerarMapa(mapa);
	mapa_posicionarInimigos(mapa);
	int posInimigo = mapa_procuraInimigo(mapa, 1);
	converteIJ(posInimigo, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, posX, posY);
}

#endif