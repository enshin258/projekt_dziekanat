#pragma once
#include "pch.h"
#include <iostream>

using namespace std;

template<typename typ_argumentow>
class Warunek
{
public:
	typ_argumentow platnosc;
	Warunek() { platnosc = 0; };
};