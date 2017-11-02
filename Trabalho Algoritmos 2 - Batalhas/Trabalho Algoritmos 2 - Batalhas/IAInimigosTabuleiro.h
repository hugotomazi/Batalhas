#pragma once
#ifndef IAINIMIGOSTABULEIRO_H
#define IAINIMIGOSTABULEIRO_H
#include <iostream>
#include <string>
#include <limits>
#include "mapa.h"
#include "Console.h"
#include "auxiliar.h"

using namespace std;

bool validaMovimentacaoInimigoTabuleiro(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa celulaInimigo, int posicaoMovimentacao)
{
	int posI = -1,
		posJ = -1;
	converteIJ(posicaoMovimentacao, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, posI, posJ);
	return (mapa[posI][posJ].ocupadorPosicao == 0) && (celulaInimigo.ocupadorPosicao == 2);
}

/*int movimentaInimigoTeste(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa celulaInimigo, int irPara, int posJogador, int &x, int &y, int noAtual=0)
{
	x = -1;
	y = -1;
	converteIJ(irPara, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, x, y);
	cout << x << " " << y << endl;
	if (irPara == posJogador)
	{
		return 1 - noAtual;
	}
	else if (!validaMovimentacaoInimigoTabuleiro(mapa, celulaInimigo, irPara))
	{
		return -1 - noAtual;
	}
	else {
		//int proximaPosicao = convertePosicao(x, y, TAMANHO_MAPA_X);
		int notaMovimentos[4] = { INT_MIN, INT_MIN, INT_MIN, INT_MIN };
		if (x != 0) notaMovimentos[0] = movimentaInimigoTeste(mapa, celulaInimigo, convertePosicao(x - 1, y, TAMANHO_MAPA_X), posJogador, x, y, noAtual + 1); mapa[x][y].identificadorInimigo = celulaInimigo.identificadorInimigo; mapa[x][y].ocupadorPosicao = 2;

		if (y != 0) notaMovimentos[2] = movimentaInimigoTeste(mapa, celulaInimigo, convertePosicao(x, y - 1, TAMANHO_MAPA_X), posJogador, x, y, noAtual + 1); mapa[x][y].identificadorInimigo = celulaInimigo.identificadorInimigo; mapa[x][y].ocupadorPosicao = 2;
		
		if (x != TAMANHO_MAPA_X - 1) notaMovimentos[1] = movimentaInimigoTeste(mapa, celulaInimigo, convertePosicao(x + 1, y, TAMANHO_MAPA_X), posJogador, x, y, noAtual + 1); mapa[x][y].identificadorInimigo = celulaInimigo.identificadorInimigo; mapa[x][y].ocupadorPosicao = 2;

		if (y != TAMANHO_MAPA_Y-1) notaMovimentos[3] = movimentaInimigoTeste(mapa, celulaInimigo, convertePosicao(x, y + 1, TAMANHO_MAPA_X), posJogador, x, y, noAtual + 1); mapa[x][y].identificadorInimigo = celulaInimigo.identificadorInimigo; mapa[x][y].ocupadorPosicao = 2;
		
		ordenaVetor(notaMovimentos, 4);
		cout << notaMovimentos[0] << endl;
		return notaMovimentos[0];
	}
}*/

void movimentaInimigoAleatoriamente(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa &celulaInimigo)
{
	if (celulaInimigo.ocupadorPosicao == 2)
	{
		int x = -1, 
			y = -1;
		converteIJ(celulaInimigo.posicaoCelula, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, x, y);
		if (x != (TAMANHO_MAPA_X - 1) && (mapa[x + 1][y].ocupadorPosicao == 0))
		{
			mapa[x + 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
			mapa[x + 1][y].ocupadorPosicao = 2;		

			celulaInimigo.identificadorInimigo = -1;
			celulaInimigo.ocupadorPosicao = 0;
		}
		else if (y != (TAMANHO_MAPA_Y - 1) && mapa[x][y + 1].ocupadorPosicao == 0)
		{
			mapa[x][y + 1].identificadorInimigo = celulaInimigo.identificadorInimigo;
			mapa[x][y + 1].ocupadorPosicao = 2;

			celulaInimigo.identificadorInimigo = -1;
			celulaInimigo.ocupadorPosicao = 0;
		}
		else if ((x != 0) && (mapa[x - 1][y].ocupadorPosicao == 0))
		{
			mapa[x - 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
			mapa[x - 1][y].ocupadorPosicao = 2;

			celulaInimigo.identificadorInimigo = -1;
			celulaInimigo.ocupadorPosicao = 0;
		}
		else if ((y != 0) && (mapa[x][y-1].ocupadorPosicao == 0))
		{
			mapa[x][y - 1].identificadorInimigo = celulaInimigo.identificadorInimigo;
			mapa[x][y - 1].ocupadorPosicao = 2;

			celulaInimigo.identificadorInimigo = -1;
			celulaInimigo.ocupadorPosicao = 0;
		}
	}
}

bool movimentaInimigos(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa &celulaInimigo, string &erro)
{
	if (celulaInimigo.ocupadorPosicao != 2)
	{
		erro = "A celula não é um inimigo.";
		return false;
	}
	int jogadorI = -1,
		jogadorJ = -1;
	int x, y;
	mapa_posicaoJogador(mapa, jogadorI, jogadorJ);
	int posicaoJogador = convertePosicao(jogadorI, jogadorJ, TAMANHO_MAPA_X);
	//movimentaInimigoTeste(mapa, celulaInimigo, celulaInimigo.posicaoCelula, posicaoJogador, x, y);
	movimentaInimigoAleatoriamente(mapa, celulaInimigo);
	return true;
}



#endif