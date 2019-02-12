#include "pch.h"
#include "Dziekanat.h"
#include <fstream>
#include <string>
//sekcja na obsluge plikow

void Dziekanat::wczytanie_danych_z_plikow()
{
	fstream plik_studenci;
	fstream plik_nauczyciele;
	fstream plik_grupy;
	fstream plik_przedmioty;
	fstream plik_oceny;


	string p_imie;
	string p_nazwisko;
	string p_pesel;
	string p_id_grupy_studenta;
	string p_nazwa_przedmiotu;
	string p_punkty_ects;
	string p_nazwa_grupy;
	string p_id_przedmiotu;
	string p_id_przedmiotu_uczonego;
	string p_id_studenta_ocena;
	string p_id_przedmiotu_ocena;
	string p_ocena;
	int p_id_przedmiotu_int;

	plik_studenci.open("studenci.txt", ios::in);
	if (plik_studenci.good())
	{
		while (plik_studenci >> p_imie >> p_nazwisko >> p_pesel>>p_id_grupy_studenta)
		{
			Student s;
			s.id_studenta = this->id_nowego_studenta;
			this->id_nowego_studenta++;
			s.imie = p_imie;
			s.nazwisko = p_nazwisko;
			s.pesel = p_pesel;
			s.id_grupy_studenta = stoi(p_id_grupy_studenta, nullptr, 10);
			this->studenci.push_back(s);
		}
	}

	plik_studenci.close();

	plik_nauczyciele.open("nauczyciele.txt", ios::in);
	if (plik_nauczyciele.good())
	{
		while (plik_nauczyciele>> p_imie >> p_nazwisko >> p_pesel>>p_id_przedmiotu_uczonego)
		{
			Nauczyciel n;
			n.id_nauczyciela = this->id_nowego_nauczyciela;
			this->id_nowego_nauczyciela++;
			n.imie = p_imie;
			n.nazwisko = p_nazwisko;
			n.pesel = p_pesel;
			n.id_przedmiotu_uczonego = stoi(p_id_przedmiotu_uczonego, nullptr, 10);
			this->nauczyciele.push_back(n);
		}
	}

	plik_nauczyciele.close();

	plik_przedmioty.open("przedmioty.txt", ios::in);
	if (plik_przedmioty.good())
	{
		while (plik_przedmioty>>p_punkty_ects)
		{
			plik_przedmioty.seekg(1, ios::cur);//przesuwam sie o jeden znak w prawo bo byl blad ze odczytywalo spacje przed nazwa
			getline(plik_przedmioty, p_nazwa_przedmiotu,'\n');
			Przedmiot p;
			p.id_przedmiotu = this->id_nowego_przedmiotu;
			this->id_nowego_przedmiotu++;
			p.nazwa_przedmiotu = p_nazwa_przedmiotu;
			p.punkty_ects = stoul(p_punkty_ects,nullptr,10);//konwersja stringa na liczbe dziesietna
			this->przedmioty.push_back(p);

		}
	}
	plik_przedmioty.close();

	plik_grupy.open("grupy.txt", ios::in);
	if (plik_grupy.good())
	{
		char znak;
		while (plik_grupy >> p_nazwa_grupy)
		{
			Grupa g;
			g.id_grupy = this->id_nowej_grupy;
			this->id_nowej_grupy++;
			g.nazwa_grupy = p_nazwa_grupy;
			while (plik_grupy.get(znak))
			{
				if (znak != '\n')//sprawdzam czy juz skonczyla sie linnia dla danej grupy
				{
					plik_grupy >> p_id_przedmiotu;
					p_id_przedmiotu_int = stoi(p_id_przedmiotu, nullptr, 10);
					g.id_przedmiotow_w_grupie.push_back(p_id_przedmiotu_int);
				}
				else
				{
					break;
				}
			}
			this->grupy.push_back(g);
		}
	}
	plik_grupy.close();

	plik_oceny.open("oceny.txt", ios::in);
	if (plik_oceny.good())
	{
		while (plik_oceny >> p_id_studenta_ocena >> p_id_przedmiotu_ocena >> p_ocena)
		{
			Ocena o;
			o.id_oceny = this->id_nowej_oceny;
			this->id_nowej_oceny++;
			o.id_studenta_ocena = stoi(p_id_studenta_ocena,nullptr,10);
			o.id_przedmiotu = stoi(p_id_przedmiotu_ocena, nullptr, 10);
			o.ocena = stoi(p_ocena, nullptr, 10);
			this->oceny.push_back(o);
		}
	}
	plik_oceny.close();



}
void Dziekanat::zapis_do_plikow()
{
	fstream plik_studenci;
	fstream plik_nauczyciele;
	fstream plik_grupy;
	fstream plik_przedmioty;
	fstream plik_oceny;

	plik_studenci.open("studenci.txt", ios::out);
	auto it = studenci.begin();
	for (it ;it != studenci.end(); it++)
	{
		plik_studenci << it->imie << " ";
		plik_studenci << it->nazwisko << " ";
		plik_studenci << it->pesel << " ";
		plik_studenci << it->id_grupy_studenta << endl;
	}
	plik_studenci.close();

	plik_nauczyciele.open("nauczyciele.txt", ios::out);
	auto it2 = nauczyciele.begin();
	for (it2; it2 != nauczyciele.end(); it2++)
	{
		plik_nauczyciele << it2->imie << " ";
		plik_nauczyciele << it2->nazwisko << " ";
		plik_nauczyciele << it2->pesel << " ";
		plik_nauczyciele << it2->id_przedmiotu_uczonego << endl;
	}
	plik_nauczyciele.close();

	plik_przedmioty.open("przedmioty.txt", ios::out);
	auto it3 = przedmioty.begin();
	for (it3; it3 != przedmioty.end(); it3++)
	{
		plik_przedmioty << it3->punkty_ects << " ";
		plik_przedmioty << it3->nazwa_przedmiotu << endl;
	}
	plik_przedmioty.close();

	plik_grupy.open("grupy.txt", ios::out);
	auto it4 = grupy.begin();
	for (it4; it4 != grupy.end(); it4++)
	{
		plik_grupy << it4->nazwa_grupy << " ";
		for (int i = 0; i < it4->id_przedmiotow_w_grupie.size() -1 ; i++)
		{
			plik_grupy<<it4->id_przedmiotow_w_grupie[i] << " ";
		}
		plik_grupy << it4->id_przedmiotow_w_grupie.back();
		plik_grupy << endl;
	}
	plik_oceny.open("oceny.txt", ios::out);
	auto it5 = oceny.begin();
	for (it5; it5 != oceny.end(); it5++)
	{
		plik_oceny << it5->id_studenta_ocena << " ";
		plik_oceny << it5->id_przedmiotu << " ";
		plik_oceny << it5->ocena << endl;
	}
}


