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

void jogo_inimigoAtaca(monstro &jogador, monstro &inimigo, bool &venceuBatalha, int turnoAtual)
{
	int ataque = numeroAleatorio(0, 3);
	while (!monstros_recebeAtaque(jogador, inimigo, inimigo.poderes[ataque], venceuBatalha, turnoAtual))
	{
		ataque = numeroAleatorio(0, 3);
	}
}

int jogo_criaBotoesHabilidades(Botao botoes[4], Jogador jogador, int monstroJogador, Jogador inimigo, int monstroInimigo)
{
	console_exibeTelaLuta(jogador, inimigo, monstroJogador, monstroInimigo);

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
		logbatalhas_lerLogs();
		console_exibeTelaLuta(jogador, inimigo, monstroJogador, monstroInimigo);
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

		bool exibirTabuleiro = true;

		if (procuraJogador(mapa, mapa[posInimigoX][posInimigoY]))
		{
			console_iniciaBatalha(mapa, inimigoAtual);
			system("cls");
			logbatalhas_limparLog();
			Botao botoes[4];
			jogador_resetaMonstros(jogadores[0]);
			bool emBatalha = true;
			int turnoAtual = 0, monstroInimigo = 0, monstroJogador = jogador_atribuiMonstroInicial(jogadores[0]);
			
			while (emBatalha)
			{
				int poderSelecionado = jogo_criaBotoesHabilidades(botoes, jogadores[0], monstroJogador, jogadores[inimigoAtual], monstroInimigo);
				bool venceuBatalha = false;
				int vencedor = -1;
				
				if (monstros_recebeAtaque(jogadores[inimigoAtual].monstros[monstroInimigo], jogadores[0].monstros[monstroJogador], jogadores[0].monstros[monstroJogador].poderes[poderSelecionado], venceuBatalha, turnoAtual+1))
				{
					turnoAtual++;
					if (venceuBatalha)
					{	
						monstroInimigo = jogador_trocarMonstro(jogadores[inimigoAtual], monstroInimigo);
						if (monstroInimigo == -1)
						{
							mapa_destruirInimigo(mapa[posInimigoX][posInimigoY]);
							vencedor = 1;
							emBatalha = false;
						}
						
						
					}
					else {
						_sleep(2000);
						jogo_inimigoAtaca(jogadores[0].monstros[monstroJogador], jogadores[inimigoAtual].monstros[monstroInimigo], venceuBatalha, turnoAtual);
						
						if (venceuBatalha)
						{
							monstroJogador = jogador_trocarMonstro(jogadores[0], monstroJogador);
							if (monstroJogador == -1)
							{
								vencedor = 2;
								jogando = false;
								emBatalha = false;
							}
						}
					}
					
					jogador_atualizaEstatisticasTurno(jogadores[0], turnoAtual);
					jogador_atualizaEstatisticasTurno(jogadores[inimigoAtual], turnoAtual);
					//emBatalha = false;
				}
				if (venceuBatalha && vencedor == 1)
				{
					system("cls");
					cout << "Historico da batalha:" << endl << endl;
					logbatalhas_lerLogs();
					cout << endl << "Pressione qualquer tecla para continuar...";
					getch();
				}
				else if(venceuBatalha && vencedor == 2){
					system("cls");
					cout << "GAME OVER" << endl;
					exibirTabuleiro = false;
				}
				else {
					logbatalhas_lerLogs();
				}
			}
			inimigosEmJogo[0] = INT_MAX;
			
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

		if(exibirTabuleiro)
			console_exibeTabuleiro(mapa, inimigoAtual);
		
		inimigoAtual = proximoAJogar(inimigosEmJogo, inimigoAtual);
		
		_sleep(1000);
	}
}
#endif