#pragma once
#include "pch.h"
#include <vector>
#include <string>
#include <regex>
#include <iostream>

using namespace std;

class Grupa
{
	friend class Dziekanat;

	unsigned int id_grupy;
	string nazwa_grupy;

	vector <unsigned int> id_przedmiotow_w_grupie;

	unsigned int ectsy_w_grupie;

	bool grupa_dodaj();
	void grupa_wyswietl();
	void grupa_modyfikuj();

};