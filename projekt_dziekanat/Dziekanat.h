#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include "Grupa.h"
#include "Nauczyciel.h"
#include "Student.h"
#include "Przedmiot.h"

using namespace std;

class Dziekanat
{
private:


	vector <Grupa> grupy;
	vector <Nauczyciel> nauczyciele;
	vector <Student> studenci;
	vector <Przedmiot> przedmioty;
	vector <Ocena> oceny;


	unsigned int id_nowego_studenta = 1;
	unsigned int id_nowego_nauczyciela = 1;
	unsigned int id_nowej_grupy = 1;
	unsigned int id_nowego_przedmiotu = 1;
	unsigned int id_nowej_oceny = 1;

public:
	void wczytanie_danych_z_plikow();
	void zapis_do_plikow();

	void dodaj_studenta();
	void wyswietl_studentow();
	void usun_studenta();
	void modyfikuj_studenta();


	void dodaj_nauczyciela();
	void wyswietl_nauczycieli();
	void usun_nauczyciela();
	void modyfikuj_nauczyciela();

	void dodaj_przedmiot();
	void wyswietl_przedmioty();
	void usun_przedmiot();
	void modyfikuj_przedmiot();

	void dodaj_grupe();
	void wyswietl_grupy();
	void usun_grupe();
	void modyfikuj_grupe();

	void dodaj_ocene();
	void wyswietl_oceny();
	void usun_oceny();
	void modyfikuj_oceny();

	void kto_zdal();



};