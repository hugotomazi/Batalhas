// Trabalho Algoritmos 2 - Batalhas.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <locale>
#include <string>
#include "auxiliar.h"
#include "IAInimigosTabuleiro.h"
#include "Console.h"
#include "Jogo.h"
#include "mapa.h"
#include "botao.h"
#include "Jogadores.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, NULL);
	Mapa mapaPrincipal[TAMANHO_MAPA_X][TAMANHO_MAPA_Y];
	int posJogadorAtualX = -1,
		posJogadorAtualY = -1;
	mapa_preparaInicioJogo(mapaPrincipal, posJogadorAtualX, posJogadorAtualY);
	
	//_sleep(1000);
	
	Botao btn[2];

	btn[0].identificador = 1;
	btn[0].selecionado = true;
	btn[0].textoExibicao = "Inicializar Jogo";

	btn[1].identificador = 2;
	btn[1].selecionado = false;
	btn[1].textoExibicao = "Finalizar Jogo";
	botao_exibirMenu(btn, 2, "Bem-vindo ao Caotic! O que deseja fazer?");

	int tecla = getch();
	while (tecla != 13)
	{
		tecla = getch();
		if (tecla == 72)
		{
			botao_moveMenu(btn, 2, TECLA_CIMA);
		}
		else if (tecla == 80)
		{
			botao_moveMenu(btn, 2, TECLA_BAIXO);
		}
		system("cls");
		botao_exibirMenu(btn, 2, "Bem-vindo ao Caotic! O que deseja fazer?");
	}
	int selecao = botao_retornarSelecionado(btn, 2);
	if (selecao == 0)
	{
		system("cls");
		console_exibeTabuleiro(mapaPrincipal, 1);
		iniciaJogo(mapaPrincipal);
		//mapa_exibirMapa(mapaPrincipal);
		//cout << endl << convertePosicao(2, 0, TAMANHO_MAPA_X) << endl;
	}
	else if (selecao == 1)
	{
		system("cls");
		cout << "Até a próxima!" << endl;
	}
	//botao_exibirBotao(btnIniciar);
	//cout << endl << endl;
	//botao_exibirBotao(btnFinalizar);

	
    return 0;
}

