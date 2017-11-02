#pragma once
#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "mapa.h"
#include "Console.h"
#include "IAInimigosTabuleiro.h"

void iniciaJogo(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	bool jogando = true;
	int inimigoAtual = 1;

	while (jogando)
	{
		int posInimigo = mapa_procuraInimigo(mapa, inimigoAtual),
			posInimigoX = -1,
			posInimigoY = -1;
		converteIJ(posInimigo, TAMANHO_MAPA_X, TAMANHO_MAPA_Y, posInimigoX, posInimigoY);

		movimentaInimigoAleatoriamente(mapa, mapa[posInimigoX][posInimigoY]);

		console_exibeTabuleiro(mapa, inimigoAtual);

		if (inimigoAtual == QUANTIDADE_INIMIGOS)
		{
			inimigoAtual = 1;
		}
		else {
			inimigoAtual++;
		}
		_sleep(3000);
	}
}
#endif