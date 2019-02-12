#include "pch.h"
#include "Przedmiot.h"

void Przedmiot::przedmiot_wyswietl()
{
	cout << "Id przedmiotu: " << this->id_przedmiotu << endl;
	cout << "Nazwa przedmiotu: " << this->nazwa_przedmiotu << endl;
	cout << "Ilosc punktow ECTS za przedmiot: " << this->punkty_ects << endl;
}
bool Przedmiot::przedmiot_dodaj()
{
	string nazwa_przedmiotu;
	string punkty_ects;//potem konwertuje na inta
	bool same_litery_nazwa_przedmiotu;
	bool same_cyfry;

	cin.ignore();
	cout << "Podaj nazwe przedmiotu" << endl;
	getline(cin, nazwa_przedmiotu);
	cout << "Podaj ile punktow ECTS ma byc wart przedmiot" << endl;
	cin >> punkty_ects;


	same_litery_nazwa_przedmiotu = regex_match(nazwa_przedmiotu, regex("^[A-Za-z' ']+$"));
	same_cyfry = regex_match(punkty_ects, regex("^[0-9]+$"));

	if ((same_litery_nazwa_przedmiotu == true) & (same_cyfry == true))
	{
		this->nazwa_przedmiotu = nazwa_przedmiotu;
		this->punkty_ects = stoul(punkty_ects);
		return true;
	}
	else
	{
		return false;
	}
}
void Przedmiot::przedmiot_modyfikuj()
{
	cout << "Aktualne przedmiot to: " << endl;
	this->przedmiot_wyswietl();
	cout << "Podaj nowe dane przedmiotu" << endl;
	this->przedmiot_dodaj();
}