//sekcja na obsluge studentow
void Dziekanat::dodaj_studenta()
{
	bool poprawne_dane;
	Student s;
	poprawne_dane=s.student_dodaj();
	if (poprawne_dane == true)
	{
		auto it = this->grupy.begin();
		for (it; it != grupy.end(); it++)
		{
			if(it->id_grupy==s.id_grupy_studenta)
			{
				s.id_studenta = this->id_nowego_studenta;
				id_nowego_studenta++;
				this->studenci.push_back(s);
				break;
			}

		}
	}
	else
	{
		cout << "Blad wprowadzania danych" << endl;
	}

}
void Dziekanat::wyswietl_studentow()
{
	cout << "Studenci w systemie:" << endl;
	if (this->studenci.empty())
	{
		cout << "Brak studentow do wyswietlenia!" << endl;
	}
	auto it = studenci.begin();
	for (it; it != studenci.end(); it++)
	{
		it->student_wyswietl();
		auto it2 = grupy.begin();
		for (it2; it2 != grupy.end(); it2++)
		{
			if (it->id_grupy_studenta == it2->id_grupy)
			{
				cout <<" Nazwa grupy: "<< it2->nazwa_grupy << endl;
				break;
			}
		}
		cout << endl;
	}
}
void Dziekanat::modyfikuj_studenta()
{
	int id_studenta_modyfikacja;
	cout << "Podaj ID studenta do zmodyfikowania" << endl;
	cin >> id_studenta_modyfikacja;
	auto it = studenci.begin();
	for (it; it != studenci.end(); it++)
	{
		if (it->id_studenta == id_studenta_modyfikacja)
		{
			it->student_modyfikuj();
			break;
		}

	}
}
void Dziekanat::usun_studenta()
{
	int id_studenta_usun;
	cout << "Podaj Id studenta do usuniecia: " << endl;
	cin >> id_studenta_usun;
	auto it = studenci.begin();
	for (it; it != studenci.end(); it++)
	{
		if (it->id_studenta == id_studenta_usun)
		{
			this->studenci.erase(it);
			break;
		}
	}

}








