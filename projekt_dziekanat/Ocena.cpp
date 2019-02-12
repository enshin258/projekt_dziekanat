#include "pch.h"
#include "Ocena.h"

bool Ocena::ocena_dodaj()
{
	string id_studenta, id_przedmiotu, ocena_z_przedmiotu;
	bool same_cyfry;
	bool same_cyfry2;
	bool same_cyfry_ocena;


	cout << "Podaj ID studenta,id przedmiotu i ocene" << endl;
	cin >> id_studenta >> id_przedmiotu >> ocena_z_przedmiotu;

	same_cyfry = regex_match(id_studenta, regex("^[0-9]+$"));
	same_cyfry2 = regex_match(id_przedmiotu, regex("^[0-9]+$"));
	same_cyfry_ocena = regex_match(ocena_z_przedmiotu, regex("^[2-5]$"));

	if (same_cyfry == true & same_cyfry2 == true & same_cyfry_ocena == true)
	{
		this->id_przedmiotu = stoi(id_przedmiotu, nullptr, 10);
		this->id_studenta_ocena = stoi(id_studenta, nullptr, 10);
		this->ocena = stoi(ocena_z_przedmiotu, nullptr, 10);
		return true;
	}
	else
	{
		return false;
	}


}
void Ocena::ocena_wyswietl()
{
	cout << "ID oceny: " << this->id_oceny << endl;
	cout << "ID studenta: " << this->id_studenta_ocena << endl;
	cout << "ID przedmiotu z ktorego jest ocena: " << this->id_przedmiotu<< endl;
	cout << "Ocena: " << this->ocena << endl;
}
void Ocena::ocena_modyfikuj()
{
	cout << "Aktualna ocena studenta: " << endl;
	this->ocena_wyswietl();
	cout << "Podaj nowa ocene studenta:" << endl;
	this->ocena_dodaj();
}
