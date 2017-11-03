// Trabalho Algoritmos 2 - Batalhas.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "mapa.h"
#include "auxiliar.h"
#include "IAInimigosTabuleiro.h"
#include "Console.h"
#include "Jogo.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Mapa mapaPrincipal[TAMANHO_MAPA_X][TAMANHO_MAPA_Y];
	int posJogadorAtualX = -1,
		posJogadorAtualY = -1;
	mapa_preparaInicioJogo(mapaPrincipal, posJogadorAtualX, posJogadorAtualY);
	console_exibeTabuleiro(mapaPrincipal, 1);
	_sleep(1000);
	iniciaJogo(mapaPrincipal);

	//system("cls");
	//mapa_exibirMapa(mapaPrincipal);
	//cout << endl << convertePosicao(2, 0, TAMANHO_MAPA_X) << endl;
    return 0;
}