//sekcja na obsluge nauczycieli

void Dziekanat::dodaj_nauczyciela()
{
	bool poprawne_dane;
	Nauczyciel n;
	poprawne_dane = n.nauczyciel_dodaj();
	if (poprawne_dane == true)
	{
		auto it = this->przedmioty.begin();
		for (it; it != przedmioty.end(); it++)
		{
			if (it->id_przedmiotu == n.id_przedmiotu_uczonego)
			{
				n.id_nauczyciela = this->id_nowego_nauczyciela;
				id_nowego_nauczyciela++;
				this->nauczyciele.push_back(n);
				break;
			}

		}

	}
	else
	{
		cout << "Blad wprowadzania danych" << endl;
	}

}
void Dziekanat::wyswietl_nauczycieli()
{
	cout << "Nauczyciele w systemie:" << endl;
	if (this->nauczyciele.empty())
	{
		cout << "Brak nauczycieli do wyswietlenia!" << endl;
	}
	auto it = nauczyciele.begin();
	for (it; it != nauczyciele.end(); it++)
	{
		it->nauczyciel_wyswietl();
		cout << endl;
	}
}
void Dziekanat::modyfikuj_nauczyciela()
{
	int id_nauczyciela_modyfikacja;
	cout << "Podaj ID nauczyciela do zmodyfikowania" << endl;
	cin >> id_nauczyciela_modyfikacja;
	auto it = nauczyciele.begin();
	for (it; it != nauczyciele.end(); it++)
	{
		if (it->id_nauczyciela == id_nauczyciela_modyfikacja)
		{
			it->nauczyciel_modyfikuj();
			break;
		}

	}
}
void Dziekanat::usun_nauczyciela()
{
	int id_nauczyciela_usun;
	cout << "Podaj Id nauczyciela do usuniecia: " << endl;
	cin >> id_nauczyciela_usun;
	auto it = nauczyciele.begin();
	for (it; it != nauczyciele.end(); it++)
	{
		if (it->id_nauczyciela == id_nauczyciela_usun)
		{
			this->nauczyciele.erase(it);
			break;
		}

	}

}


//sekcja na obsluge przedmiotow

void Dziekanat::dodaj_przedmiot()
{
	bool poprawne_dane;
	Przedmiot p;
	poprawne_dane = p.przedmiot_dodaj();
	if (poprawne_dane == true)
	{
		p.id_przedmiotu = this->id_nowego_przedmiotu;
		id_nowego_przedmiotu++;
		this->przedmioty.push_back(p);
	}
	else
	{
		cout << "Blad wprowadzania danych" << endl;
	}
}
void Dziekanat::wyswietl_przedmioty()
{
	cout << "Przedmioty w systemie:" << endl;
	if (this->przedmioty.empty())
	{
		cout << "Brak przedmiotow do wyswietlenia!" << endl;
	}
	auto it = przedmioty.begin();
	for (it; it != przedmioty.end(); it++)
	{
		it->przedmiot_wyswietl();
		cout << endl;
	}
}
void Dziekanat::usun_przedmiot()
{
	int id_przedmiot_usun;
	cout << "Podaj Id przedmiotu do usuniecia: " << endl;
	cin >> id_przedmiot_usun;
	auto it = przedmioty.begin();
	for (it; it != przedmioty.end(); it++)
	{
		if (it->id_przedmiotu == id_przedmiot_usun)
		{
			this->przedmioty.erase(it);
			break;
		}
	}
}
void Dziekanat::modyfikuj_przedmiot()
{
	int id_przedmiotu_modyfikacja;
	cout << "Podaj ID przedmiotu do zmodyfikowania" << endl;
	cin >> id_przedmiotu_modyfikacja;
	auto it = przedmioty.begin();
	for (it; it != przedmioty.end(); it++)
	{
		if (it->id_przedmiotu == id_przedmiotu_modyfikacja)
		{
			it->przedmiot_modyfikuj();
			break;
		}
	}
}


