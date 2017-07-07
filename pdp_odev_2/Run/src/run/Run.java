/**  *  
 * @author Salih Güngör G140910053 Ömer Kadir Şengül omerkadirsengul123@gmail.com
 * @since Programın yazıldığı tarih  *
 * <p>  
 *  
 * Pdp 2. ödev kendi kodlarımızla rastgele karakter üretimi  *
 * </p>  
 */ 



package run;

import com.RastgeleKarakter;
import java.util.Scanner;


public class Run {

 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
               RastgeleKarakter rastgele = new RastgeleKarakter(); 
               char karakter1; 
               char karakter2;
               int karakterAdedi;
               System.out.println("Rastgele Karakter: " + rastgele.tekKarakterUret());
               System.out.println("Rastgele Karakter: " + rastgele.tekKarakterUret());
               System.out.println("Rastgele Karakter: " + rastgele.ucKarakterUret());
               System.out.println("Rastgele Karakter: " + rastgele.ucKarakterUret());
               System.out.print("1. karakteri giriniz: ");
               karakter1 =input.nextLine().charAt(0);
               System.out.print("2. karakteri giriniz: ");
               karakter2 =input.nextLine().charAt(0);
               System.out.println("Rastgele Karakter: " + rastgele.karakterArasindanUret(karakter1, karakter2));
               System.out.println("Rastgele Karakter: " + rastgele.karakterArasindanUret(karakter1, karakter2));
               System.out.print("Belirtilen karakterlerden kaç adet karakter üretmek istiyorsunuz(a,b,c,d): ");
               karakterAdedi = Integer.parseInt(input.nextLine());
               System.out.println("Belirtilen Karakterler: " + rastgele.belirtilenKarakterlerdenUret(karakterAdedi,'a','b','c','d'));
               System.out.println("Belirtilen Karakterler: " + rastgele.belirtilenKarakterlerdenUret(karakterAdedi+1,'a','b','c','d'));
               System.out.println("Belirtilen Karakterler: " + rastgele.belirtilenKarakterlerdenUret(karakterAdedi,'a','b','c','d'));
    }
    
}
