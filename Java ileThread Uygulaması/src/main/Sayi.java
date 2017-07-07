
/** *
 * @author Salih Güngör / g140910053@sakarya.edu.tr
 * @since 23.04.2017
 * <p>
 * Bu program bir sayının faktöriyelini hem döngü ile yani seri olarak hem de
 * thread kullanılarak eş zamanlılığı kullanarak daha hızlı hesaplanabildiği
 * ispatlanma amacıyla yazılmıştır.
 * </p>
 */

package main;                                  //Paketimizin adı.

import java.math.BigInteger;                   // BigInteger kütüphanesini hesaplanan sonucumuzu tutmak için kullanıyorum.

public class Sayi {

    private BigInteger sayi;                   // Çarpılan sonuc burada tutuluyor.

    public BigInteger getSayi() {              // Getter metodu hesaplanan sonucu yollmak için kullanıyorum.
        return sayi;                           // Yolama satırı.
    }

    public void setSayi(BigInteger sayi) {     // İlk değer atamasında bu Setter metodu kullanılıyor.
        this.sayi = sayi;                      // atama satırı
    }

    public void Carp(int sayi) {               // Çarpma işlemi burada yapılıyor.
        String s = String.valueOf(sayi);       // çarpılak sayı stringe dönüştürülüp s ye atanıyor.
        BigInteger nesne = new BigInteger(s);  // BigIntegerdan nesne oluşturup 
        this.sayi = this.sayi.multiply(nesne); // o nesneyi burada kullanarak sayi ya yani sonuca yazıyoruz.
    }

    @Override
    public String toString() {                 // toString metodu yardımıyla ekrana nesneyi yazdırsak bile bu metod devreye 
        return "" + sayi;                      // girecektir ve bizim belirlediğimiz şekilde yazacaktır.
    }

}
