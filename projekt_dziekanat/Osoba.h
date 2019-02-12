#pragma once
#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

class Osoba
{
public:
	string imie;
	string nazwisko;
	string pesel;
	virtual void test();
	virtual ~Osoba()=default;
	Osoba() { imie = ""; nazwisko = ""; pesel = ""; };
};