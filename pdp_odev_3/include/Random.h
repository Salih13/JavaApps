#ifndef RANDOM_H                    
#define RANDOM_H

#include "stdio.h"                 // giriþ çýkýþ kütüphanemizi ekledik
#include "stdlib.h"                //  tamsayý aritmetiði, arama, sýralama gibi iþlemkleri için gerekli olan kütüphanemiz 
#include "time.h"                  // rastgele sayý üretimi için gerekli kütüphanelerimizi ekledik

struct RANDOM{                     // Bu yapý ile 
	int bol,topla;
	int (*SayiUret)(struct RANDOM*,int,int);     // fonksiyon göstercilerini tanýmladýk
	void (*Yoket)(struct RANDOM*);	
};
typedef struct RANDOM* Random;       // yapýnýn isminde deðiþiklik yaptýk labtaki gibi.

Random RandomOlustur();                   // Metotolarýn imzalarýný belirttik.
int _SayiUret(Random,int,int);
void _Yoket(Random);

#endif
