#include "RastgeleKarakter.h"        // baþlýk dosyamýzý include ettik

void Ekrana_Yazdir(Random,char*);     // Ekrana yazdýrma metodunun prototipi belirtildi
//void Yazi_Tipi(int*,int*);
//void Ayarlar(int*,int*,int*);      // Buradaki metotlar extra olarak yapýlmýþtý fakat linux yazýlmýþtý windowsta desteklenmedi
//void Yazi_Rengi(int*);

int main()
{
	 
	RastgeleKarakter rnd =RastgeleOlustur();     // Burada new anahtar kelimesi kullanýlamadýðý için RastgeleKarakter içinde bellekte bölge oluþturulup týpký
	Random rastgeleSayi=RandomOlustur();         // kurucu fonksiyon gibi kullanýldý. Ayný þekilde Random içinde ayný þekilde yaptýk

	int adet=0,secim;                            // menü için ve kaç adet karakter üretilmesi için gerekli olan deðiþkenler
	int nitelik1=0,nitelik2=0,nitelik3=34;       // Buradaki deðiþkenler yazý tipi ile ilgili olan kýsým fakat kullanýlömýyor yukarýda bahsetmiþtik

	char baslangic,bitis;                       // 3. menüde gerekli olan hangi karakterler arasýnda üretim saðlanacaðýný belirtmek için gerekli alanlar
	char karakterler[100];                      // karakterleri tutan dizimizi tanýmladýk
	
		

	while(1)                                   // Bu döngü biz menüden çýkýþ seçeneðini seçeceðimiz ana kadar sürekli çalýþacaktýr.
	{
		
		system("cls");                        // Bu komut console ekranýný temizlemeye yarar sonuçlarý daha iyi gözlemlemeye yarar istersek kaldýrabilirizde.
		
	//	printf("\x1b[%d;34m",nitelik1);                    // Extra olarak yaptýðýmýz renk ve yazý tipi ile ilgili ayarlar
	//	printf("\x1b[%d;%dm",nitelik2,nitelik3);

		printf("\n 1-Rastgele Karakter Uret");                    // Burasý bizim menümüzdür.
		printf("\n 2-Rastgele Karakter Dizisi Uret");
		printf("\n 3-Iki Karakter Arasinda Rastgele Uret");
		printf("\n 4-Belirtilen Karakterlerde Rastgele Uret");
	//	printf("\n 5-Ayarlar");
		printf("\n 5-Cikis");
		printf("\n\n Seciminiz :");                                // Kullanýcýdan menüden hangi seçeneði seçtiðini alýp ona göre iþlem yapýyoruz.
		scanf(" %d",&secim);

		switch(secim)                                              // seçime göre iþlem yapacaktýr.
		{
			case 1:
				printf("\n Rastgele Karakter :");                             // Burada 1 adet karakter istiyoruz. RastgeleKarakterin içindeki fonksiyondan.
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,1));   // Ekrana yazdýr metoduyla birlikte parametre olarak RastgeleKaraktre kaynak kodundaki
				getchar();                                                    // Karakte üretme metodunu çaðýrýp ekrana bastýrmayý saðladýk
				getchar();                                                    // Sonucu ekrana bastýkran sonra beklememiz gerekiyordu onun bu kodu kullandýk 1 kere
				break;                                                        // yazýnca kabul etmiyordu 2 kere yazdýk. break komutu iþimizin bittiðini gösteriyor.
			case 2: 
				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");     // Kullanýcýdan kaç adet karakter istediðimizi belirtmesini istiyoruz.
				scanf(" %d",&adet);
			
				printf("\n Rastgele Karakter Dizisi :");
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,adet));  // Burasýda ayný case1 gibi fakat ekrana yazdýrma yaparken karakter dizisi üretmek için gerekli
				getchar();                                                      // olan fonksiyonun adet olark kullanýcýnýn girdiði sayýyý giriyoruz.
				getchar();                                                       // bu komut yine yukarýdaki gibi ayný maksatla kullanýldý.
				break;                                                           // case 2 ile iþimizin bittiðini belirtiyoruz.
			case 3:
				                                                       // burasý belirtilen 2 karakter arasýnda rastgele karakter üremtimi yapacaktýr
				printf(" Baslangic Karakteri Giriniz : ");             // tabi alfabeye göre  yapacaktýr.
				scanf(" %c",&baslangic);		                        // hangi karakterden baþlamak istersin sorusunu yömneltiyoruz kullanýcýya

				printf(" Bitis Karakteri Giriniz : ");
				scanf(" %c",&bitis);                                   // ayný þekilde hangi karaktere kadar rastgele üretim yapýlacaðýný soruyoruz.

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");   // belirtilen aralýkta kaç adet üretilmek istenilidðini soruyoruz.
				scanf(" %d",&adet);

				printf("\n Verilen Iki Karakter Arasi :");              // Ekrana yazdýrma iþleminde yine ayný þekilde RastgeleKarakter yapýsýndaki metodu kullanýyoruz.
				Ekrana_Yazdir(rastgeleSayi,rnd->VerilenIkiKarakter(rnd,baslangic,bitis,adet));   // Burayý RastgeleKarakter yapýsýnda anlatacaðýz.
				getchar();                                                  // bu komut yukarýdaki gibi ayný maksatla kullanýldý
				getchar();
				break;                                                     // case 3 ile iþimiz bittiðini belirtiyoruz.
			case 4:
				printf(" Lutfen Belirtilen Karakterleri Giriniz :");       // Klavyeden istediðimiz karakterleri giriyoruz. Bunu char* yani string tipinde alýyoruz.
				scanf(" %s",karakterler);		

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");   // Kullanýcýnýn belirlediði karakterler arasýndan yine kaç adet üretim yapýlacaðýný
				scanf(" %d",&adet);                                        // kullanýcý belirliyor.
	
				printf("\n Belirtilen Rastgele Karakterler :");
				Ekrana_Yazdir(rastgeleSayi,rnd->BelirtilenKarakterler(rnd,karakterler,adet));  // RastgeleKarakter yapýsýndaki fonksiyon yardýmýyla Ekrana yazdýrýyoruz.
				getchar();                                                 // ekraný bekletiyoruz yukarýdaki maksatla kullandýk
				getchar();
				break;                                                  // case 4 ile iþimizin bittiðini belirtiyoruz.
