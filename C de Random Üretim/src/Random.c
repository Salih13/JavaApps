#include "Random.h"          //  baþlýk dosyamýzý include ettik

Random RandomOlustur()                   // Bu metodu kurucu fonksiyon gibi kullanacaðýz.
{
	Random this;
	this = (Random)malloc(sizeof(struct RANDOM));      // Bellekten yapý kadar yer ayrýldý.
	this->SayiUret=&_SayiUret;                         // Labtaki gibi metotlarý burdaki fonksiyon için kullancaðýmýz için atama iþlemþ yapýyoruz ve fonksiyon
	this->Yoket=&_Yoket;                               // göstercisi kullanmak için.
	this->bol=2;                                       // Rastgele karakter üretmek için 
	this->topla=1;                                     // gerekli alanlar.

	return this;                                       // this referans ý  na alanlar ve fonksiyonlar atayarak bunu döndürüyoruz.
}
int _SayiUret(Random rastgele,int baslangic,int son)      // sayý üretmek fonksiyonu
{
	int simdi,dondur=0;
	time_t now;                                             // saniyeyi tütmak için time_t türünde bir alan ayýrdýk.
	now=time(0);                                           // Burada saniyeyi alýp now deðiskenine atadýk.
	
	simdi=(int)now;                                         // now deðiþkenini cast ettik ve int türünde simdi deðiþkenine atadýk.
	dondur=(simdi/rastgele->bol)%(son-baslangic)+baslangic;    // Burada uzun uzun bir denklem oluþturup sürekli farklý bir sayý üretmesini saðladýk.
	rastgele->bol=dondur*7/son+rastgele->topla;             // sayýyý ürettikten sonra bazý deðiþikler yaptýk farklý olmasý için
	rastgele->topla++;

    return dondur;                                         // Üretiðimiz sayýyý yolluyoruz.          
}
void _Yoket(Random rnd)                                    // Yer ayýrdýðýmýz bölgeleri serbest býrakýyoruz.
{
	if(rnd==NULL)return;                                   // bu kontrol ile eðer bölge bull ise hiçbirþey yapma
	free(rnd);                                             // deðilse olaný serbest býrak ve
	rnd=NULL;                                               // NULL deðeri ata.
} 



