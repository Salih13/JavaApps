#ifndef RANDOM_H                    
#define RANDOM_H

#include "stdio.h"                 // giri� ��k�� k�t�phanemizi ekledik
#include "stdlib.h"                //  tamsay� aritmeti�i, arama, s�ralama gibi i�lemkleri i�in gerekli olan k�t�phanemiz 
#include "time.h"                  // rastgele say� �retimi i�in gerekli k�t�phanelerimizi ekledik

struct RANDOM{                     // Bu yap� ile 
	int bol,topla;
	int (*SayiUret)(struct RANDOM*,int,int);     // fonksiyon g�stercilerini tan�mlad�k
	void (*Yoket)(struct RANDOM*);	
};
typedef struct RANDOM* Random;       // yap�n�n isminde de�i�iklik yapt�k labtaki gibi.

Random RandomOlustur();                   // Metotolar�n imzalar�n� belirttik.
int _SayiUret(Random,int,int);
void _Yoket(Random);

#endif
