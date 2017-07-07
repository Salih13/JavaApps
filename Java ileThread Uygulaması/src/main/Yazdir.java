
/** *
 * @author Salih Güngör / g140910053@sakarya.edu.tr
 * @since 23.04.2017
 * <p>
 * Bu program bir sayının faktöriyelini hem döngü ile yani seri olarak hem de
 * thread kullanılarak eş zamanlılığı kullanarak daha hızlı hesaplanabildiği
 * ispatlanma amacıyla yazılmıştır.
 * </p>
 */

package main;                               // Paket adımız.

import java.io.FileNotFoundException;       // Dosyayı yazarken bazı hatalar çıkmasına karşılık
import java.io.FileOutputStream;            // gerekli olan kütüphaneler yazılıyor.
import java.io.PrintWriter;

public class Yazdir {                       // Bu class dosyay sonucumuzu yazmaya yarıyor.
    
     public void dosyayaYazdir(String yazilacak) throws FileNotFoundException {  // Metoda parametre olarak girilen değeri dosyaya yazıyor.
       FileOutputStream dosya = new FileOutputStream("Sonuc.txt", true);   // Dosyamızın ismi

        try (PrintWriter dosyayaYaz = new PrintWriter(dosya)) {
            dosyayaYaz.println(yazilacak);          // Dosyaya yazma satırı.

        }
     
    }
}
