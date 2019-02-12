#pragma once
#include "pch.h"
#include "Osoba.h"
#include <iostream>
#include <string>
#include <regex>
#include "Ocena.h"
#include <vector>

using namespace std;

class Student:public Osoba
{
	friend class Dziekanat;

	unsigned int id_studenta;
	unsigned int id_grupy_studenta;
	
	unsigned int suma_ects;

	void student_wyswietl();
	bool student_dodaj();
	void student_modyfikuj();
public:
	void virtual test();
	Student() { id_studenta = 0; id_grupy_studenta = 0; suma_ects = 0; };
	~Student() = default;
};