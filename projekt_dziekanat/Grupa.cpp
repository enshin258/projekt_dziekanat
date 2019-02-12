#include "pch.h"
#include "Grupa.h"
#include "Dziekanat.h"
bool Grupa::grupa_dodaj()
{
	string nazwa_grupy;
	bool same_cyfry_i_litery;
	bool same_cyfry;
	bool same_cyfry2;
	string id_przedmiotu;
	string ilosc_przedmiotow;
	int ilosc_przedmiotow_int;
	int id_przedmiotu_int;

	cout << "Podaj nazwe grupy" << endl;
	cin >> nazwa_grupy;
	same_cyfry_i_litery= regex_match(nazwa_grupy, regex("^[A-Za-z0-9]+$"));
	cout << "Podaj ilosc przedmiotow jakie maja byc w grupie" << endl;
	cin >> ilosc_przedmiotow;
	same_cyfry2= regex_match(ilosc_przedmiotow, regex("^[0-9]+$"));

	ilosc_przedmiotow_int=stoi(ilosc_przedmiotow, nullptr, 10);

	cout << "Podaj id przedmiotow nauczanych w grupie" << endl;
	for (int i = 0; i < ilosc_przedmiotow_int; i++)
	{
		cout << "Podaj ID przedmiotu: " << endl;
		cin >> id_przedmiotu;

		same_cyfry= regex_match(id_przedmiotu, regex("^[0-9]+$"));//sprawdza czy same cyfry
		id_przedmiotu_int = stoi(id_przedmiotu, nullptr, 10);//konwersja na inta

		auto it = id_przedmiotow_w_grupie.begin();//sprawdzam czy nie podano powtorki przedmiotu
		for (it; it != id_przedmiotow_w_grupie.end(); it++)
		{
			if (id_przedmiotu_int == (*it))
			{
				cout << "ID tego przedmiotu juz jest w grupie!!!" << endl;
				return false;
				break;
			}
			
		}
		id_przedmiotow_w_grupie.push_back(id_przedmiotu_int);
	}
	
	if ((same_cyfry_i_litery == true) & (same_cyfry==true) & (same_cyfry2==true))
	{
		this->nazwa_grupy = nazwa_grupy;
		return true;
	}
	else
	{
		return false;
	}
}
void Grupa::grupa_wyswietl()
{
	cout << "ID grupy: " << this->id_grupy << endl;
	cout << "Nazwa grupy: " << this->nazwa_grupy << endl;
	//cout << "Przedmioty w grupie (ID): " << endl;
	//auto it = id_przedmiotow_w_grupie.begin();
	//for (it; it != id_przedmiotow_w_grupie.end(); it++)
	//{
	//	cout << "ID przedmiottu: " << (*it) << endl;
	//}
	////////<-auto it na przedmioty nie dziala!>!>!>!
	
	//auto it = przedmioty.begin();

	

}
void Grupa::grupa_modyfikuj()
{
	cout << "Aktualne dane grupy: " << endl;
	this->grupa_wyswietl();
	cout << "Podaj nowe dane grupy:" << endl;
	this->id_przedmiotow_w_grupie.clear();
	this->grupa_dodaj();
}