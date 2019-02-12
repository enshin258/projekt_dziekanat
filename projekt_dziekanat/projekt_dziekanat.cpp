
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "Dziekanat.h"
#include "Warunek.h"
#include "Student.h"
#include "Osoba.h"
#include "Nauczyciel.h"

/*
Napisz program do obsługi dziekanatu. Musi umożliwiać:

Zarządzanie studentami (wstaw, usuń, edytuj)-ok wraz z walidacja
Zarządzanie nauczycielami (wstaw, usuń, edytuj)-ok wraz z walidacja
Zarządzanie przedmiotami (wstaw, usuń, edytuj)-ok wraz z walidacja
Zarządzanie ocenami (wstaw, usuń, edytuj)-ok wraz z walidacja chyba
Zarządzanie grupami (wstaw, usuń, edytuj)-ok wraz z walidacja

Nauczyciele są powiązani z przedmiotami, które prowadzą-ok
Studenci są powiązani z grupami-ok
Grupy mają przypisane przedmioty w których uczestniczą-ok

Każdy przedmiot posiada ilość punktów ECTS, którą student zdobywa za
zaliczenie-ok
Określenie dla studenta aktualnego statusu (czy zdobył wystarczającą liczbę
punktów ECTS do przejścia na kolejny semestr)-ok

Zapis i odczyt stanu aplikacji (plik/baza danych)-ok

Walidacja danych wejściowych-ok

Wykorzystać dziedziczenie-ok,studenci i nauczyciele dziedzicza po osobie
Wykorzystać kompozycję-ok,w dziekanacie wektory studentow,grup,itd.

Wykorzystać funkcje wirtualne-ok
Wykorzystać szablon klas-ok
Wykorzystać szablon funkcji-ok

Ponadto, zbuduj:

1. Diagram przypadków użycia

2. Diagram klas


Termin oddania: 4.01.2019

struktura w plikach
studenci->imie,nazwisko,pesel,id grupy studenta
przedmioty->ectsy,nazwa
nauczyciele->imie,nazwisko,pesel
grupy->nazwa grupy,przedmioty uczone w grupie
oceny-> id studenta,id przedmiotu,ocena
*/


using namespace std;

template <typename typ1,typename typ2>
typ2 przetarg(typ1 x, typ2 y)
{
	return x * y;
}

