
/** *
 * @author Salih Güngör / g140910053@sakarya.edu.tr
 * @since 23.04.2017
 * <p>
 * Bu program bir sayının faktöriyelini hem döngü ile yani seri olarak hem de
 * thread kullanılarak eş zamanlılığı kullanarak daha hızlı hesaplanabildiği
 * ispatlanma amacıyla yazılmıştır.
 * </p>
 */

package main;                                   //Paketimizin adı.

import java.util.concurrent.ExecutorService;    // Birden fazla thread kullanacağım için bu kütüphaneyi kullanıyorum.

public class Sure implements Runnable {         // run fonksiyonunu kullanmamız için Runnable arayüzünü implement ve override ediyoruz.
                                                // Burada hem seri için hemde paralel için süre hesaplama yapılıyor.
    private double sure;                        // Hesaplanan süre burada tutulacaktır.
    private double baslangic;                   // başlangıç süre
    private double son;                         // bitis süresi
    private Thread seriIs;                      // Seri için süreyi hesaplanamsı için gerekli alan
    private ExecutorService paralelIs;          // Paralel için süreyi tutmak için gereli alan.
    
    public Sure(ExecutorService paralelIs){     // Kurucu ile paralel iş tanımlanarak ona göre süre tutulacaktır.
        this.paralelIs = paralelIs;             // değer ataması
    }
    
    public Sure(Thread seriIs) {                // Kurucu ile paralel iş tanımlanarak ona göre süre tutulacaktır.
        this.seriIs = seriIs;                   // değer ataması
    }

    public double getSure() {                   // Süreyi yollmak için Getter metodu yazıldı.
        return sure;                            // süre yollanıyor.
    }

    @Override 
    public void run() {                         // run metodu ekrana bu class tütünden bir nesne yazıldığı taktirde buradaki metod çalışacaktır.
        baslangic = System.nanoTime();          // başlangıç süresi
        if(paralelIs == null){                  // bu işlem paralel için yapılmıyorsa else çalışcaktır.
            while (seriIs.isAlive());           // threadin bitmesi bekleniyor.
        }else{                                  // Seri için seri hesaplama burada yapılıyor.
            while (!paralelIs.isTerminated());  // Threadin bitmesi bekleniyor.
        }       
        son = System.nanoTime();                // Son olarak süre alınıypr bittiği taktirde alınıyor.
        sure = (son - baslangic) / 1000000.0;   // Burada süre milisaniyeye çevriliyor.
    }

}
