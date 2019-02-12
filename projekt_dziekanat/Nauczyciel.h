#pragma once
#include "pch.h"
#include "Osoba.h"
#include <iostream>
#include <string>
#include <regex>


class Nauczyciel:public Osoba
{

	friend class Dziekanat;
	unsigned int id_nauczyciela;
	unsigned int id_przedmiotu_uczonego;
	
	void nauczyciel_wyswietl();
	bool nauczyciel_dodaj();
	void nauczyciel_modyfikuj();
public:
	virtual void test();
	Nauczyciel() { id_nauczyciela = 0; id_przedmiotu_uczonego = 0; };
	~Nauczyciel() = default;



};