//			case 6:
//				Ayarlar(&nitelik1,&nitelik2,&nitelik3);                 // Burada ayarlar menüsü vardý fakat windowsta çalýþmadýðýndan dolayý yorum satýeý haline
//				break;                                                  // getiridik biz linuxta yazdýk.
			case 5:
				rnd->YoketRastgele(rnd);                                // Çýkýþ casemizdir. Kullanýdýðýmýz bölgeleri sebest býrakýyoruz.
				return 0;
				break;
			default:
				printf("\nHatali Giris!");
				getchar();                                             // Hatalý bir seçim yaptýðýmýzda burasu çalýþacaktýr.
				getchar();
				break;
		}
	}

}


void Ekrana_Yazdir(Random rastgele,char* yazilacak)          // karakterleri ekrana yazma fonksiyonu
{
	int boyut=0,i;                                           // for döngüsü için ve üretilen karakterlerin kaç adet olduðunu tutmak için gerekli deðiþkenler

		
	for(i=0;i<yazilacak[i]!=NULL;i++)                        // Bu döngü ile üretilen karakterin boyutunu hesaplýyoruz.
	boyut++;


	for(i=0;i<boyut;i++)                                   // Boyut kadar for döngüsü çalýþacak ve tek tek ekrana basacaktýr.
	{
	//	printf("%d", rastgele->SayiUret(rastgele,31,37));
		printf("%c", yazilacak[i]);
		
	}	
//	printf("\x1b[0;34m"); //Eski Renk...	
}

// ****************Bu satýrdan sonrasý ek olarak yazdýk. Yazý rengini,tipini deðiþtirmek için yapmýþtýk
// ************************* fakat linuxta yazdýðýmýz için windowsta desteklenmedi


//void Yazi_Tipi(int* nitelik1,int* nitelik2)
//{	
//	int secim;	
//	
//	system("cls");
//
//	printf("\n 1-Kalin");
//	printf("\n 2-Italic");
//	printf("\n 3 Kalin+Italic");
//	printf("\n 4-Duz");
//	
//	printf("\n\n Seciminiz:");
//	scanf(" %d",&secim);
//
//	switch(secim)
//	{
//		case 1:
//			*nitelik1=0;
//			*nitelik2=1;
//			break;
//		case 2:
//			*nitelik1=0;
//			*nitelik2=3;
//			break;
//		case 3:
//			*nitelik1=1;
//			*nitelik2=3;
//			break;
//		case 4:
//			*nitelik1=0;
//			*nitelik2=0;
//			break;
//		default:
//			return;
//			break;
//			
//	}
//	
//}
//
//void Ayarlar(int* nitelik1,int* nitelik2,int* nitelik3)
//{
//	int secim;	
//	
//	system("cls");
//
//	printf("\n 1-Yazi Tipi");
//	printf("\n 2-Yazi Rengi");
//	printf("\n 3-Sifirla");
//	
//	printf("\n\n Seciminiz:");
//	scanf(" %d",&secim);
//
//	switch(secim)
//	{
//		case 1:
//			Yazi_Tipi(nitelik1,nitelik2);
//			break;
//		case 2:
//			Yazi_Rengi(nitelik3);
//			break;
//		case 3:
//			*nitelik1=0;
//			*nitelik2=0;
//			*nitelik3=34;
//			break;
//	
//		default:
//			return;
//			break;
//			
//	}
//	
//}
//
//void Yazi_Rengi(int* nitelik)
//{
//	int secim;	
//	
//	system("cls");
//
//	printf("\n 1-Kirmizi");
//	printf("\n 2-Yesil");
//	printf("\n 3-Kahverengi");
//	printf("\n 4-Mavi");
//	printf("\n 5-Magenda");
//	printf("\n 6-Cyan");
//	printf("\n 7-Acik Gri");
//	
//	printf("\n\n Seciminiz:");
//	scanf(" %d",&secim);
//	
//	if(secim>=1 && secim<=7)
//		*nitelik=30+secim;
//}
//







