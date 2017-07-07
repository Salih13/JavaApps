
/**  *  
 * @author Salih Güngör G140910053 Ömer Kadir Şengül omerkadirsengul123@gmail.com
 * @since Programın yazıldığı tarih  *
 * <p>  
 *  
 * Pdp 2. ödev kendi kodlarımızla rastgele karakter üretimi  *
 * </p>  
 */ 

package com;

public class RastgeleKarakter {
   
    char karakterler[] = new char[52];       // Rastgele üretilen karakter için dizi tanımladık 
          public RastgeleKarakter(){               // kurucumuzda diziye asci tablosu yardıyla alfabedeki karakterleri atadık
               int indis=0;                    
               for(char karakter=65;  karakter<=122 ; karakter++){     // char tipi değişkenleri ascii tablosundaki karşığı olarak yazdık
                   if(karakter>90 && karakter<97)          // burası ascii tablosunda büyük ve küçük harfler arasında farklı karakterler
                       continue;                           // olduğu için bir kontrol koyarak o karakterleri için o iterasyonu es geçtik
                   karakterler[indis] = karakter;          // diziye karakter atama satırı
                   indis++;
               }              
           }          
           
          public char tekKarakterUret(){                               // tek karakter üretme fonksiyonu
               int indis;                                              // nanotime ile bilgisayardan bir sayı alıp o sayının yukarıda belirttiğimz
                 indis = (int)System.nanoTime()%karakterler.length;    // dizinin uzunluğuna modunu alarak dizinin indisinin aralığını belirttik
                 if(indis<0)                                           // ve ve bu şekilde dizinin indisi tanımladık.
                     indis = indis*-1;                                 // dizinin indisleri negatif olamayacığından dolayı burada kontrol oluşturup
               return karakterler[indis];                              // indisi negatif üretirse şayet -1 ile çarpıp pozitif olmasını sağladık
           }                                                   // burada döngü oluşturup tekrarda üretebilirdik ama o şekilde döngü hızlı bir şekilde çalışacağından
                                                                // dolayı aynı karakterleri üretme olasılığı oldukça artacaktr.
           
          public String ucKarakterUret(){               // yukarıda ki fonksiyondan yararlanarak yanyana 3 karakter üretmeyi sağladık
               String kelime="";                        // String başlangıç değeri verilmelidir burada.
               kelime = tekKarakterUret()+ "" +tekKarakterUret()+ "" + tekKarakterUret(); // burada ufak bir hile yapıp "" koyup stringe dönüşüm sağladık                    
               return kelime;
           }
           
          public String karakterArasindanUret(char karakter1, char karakter2){  // 2 karakter parametre olarak aldık
                String kelime="";
                char karakter;
                int sayi=0;                           // buradaki sayi aslında bizim indis değerimizdir.
                do{                                  // burada farklı olması açısında ilk fonksiyondaki gibi indis üretimi yapmayıp farklı olması açısından
                    sayi=(int)System.nanoTime()%7;   // döngü kullandım. farklı yöntemleri göstermek açısından
                }while(sayi<=0);                     // sayi 0 dan küçük olduğu takdirde farklı bir indisyani sayi üretecektir
                                                      // burada 7 dememmizin nedeni 7 farklı karakter üretmesidir bunu kullanıcından isteyebilrdik
                                                      // fakat bu şekilde tercih ettik
                do{
                    karakter = tekKarakterUret();     // yukarıdaki fonk çağırarrak karakter üretimi yapptık
                    if((karakter > karakter1 && karakter < karakter2)){ // burada 2 karakter arasında üretim yapmayı sağlamak için koşul koyduk
                      kelime+=karakter;           // buarda karakter değilde kebirden fazla karakterde üretebilidği için bu şekilde yaptık.
                      sayi--;                     // saiyiyı yukarıda 0 olarak belirlemniştir burda bir azlatarak döngüden çıkmasını sağladık.
                    }
                }while(sayi>0);                   // sayii-- satırı sayesinden döngüden çıkacaktır.
                                  
                return kelime;                    // birden fazla karakter üretebileceğinden dolayı String döndürdük.
           }
          public String belirtilenKarakterlerdenUret(int sayi, char ... parametreler){  // ... koymamızın nedeni birden fazla parametre almasını sağlamaktır.
               String kelime="";
               char karakter;
               do{
                    karakter = tekKarakterUret();                 // yukarudaki fonksiyon yardımıyla karakter ürettik
                    for(int i=0; i<parametreler.length; i++)  {   // main fonksiyonunda belirtilen parametre adedince iterasyon oluşturduk
                        if(karakter == parametreler[i]) {      // üretilen karakter parameyre olarak girilen karakterlin içinde mevcut mu olduğunud 
                            kelime += karakter;                // kontorl edecek ve üretim kelime olma ihtimalinden dolayı bu sattırı yazdık.
                            sayi--;                              // sayi bir azaltmamızın nedeni döngüden çıkmasıdır.
                        }
                    }
               }while(sayi>0);                 // sayıyı if bloğunun içinde bir azaltmıştık o bloğa girdiği taktirde döngüden çıkacaktır.
   
               return kelime;
           }
           
}
