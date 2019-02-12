#pragma once
#include "pch.h"
#include "Osoba.h"
#include <iostream>
#include <string>
#include <regex>

class Ocena
{
	friend class Dziekanat;

	unsigned int id_oceny;

	unsigned int id_studenta_ocena;
	unsigned int id_przedmiotu;
	unsigned int ocena;
	bool ocena_dodaj();
	void ocena_modyfikuj();
	void ocena_wyswietl();
};