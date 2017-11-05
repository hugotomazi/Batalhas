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

bool procuraJogador(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa celulaInimigo)
{
	int x = -1,
		y = -1;
	converteIJ(celulaInimigo.posicaoCelula, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, x, y);

	if (x != (TAMANHO_MAPA_X - 1) && (mapa[x + 1][y].ocupadorPosicao == 1))
	{
		return true;
	}
	else if (y != (TAMANHO_MAPA_Y - 1) && mapa[x][y + 1].ocupadorPosicao == 1)
	{
		return true;
	}
	else if ((x != 0) && (mapa[x - 1][y].ocupadorPosicao == 1))
	{
		return true;
	}
	else if ((y != 0) && (mapa[x][y - 1].ocupadorPosicao == 1))
	{
		return true;
	}

	return false;
}

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
			y = -1,
			condicaoAleatoria = numeroAleatorio(1, 4);
		bool checador = true;
		converteIJ(celulaInimigo.posicaoCelula, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, x, y);
		while (checador)
		{
			if (x != (TAMANHO_MAPA_X - 1) && (mapa[x + 1][y].ocupadorPosicao == 0) && condicaoAleatoria == 1)
			{
				mapa[x + 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x + 1][y].ocupadorPosicao = 2;

				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
				checador = false;
			}
			else if (y != (TAMANHO_MAPA_Y - 1) && mapa[x][y + 1].ocupadorPosicao == 0 && condicaoAleatoria == 2)
			{
				mapa[x][y + 1].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x][y + 1].ocupadorPosicao = 2;

				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
				checador = false;
			}
			else if ((x != 0) && (mapa[x - 1][y].ocupadorPosicao == 0) && condicaoAleatoria == 3)
			{
				mapa[x - 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x - 1][y].ocupadorPosicao = 2;

				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
				checador = false;
			}
			else if ((y != 0) && (mapa[x][y - 1].ocupadorPosicao == 0) && condicaoAleatoria == 4)
			{
				mapa[x][y - 1].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x][y - 1].ocupadorPosicao = 2;

				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
				checador = false;
			}
			condicaoAleatoria = numeroAleatorio(1, 4);
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

int proximoAJogar(int jogadoresAtivos[QUANTIDADE_INIMIGOS], int jogadorAtual)
{
	int contador = 0;
	for (int i = 0; i < QUANTIDADE_INIMIGOS; i++)
	{
		if (jogadoresAtivos[i] == INT_MAX)
		{
			contador++;
		}
	}
	if (contador == QUANTIDADE_INIMIGOS) return -1;
	int valorGuardado = -1;
	while (jogadoresAtivos[0] == INT_MAX || valorGuardado == -1)
	{
		for (int i = 0; i < QUANTIDADE_INIMIGOS; i++)
		{
			if (i == 0)
			{
				valorGuardado = jogadoresAtivos[0];
			}
			else {
				int temp = jogadoresAtivos[i - 1];
				jogadoresAtivos[i - 1] = jogadoresAtivos[i];

			}
		}
		jogadoresAtivos[QUANTIDADE_INIMIGOS - 1] = valorGuardado;
	}
	return jogadoresAtivos[0];
}

bool movimentaInimigoRecursivamente(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], Mapa celulaInimigo, int profundidade=0)
{
	int x = -1,
		y = -1;
	converteIJ(celulaInimigo.posicaoCelula, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, x, y);
	
	int prof = profundidade + 1;
	/*if (((x != 0) && (mapa[x - 1][y].ocupadorPosicao == 1)) || ((x != TAMANHO_MAPA_X) && (mapa[x+1][y].ocupadorPosicao == 1) || ()))
	{
		return true
	}*/
	if (mapa[x][y].ocupadorPosicao == 1)
	{
		return true;
	}
	else {
		if ((x != 0) && ((mapa[x - 1][y].ocupadorPosicaoTemporario != celulaInimigo.identificadorInimigo*10) && (mapa[x - 1][y].ocupadorPosicao != 2)))
		{
			mapa[x - 1][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
			movimentaInimigoRecursivamente(mapa, mapa[x-1][y], prof);
			mapa[x - 1][y].ocupadorPosicaoTemporario = -1;
			if (prof == 1)
			{
				mapa[x - 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x - 1][y].ocupadorPosicao = 2;
				mapa[x - 1][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
			}
			//mapa[x - 1][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
		}
		else if((x != TAMANHO_MAPA_X-1) && ((mapa[x + 1][y].ocupadorPosicaoTemporario != celulaInimigo.identificadorInimigo * 10) && (mapa[x + 1][y].ocupadorPosicao != 2))) {
			mapa[x + 1][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
			movimentaInimigoRecursivamente(mapa, mapa[x+1][y], prof);
			mapa[x + 1][y].ocupadorPosicaoTemporario = -1;
			if (prof == 1)
			{
				mapa[x + 1][y].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x + 1][y].ocupadorPosicao = 2;
				mapa[x + 1][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
			}
			//mapa[x + 1][y].ocupadorPosicaoTemporario = -1;
			
		}
		else if ((y != 0) && ((mapa[x][y - 1].ocupadorPosicaoTemporario != celulaInimigo.identificadorInimigo * 10) && (mapa[x][y - 1].ocupadorPosicao != 2))) {
			mapa[x][y - 1].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
			movimentaInimigoRecursivamente(mapa, mapa[x][y-1], prof);
			mapa[x][y - 1].ocupadorPosicaoTemporario = -1;
			if (prof == 1)
			{
				mapa[x][y-1].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x][y-1].ocupadorPosicao = 2;
				mapa[x][y - 1].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
			}
			//mapa[x][y - 1].ocupadorPosicaoTemporario = -1;
			
		}
		else if ((y != TAMANHO_MAPA_X-1) && ((mapa[x][y + 1].ocupadorPosicaoTemporario != celulaInimigo.identificadorInimigo * 10) && (mapa[x][y + 1].ocupadorPosicao != 2))) {
			mapa[x][y + 1].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
			movimentaInimigoRecursivamente(mapa, mapa[x][y+1], prof);
			mapa[x][y + 1].ocupadorPosicaoTemporario = -1;
			if (prof == 1)
			{
				mapa[x][y+1].identificadorInimigo = celulaInimigo.identificadorInimigo;
				mapa[x][y+1].ocupadorPosicao = 2;
				mapa[x][y + 1].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
				celulaInimigo.identificadorInimigo = -1;
				celulaInimigo.ocupadorPosicao = 0;
			}
			
			//mapa[x][y].ocupadorPosicaoTemporario = celulaInimigo.identificadorInimigo * 10;
		}

		if (prof == 1)
		{
			mapa[x][y].identificadorInimigo = -1;
			mapa[x][y].ocupadorPosicao = 0;
		}

	}
}

#endif