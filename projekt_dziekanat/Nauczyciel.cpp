#include "pch.h"
#include "Nauczyciel.h"
 void Nauczyciel::nauczyciel_wyswietl()
{
	cout << "ID nauczyciela: " << this->id_nauczyciela << endl;
	cout << "Imie: " << this->imie << endl;
	cout << "Nazwisko: " << this->nazwisko << endl;
	cout << "Pesel: " << this->pesel << endl;
	cout << "Id uczonego przedmiotu: "<<this->id_przedmiotu_uczonego<<endl;
}

bool Nauczyciel::nauczyciel_dodaj()
{
	string imie, nazwisko, pesel, id_przedmiotu_uczonego;
	bool same_litery_imie;
	bool same_litery_nazwisko;
	bool same_cyfry;
	bool same_cyfry2;
	int dlugosc_peselu;

	cout << "Podaj imie,nazwisko, pesel i id uczonego przedmiotu oddzielone spacjami" << endl;
	cin >> imie >> nazwisko >> pesel >> id_przedmiotu_uczonego;

	same_litery_imie = regex_match(imie, regex("^[A-Za-z]+$"));
	same_litery_nazwisko = regex_match(nazwisko, regex("^[A-Za-z]+$"));
	same_cyfry = regex_match(pesel, regex("^[0-9]+$"));
	same_cyfry2 = regex_match(id_przedmiotu_uczonego, regex("^[0-9]+$"));
	dlugosc_peselu = pesel.length();

	if ((same_litery_imie == true) & (same_litery_nazwisko == true) & (same_cyfry == true)&(same_cyfry2==true) & (dlugosc_peselu == 11))
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->pesel = pesel;
		this->id_przedmiotu_uczonego = stoi(id_przedmiotu_uczonego, nullptr, 10);
		return true;
	}
	else
	{
		return false;
	}

}
void Nauczyciel::nauczyciel_modyfikuj()
{
	cout << "Aktualne dane nauczyciela: " << endl;
	this->nauczyciel_wyswietl();
	cout << "Podaj nowe dane studenta:" << endl;
	this->nauczyciel_dodaj();
}
void Nauczyciel::test()
{
	cout << "Test dla nauczyciela" << endl;
}