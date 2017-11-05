#pragma once
#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <string>
#include "auxiliar.h"
#include "Tipos.h"
#include "poderes.h"
#include "monstros.h"


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

	//-1 - Vazio
	int identificadorInimigo;
	
	int posicaoCelula;
	//-1 - Vazio
	int ocupadorPosicaoTemporario;
	//-1 - vazio
	int rastro;

	monstro monstros[2];
};


void mapa_destruirInimigo(Mapa &celulaInimigo)
{
	celulaInimigo.identificadorInimigo = -1;
	celulaInimigo.ocupadorPosicao = 0;
}
void mapa_exibirMapa(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	int linha = 0;
	for (int k = 0; k < TAMANHO_MAPA_X; k++)
	{
		if (k == 0)
		{
			cout << (char)218;
			for (int l = 0; l < 15; l++)
			{
				cout << (char)196;
			}
			cout << (char)194;
		}
		else {
			for (int l = 0; l < 15; l++)
			{
				cout << (char)196;
			}

			if (k == TAMANHO_MAPA_X - 1)
			{

				cout << (char)191;
			}
			else {
				if (linha == 0)
				{
					cout << (char)194;
				}
				else {
					cout << (char)197;
				}
				
			}
			
		}
		
	}
	linha++;
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
					cout << (char)179 << "\t\t" << (char)179/*(char)179*/;
				}
				else {
					
					cout << "\t\t" << (char)179;
				}
			}
			else if (mapa[i][j].ocupadorPosicao == 1)
			{
				if (j == 0)
				{
					cout << (char)179 << "\tP\t" << (char)179;
				}
				else {
					cout << "\tP\t" << (char)179;
				}
			}
			else if (mapa[i][j].ocupadorPosicao == 2)
			{
				if (j == 0)
				{
					cout << (char)179 << "\tI" << mapa[i][j].identificadorInimigo << "\t" << (char)179;
				}
				else {
					cout << "\tI" << mapa[i][j].identificadorInimigo << "\t" << (char)179;
				}
			}
			
		}
		cout << endl;
		linha++;
		for (int k = 0; k < TAMANHO_MAPA_X; k++)
		{
			if (k == 0)
			{
				if (linha == 6)
				{
					cout << (char)192;
				}
				else {
					cout << (char)195;
				}
				
				for (int l = 0; l < 15; l++)
				{
					cout << (char)196;
				}
				//cout << (char)192;
				if (linha == 6)
				{
					cout << (char)193;
				}
				else {
					cout << (char)197;
				}
				
			}
			else {
				for (int l = 0; l < 15; l++)
				{
					cout << (char)196;
				}
				if (k == TAMANHO_MAPA_X - 1)
				{
					if (linha == 6)
					{
						cout << (char)217;
					}
					else {
						cout << (char)180;
					}
				}
				else {
					if (linha == 6)
					{
						cout << (char)193;
					}
					else {
						cout << (char)197;
					}
				}	
			}
		}
		//cout << endl << "----------------+---------------+---------------+---------------+---------------+";
	}
	linha++;
	cout << endl;
}

void mapa_gerarMapa(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	int medianaX = mediana(TAMANHO_MAPA_X), 
		medianaY = mediana(TAMANHO_MAPA_Y);
	monstro
		tangath_toborn,
		maxxor,
		intress,
		rellim,
		donmar,
		intress2,
		ekuud,
		frafdo,
		bylkian,
		titanix;

	monstro_inicializarMonstro(
		tangath_toborn,
		maxxor,
		intress,
		rellim,
		donmar,
		intress2,
		ekuud,
		frafdo,
		bylkian,
		titanix);

	for (int i = 0; i < TAMANHO_MAPA_X; i++)
	{
		for (int j = 0; j < TAMANHO_MAPA_Y; j++)
		{
			if (i == medianaX && j == medianaY)
			{
				mapa[i][j].ocupadorPosicao = 1;

				mapa[i][j].monstros[0] = maxxor;
				mapa[i][j].monstros[1] = frafdo;
			}
			else {
				mapa[i][j].ocupadorPosicao = 0;
			}
			mapa[i][j].identificadorInimigo = -1;
			mapa[i][j].posicaoCelula = convertePosicao(i, j, TAMANHO_MAPA_X);
			mapa[i][j].ocupadorPosicaoTemporario = -1;
			mapa[i][j].rastro = -1;
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
		mapa[x][y].rastro = i * 10;
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