#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H
#include "Random.h"

#define MAX 500             // kaynak dosyas�nda kullan�ld�

struct RASTGELEKARAKTER
{
	Random super;                      // kal�t�m olmad��� i�in random yap�s�n�a s�per ile ula�u�ld�.
	char KarakterDizisi[52];
	char karakterler[MAX];
	char Dizi[MAX];                         // 2 karakter ara�ndaki karakterklei bu dizi tutuyor
	char (*KarakterUret)(struct RASTGELEKARAKTER*);                             // lab taki gibi fonksiyon g�stericileri tan�mland�.
	char* (*KarakterDizisiUret)(struct RASTGELEKARAKTER*,int);
	char* (*VerilenIkiKarakter)(struct RASTGELEKARAKTER*,char,char,int);
	char* (*BelirtilenKarakterler)(struct RASTGELEKARAKTER*,char*,int);
	void (*YoketRastgele)(struct RASTGELEKARAKTER*);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;     // Yap�n�n ismi de�i�tirildi.

RastgeleKarakter RastgeleOlustur();                                // fonksiyonlar i�in imzalar at�ld�.
char _KarakterUret(const RastgeleKarakter);
char* _KarakterDizisiUret(const RastgeleKarakter,int);
char* _VerilenIkiKarakter(const RastgeleKarakter,char,char,int);
char* _BelirtilenKarakterler(const RastgeleKarakter,char*,int);
void _YoketRastgele(RastgeleKarakter);

#endif
