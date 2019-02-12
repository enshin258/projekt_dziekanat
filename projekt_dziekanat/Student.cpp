#include "pch.h"
#include "Student.h"
void Student::student_wyswietl()
{
	cout << "ID studenta: " << this->id_studenta << endl;
	cout << "Imie: " << this->imie << endl;
	cout << "Nazwisko: " << this->nazwisko << endl;
	cout << "Pesel: " << this->pesel << endl;
	cout << "Id grupy studenta: " << this->id_grupy_studenta << " ";
}

bool Student::student_dodaj()
{
	string imie, nazwisko, pesel,id_grupy_studenta;
	bool same_litery_imie;
	bool same_litery_nazwisko;
	bool same_cyfry;
	bool same_cyfry2;
	int dlugosc_peselu;

	cout << "Podaj imie,nazwisko,pesel i id grupy oddzielone spacjami" << endl;
	cin >> imie >> nazwisko >> pesel>>id_grupy_studenta;

	same_litery_imie = regex_match(imie, regex("^[A-Za-z]+$"));
	same_litery_nazwisko = regex_match(nazwisko, regex("^[A-Za-z]+$"));
	same_cyfry = regex_match(pesel, regex("^[0-9]+$"));
	same_cyfry2 = regex_match(id_grupy_studenta, regex("^[0-9]+$"));
	dlugosc_peselu = pesel.length();

	if (same_litery_imie == true & same_litery_nazwisko==true & same_cyfry==true & same_cyfry2==true & dlugosc_peselu==11 )
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->pesel = pesel;
		this->id_grupy_studenta = stoi(id_grupy_studenta, nullptr, 10);
		return true;
	}
	else
	{
		return false;
	}
	
}
void Student::student_modyfikuj()
{
	cout << "Aktualne dane studenta: " << endl;
	this->student_wyswietl();
	cout << "Podaj nowe dane studenta:" << endl;
	this->student_dodaj();
}

void Student::test()
{
	cout << "Test dla Studenta" << endl;
}


