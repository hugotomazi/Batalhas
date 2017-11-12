#pragma once
#ifndef LOGBATALHAS_H
#define LOGBATALHAS_H
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdio.h>

using namespace std;

void logbatalhas_lerLogs()
{
	//string linha;
	char linha[200];
	ifstream arquivo;
	arquivo.open("arquivoLog.txt");
	if (arquivo.is_open())
	{
		while (!arquivo.eof())
		{
			arquivo.getline(linha, 200);
			cout << linha << endl;	
		}
		arquivo.close();
	}
	arquivo.clear();
}

void logbatalhas_escreverLog(string linha)
{
	ofstream arquivo;
	arquivo.open("arquivoLog.txt", ofstream::app);
	if (arquivo.is_open())
	{
		arquivo << linha;
		arquivo << "\n";
		arquivo.close();
	}
	arquivo.clear();
}

void logbatalhas_limparLog()
{
	ofstream arquivo;
	arquivo.open("arquivoLog.txt");
	if (arquivo.is_open())
	{
		arquivo << "";
		arquivo.close();
	} 
	arquivo.clear();
}

#endif