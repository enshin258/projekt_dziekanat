#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

class Przedmiot
{
	friend class Dziekanat;

	unsigned int id_przedmiotu;
	string nazwa_przedmiotu;
	unsigned int punkty_ects;

	void przedmiot_wyswietl();
	bool przedmiot_dodaj();
	void przedmiot_modyfikuj();

};