#pragma once
#ifndef MONSTROS_H
#define MONSTROS_H

#include <iostream>
#include <string>
#include "Tipos.h"
#include "poderes.h"
#include "LogBatalhas.h"
using namespace std;

struct monstro{
	int identificador;
	string nomeMonstro;
	int hp;
	int level;
	Tipo elemento;
	poder poderes[4];
};

bool monstros_recebeAtaque(monstro &monstroReceptor, monstro &monstroEmissor, poder &ataqueUtilizado, bool &venceuBatalha, int turnoAtual)
{
	int vidaPerdida = 0;
	if (ataqueUtilizado.auxQuantidadeVezesUso >= ataqueUtilizado.quantidadeVezesUso)
	{
		logbatalhas_escreverLog("Este ataque nao pode mais ser utilizado!");
		return false;
	}
	
	if (!ataqueUtilizado.disponivel)
	{
		logbatalhas_escreverLog("Este ataque esta em espera! Tente no proximo turno.");
		return false;
	}

	if (monstroReceptor.elemento.identificadorDesvantagem == monstroEmissor.elemento.identificador)
	{
		vidaPerdida = (ataqueUtilizado.danoVantagem + ataqueUtilizado.dano);
		monstroReceptor.hp -= (ataqueUtilizado.danoVantagem + ataqueUtilizado.dano);
		
	}
	else
	{
		vidaPerdida = ataqueUtilizado.dano;
		monstroReceptor.hp -= (ataqueUtilizado.dano);
	}

	if (monstroReceptor.hp <= 0)
	{ 
		venceuBatalha = true;
		logbatalhas_escreverLog(monstroReceptor.nomeMonstro + " levou um ataque fatal! O vencedor e " + monstroEmissor.nomeMonstro + ".");
	}
	else {
		venceuBatalha = false;
		char buffer[11];
		itoa(vidaPerdida, buffer, 10);
		logbatalhas_escreverLog(monstroReceptor.nomeMonstro + " levou o ataque " + ataqueUtilizado.nomeAtaque + " de " + monstroEmissor.nomeMonstro + " e perdeu " + buffer + " de Vida!");
		
		ataqueUtilizado.auxQuantidadeVezesUso++;
		ataqueUtilizado.auxTurnoAtaque = turnoAtual;
		ataqueUtilizado.disponivel = false;
	}
	return true;
}

monstro monstro_setaMonstroPorId(monstro monstros[], int quantidadeMonstros, int identificador)
{
	for (int i = 0; i < quantidadeMonstros; i++)
	{
		if (monstros[i].identificador == identificador)
		{
			return monstros[i];
		}
	}
}

void monstro_inicializarMonstro(monstro &tipo1, monstro &tipo2, monstro &tipo3, monstro &tipo4, monstro &tipo5, monstro &tipo6, monstro &tipo7, monstro &tipo8, monstro &tipo9, monstro &tipo10)
{

	Tipo fogo, agua, vegetal, raio;

	poder bola_de_fogo, chama_nenem, mega_blaster, tornado_de_chamas; //Tipos fogo
	poder jato_de_agua, bomba_de_agua, hiper_bomba_aquatica; //Tipos água
	poder folha_navalha, ataque_de_espinho, raio_solar, semente_da_insonia; //Tipos vegetais
	poder choque_do_trovao, investida_relampago, wave_thunder, whild_charger; //Tipos trovão

	tipo_inicializarTipos(fogo, agua, vegetal, raio);
	poder_inicializarPoder(bola_de_fogo, chama_nenem, mega_blaster, tornado_de_chamas, jato_de_agua, bomba_de_agua, mega_blaster, hiper_bomba_aquatica, folha_navalha, ataque_de_espinho, raio_solar, semente_da_insonia, choque_do_trovao, investida_relampago, wave_thunder, whild_charger);

	tipo1.identificador = 1;
	tipo1.nomeMonstro = "Tangath Toborn";
	tipo1.hp = 100;
	tipo1.level = 50;
	tipo1.elemento = fogo;
	tipo1.poderes[0] = bola_de_fogo;
	tipo1.poderes[1] = chama_nenem;
	tipo1.poderes[2] = mega_blaster;
	tipo1.poderes[3] = tornado_de_chamas;

	tipo2.identificador = 2;
	tipo2.nomeMonstro = "Maxxor";
	tipo2.hp = 100;
	tipo2.level = 50;
	tipo2.elemento = fogo;
	tipo2.poderes[0] = bola_de_fogo;
	tipo2.poderes[1] = chama_nenem;
	tipo2.poderes[2] = mega_blaster;
	tipo2.poderes[3] = tornado_de_chamas;

	tipo3.identificador = 3;
	tipo3.nomeMonstro = "Intress";
	tipo3.hp = 100;
	tipo3.level = 50;
	tipo3.elemento = agua;
	tipo3.poderes[0] = jato_de_agua;
	tipo3.poderes[1] = bomba_de_agua;
	tipo3.poderes[2] = mega_blaster;
	tipo3.poderes[3] = hiper_bomba_aquatica;

	tipo4.identificador = 4;
	tipo4.nomeMonstro = "Rellim";
	tipo4.hp = 100;
	tipo4.level = 50;
	tipo4.elemento = agua;
	tipo4.poderes[0] = jato_de_agua;
	tipo4.poderes[1] = bomba_de_agua;
	tipo4.poderes[2] = mega_blaster;
	tipo4.poderes[3] = hiper_bomba_aquatica;

	tipo5.identificador = 5;
	tipo5.nomeMonstro = "Donmar";
	tipo5.hp = 100;
	tipo5.level = 50;
	tipo5.elemento = vegetal;
	tipo5.poderes[0] = folha_navalha;
	tipo5.poderes[1] = ataque_de_espinho;
	tipo5.poderes[2] = raio_solar;
	tipo5.poderes[3] = semente_da_insonia;

	tipo6.identificador = 6;
	tipo6.nomeMonstro = "Intress";
	tipo6.hp = 100;
	tipo6.level = 50;
	tipo6.elemento = vegetal;
	tipo6.poderes[0] = folha_navalha;
	tipo6.poderes[1] = ataque_de_espinho;
	tipo6.poderes[2] = raio_solar;
	tipo6.poderes[3] = semente_da_insonia;

	tipo7.identificador = 7;
	tipo7.nomeMonstro = "Ekuud";
	tipo7.hp = 100;
	tipo7.level = 50;
	tipo7.elemento = vegetal;
	tipo7.poderes[0] = folha_navalha;
	tipo7.poderes[1] = ataque_de_espinho;
	tipo7.poderes[2] = raio_solar;
	tipo7.poderes[3] = semente_da_insonia;

	tipo8.identificador = 8;
	tipo8.nomeMonstro = "Frafdo";
	tipo8.hp = 100;
	tipo8.level = 50;
	tipo8.elemento = vegetal;
	tipo8.poderes[0] = folha_navalha;
	tipo8.poderes[1] = ataque_de_espinho;
	tipo8.poderes[2] = raio_solar;
	tipo8.poderes[3] = semente_da_insonia;

	tipo9.identificador = 9;
	tipo9.nomeMonstro = "Bylkian";
	tipo9.hp = 100;
	tipo9.level = 50;
	tipo9.elemento = raio;
	tipo9.poderes[0] = choque_do_trovao;
	tipo9.poderes[1] = investida_relampago;
	tipo9.poderes[2] = wave_thunder;
	tipo9.poderes[3] = whild_charger;

	tipo10.identificador = 10;
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
