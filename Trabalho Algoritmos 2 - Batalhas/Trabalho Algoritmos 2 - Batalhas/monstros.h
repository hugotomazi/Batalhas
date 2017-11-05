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
	Tipo elemento;
	poder poderes[4];
};

void monstro_inicializarMonstro(monstro &tipo1, monstro &tipo2, monstro &tipo3, monstro &tipo4, monstro &tipo5, monstro &tipo6, monstro &tipo7, monstro &tipo8, monstro &tipo9, monstro &tipo10)
{

	Tipo fogo, agua, vegetal, raio;

	poder bola_de_fogo, chama_nenem, mega_blaster, tornado_de_chamas; //Tipos fogo
	poder jato_de_agua, bomba_de_agua, hiper_bomba_aquatica; //Tipos água
	poder folha_navalha, ataque_de_espinho, raio_solar, semente_da_insonia; //Tipos vegetais
	poder choque_do_trovao, investida_relampago, wave_thunder, whild_charger; //Tipos trovão

	tipo_inicializarTipos(fogo, agua, vegetal, raio);
	poder_inicializarPoder(bola_de_fogo, chama_nenem, mega_blaster, tornado_de_chamas, jato_de_agua, bomba_de_agua, mega_blaster, hiper_bomba_aquatica, folha_navalha, ataque_de_espinho, raio_solar, semente_da_insonia, choque_do_trovao, investida_relampago, wave_thunder, whild_charger);

	tipo1.nomeMonstro = "Tangath Toborn";
	tipo1.hp = 100;
	tipo1.level = 50;
	tipo1.elemento = fogo;
	tipo1.poderes[0] = bola_de_fogo;
	tipo1.poderes[1] = chama_nenem;
	tipo1.poderes[2] = mega_blaster;
	tipo1.poderes[3] = tornado_de_chamas;

	tipo2.nomeMonstro = "Maxxor";
	tipo2.hp = 100;
	tipo2.level = 50;
	tipo2.elemento = fogo;
	tipo2.poderes[0] = bola_de_fogo;
	tipo2.poderes[1] = chama_nenem;
	tipo2.poderes[2] = mega_blaster;
	tipo2.poderes[3] = tornado_de_chamas;

	tipo3.nomeMonstro = "Intress";
	tipo3.hp = 100;
	tipo3.level = 50;
	tipo3.elemento = agua;
	tipo3.poderes[0] = jato_de_agua;
	tipo3.poderes[1] = bomba_de_agua;
	tipo3.poderes[2] = mega_blaster;
	tipo3.poderes[3] = hiper_bomba_aquatica;

	tipo4.nomeMonstro = "Rellim";
	tipo4.hp = 100;
	tipo4.level = 50;
	tipo4.elemento = agua;
	tipo4.poderes[0] = jato_de_agua;
	tipo4.poderes[1] = bomba_de_agua;
	tipo4.poderes[2] = mega_blaster;
	tipo4.poderes[3] = hiper_bomba_aquatica;

	tipo5.nomeMonstro = "Donmar";
	tipo5.hp = 100;
	tipo5.level = 50;
	tipo5.elemento = vegetal;
	tipo5.poderes[0] = folha_navalha;
	tipo5.poderes[1] = ataque_de_espinho;
	tipo5.poderes[2] = raio_solar;
	tipo5.poderes[3] = semente_da_insonia;

	tipo6.nomeMonstro = "Intress";
	tipo6.hp = 100;
	tipo6.level = 50;
	tipo6.elemento = vegetal;
	tipo6.poderes[0] = folha_navalha;
	tipo6.poderes[1] = ataque_de_espinho;
	tipo6.poderes[2] = raio_solar;
	tipo6.poderes[3] = semente_da_insonia;

	tipo7.nomeMonstro = "Ekuud";
	tipo7.hp = 100;
	tipo7.level = 50;
	tipo7.elemento = vegetal;
	tipo7.poderes[0] = folha_navalha;
	tipo7.poderes[1] = ataque_de_espinho;
	tipo7.poderes[2] = raio_solar;
	tipo7.poderes[3] = semente_da_insonia;

	tipo8.nomeMonstro = "Frafdo";
	tipo8.hp = 100;
	tipo8.level = 50;
	tipo8.elemento = vegetal;
	tipo8.poderes[0] = folha_navalha;
	tipo8.poderes[1] = ataque_de_espinho;
	tipo8.poderes[2] = raio_solar;
	tipo8.poderes[3] = semente_da_insonia;

	tipo9.nomeMonstro = "Bylkian";
	tipo9.hp = 100;
	tipo9.level = 50;
	tipo9.elemento = raio;
	tipo9.poderes[0] = choque_do_trovao;
	tipo9.poderes[1] = investida_relampago;
	tipo9.poderes[2] = wave_thunder;
	tipo9.poderes[3] = whild_charger;

	tipo10.nomeMonstro = "Titanix";
	tipo10.hp = 100;
	tipo10.level = 50;
	tipo10.elemento = raio;
	tipo10.poderes[0] = choque_do_trovao;
	tipo10.poderes[1] = investida_relampago;
	tipo10.poderes[2] = wave_thunder;
	tipo10.poderes[3] = whild_charger;
}

#endif
