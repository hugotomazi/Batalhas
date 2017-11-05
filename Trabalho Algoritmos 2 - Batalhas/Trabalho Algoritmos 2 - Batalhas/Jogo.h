#pragma once
#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include <conio.h>
#include <limits>
#include "mapa.h"
#include "Console.h"
#include "IAInimigosTabuleiro.h"
#include "botao.h"

int jogo_criaBotoesHabilidades(Botao botoes[4], Jogador jogador, int monstroJogador, Jogador inimigo, int monstroInimigo)
{
	console_exibeTelaLuta(jogador, inimigo, 0, 0);

	botoes[0].identificador = 1;
	botoes[0].selecionado = true;
	botoes[0].textoExibicao = jogador.monstros[monstroJogador].poderes[0].nomeAtaque;

	botoes[1].identificador = 2;
	botoes[1].selecionado = false;
	botoes[1].textoExibicao = jogador.monstros[monstroJogador].poderes[1].nomeAtaque;

	botoes[2].identificador = 3;
	botoes[2].selecionado = false;
	botoes[2].textoExibicao = jogador.monstros[monstroJogador].poderes[2].nomeAtaque;

	botoes[3].identificador = 4;
	botoes[3].selecionado = false;
	botoes[3].textoExibicao = jogador.monstros[monstroJogador].poderes[3].nomeAtaque;

	botao_exibirMenu(botoes, 4, "Qual ataque deseja usar?");

	int tecla = getch();
	while (tecla != 13)
	{
		tecla = getch();
		switch (tecla)
		{
		case 72:
			botao_moveMenu(botoes, 4, TECLA_CIMA);
			break;
		case 80:
			botao_moveMenu(botoes, 4, TECLA_BAIXO);
			break;
		}
		system("cls");
		console_exibeTelaLuta(jogador, inimigo, 0, 0);
		botao_exibirMenu(botoes, 4, "Qual ataque deseja usar?");
	}

	return botao_retornarSelecionado(botoes, 4);
}

void iniciaJogo(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y])
{
	bool jogando = true;
	int inimigoAtual = 1,
		quantidadeInimigosTabuleiro = QUANTIDADE_INIMIGOS,
		inimigosEmJogo[QUANTIDADE_INIMIGOS];
	Jogador jogador, inimigo1, inimigo2, inimigo3, inimigo4;
	jogadores_inicializarJogadores(jogador, inimigo1, inimigo2, inimigo3, inimigo4);

	Jogador jogadores[5] = { jogador, inimigo1, inimigo2, inimigo3, inimigo4};
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
			system("cls");
			Botao botoes[4];
			int opcao = jogo_criaBotoesHabilidades(botoes, jogadores[0], 0, jogadores[inimigoAtual], 0);

			//_sleep(1000000);
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