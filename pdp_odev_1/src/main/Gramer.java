/**  *  *
 * @author   Salih Güngör  g140910053@sakarya.edu.tr  
 * @since    4.03.2017 
 * <p>  
 *  Verilen ödev istenildiği şekilde hazırdır.
 * </p>  
 */ 
 

package main;
                                        // Gerekli kütüphanelerimizi(namespace) ekledik
import java.io.BufferedReader;          // Tampon bellek özelliği kullanmak için namespacemizi ekledik
import java.io.File;                    // Dosyalama işlemleri için gerekli kütüphane
import java.io.FileNotFoundException;   // Hata fırlatma kütüphanemiz
import java.io.FileReader;              // Dosyadan okumak için gerekli kütüphanemiz
import java.io.IOException;             // Girdi/Çıktı için gerekli kütüphanemiz

public class Gramer {
    public static void main(String[] args) throws FileNotFoundException, IOException  {  // Metot içinde geçerli olacak istisnalarımızı tanımladım.     
        File file = new File("BNF.txt");  
        try{                               // Hata çıkmasına karşılık hata kontrolü için try-catch bloklarını koydum.
        if (!file.exists()) {              // Burada eğer dosya yoksa       
            file.createNewFile();          // Dosyamızı oluşturur.
        }
        }catch(IOException exp){          // Hata yakalama satırımız.
             exp.printStackTrace();       // Burada hata olultuğu takdirde ekrana yazar.
        }
        FileReader fileReader = new FileReader(file);    // Dosyadan okuma için FileReader sınıfından nesne ürettik.
        String line;                                     // Dosyada okuyacağımız satırı line alanına atacağız(aşağıdaki koddaki gibi)
        BufferedReader buffer = new BufferedReader(fileReader);    // Tampon bellek özelliğini kullanmak için BUfferedReader sınfından nesne oluşturduk. 
        int sayac=0;       // Tanımlayıp başlangıç değeri verdiğim değişken nonterminalleri atlamamızda işe yarıyor bu şekilde terminale ulaşabiliyoruz.
        int indis=0;       // Terminal sayısını tutmak için değişkenimizi tanımlayıp başlangıç değeri verdik.
        char Terminaller[]=new char[1000];  // Karakter türünde dizimizi tanımladık.
        while ((line = buffer.readLine()) != null) {   // Bu döngü dosyadaki veri null'dan farklı olduğu sürece çalışacaktır.
            for(int i=0;i<line.length();i++) {   // Bu döndü dosyadaki verinin 0. karakterinden başlayarak son karakterine kadar dolaşmasını sağlıyor.
                if(line.charAt(i)=='[')  // Okunan satır [ eşitse sayacı 1 artıracaktır. Buradaki amaç Non-terminali tespit              
                    sayac++;             // edip non termainallerden kurtulup terminale ulaşmaktır.
                if(sayac==1 && line.charAt(i)!=']')   // Non-terminalin tespit edilip onunile işimizi bitirip o iterasyondan
                    continue;                         // kurtularak diğer non-terminallerdenyine aynı şekilde işimizi bitirip
                else sayac=0;                         // terminal arama işlemini yapacağız. sayac=0 olması diğer bir nonterminale geçip dolayısıyla ondan kurtulmayı sağlıyor.
                if(line.charAt(i)!='|' && line.charAt(i)!=':' && line.charAt(i)!='=' && line.charAt(i)!=' ' && line.charAt(i)!=']') {
                    Terminaller[indis] = line.charAt(i);        // Okunulan satır belirtilen karakterlerden farklı ise terminal olduğu anlaşılıyor ve dizimize atılıyor.
                    indis++;                          //indis değeri 1 artırılarak bir sonraki terminal için yer açılıyor.
                }
            }           
        }
        buffer.close();       // Dosyadan okuma işlemini kapattık. 
        System.out.println("Toplam Termminal: " + indis);    // Terminal sayısını ekrana bastık.
        System.out.println("Terminaller : ");
        for(int i=0;i<indis;i++)                     // Döngü ile bütün terminallerimizi ekrana bastık aynı şekilde.
            System.out.println(Terminaller[i]);
    }  
}
