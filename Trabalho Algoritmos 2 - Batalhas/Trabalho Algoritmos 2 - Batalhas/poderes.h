#pragma once
#ifndef PODERES_H
#define PODERES_H
#include <iostream>
#include <string>
#include "Tipos.h"
using namespace std;

struct poder{
	int identificador;
	string nomeAtaque;
	int dano;
	int danoVantagem;
	int danoDesvantagem;
	int turnoAtaque;
};

void poder_inicializarPoder(poder &tipo1, poder &tipo2, poder &tipo3, poder &tipo4, poder &tipo5, poder &tipo6, poder &tipo7, poder &tipo8, poder &tipo9, poder &tipo10, poder &tipo11, poder &tipo12, poder &tipo13, poder &tipo14, poder &tipo15, poder &tipo16)
{

	tipo1.identificador = 1;
	tipo1.nomeAtaque = "bola de fogo";
	tipo1.dano = 20;
	tipo1.danoVantagem = 10;
	tipo1.danoDesvantagem = 10;
	tipo1.turnoAtaque = 1;

	tipo2.identificador = 1;
	tipo2.nomeAtaque = "chama neném";
	tipo2.dano = 20;
	tipo2.danoVantagem = 10;
	tipo2.danoDesvantagem = 10;
	tipo2.turnoAtaque = 1;

	tipo3.identificador = 1;
	tipo3.nomeAtaque = "mega blaster";
	tipo3.dano = 40;
	tipo3.danoVantagem = 10;
	tipo3.danoDesvantagem = 10;
	tipo3.turnoAtaque = 2;

	tipo4.identificador = 1;
	tipo4.nomeAtaque = "tornado de chamas";
	tipo4.dano = 40;
	tipo4.danoVantagem = 10;
	tipo4.danoDesvantagem = 10;
	tipo4.turnoAtaque = 2;

	tipo5.identificador = 2;
	tipo5.nomeAtaque = "jato de agua";
	tipo5.dano = 20;
	tipo5.danoVantagem = 10;
	tipo5.danoDesvantagem = 10;
	tipo2.turnoAtaque = 1;

	tipo6.identificador = 2;
	tipo6.nomeAtaque = "bomba de agua";
	tipo6.dano = 20;
	tipo6.danoVantagem = 10;
	tipo6.danoDesvantagem = 10;
	tipo6.turnoAtaque = 1;

	tipo7.identificador = 2;
	tipo7.nomeAtaque = "mega blaster";
	tipo7.dano = 40;
	tipo7.danoVantagem = 10;
	tipo7.danoDesvantagem = 10;
	tipo7.turnoAtaque = 2;

	tipo8.identificador = 2;
	tipo8.nomeAtaque = "hiper bomba aquatica";
	tipo8.dano = 40;
	tipo8.danoVantagem = 10;
	tipo8.danoDesvantagem = 10;
	tipo8.turnoAtaque = 2;

	tipo9.identificador = 3;
	tipo9.nomeAtaque = "folha navalha";
	tipo9.dano = 40;
	tipo9.danoVantagem = 10;
	tipo9.danoDesvantagem = 10;
	tipo9.turnoAtaque = 2;

	tipo10.identificador = 3;
	tipo10.nomeAtaque = "ataque de espinho";
	tipo10.dano = 40;
	tipo10.danoVantagem = 10;
	tipo10.danoDesvantagem = 10;
	tipo10.turnoAtaque = 2;

	tipo11.identificador = 3;
	tipo11.nomeAtaque = "raio solar";
	tipo11.dano = 40;
	tipo11.danoVantagem = 10;
	tipo11.danoDesvantagem = 10;
	tipo11.turnoAtaque = 2;

	tipo12.identificador = 3;
	tipo12.nomeAtaque = "semente da insonia";
	tipo12.dano = 40;
	tipo12.danoVantagem = 10;
	tipo12.danoDesvantagem = 10;
	tipo12.turnoAtaque = 2;

	tipo13.identificador = 4;
	tipo13.nomeAtaque = "choque do trovao";
	tipo13.dano = 20;
	tipo13.danoVantagem = 10;
	tipo13.danoDesvantagem = 10;
	tipo13.turnoAtaque = 1;

	tipo14.identificador = 4;
	tipo14.nomeAtaque = "investida relampago";
	tipo14.dano = 20;
	tipo14.danoVantagem = 10;
	tipo14.danoDesvantagem = 10;
	tipo14.turnoAtaque = 1;

	tipo15.identificador = 4;
	tipo15.nomeAtaque = "wave thunder";
	tipo15.dano = 40;
	tipo15.danoVantagem = 10;
	tipo15.danoDesvantagem = 10;
	tipo15.turnoAtaque = 2;

	tipo16.identificador = 4;
	tipo16.nomeAtaque = "wild charger";
	tipo16.dano = 40;
	tipo16.danoVantagem = 10;
	tipo16.danoDesvantagem = 10;
	tipo16.turnoAtaque = 2;
}

#endif