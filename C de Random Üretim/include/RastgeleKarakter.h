#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H
#include "Random.h"

#define MAX 500             // kaynak dosyasýnda kullanýldý

struct RASTGELEKARAKTER
{
	Random super;                      // kalýtým olmadýðý için random yapýsýnýa süper ile ulaþuýldý.
	char KarakterDizisi[52];
	char karakterler[MAX];
	char Dizi[MAX];                         // 2 karakter araýndaki karakterklei bu dizi tutuyor
	char (*KarakterUret)(struct RASTGELEKARAKTER*);                             // lab taki gibi fonksiyon göstericileri tanýmlandý.
	char* (*KarakterDizisiUret)(struct RASTGELEKARAKTER*,int);
	char* (*VerilenIkiKarakter)(struct RASTGELEKARAKTER*,char,char,int);
	char* (*BelirtilenKarakterler)(struct RASTGELEKARAKTER*,char*,int);
	void (*YoketRastgele)(struct RASTGELEKARAKTER*);
};
typedef struct RASTGELEKARAKTER* RastgeleKarakter;     // Yapýnýn ismi deðiþtirildi.

RastgeleKarakter RastgeleOlustur();                                // fonksiyonlar için imzalar atýldý.
char _KarakterUret(const RastgeleKarakter);
char* _KarakterDizisiUret(const RastgeleKarakter,int);
char* _VerilenIkiKarakter(const RastgeleKarakter,char,char,int);
char* _BelirtilenKarakterler(const RastgeleKarakter,char*,int);
void _YoketRastgele(RastgeleKarakter);

#endif