//sekcja na obsluge grup

void Dziekanat::dodaj_grupe()
{
	bool poprawne_dane;
	Grupa g;
	poprawne_dane = g.grupa_dodaj();
	if (poprawne_dane == true)
	{
		g.id_grupy = this->id_nowej_grupy;
		id_nowej_grupy++;
		this->grupy.push_back(g);
	}
	else
	{
		cout << "Blad wprowadzania danych" << endl;
	}
}
void Dziekanat::wyswietl_grupy()
{
	cout << "Grupy w systemie...:" << endl;
	if (this->grupy.empty())
	{
		cout << "Brak grup do wyswietlenia!" << endl;
	}
	auto it =grupy.begin();
	for (it; it != grupy.end(); it++)//wszystkie grupy
	{
		it->grupa_wyswietl();//pokazuje id i nazwe grupy
		auto it2 = przedmioty.begin();
		cout << "Przedmioty uczone w grupie to: " << endl;
		for (it2; it2 != przedmioty.end();it2++)//przeszukuje wszystkie przedmioty
		{
			for(int j=0;j<it->id_przedmiotow_w_grupie.size();j++)//przeszukuje wszystkie id w grupie
			{
				if (it2->id_przedmiotu == it->id_przedmiotow_w_grupie[j])
				{
					cout<<"-> "<<it2->nazwa_przedmiotu << endl;
				}

			}
		}
		cout << endl;
	}
}
void Dziekanat::usun_grupe()
{
	int id_grupy_usun;
	cout << "Podaj Id grupy do usuniecia: " << endl;
	cin >> id_grupy_usun;
	auto it = grupy.begin();

	for (it; it != grupy.end(); it++)
	{
		if (it->id_grupy == id_grupy_usun)//znaleziono id grupy do usuniecia
		{
			this->grupy.erase(it);
			break;

		}
	}
}
void Dziekanat::modyfikuj_grupe()
{
	int id_grupy_modyfikacja;
	cout << "Podaj ID grupy do zmodyfikowania" << endl;
	cin >> id_grupy_modyfikacja;
	auto it = grupy.begin();
	for (it; it != grupy.end(); it++)
	{
		if (it->id_grupy == id_grupy_modyfikacja)
		{
			it->grupa_modyfikuj();
			break;
		}
	}
}




