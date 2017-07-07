#include "RastgeleKarakter.h"        // ba�l�k dosyam�z� include ettik

void Ekrana_Yazdir(Random,char*);     // Ekrana yazd�rma metodunun prototipi belirtildi
//void Yazi_Tipi(int*,int*);
//void Ayarlar(int*,int*,int*);      // Buradaki metotlar extra olarak yap�lm��t� fakat linux yaz�lm��t� windowsta desteklenmedi
//void Yazi_Rengi(int*);

int main()
{
	 
	RastgeleKarakter rnd =RastgeleOlustur();     // Burada new anahtar kelimesi kullan�lamad��� i�in RastgeleKarakter i�inde bellekte b�lge olu�turulup t�pk�
	Random rastgeleSayi=RandomOlustur();         // kurucu fonksiyon gibi kullan�ld�. Ayn� �ekilde Random i�inde ayn� �ekilde yapt�k

	int adet=0,secim;                            // men� i�in ve ka� adet karakter �retilmesi i�in gerekli olan de�i�kenler
	int nitelik1=0,nitelik2=0,nitelik3=34;       // Buradaki de�i�kenler yaz� tipi ile ilgili olan k�s�m fakat kullan�l�m�yor yukar�da bahsetmi�tik

	char baslangic,bitis;                       // 3. men�de gerekli olan hangi karakterler aras�nda �retim sa�lanaca��n� belirtmek i�in gerekli alanlar
	char karakterler[100];                      // karakterleri tutan dizimizi tan�mlad�k
	
		

	while(1)                                   // Bu d�ng� biz men�den ��k�� se�ene�ini se�ece�imiz ana kadar s�rekli �al��acakt�r.
	{
		
		system("cls");                        // Bu komut console ekran�n� temizlemeye yarar sonu�lar� daha iyi g�zlemlemeye yarar istersek kald�rabilirizde.
		
	//	printf("\x1b[%d;34m",nitelik1);                    // Extra olarak yapt���m�z renk ve yaz� tipi ile ilgili ayarlar
	//	printf("\x1b[%d;%dm",nitelik2,nitelik3);

		printf("\n 1-Rastgele Karakter Uret");                    // Buras� bizim men�m�zd�r.
		printf("\n 2-Rastgele Karakter Dizisi Uret");
		printf("\n 3-Iki Karakter Arasinda Rastgele Uret");
		printf("\n 4-Belirtilen Karakterlerde Rastgele Uret");
	//	printf("\n 5-Ayarlar");
		printf("\n 5-Cikis");
		printf("\n\n Seciminiz :");                                // Kullan�c�dan men�den hangi se�ene�i se�ti�ini al�p ona g�re i�lem yap�yoruz.
		scanf(" %d",&secim);

		switch(secim)                                              // se�ime g�re i�lem yapacakt�r.
		{
			case 1:
				printf("\n Rastgele Karakter :");                             // Burada 1 adet karakter istiyoruz. RastgeleKarakterin i�indeki fonksiyondan.
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,1));   // Ekrana yazd�r metoduyla birlikte parametre olarak RastgeleKaraktre kaynak kodundaki
				getchar();                                                    // Karakte �retme metodunu �a��r�p ekrana bast�rmay� sa�lad�k
				getchar();                                                    // Sonucu ekrana bast�kran sonra beklememiz gerekiyordu onun bu kodu kulland�k 1 kere
				break;                                                        // yaz�nca kabul etmiyordu 2 kere yazd�k. break komutu i�imizin bitti�ini g�steriyor.
			case 2: 
				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");     // Kullan�c�dan ka� adet karakter istedi�imizi belirtmesini istiyoruz.
				scanf(" %d",&adet);
			
				printf("\n Rastgele Karakter Dizisi :");
				Ekrana_Yazdir(rastgeleSayi,rnd->KarakterDizisiUret(rnd,adet));  // Buras�da ayn� case1 gibi fakat ekrana yazd�rma yaparken karakter dizisi �retmek i�in gerekli
				getchar();                                                      // olan fonksiyonun adet olark kullan�c�n�n girdi�i say�y� giriyoruz.
				getchar();                                                       // bu komut yine yukar�daki gibi ayn� maksatla kullan�ld�.
				break;                                                           // case 2 ile i�imizin bitti�ini belirtiyoruz.
			case 3:
				                                                       // buras� belirtilen 2 karakter aras�nda rastgele karakter �remtimi yapacakt�r
				printf(" Baslangic Karakteri Giriniz : ");             // tabi alfabeye g�re  yapacakt�r.
				scanf(" %c",&baslangic);		                        // hangi karakterden ba�lamak istersin sorusunu y�mneltiyoruz kullan�c�ya

				printf(" Bitis Karakteri Giriniz : ");
				scanf(" %c",&bitis);                                   // ayn� �ekilde hangi karaktere kadar rastgele �retim yap�laca��n� soruyoruz.

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");   // belirtilen aral�kta ka� adet �retilmek istenilid�ini soruyoruz.
				scanf(" %d",&adet);

				printf("\n Verilen Iki Karakter Arasi :");              // Ekrana yazd�rma i�leminde yine ayn� �ekilde RastgeleKarakter yap�s�ndaki metodu kullan�yoruz.
				Ekrana_Yazdir(rastgeleSayi,rnd->VerilenIkiKarakter(rnd,baslangic,bitis,adet));   // Buray� RastgeleKarakter yap�s�nda anlataca��z.
				getchar();                                                  // bu komut yukar�daki gibi ayn� maksatla kullan�ld�
				getchar();
				break;                                                     // case 3 ile i�imiz bitti�ini belirtiyoruz.
			case 4:
				printf(" Lutfen Belirtilen Karakterleri Giriniz :");       // Klavyeden istedi�imiz karakterleri giriyoruz. Bunu char* yani string tipinde al�yoruz.
				scanf(" %s",karakterler);		

				printf(" Lutfen Rastgele Karakter Adedini  Giriniz : ");   // Kullan�c�n�n belirledi�i karakterler aras�ndan yine ka� adet �retim yap�laca��n�
				scanf(" %d",&adet);                                        // kullan�c� belirliyor.
	
				printf("\n Belirtilen Rastgele Karakterler :");
				Ekrana_Yazdir(rastgeleSayi,rnd->BelirtilenKarakterler(rnd,karakterler,adet));  // RastgeleKarakter yap�s�ndaki fonksiyon yard�m�yla Ekrana yazd�r�yoruz.
				getchar();                                                 // ekran� bekletiyoruz yukar�daki maksatla kulland�k
				getchar();
				break;                                                  // case 4 ile i�imizin bitti�ini belirtiyoruz.
//			case 6:
//				Ayarlar(&nitelik1,&nitelik2,&nitelik3);                 // Burada ayarlar men�s� vard� fakat windowsta �al��mad���ndan dolay� yorum sat�e� haline
//				break;                                                  // getiridik biz linuxta yazd�k.
			case 5:
				rnd->YoketRastgele(rnd);                                // ��k�� casemizdir. Kullan�d���m�z b�lgeleri sebest b�rak�yoruz.
				return 0;
				break;
			default:
				printf("\nHatali Giris!");
				getchar();                                             // Hatal� bir se�im yapt���m�zda burasu �al��acakt�r.
				getchar();
				break;
		}
	}

}


void Ekrana_Yazdir(Random rastgele,char* yazilacak)          // karakterleri ekrana yazma fonksiyonu
{
	int boyut=0,i;                                           // for d�ng�s� i�in ve �retilen karakterlerin ka� adet oldu�unu tutmak i�in gerekli de�i�kenler

		
	for(i=0;i<yazilacak[i]!=NULL;i++)                        // Bu d�ng� ile �retilen karakterin boyutunu hesapl�yoruz.
	boyut++;


	for(i=0;i<boyut;i++)                                   // Boyut kadar for d�ng�s� �al��acak ve tek tek ekrana basacakt�r.
	{
	//	printf("%d", rastgele->SayiUret(rastgele,31,37));
		printf("%c", yazilacak[i]);
		
	}	
//	printf("\x1b[0;34m"); //Eski Renk...	
}

// ****************Bu sat�rdan sonras� ek olarak yazd�k. Yaz� rengini,tipini de�i�tirmek i�in yapm��t�k
// ************************* fakat linuxta yazd���m�z i�in windowsta desteklenmedi


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







