#pragma once
#ifndef MONSTROS_H
#define MONSTROS_H
#include <iostream>
#include <string>
#include "Tipos.h"
#include "poderes.h"
using namespace std;

struct monstro{
	string nomeMonstro;
	int hp;
	int level;
	string tipo;
	string nomeAtaque1;
	string nomeAtaque2;
	string nomeAtaque3;
	string nomeAtaque4;
};

void monstro_inicializarmonstro(monstro &tipo1, monstro &tipo2, monstro &tipo3, monstro &tipo4, monstro &tipo5, monstro &tipo6, monstro &tipo7, monstro &tipo8, monstro &tipo9, monstro &tipo10)
{
	
	tipo1.nomeMonstro = "Tangath Toborn";
	tipo1.hp = 100;
	tipo1.level = 50;
	tipo1.tipo = "fogo";
	tipo1.nomeAtaque1 = "bola de fogo";
	tipo1.nomeAtaque2 = "chama neném";
	tipo1.nomeAtaque3 = "mega blaster";
	tipo1.nomeAtaque4 = "tornado de chamas";

	tipo2.nomeMonstro = "Maxxor";
	tipo2.hp = 100;
	tipo2.level = 50;
	tipo2.tipo = "fogo";
	tipo2.nomeAtaque1 = "bola de fogo";
	tipo2.nomeAtaque2 = "chama neném";
	tipo2.nomeAtaque3 = "mega blaster";
	tipo2.nomeAtaque4 = "tornado de chamas";

	tipo3.nomeMonstro = "Intress";
	tipo3.hp = 100;
	tipo3.level = 50;
	tipo3.tipo = "agua";
	tipo3.nomeAtaque1 = "jato de agua";
	tipo3.nomeAtaque2 = "bomba de agua";
	tipo3.nomeAtaque3 = "mega blaster";
	tipo3.nomeAtaque4 = "hiper bomba aquatica";

	tipo4.nomeMonstro = "Rellim";
	tipo4.hp = 100;
	tipo4.level = 50;
	tipo4.tipo = "agua";
	tipo4.nomeAtaque1 = "jato de agua";
	tipo4.nomeAtaque2 = "bomba de agua";
	tipo4.nomeAtaque3 = "mega blaster";
	tipo4.nomeAtaque4 = "hiper bomba aquatica";

	tipo5.nomeMonstro = "Donmar";
	tipo5.hp = 100;
	tipo5.level = 50;
	tipo5.tipo = "vegetal";
	tipo5.nomeAtaque1 = "folha navalha";
	tipo5.nomeAtaque2 = "ataque de espinho";
	tipo5.nomeAtaque3 = "raio solar";
	tipo5.nomeAtaque4 = "semente da insonia";

	tipo6.nomeMonstro = "Intress";
	tipo6.hp = 100;
	tipo6.level = 50;
	tipo6.tipo = "vegetal";
	tipo6.nomeAtaque1 = "folha navalha";
	tipo6.nomeAtaque2 = "ataque de espinho";
	tipo6.nomeAtaque3 = "raio solar";
	tipo6.nomeAtaque4 = "semente da insonia";

	tipo7.nomeMonstro = "Ekuud";
	tipo7.hp = 100;
	tipo7.level = 50;
	tipo7.tipo = "vegetal";
	tipo7.nomeAtaque1 = "folha navalha";
	tipo7.nomeAtaque2 = "ataque de espinho";
	tipo7.nomeAtaque3 = "raio solar";
	tipo7.nomeAtaque4 = "semente da insonia";

	tipo8.nomeMonstro = "Frafdo";
	tipo8.hp = 100;
	tipo8.level = 50;
	tipo8.tipo = "vegetal";
	tipo8.nomeAtaque1 = "folha navalha";
	tipo8.nomeAtaque2 = "ataque de espinho";
	tipo8.nomeAtaque3 = "raio solar";
	tipo8.nomeAtaque4 = "semente da insonia";

	tipo9.nomeMonstro = "Bylkian";
	tipo9.hp = 100;
	tipo9.level = 50;
	tipo9.tipo = "raio";
	tipo9.nomeAtaque1 = "choque do trovao";
	tipo9.nomeAtaque2 = "investida relampago";
	tipo9.nomeAtaque3 = "wave thunder";
	tipo9.nomeAtaque4 = "whild charger";

	tipo10.nomeMonstro = "Titanix";
	tipo10.hp = 100;
	tipo10.level = 50;
	tipo10.tipo = "raio";
	tipo10.nomeAtaque1 = "choque do trovao";
	tipo10.nomeAtaque2 = "investida relampago";
	tipo10.nomeAtaque3 = "wave thunder";
	tipo10.nomeAtaque4 = "whild charger";


#endif
