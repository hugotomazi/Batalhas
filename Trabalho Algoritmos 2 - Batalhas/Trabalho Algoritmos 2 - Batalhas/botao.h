#pragma once
#ifndef BOTAO_H
#define BOTAO_H
#include <iostream>
#include <string>
using namespace std;

#define TECLA_CIMA 1
#define TECLA_BAIXO 2

struct Botao {
	int identificador;
	string textoExibicao;
	bool selecionado;
};

string preencheEspacoVazio(int tamanho)
{
	string texto = "";
	for (int i = 0; i < tamanho; ++i)
	{
		texto += " ";
	}
	return texto;
}



int botao_retornarSelecionado(Botao botoes[], int quantidadeBotoes)
{
	for (int i = 0; i < quantidadeBotoes; ++i)
	{
		if (botoes[i].selecionado)
		{
			return i;
		}
	}
}

void botao_exibirBotao(Botao botao)
{
	int tamanhoEspacoVazio = 31 - botao.textoExibicao.length();
	if (botao.selecionado)
	{

		cout << (char)201;
		for (int i = 0; i < 31; i++)
		{
			cout << (char)205;
		}
		cout << (char)187 << endl;

		cout << (char)186 << botao.textoExibicao;
		if (tamanhoEspacoVazio > 0)
		{
			cout << preencheEspacoVazio(tamanhoEspacoVazio) << (char)186 << endl;
		}

		cout << (char)200;
		for (int i = 0; i < 31; i++)
		{
			cout << (char)205;
		}
		cout << (char)188 << endl;
		
	}
	else {

		cout << (char)218;
		for (int i = 0; i < 31; i++)
		{
			cout << (char)196;
		}
		cout << (char)191 << endl;

		cout << (char)179 << botao.textoExibicao;

		if (tamanhoEspacoVazio > 0)
		{
			cout << preencheEspacoVazio(tamanhoEspacoVazio) << (char)179 << endl;
		}

		cout << (char)192;
		for (int i = 0; i < 31; i++)
		{
			cout << (char)196;
		}
		cout << (char)217 << endl;

	}
}

void botao_moveMenu(Botao botoes[], int quantidadeBotoes, int moverPara)
{
	int selecionado = botao_retornarSelecionado(botoes, quantidadeBotoes);
	switch (moverPara)
	{
	case TECLA_BAIXO: 
		if (selecionado != quantidadeBotoes - 1)
		{
			botoes[selecionado].selecionado = false;
			botoes[selecionado + 1].selecionado = true;
		}
		break;
	case TECLA_CIMA:
		if (selecionado != 0)
		{
			botoes[selecionado].selecionado = false;
			botoes[selecionado - 1].selecionado = true;
		}
	default:
		break;
	}
}

void botao_exibirMenu(Botao botoes[], int quantidadeBotoes, string textoExibicao)
{
	/*for (int i = 0; i < quantidadeBotoes; i++)
	{
		botoes[i].selecionado = false;
	}
	botoes[botaoInicializado].selecionado = true;*/

	int tamanhoEspacoVazio = 93 - textoExibicao.length();

	cout << (char)218;
	for (int i = 0; i < 93; i++)
	{
		cout << (char)196;
	}
	cout << (char)191 << endl;
	cout << (char)179 << textoExibicao << preencheEspacoVazio(tamanhoEspacoVazio) << (char)179 << endl;
	cout << (char)192;
	for (int i = 0; i < 93; i++)
	{	
		cout << (char)196;
	}
	cout << (char)217 << endl;

	for (int i = 0; i < quantidadeBotoes; i++)
	{
		botao_exibirBotao(botoes[i]);
		cout << endl;
	}
}

#endif