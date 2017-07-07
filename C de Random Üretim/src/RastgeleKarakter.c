#include "RastgeleKarakter.h"            // baþlýk dosyamýzý ekledik

RastgeleKarakter RastgeleOlustur()
{
	RastgeleKarakter this;
	this=(RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));    // Yapý için bellekten yer ayýrdýk
	this->super=RandomOlustur();                           // C de kalýtým olmadý için süper gibi bir referans oluþturup bu þekilde Random yapýsýna ulaþtýk.
	this->KarakterUret=&_KarakterUret;                     // Oluþturduðumuz metotlarý yapýda kullanmak için atama yaptýk ve fonksiyon göstericisi ile kullanacaðýz.
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
	
	return this;                                   // this referans ý  na alanlar ve fonksiyonlar atayarak bunu döndürüyoruz.
}
char _KarakterUret(const RastgeleKarakter rastgele)        
{															// süper ile randoma ulaþýý oradan sayý üreten fonksiyonu çaðýrdýk ve deðiþkene atadýk.
	int rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,52);    // 0, 52 olmasýnýn nedeni alfabedeki harflerden dolayý
	
	return 	rastgele->KarakterDizisi[rastgeleindis];     // Getirdiðimiz sayýyý dizinin indisinde kullanýyoruz. char dönüyor
}

char* _KarakterDizisiUret(const RastgeleKarakter rastgele,int adet)
{	                                  // Kullanýcýdan istenildiði adet kadar karakter üretimi yapýlacaktýr.
	if(adet>MAX)                     // define ile MAX 500 yapýp 500 den fazla karakter üretilemeyeceðini belittik.
	adet=MAX-2;                      // 500 den fazla karakter istenildiði taktirde 2 azaltýp o þekilde üretim yapýlacaktýr.

	for(int i=0;i<adet;i++)         // adet kadar yukarýdaki metot yardýmýyla karakter üretilip diziye atandý.
	{
		rastgele->karakterler[i]=rastgele->KarakterUret(rastgele);
	}
	rastgele->karakterler[adet]='\0';    // dizinin son indisine boþluk koyuldu çünkü bu for döngülerimizde ve diziyi sonuna kadar dolaþmak iin yardýmcý olacaktýr.
	return rastgele->karakterler;         // String yani char* türünde dönecektir.
	
}
char* _VerilenIkiKarakter(const RastgeleKarakter rastgele,char karakter1,char karakter2,int adet)
{                                // Belirtilen 2 karakter arasýnda üretim yapýlcaktýr.
	char temp;                     // swap iþelmi için gerekli                 
	int rastgeleindis;
	int indis=0;

	if(karakter2<karakter1)            // eðer kullancýý belirtilen karakterleri sýrasýný yanlýþ girerse biz swap iþlemi ile düzelttik.
	{
		temp=karakter1;
		karakter1=karakter2;           // swap iþlemi
		karakter2=temp;
	}
	

	for(char krt=karakter1;krt<=karakter2;krt++)       // aralýktaki karakterler diziyte atandý.
	rastgele->Dizi[indis++]=krt;

	for(int i=0;i<adet;i++)                                      // kullanýcýnýn istediði kadar üretim yapýlcaktýr.
	{
		rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,indis);     // rastgele karakter için indis oluþturuldu rastgele olarak
		rastgele->karakterler[i]=rastgele->Dizi[rastgeleindis];                // rastgele karakter seçilip diziye atýlýp ensonda yollacaktýr.      
		rastgele->karakterler[i+1]='\0';
	}
	
	return rastgele->karakterler;

}

char* _BelirtilenKarakterler(const RastgeleKarakter rastgele,char* gonderilen,int adet)
{                                                // kullanýcýn girdiði karakterlerden üretim yapacaktýr.
	int rastgeleindis=0;
	int boyut=0;

	for(int i=0;i<gonderilen[i]!='\0';i++)               // burada kullanýcýn kaç adet karakter girdiði hesaplanýyor.
	boyut++;	

	for(int i=0;i<adet;i++)                             // kullanýcýn belirtiði kadar üretim yapýlcaktýr.
	{
		rastgeleindis=rastgele->super->SayiUret(rastgele->super,0,boyut);    // burada rastgele sayý üretildi.
		rastgele->karakterler[i]=gonderilen[rastgeleindis];              // üreitlen sayýyý dizinin indisinde yazýldý.       
		rastgele->karakterler[i+1]='\0';                 // dizinin en sonuna boþluk koyuyorizki diziyi main de sonuna kadar dolaþalým
	}

	return rastgele->karakterler;
}

void _YoketRastgele(RastgeleKarakter rastgele)        // kullanýlan alanlarý serbest býrakýyoruz.
{
	if(rastgele==NULL) return;
	if(rastgele->super!=NULL)
	rastgele->super->Yoket(rastgele->super); 
	free(rastgele);
	rastgele=NULL;
}







