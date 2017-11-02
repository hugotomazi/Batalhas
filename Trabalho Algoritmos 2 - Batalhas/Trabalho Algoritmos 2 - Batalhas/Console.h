#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include "mapa.h"
//#include <Windows.h>
//#include "conio.h"

using namespace std;

string console_ajustarLinha()
{
	return "\t\t\t\t\t\t\t";
}

void console_exibeTabuleiro(Mapa mapa[TAMANHO_MAPA_X][TAMANHO_MAPA_Y], int identificadorInimigo)
{
	system("cls");
	system("Color 1C");
	cout << "+--------------------------------------------------------------------------------------------+" << endl;
	cout << "|Jogando Atualmente: Inimigo " << identificadorInimigo << "\t|\tQuantidade de Monstros: 0" << "\tInimigos Restantes: " << mapa_quantidadeInimigosAtivos(mapa) << "|" << endl;
	cout << "+--------------------------------------------------------------------------------------------+" << endl << endl;
	mapa_exibirMapa(mapa);
	cout << endl;
	
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