int main()
{

	string login;
	string haslo;

	Dziekanat d;
	d.wczytanie_danych_z_plikow();

	cout << "Witaj w E-dziekanacie" << endl;
	cout << "Podaj login i haslo zeby sie zalogowac" << endl;
	cout << "Login: " << endl;
	cin >> login;
	cout << "Haslo: " << endl;
	cin >> haslo;
	if (login == "admin" && haslo == "admin")
	{
		while (1)
		{
			int wybor;
			cout << endl;
			cout << "Zalogowano jako admin.Pelna kontrola nad programem" << endl;
			cout << "1.Obsluga studentów" << endl;
			cout << "2.Obsluga nauczycieli" << endl;
			cout << "3.Obsluga przedmiotów" << endl;
			cout << "4.Obsluga grup" << endl;
			cout << "5.Oblsuga ocen" << endl;
			cout << "6. Dodatkowe opcje" << endl;
			cout << "Kazda inna opcja zakonczy program" << endl;
			cin >> wybor;
			switch (wybor)
			{
				case 1:
				{
					int wybor_2;
					cout << "Wybierz co chcesz zrobic" << endl;
					cout << "1.Wyswietlic wszytkich studentow" << endl;
					cout << "2.Dodac nowego studenta" << endl;
					cout << "3.Edytowac dane studenta" << endl;
					cout << "4.Usunac studenta" << endl;
					cin >> wybor_2;
					switch (wybor_2)
					{
						case 1:
						{
							d.wyswietl_studentow();

							break;
						}
						case 2:
						{
							d.dodaj_studenta();
							break;
						}
						case 3:
						{
							d.modyfikuj_studenta();
							break;
						}
						case 4:
						{
							d.usun_studenta();
							break;
						}
						default:
						{
					
							break;
						}
					}

					break;
				}

				case 2:
				{
					int wybor_3;
					cout << "Wybierz co chcesz zrobic" << endl;
					cout << "1.Wyswietlic wszytkich nauczycieli" << endl;
					cout << "2.Dodac nowego nauczyciela" << endl;
					cout << "3.Edytowac dane nauczyciela" << endl;
					cout << "4.Usunac nauczyciela" << endl;
					cin >> wybor_3;
					switch (wybor_3)
					{
						case 1:
						{
							d.wyswietl_nauczycieli();
							break;
						}
						case 2:
						{
							d.dodaj_nauczyciela();
							break;
						}
						case 3:
						{
							d.modyfikuj_nauczyciela();
							break;
						}
						case 4:
						{
							d.usun_nauczyciela();
							break;
						}
						default:
						{
							break;
						}
					}

					break;
				}
				case 3:
				{
					int wybor_4;
					cout << "Wybierz co chcesz zrobic" << endl;
					cout << "1.Wyswietlic wszytkie przedmioty" << endl;
					cout << "2.Dodac nowy przedmiot" << endl;
					cout << "3.Edytowac przedmiot" << endl;
					cout << "4.Usunac przedmiot" << endl;
					cin >> wybor_4;
					switch (wybor_4)
					{
						case 1:
						{
							d.wyswietl_przedmioty();
							break;
						}
						case 2:
						{
							d.dodaj_przedmiot();
							break;
						}
						case 3:
						{
							d.modyfikuj_przedmiot();
							break;
						}
						case 4:
						{
							d.usun_przedmiot();
							break;
						}
						default:
						{
							break;

						}
					}
					break;
				}
				case 4:
				{

					int wybor_5;
					cout << "Wybierz co chcesz zrobic" << endl;
					cout << "1.Wyswietlic wszytkie grupy" << endl;
					cout << "2.Dodac nowa grupe " << endl;
					cout << "3.Edytowac grupe" << endl;
					cout << "4.Usunac grupe" << endl;
					cin >> wybor_5;
					switch (wybor_5)
					{
						case 1:
						{
							d.wyswietl_grupy();
							break;
						}
						case 2:
						{
							d.dodaj_grupe();
							break;
						}
						case 3:
						{
							d.modyfikuj_grupe();
							break;
						}
						case 4:
						{
							d.usun_grupe();
							break;
						}
						default:
						{
							break;

						}
					}
					break;
				}
				case 5:
				{

					int wybor_6;
					cout << "Wybierz co chcesz zrobic" << endl;
					cout << "1.Wyswietlic wszytkie oceny" << endl;
					cout << "2.Dodac nowa ocene " << endl;
					cout << "3.Edytowac ocene" << endl;
					cout << "4.Usunac ocene" << endl;
					cout << "5. kto zdal" << endl;
					cin >> wybor_6;
					switch (wybor_6)
					{
					case 1:
					{
						d.wyswietl_oceny();
						break;
					}
					case 2:
					{
						d.dodaj_ocene();
						break;
					}
					case 3:
					{
						d.modyfikuj_oceny();
						break;
					}
					case 4:
					{
						d.usun_oceny();
						break;
					}
					case 5:
					{
						d.kto_zdal();
						break;
					}
					default:
					{
						break;

					}
					}
					break;
				}
				case 6:
				{
					int wybor_7;
					cout << "Dostepne opcje" << endl;
					cout << "1.funkcja wirtualna" << endl;
					cout << "2.szablony klas" << endl;
					cout << "3.szablon funkcji" << endl;

					cin >> wybor_7;
					switch (wybor_7)
					{
					case 1:
					{
						Nauczyciel n;
						Student s;
						Osoba *wsk = nullptr;

						cout << "Ustawiam wskaznik osoby na nauczyciela" << endl;
						wsk = &n;
						wsk->test();
						cout << "Przestawiam wskaznik osoby na studenta" << endl;
						wsk= &s;
						wsk->test();
						
						break;

					}
					case 2:
					{
						Warunek<bool> p1;
						Warunek<int> p2;
						p1.platnosc = true;
						p2.platnosc = 500;
						cout << "Czy warunki sa platne?(0->nie, 1->tak): " << p1.platnosc << endl;
						cout << "Cena warunku: " << p2.platnosc << endl;
						break;
					}
					case 3:
					{
						int ilosc = 6;
						float cena = 2140.56;
						cout << "Cena wynagrodzenia dla pracownikow(int): ";
						cout << przetarg<float, int>(cena, ilosc) << endl;
						cout << "Cena wynagrodzenia dla pracownikowy(float): ";
						cout << przetarg <float, float>(cena, ilosc) << endl;
						break;


					}
					default:
						break;
					}
					break;
				}

				default:
				{
					cout << "Zapisywanie zmian w plikach bazy danych..." << endl;
					d.zapis_do_plikow();
					return 0;
				}
				
			}
		}
	}
	return 0;
}