//sekcja do ocen
void Dziekanat::dodaj_ocene()//sprawdzam czy jest student,czy jest w grupie co ma 
//taki przedmiot 
{
	bool poprawne_dane;
	bool jest_student = false;
	bool ma_taki_przedmiot = false;
	Ocena o;
	poprawne_dane = o.ocena_dodaj();
	if (poprawne_dane == true)//id studenta id przedmiotu ocena
	{

		auto it = studenci.begin();
		for (it; it != studenci.end(); it++)
		{
			if (it->id_studenta == o.id_studenta_ocena)
			{
				jest_student = true;
			}

		}
		auto it2 = przedmioty.begin();
		for (it2; it2 != przedmioty.end(); it2++)
		{
			if (it2->id_przedmiotu == o.id_przedmiotu)
			{
				ma_taki_przedmiot = true;
			}
		}
		if (jest_student & ma_taki_przedmiot)
		{
			o.id_oceny = this->id_nowej_oceny;
			id_nowej_oceny++;
			this->oceny.push_back(o);
		}
		else
		{
			cout << "Blad wprowadzania danych" << endl;
		}

	}

	else
	{
		cout << "Blad wprowadzania danych" << endl;
	}
}
void Dziekanat::wyswietl_oceny()
{
	cout << "Oceny w systemie..." << endl;
	if (oceny.empty())
	{
		cout << "Brak ocen do wyswietlenia!" << endl;

	}
	else
	{
		auto it = oceny.begin();
		for (it; it != oceny.end(); it++)
		{
			it->ocena_wyswietl();
			cout << endl;
		}
	}
}
void Dziekanat::usun_oceny()
{
	int id_oceny_usun;
	cout << "Podaj ID oceny do usuniecia" << endl;
	cin >> id_oceny_usun;
	auto it = oceny.begin();
	for (it; it != oceny.end(); it++)
	{
		if (it->id_oceny == id_oceny_usun)
		{
			this->oceny.erase(it);
			break;
		}
	}
}
void Dziekanat::modyfikuj_oceny()
{
	int id_oceny_modyfikacja;
	cout << "Podaj ID oceny do zmodyfikowania" << endl;
	cin >> id_oceny_modyfikacja;
	auto it = oceny.begin();
	for (it; it != oceny.end(); it++)
	{
		if (it->id_oceny == id_oceny_modyfikacja)
		{
			it->ocena_modyfikuj();
			break;
		}
	}
}
void Dziekanat::kto_zdal()
{

	auto it2 = this->studenci.begin();
	auto it3 = this->oceny.begin();
	auto it4 = this->przedmioty.begin();
	auto it5 = this->grupy.begin();
	//liczenie ectsow dla kazdej grupy
	cout << "Punkty mozliwe do zdobycia w kazdej grupie..." << endl;
	for (it5; it5 != this->grupy.end(); it5++)//grupy po kolei
	{
		it5->ectsy_w_grupie = 0;
		cout << "Grupa: " << it5->nazwa_grupy;
		it4 = przedmioty.begin();
		for (it4; it4 != this->przedmioty.end(); it4++)//przedmioty
		{
			for (int i = 0; i < it5->id_przedmiotow_w_grupie.size(); i++)//przedmoty w grupie
			{
				if (it5->id_przedmiotow_w_grupie[i] == it4->id_przedmiotu)
				{
					it5->ectsy_w_grupie += it4->punkty_ects;
				}
			}

		}
		cout << " Punkty mozliwe do uzyskania: " << it5->ectsy_w_grupie << endl;
	}
	cout << endl;
	//liczenie ectsow kazdego studenta
	for (it2; it2 != studenci.end();it2++)//przeszukuje studentow
	{
		it2->suma_ects = 0;
		it3 = oceny.begin();
		for (it3; it3 != this->oceny.end(); it3++)//sprawdzam oceny
		{
			if (it2->id_studenta == it3->id_studenta_ocena)//czy to jego ocena
			{
				it4 = przedmioty.begin();
				for (it4; it4 != this->przedmioty.end(); it4++)//przedmioty
				{
					if (it3->id_przedmiotu == it4->id_przedmiotu)//sprawdzam przedmiot
					{
						if (it3->ocena >= 3)//czy zaliczone
						{
							it2->suma_ects += it4->punkty_ects;
						}
					}
					
				}
			}
		}

	}
	it2 = studenci.begin();
	for (it2; it2 != studenci.end(); it2++)
	{
		cout << "Student: " << it2->imie << " " << it2->nazwisko << endl;
		cout << "Zdobyl: " << it2->suma_ects << " punktow ects" << endl;
		it5 = grupy.begin();
		for (it5; it5 != grupy.end(); it5++)
		{
			if (it2->id_grupy_studenta == it5->id_grupy)
			{
				if (it2->suma_ects >= (it5->ectsy_w_grupie / 2))
				{
					cout << "Student ma zaliczony semestr" << endl;
					cout << endl;
				}
				else
				{
					cout << "Student NIE zaliczyl" << endl;
					cout << endl;
				}
			}
		}
	}

}

