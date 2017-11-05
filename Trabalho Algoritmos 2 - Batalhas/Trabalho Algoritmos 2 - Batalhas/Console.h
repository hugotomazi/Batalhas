#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "mapa.h"
#include "Jogadores.h"
#include "botao.h"
using namespace std;

void console_exibeTabuleiro(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int identificadorInimigo)
{
	system("cls");
	system("Color 1C");
	cout << (char)218;
	for (int i = 0; i < 92; i++)
	{
		if (i == 31)
		{
			cout << (char)194;
		}
		else {
			cout << (char)196;
		}
	}
	cout << (char)191 << endl;
	cout << (char)179 << "Jogando Atualmente: Inimigo " << identificadorInimigo << "\t" << (char)179 << "\tQuantidade de Monstros: 0" << "\tInimigos Restantes: " << mapa_quantidadeInimigosAtivos(mapa) << (char)179 << endl;
	cout << (char)192;
	for (int i = 0; i < 92; i++)
	{
		if (i == 31)
		{
			cout << (char)193;
		}
		else {
			cout << (char)196;
		}
	}
	cout << (char)217 << endl;
	mapa_exibirMapa(mapa);
	cout << endl;
	
}

void console_exibeTelaLuta(Jogador jogador, Jogador inimigo, int monstroJogador, int monstroInimigo)
{
	/*cout << (char)218;
	for (int i = 0; i < 30; ++i)
	{
		cout << (char)196;
	}
	cout << (char)191 << endl;*/
	cout << jogador.nome << "\t\t\t\t\t\t" << inimigo.nome << endl;
	cout << "Nivel: " << jogador.nivel << "\t\t\t\t\t\tNivel: " << inimigo.nivel << endl << endl;
	cout << "Monstro: " << jogador.monstros[monstroJogador].nomeMonstro << "\t\t\t\t\tMonstro: " << inimigo.monstros[monstroInimigo].nomeMonstro << endl;
	cout << "Vida: " << jogador.monstros[monstroJogador].hp << " %\t\t\t\t\t\tVida: " << inimigo.monstros[monstroInimigo].hp << " %" << endl;
	cout << "Tipo: " << jogador.monstros[monstroJogador].elemento.nome << "\t\t\t\t\t\tTipo: " << inimigo.monstros[monstroInimigo].elemento.nome << endl << endl;
}

void console_iniciaBatalha(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int identificadorInimigo)
{
	console_exibeTabuleiro(mapa, identificadorInimigo);
	system("Color CB");
	_beep(500, 230);
	system("Color 1C");
	_beep(400, 230);
	system("Color CB");
	_beep(660, 230);
	system("Color 1C");
	_sleep(800);
	//system("Color ");
}


#endif