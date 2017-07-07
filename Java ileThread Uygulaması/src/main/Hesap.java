
/** *
 * @author Salih Güngör / g140910053@sakarya.edu.tr
 * @since 23.04.2017
 * <p>
 * Bu program bir sayının faktöriyelini hem döngü ile yani seri olarak hem de
 * thread kullanılarak eş zamanlılığı kullanarak daha hızlı hesaplanabildiği
 * ispatlanma amacıyla yazılmıştır.
 * </p>
 */

package main;                                 // Paketimizin adı

import java.math.BigInteger;                  // BigInteger kütüphanesini hesaplanan sonucumuzu tutmak için kullanıyorum.

public class Hesap implements Runnable {      // run fonksiyonunu kullanmamız için Runnable arayüzünü implement ve override ediyoruz.

    private Sayi sonuc = new Sayi();          // Sonucumuzu Sayı classı türünden bir nesnede tutuyoruz.
    private int bas;                          // Hangi sayıdan başlayarak çarpacaktır.
    private int son;                          // Kaça kadar çarpacaktır sorularının cevabı bu satırlardadır.
 
    public Hesap(int bas, int son) {          // Kurucumuz yardımıyla ilk değer ataması yapılıyor.
        this.bas = bas;                       // Test classında girilen değerleri buraya gelip kurucu yardımıyla kullanılıyor.
        this.son = son;                       // İlk değer atamaları yapıldı.
       
        sonuc.setSayi(new BigInteger("1"));   // Sonuc değerine ilk değer olarak 1 atandı 0 atandığı takdirde sonuc heğ 0 çıkacaktır.
    }

    public BigInteger getSonuc() {            // Sayı classında ki sonucu yollamak için Getter metodu oluşturdum.
        return sonuc.getSayi();               // Sayıyı yolluyoruz.
    }

    @Override
    public void run() {                       // override edilen run metodu
        for (int i = bas; i <= son; i++) {    // döngü yardımıyla belirlen aralıkta iterasyon çalışacak ve sayılar çarpılcaktır.
            sonuc.Carp(i);                    // Çarpma işlemini Sayı classında yapmaktayım.
        }
    }

}
