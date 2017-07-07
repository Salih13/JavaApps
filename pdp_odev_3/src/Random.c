#include "Random.h"          //  ba�l�k dosyam�z� include ettik

Random RandomOlustur()                   // Bu metodu kurucu fonksiyon gibi kullanaca��z.
{
	Random this;
	this = (Random)malloc(sizeof(struct RANDOM));      // Bellekten yap� kadar yer ayr�ld�.
	this->SayiUret=&_SayiUret;                         // Labtaki gibi metotlar� burdaki fonksiyon i�in kullanca��m�z i�in atama i�lem� yap�yoruz ve fonksiyon
	this->Yoket=&_Yoket;                               // g�stercisi kullanmak i�in.
	this->bol=2;                                       // Rastgele karakter �retmek i�in 
	this->topla=1;                                     // gerekli alanlar.

	return this;                                       // this referans �  na alanlar ve fonksiyonlar atayarak bunu d�nd�r�yoruz.
}
int _SayiUret(Random rastgele,int baslangic,int son)      // say� �retmek fonksiyonu
{
	int simdi,dondur=0;
	time_t now;                                             // saniyeyi t�tmak i�in time_t t�r�nde bir alan ay�rd�k.
	now=time(0);                                           // Burada saniyeyi al�p now de�iskenine atad�k.
	
	simdi=(int)now;                                         // now de�i�kenini cast ettik ve int t�r�nde simdi de�i�kenine atad�k.
	dondur=(simdi/rastgele->bol)%(son-baslangic)+baslangic;    // Burada uzun uzun bir denklem olu�turup s�rekli farkl� bir say� �retmesini sa�lad�k.
	rastgele->bol=dondur*7/son+rastgele->topla;             // say�y� �rettikten sonra baz� de�i�ikler yapt�k farkl� olmas� i�in
	rastgele->topla++;

    return dondur;                                         // �reti�imiz say�y� yolluyoruz.          
}
void _Yoket(Random rnd)                                    // Yer ay�rd���m�z b�lgeleri serbest b�rak�yoruz.
{
	if(rnd==NULL)return;                                   // bu kontrol ile e�er b�lge bull ise hi�bir�ey yapma
	free(rnd);                                             // de�ilse olan� serbest b�rak ve
	rnd=NULL;                                               // NULL de�eri ata.
} 



