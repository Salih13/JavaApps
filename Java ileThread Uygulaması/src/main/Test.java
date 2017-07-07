
/** *
 * @author Salih Güngör / g140910053@sakarya.edu.tr
 * @since 23.04.2017
 * <p>
 * Bu program bir sayının faktöriyelini hem döngü ile yani seri olarak hem de
 * thread kullanılarak eş zamanlılığı kullanarak daha hızlı hesaplanabildiği
 * ispatlanma amacıyla yazılmıştır.
 * </p>
 */

package main;                                        // Çalıştığımız paketin ismi

import java.io.FileNotFoundException;                // Hata yakalamak için gerekli kütüphane
import java.math.BigInteger;                         // BigUnteger için gerekli kütüphane
import java.util.Scanner;                            // Kullanıcıdan sayı almak için gerekli kütüphane
import java.util.concurrent.ExecutorService;         // çoklu thread için gerekli kütüphaneler
import java.util.concurrent.Executors;                

public class Test {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);   // Kullanıcudan sayı almamız için bu nesneyi oluşturmamız gereklidir
        Test test = new Test();                   // test classımız içinde bazı fonksiyonlara ulaşmamız için bu classtan nesne üretmemiz gerekiyordu.
        Yazdir yazdir = new Yazdir();      // Hesaplanan sonucu ekrana yazmak için Class oluşturdum ve sonucu nesne yardımıyla bu classın
                                           // içinde parametre olarak yollayıp dosyaya yazdırılıyor.
        Sayi sonuc = new Sayi();                // Hesaplanan sayının çarpımı ve orada oluşturulma işlemi için Sayi isimli class oluşturdum.
        sonuc.setSayi(new BigInteger("1"));     // Burada sonuca ilk değer ataması olarak 1 girdik 0 girseydik şayet sonuc hep 0 çıkacaktır.

        int sayi;                // Kullanıcıdan sayı almak için bellekte yer ayırdık.
        int threadSayisi;        // Thread Sayısını tutmak için bellekten yer ayırdık.

        double saniyebas;        // Threadların hesaplandığı anda onların ne kadar sürede işlerini yaptıklarını hesaplamak için
        double saniyeson;        // süreleri tutmamız gerekiyor süre tutma mantığı; ilk alınan nanotime ile son alınan nanotime
        double sure3;            // çıkarıp ne kadar sürede hesaplmadığını bu şekilde bulabiliyoruz.

        System.out.print("Sayi: ");    // Kullanıcıdan sayıyı istiyoruz.
        sayi = input.nextInt();        // Kullanıcı sayıyı giriyor.

        Hesap seriHesap = new Hesap(1, sayi);         // Seri hesaplamayı bulmamız için Hesap türünde bir nesne oluşturuyoruz.
        Thread seriThread = new Thread(seriHesap);    // bu işlemi Thread kullanarak yapacağımız için Thread nesnesi oluşturup parametre olarak hesabun nesnesini veriyoruz.

        Sure sure1 = new Sure(seriThread);   // Süreyi hesaplamak için Süre classından nesne oluşturuyoruz.
        Thread seriSure = new Thread(sure1); // Süreyide yine paralel ve seri için aynı anda hesaplayacağımız için Thread kullanark parametre olarak nesneyş yolluyoruz.

        threadSayisi = test.threadSayisiBelirle(sayi);  // Bu classında en altında Thread sayısını belirlemek için metod oluşturmuştum onu çağırıyorupve thread sayısını hesaplatıyorum.
        int kalan = sayi % threadSayisi;   // sayı thread sayısına tam olarak da bölünemebileceği için modunu alarak onu kullanıyoruz.
        int bas = 1;                       // Faktöriyel 1 den başladığı için ilk bas değişkenine 1 atıyoruz.
        int son = sayi / threadSayisi;     // Girilen sayıyı thread sayısına bölerek 1 den kaça kadar çarpılacağını belirtiyoruz.
        if (kalan != 0) {            // Kalan şayet 0 ise Thread sayısı normal olacaktır ama sayi thread sayısına tam olarak bölünmüyorsa
            threadSayisi++;          // thread sayısı 1 aratacaktır ve kalan kısmıda bu şekilde kontrol etmiş oldum.
        }
        ExecutorService havuz = Executors.newFixedThreadPool(threadSayisi);  // Ne kadar thread oluşturmamız gerektiğini burada belirtiyoruz.

        Sure sure2 = new Sure(havuz);            // paralel için süre hesaplamak için yine serideki gibi sürden nesne oluşturuyoruz.
        Thread paralelSure = new Thread(sure2);  // Bu nesneyi seri ile aynı anda çalışacağı için thread oluşturup parametresinin veriyoruz.

        Hesap hesaplar[] = new Hesap[10000000];     // Hesap classındaki sonuca ulaşmak için bu şekilde yöntem kullandım.
        for (int i = 0; i < threadSayisi; i++) {    // Burada işin ana kısmı belirleniyor. Thread sayısı kadar çalışacak ve oradada sayılar çarpılacaktır.
            hesaplar[i] = new Hesap(bas, son);      // Burada ilk hesaplama başlıyor. 1 den ilk parçaya kadar.
            havuz.execute(hesaplar[i]);             // Thread çalıştırılıyor. Aşağıda kalan thread için bazı kontroller yapılıyor.
            if (i + 2 == threadSayisi && kalan !=0 ) { //Burada ilk iterasyon bittikten sonra hangi sayıların çarpılacağı belirleniyor.
                bas += sayi / (threadSayisi - 1);      // Kalan 0 dan farklı ise çarpılcak sayının başlangıç değeri veriliyor
                son += sayi % (threadSayisi - 1);      // Yine aynı şekilde çarpılacak sayının son değeri veriliyor.
            } else {                                   // ilk kontole girmediği takdirde yani sayı tam olarak bölünüyorsa thread sayısına
                if (kalan == 0) {                      // Kalan =0 demek sayı thread sayısına tam olarak bölünütot demektir.
                    bas += sayi / threadSayisi;        // Çarpılcak sayının baslangıç değerleri veriliyor.
                    son += sayi / threadSayisi;        // Aynı şekilde son değeri veriliyor.
                } else {                               // o koşulda sağlanmaz ise 
                    bas += sayi / (threadSayisi - 1);  // yani demekoluyorki sayı tam olarak thread sayısına bölünmüyor demektir.
                    son += sayi / (threadSayisi - 1);  // Sayılar nereden nereye kadar çarpılacağı belirtiliyor.
                }
            }
        }

        paralelSure.start();    // Paralel hesaplama için süreyi başlatıyoruz.
        havuz.shutdown();       // paralel hesaplama için oluşturulan kanallların işi bittiğinde kapatıyoruz.

        seriThread.start();     // Seri hesaplamayı başlatıyoruz.
        seriSure.start();       // Seri hesaplama için süreyi başlatıyoruz.

        while (!havuz.isTerminated());              // Burada havuz nesnesindeki threadlerin bitmesini bekliyoruz.
        saniyebas = System.nanoTime();              // Burada başlangıç için süresini alıyoruz.
        for (int i = 0; i < threadSayisi; i++) {    // Burada thread sayısı kadar faktöriel için oluştuurlan sayılar çarpıluyor.
            sonuc.setSayi(sonuc.getSayi().multiply(hesaplar[i].getSonuc()));  // Sonuc sayi ile çarpılıp tekrar sayı classındaki sonuca ekleniyor.
        }                                                // bu süre hesabı extra yapılıyor çünkü threadler için zamman harcanıyor onu da extra olarak hesapladım
        saniyeson = System.nanoTime();                   // Aradaki işlem bitince son süreyi alıyoruz.
        sure3 = (saniyeson - saniyebas) / 1000000.0;     // Burada tam olarak hesap boyunca süreyi milisaniye türünden alıyoruz.

        while (seriSure.isAlive());                      // Threadin bitmesini bekliyor.
        System.out.printf("Seri Hesaplama Süresi %.2f ms\n", sure1.getSure());              // Seri süreleri ekrana yazıyoruz.
        System.out.printf("Paralel Hesaplama Süresi %.2f ms\n", (sure2.getSure() + sure3)); // Paralel süreyi ekrana yazıyoruz.

        try {                                                                // Burada hata kontrolunu oluşturuyoruz
            yazdir.dosyayaYazdir("Seri Sonuc: " + seriHesap.getSonuc());     // Seri sonucu dosyaya yazıyoruz.
            yazdir.dosyayaYazdir("Paralel Sonuc: " + sonuc);                 // Paralel sonucu dosyaya yazıyoruz.
        } catch (FileNotFoundException ex) {                                 // Çıkabilecek hata türünü belirleyip.
            System.out.println("Dosyaya yazarken hata oluştu.");             // Hata çıktığında uyarı verecektir.
        }
        System.out.println("Sonuc dosyaya yazildi.");                        // Kullanıcı bilgilendiriliyor.
    }

    int threadSayisiBelirle(int sayi) {    // Thread Sayısını belirlemek için oluşturulan fonksiyondur. Kullanıcının girdiği sayıya göre 
        if (sayi < 10) {                   // thead sayıyı belirlemektedir.
            return 1;              
        } else if (sayi <= 10000) {        // Burada birden fazla kontrol vardır çünkü sayı her farklı durumu için
            return 10;                     // farklı thread sayısı oluşacaktır.
        } else if (sayi <= 1000000) {
            return 100;                    // Thread Sayısı belirleme işleme farklı yöntemler denenerekte yapılabilirdi fakat ben 
        } else {                           // bu şekilde bir çözüm buldum.
            return 1000;
        }
    }
}
