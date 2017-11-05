#pragma once
#ifndef TIPO_H
#define TIPO_H

#include <iostream>
#include <string>

using namespace std;

struct Tipo {
	int identificador;
	string nome;
	int identificadorVantagem;
	int identificadorDesvantagem;
};

void tipo_inicializarTipos(Tipo &tipo1, Tipo &tipo2, Tipo &tipo3, Tipo &tipo4)
{
	/*
	tipo 1 -> Fogo, terá vantagem contra vegetal e desvantegem contra aquático
	tipo 2 -> Água, terá vantagem contra fogo e desvantegem contra vegetal
	*/
	tipo1.identificador = 1;
	tipo1.nome = "Fogo";
	tipo1.identificadorDesvantagem = 2;
	tipo1.identificadorVantagem = 3;

	tipo2.identificador = 2;
	tipo2.nome = "Agua";
	tipo2.identificadorDesvantagem = 3;
	tipo2.identificadorVantagem = 1;

	tipo3.identificador = 3;
	tipo3.nome = "Vegetal";
	tipo3.identificadorDesvantagem = 1;
	tipo3.identificadorVantagem = 2;

	tipo4.identificador = 4;
	tipo4.nome = "Raio";
	tipo4.identificadorDesvantagem = 3;
	tipo4.identificadorVantagem = 2;

}

#endif // !TIPO_H
