#include "RastgeleKarakter.h"            // ba�l�k dosyam�z� ekledik

RastgeleKarakter RastgeleOlustur()
{
	RastgeleKarakter this;
	this=(RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));    // Yap� i�in bellekten yer ay�rd�k
	this->super=RandomOlustur();                           // C de kal�t�m olmad� i�in s�per gibi bir referans olu�turup bu �ekilde Random yap�s�na ula�t�k.
	this->KarakterUret=&_KarakterUret;                     // Olu�turdu�umuz metotlar� yap�da kullanmak i�in atama yapt�k ve fonksiyon g�stericisi ile kullanaca��z.
	this->KarakterDizisiUret=&_KarakterDizisiUret;
	this->VerilenIkiKarakter=&_VerilenIkiKarakter;
	this->BelirtilenKarakterler=&_BelirtilenKarakterler;
	this->YoketRastgele=&_YoketRastgele;
	
	int indis = 0;   
        //a-z arasi harfler diziye ataniyor..
        for (char krt = 'a'; krt <= 'z'; krt++) {
            this->KarakterDizisi[indis++] = krt;
        }

        //A-Z arasi harfler diziye ataniyor..
        for (char krt = 'A'; krt <= 'Z'; krt++) {
            this->KarakterDizisi[indis++] = krt;
        }
	
	return this;                                   // this referans �  na alanlar ve fonksiyonlar atayarak bunu d�nd�r�yoruz.
}
char _KarakterUret(const RastgeleKarakter rastgele)        
{															// s�per ile randoma ula��� oradan say� �reten fonksiyonu �a��rd�k ve de�i�kene atad�k.
	int rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,52);    // 0, 52 olmas�n�n nedeni alfabedeki harflerden dolay�
	
	return 	rastgele->KarakterDizisi[rastgeleindis];     // Getirdi�imiz say�y� dizinin indisinde kullan�yoruz. char d�n�yor
}

char* _KarakterDizisiUret(const RastgeleKarakter rastgele,int adet)
{	                                  // Kullan�c�dan istenildi�i adet kadar karakter �retimi yap�lacakt�r.
	if(adet>MAX)                     // define ile MAX 500 yap�p 500 den fazla karakter �retilemeyece�ini belittik.
	adet=MAX-2;                      // 500 den fazla karakter istenildi�i taktirde 2 azalt�p o �ekilde �retim yap�lacakt�r.

	for(int i=0;i<adet;i++)         // adet kadar yukar�daki metot yard�m�yla karakter �retilip diziye atand�.
	{
		rastgele->karakterler[i]=rastgele->KarakterUret(rastgele);
	}
	rastgele->karakterler[adet]='\0';    // dizinin son indisine bo�luk koyuldu ��nk� bu for d�ng�lerimizde ve diziyi sonuna kadar dola�mak iin yard�mc� olacakt�r.
	return rastgele->karakterler;         // String yani char* t�r�nde d�necektir.
	
}
char* _VerilenIkiKarakter(const RastgeleKarakter rastgele,char karakter1,char karakter2,int adet)
{                                // Belirtilen 2 karakter aras�nda �retim yap�lcakt�r.
	char temp;                     // swap i�elmi i�in gerekli                 
	int rastgeleindis;
	int indis=0;

	if(karakter2<karakter1)            // e�er kullanc�� belirtilen karakterleri s�ras�n� yanl�� girerse biz swap i�lemi ile d�zelttik.
	{
		temp=karakter1;
		karakter1=karakter2;           // swap i�lemi
		karakter2=temp;
	}
	

	for(char krt=karakter1;krt<=karakter2;krt++)       // aral�ktaki karakterler diziyte atand�.
	rastgele->Dizi[indis++]=krt;

	for(int i=0;i<adet;i++)                                      // kullan�c�n�n istedi�i kadar �retim yap�lcakt�r.
	{
		rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,indis);     // rastgele karakter i�in indis olu�turuldu rastgele olarak
		rastgele->karakterler[i]=rastgele->Dizi[rastgeleindis];                // rastgele karakter se�ilip diziye at�l�p ensonda yollacakt�r.      
		rastgele->karakterler[i+1]='\0';
	}
	
	return rastgele->karakterler;

}

char* _BelirtilenKarakterler(const RastgeleKarakter rastgele,char* gonderilen,int adet)
{                                                // kullan�c�n girdi�i karakterlerden �retim yapacakt�r.
	int rastgeleindis=0;
	int boyut=0;

	for(int i=0;i<gonderilen[i]!='\0';i++)               // burada kullan�c�n ka� adet karakter girdi�i hesaplan�yor.
	boyut++;	

	for(int i=0;i<adet;i++)                             // kullan�c�n belirti�i kadar �retim yap�lcakt�r.
	{
		rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,boyut);    // burada rastgele say� �retildi.
		rastgele->karakterler[i]=gonderilen[rastgeleindis];              // �reitlen say�y� dizinin indisinde yaz�ld�.       
		rastgele->karakterler[i+1]='\0';                 // dizinin en sonuna bo�luk koyuyorizki diziyi main de sonuna kadar dola�al�m
	}

	return rastgele->karakterler;
}

void _YoketRastgele(RastgeleKarakter rastgele)        // kullan�lan alanlar� serbest b�rak�yoruz.
{
	if(rastgele==NULL) return;
	if(rastgele->super!=NULL)
	rastgele->super->Yoket(rastgele->super); 
	free(rastgele);
	rastgele=NULL;
}







