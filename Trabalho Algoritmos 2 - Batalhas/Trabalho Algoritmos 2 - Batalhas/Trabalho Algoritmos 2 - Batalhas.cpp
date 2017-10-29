// Trabalho Algoritmos 2 - Batalhas.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "mapa.h"
#include "auxiliar.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Mapa mapaPrincipal[TAMANHO_MAPA_X][TAMANHO_MAPA_Y];
	mapa_gerarMapa(mapaPrincipal);
	mapa_posicionarInimigos(mapaPrincipal);
	
	mapa_exibirMapa(mapaPrincipal);
	//cout << endl << convertePosicao(2, 0, TAMANHO_MAPA_X) << endl;
    return 0;
}

