#pragma once
#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <limits>
#include "mapa.h"
#include "Console.h"
#include "IAInimigosTabuleiro.h"

void iniciaJogo(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	bool jogando = true;
	int inimigoAtual = 1,
		quantidadeInimigosTabuleiro = QUANTIDADE_INIMIGOS,
		inimigosEmJogo[QUANTIDADE_INIMIGOS];

	for (int i = 0; i < QUANTIDADE_INIMIGOS; i++)
	{
		inimigosEmJogo[i] = i + 1;
	}

	while (jogando)
	{
		int posInimigo = mapa_procuraInimigo(mapa, inimigoAtual),
			posInimigoX = -1,
			posInimigoY = -1;
		converteIJ(posInimigo, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, posInimigoX, posInimigoY);

		if (procuraJogador(mapa, mapa[posInimigoX][posInimigoY]))
		{
			console_iniciaBatalha(mapa, inimigoAtual);
			//inimigosEmJogo[inimigoAtual - 1] = INT_MAX;
			inimigosEmJogo[0] = INT_MAX;
			mapa_destruirInimigo(mapa[posInimigoX][posInimigoY]);
			quantidadeInimigosTabuleiro--;
			if (quantidadeInimigosTabuleiro == 0)
			{
				jogando = false;
			}
		}
		else {
			//movimentaInimigoAleatoriamente(mapa, mapa[posInimigoX][posInimigoY]);
			movimentaInimigoRecursivamente(mapa, mapa[posInimigoX][posInimigoY]);
		}

		console_exibeTabuleiro(mapa, inimigoAtual);
		inimigoAtual = proximoAJogar(inimigosEmJogo, inimigoAtual);
		
		_sleep(1000);
	}
}
#endif