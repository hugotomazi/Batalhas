#pragma once
#ifndef PODERES_H
#define PODERES_H
#include <iostream>
#include <string>
using namespace std;

struct poder{
	int identificador;
	string nomeAtaque;
	int dano;
	int danoVantagem;
	int danoDesvantagem;
	int turnoAtaque;
	int quantidadeVezesUso;
};

void poder_inicializarPoder(poder &tipo1, poder &tipo2, poder &tipo3, poder &tipo4, poder &tipo5, poder &tipo6, poder &tipo7, poder &tipo8, poder &tipo9, poder &tipo10, poder &tipo11, poder &tipo12, poder &tipo13, poder &tipo14, poder &tipo15, poder &tipo16)
{

	tipo1.identificador = 1;
	tipo1.nomeAtaque = "Bola de Fogo";
	tipo1.dano = 20;
	tipo1.quantidadeVezesUso = 10;
	tipo1.danoVantagem = 10;
	tipo1.danoDesvantagem = 10;
	tipo1.turnoAtaque = 1;

	tipo2.identificador = 1;
	tipo2.nomeAtaque = "Chama Nenem";
	tipo2.dano = 20;
	tipo2.quantidadeVezesUso = 10;
	tipo2.danoVantagem = 10;
	tipo2.danoDesvantagem = 10;
	tipo2.turnoAtaque = 1;

	tipo3.identificador = 1;
	tipo3.nomeAtaque = "Mega Blaster";
	tipo3.dano = 40;
	tipo3.quantidadeVezesUso = 3;
	tipo3.danoVantagem = 10;
	tipo3.danoDesvantagem = 10;
	tipo3.turnoAtaque = 2;

	tipo4.identificador = 1;
	tipo4.nomeAtaque = "Tornado de Chamas";
	tipo4.dano = 40;
	tipo4.quantidadeVezesUso = 3;
	tipo4.danoVantagem = 10;
	tipo4.danoDesvantagem = 10;
	tipo4.turnoAtaque = 2;

	tipo5.identificador = 2;
	tipo5.nomeAtaque = "Jato de Agua";
	tipo5.dano = 20;
	tipo5.quantidadeVezesUso = 10;
	tipo5.danoVantagem = 10;
	tipo5.danoDesvantagem = 10;
	tipo2.turnoAtaque = 1;

	tipo6.identificador = 2;
	tipo6.nomeAtaque = "Bomba de Agua";
	tipo6.dano = 20;
	tipo6.quantidadeVezesUso = 10;
	tipo6.danoVantagem = 10;
	tipo6.danoDesvantagem = 10;
	tipo6.turnoAtaque = 1;

	tipo7.identificador = 2;
	tipo7.nomeAtaque = "Mega Blaster";
	tipo7.dano = 40;
	tipo7.quantidadeVezesUso = 3;
	tipo7.danoVantagem = 10;
	tipo7.danoDesvantagem = 10;
	tipo7.turnoAtaque = 2;

	tipo8.identificador = 2;
	tipo8.nomeAtaque = "Hiper Bomba Aquatica";
	tipo8.dano = 40;
	tipo8.quantidadeVezesUso = 3;
	tipo8.danoVantagem = 10;
	tipo8.danoDesvantagem = 10;
	tipo8.turnoAtaque = 2;

	tipo9.identificador = 3;
	tipo9.nomeAtaque = "Folha Navalha";
	tipo9.dano = 40;
	tipo9.quantidadeVezesUso = 3;
	tipo9.danoVantagem = 10;
	tipo9.danoDesvantagem = 10;
	tipo9.turnoAtaque = 2;

	tipo10.identificador = 3;
	tipo10.nomeAtaque = "Ataque de Espinho";
	tipo10.dano = 40;
	tipo10.quantidadeVezesUso = 3;
	tipo10.danoVantagem = 10;
	tipo10.danoDesvantagem = 10;
	tipo10.turnoAtaque = 2;

	tipo11.identificador = 3;
	tipo11.nomeAtaque = "Raio Solar";
	tipo11.dano = 40;
	tipo11.quantidadeVezesUso = 3;
	tipo11.danoVantagem = 10;
	tipo11.danoDesvantagem = 10;
	tipo11.turnoAtaque = 2;

	tipo12.identificador = 3;
	tipo12.nomeAtaque = "Semente da Insonia";
	tipo12.dano = 40;
	tipo12.quantidadeVezesUso = 3;
	tipo12.danoVantagem = 10;
	tipo12.danoDesvantagem = 10;
	tipo12.turnoAtaque = 2;

	tipo13.identificador = 4;
	tipo13.nomeAtaque = "Choque do Trovao";
	tipo13.dano = 20;
	tipo13.quantidadeVezesUso = 10;
	tipo13.danoVantagem = 10;
	tipo13.danoDesvantagem = 10;
	tipo13.turnoAtaque = 1;

	tipo14.identificador = 4;
	tipo14.nomeAtaque = "Investida Relampago";
	tipo14.dano = 20;
	tipo14.quantidadeVezesUso = 10;
	tipo14.danoVantagem = 10;
	tipo14.danoDesvantagem = 10;
	tipo14.turnoAtaque = 1;

	tipo15.identificador = 4;
	tipo15.nomeAtaque = "Wave Thunder";
	tipo15.dano = 40;
	tipo16.quantidadeVezesUso = 3;
	tipo15.danoVantagem = 10;
	tipo15.danoDesvantagem = 10;
	tipo15.turnoAtaque = 2;

	tipo16.identificador = 4;
	tipo16.nomeAtaque = "Wild Charger";
	tipo16.dano = 40;
	tipo16.quantidadeVezesUso = 3;
	tipo16.danoVantagem = 10;
	tipo16.danoDesvantagem = 10;
	tipo16.turnoAtaque = 2;
}

#endif