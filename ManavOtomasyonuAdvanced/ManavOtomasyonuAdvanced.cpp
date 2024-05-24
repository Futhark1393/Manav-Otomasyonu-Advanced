/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

struct meyveSebze {
    char meyvesebzeAdi[80];
    int gelenKilo;
    int kalanKilo;
    int fiyat;
    meyveSebze* link;
};

meyveSebze* head = NULL;

void arama();
void stokEkle();
void stokListeleme();
void meyvesebzeSatis();
void stokSilme();
void stokDuzenle();
void dashline();
void dosyadanYukle();
void dosyayaKaydet();

int main() {
    setlocale(LC_ALL, "Turkish");
    char menu;
    dosyadanYukle();
    do {
        system("cls");
        cout << "|************Ana Menü***********|" << endl;
        dashline();
        cout << "|   Yapacaðýnýz Ýþlemi Seçiniz  |" << endl;
        dashline();
        cout << "|    1 - Meyve-Sebze Ekleme     |" << endl;
        dashline();
        cout << "|    2 - Stok Listeleme         |" << endl;
        dashline();
        cout << "|    3 - Meyve-Sebze Satýþ      |" << endl;
        dashline();
        cout << "|    4 - Stok Silme             |" << endl;
        dashline();
        cout << "|    5 - Stok Düzenleme         |" << endl;
        dashline();
        cout << "|    6 - Meyve-Sebze Arama      |" << endl;
        dashline();
        cout << "|    7 - Çýkýþ                  |" << endl;
        cout << "|_______________________________|" << endl;
        char islemSecme;
		islemSecme = getche();
        
        switch (islemSecme) {
            case '1': {
                system("cls");
                stokListeleme();
				stokEkle();
                break;
            }
            case '2': {
            	system("cls");
                stokListeleme();
                break;
            }
            case '3': {
            	system("cls");
            	stokListeleme();
                meyvesebzeSatis();
                break;
            }
            case '4': {
            	system("cls");
            	stokListeleme();
                stokSilme();
                break;
            }
            case '5': {
            	system("cls");
            	stokListeleme();
                stokDuzenle();
                break;
            }
            case '6':{
            	system("cls");
            	arama();
				break;
			}
            case '7':{
            	system("cls");
            	menu = 'h';
                cout << "Programdan Çýktýnýz!" << endl;
				break;
			}
        }
        if(islemSecme!='7'){
        cout << "Ana menüye dönmek istiyorsanýz (e), Çýkmak istiyorsanýz (h) basýnýz." << endl;
        menu = getche();
		}
    } while (menu == 'e' || menu == 'E');
    
/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/
    dosyadanYukle();
    return 0;
}

/*6. Arama Fonksiyonu (“arama”):
 - Kullanıcıdan aranacak meyve veya sebzenin adı istenir.
 - Girilen adı “stok.dat” dosyasında arar ve eğer bulunursa ilgili meyve veya sebzenin bilgilerini ekrana yazdırır.*/

void arama() {
    char aranan[80];
    cout << "Aranacak Meyve-Sebze Adýný Giriniz: ";
    cin >> aranan;

    meyveSebze* yedek = head;
    bool bulundu = false;
    while (yedek != NULL) {
        if (strcasecmp(yedek->meyvesebzeAdi, aranan) == 0) {
            cout << "Meyve-Sebzenin Adý: " << yedek->meyvesebzeAdi << endl;
            cout << "Meyve-Sebzenin Fiyatý: " << yedek->fiyat << endl;
            cout << "Meyve-Sebzenin Þuanki Stoðu: " << yedek->gelenKilo << endl;
            cout << "--------------------------------------" << endl;
            bulundu = true;
            break;
        }
        yedek = yedek->link;
    }

    if (!bulundu) {
        cout << "Aranan meyve veya sebze bulunamadý." << endl;
    }
} 

/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/

/*1. Stok Ekleme (“stokEkle”):
 - Kullanıcıdan meyve veya sebzenin adı, gelen kilosu ve kilosu başına fiyatı istenir.
 - Kullanıcı her bir meyve veya sebze için bu bilgileri girebilir.
 - Girilen bilgiler “stok.dat” adlı bir dosyaya binary formatında kaydedilir.
 - Eklenen her bir meyve veya sebze, bir bağlı listede de saklanır.*/

void stokEkle() {
    char secim;
    int cesit = 0;

    do {
        meyveSebze* yeni = new meyveSebze();
        cout << "Stoða Girilecek Meyve-Sebzenin Adýný Giriniz" << endl;
        cin >> yeni->meyvesebzeAdi;
        meyveSebze* yedek = head;
        bool bulundu = false;
        while (yedek != NULL) {
        if (strcasecmp(yedek->meyvesebzeAdi, yeni->meyvesebzeAdi) == 0) {
            bulundu = true;
            break;
        }
        yedek = yedek->link;
    }
    if(bulundu == false){
        cout << "Stoða Girilecek Meyve-Sebzenin Kilosunu Giriniz" << endl;
        cin >> yeni->gelenKilo;
        cout << "Stoða Girilecek Meyve-Sebzenin 1 Kilosunun Fiyatýný Giriniz" << endl;
        cin >> yeni->fiyat;
        yeni->kalanKilo = yeni->gelenKilo;
        yeni->link = head;
        head = yeni;
        cesit++;
        cout << "Stoða Baþka Bir Kayýt Yapacak mýsýnýz? (e/h)" << endl;
        secim = getche();
        cout << endl;
        dosyayaKaydet();
    }else{cout << "Stokta Zaten Var!" << endl; break;}
	} while (secim == 'e' || secim == 'E');
	if(cesit!=0){
    cout << cesit << " Çeþit Meyve-Sebze Stoða Girildi.." << endl;}
}

/*2. Stok Listeleme (“stokListeleme”):
 - “stok.dat” dosyasından meyve ve sebzelerin bilgileri okunarak ekrana yazdırılır.
 - Her meyve veya sebzenin adı, fiyatı ve mevcut stok durumu (kalan kilo) listelenir.*/

void stokListeleme() {
    meyveSebze* yedek = head;
    int index = 1;

    if (yedek == NULL) {
        cout << "Stok Bulunamadý" << endl;
        return;
    }

    while (yedek != NULL) {
        cout << index++ << ". Meyve-Sebzenin Bilgileri" << endl;
        cout << "Meyve-Sebzenin Adý: " << yedek->meyvesebzeAdi << endl;
        cout << "Meyve-Sebzenin Fiyatý: " << yedek->fiyat << endl;
        cout << "Meyve-Sebzenin Þuanki Stoðu: " << yedek->gelenKilo << endl;
        cout << "--------------------------------------" << endl;
		yedek = yedek->link;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/

/*3. Meyve-Sebze Satış (“meyvesebzeSatis”)”:
 - Kullanıcıdan satılacak meyve veya sebzenin adı ve satılacak kilo miktarı istenir.
 - Girilen adı “stok.dat” dosyasında arar ve ilgili meyve veya sebzenin bilgilerini gösterir.
 - Satış işlemi için uygun stok miktarı kontrol edilir.
 - Satış yapıldıktan sonra kalan stok miktarı güncellenir ve “stok.dat” dosyası üzerinde işlemler yapılır.*/

void meyvesebzeSatis() {
    char meyvesebzeadi[80];
    cout << "Satýlacak Meyve-Sebzenin Adýný Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;
    meyveSebze* once = NULL;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        once = yedek;
        yedek = yedek->link;
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamadý" << endl;
        return;
    }

    cout << "Satýlacak Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Adý: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyatý: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin Þuanki Stoðu: " << yedek->gelenKilo << endl;
    cout << endl;

    int satis;
    cout << "Kaç Kilo Satýlacaðýný Giriniz: ";
    cin >> satis;
    cout << endl;

    int ucret = 0;

    if (satis > yedek->gelenKilo) {
        cout << "Ýstenilen kilodan az stok var. Tüm stok satýldý." << endl;
        ucret = yedek->gelenKilo * yedek->fiyat;
        cout << "Satýþ Tutarý: " << ucret << endl;
        yedek->gelenKilo = 0;
        dosyayaKaydet();
    } else {
        ucret = satis * yedek->fiyat;
        cout << "Satýþ Tutarý: " << ucret << endl;
        yedek->gelenKilo -= satis;
        dosyayaKaydet();
    }

    if (yedek->gelenKilo == 0) {
        cout << "Stok sýfýrlandýðý için ürün silindi." << endl;
        if (once == NULL) {
            head = yedek->link;
        } else {
            once->link = yedek->link;
        }
        delete yedek;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/

/*4. Stok Silme (“stokSilme”):
 - Kullanıcıdan silinecek meyve veya sebzenin adı istenir.
 - Girilen adı “stok.dat” dosyasında arar ve ilgili meyve veya sebzenin bilgilerini gösterir.
 - Kullanıcı onayıyla silme işlemi gerçekleştirilir.
 - Silinen meyve veya sebzenin bilgileri “Yedek.dat” dosyasına aktarılır ve `stok.dat` dosyası üzerinde güncelleme 
yapılır. */

void stokSilme() {
    char meyvesebzeadi[80];
    cout << "Silinecek Meyve-Sebzenin Adýný Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;
    meyveSebze* once = NULL;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        once = yedek;
        yedek = yedek->link;
        system("cls");
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamadý" << endl;
        return;
    }
    cout << "Silinecek Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Adý: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyatý: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin Þuanki Stoðu: " << yedek->gelenKilo << endl;
    cout << endl;

    char secim;
    cout << "Stoktan Silinecek Meyve-Sebze bu mu? (e/h)" << endl;
    secim = getche();
    cout << endl;

    if (secim == 'e' || secim == 'E') {
        if (once == NULL) {
            head = yedek->link;
        } else {
            once->link = yedek->link;
        }
        delete yedek;
        cout << "Stok Silindi" << endl;
        dosyayaKaydet();
    } else {
        cout << "Stok Silme Ýptal Edildi" << endl;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/

/*5. Stok Düzenleme (“stokDuzenle”):
 - Kullanıcıdan düzenlenecek meyve veya sebzenin adı istenir.
 - Girilen adı “stok.dat” dosyasında arar ve ilgili meyve veya sebzenin bilgilerini gösterir.
 - Kullanıcı onayıyla düzenleme işlemi gerçekleştirilir.
 - Yeni bilgiler girilerek meyve veya sebzenin adı, gelen kilosu ve kilosu başına fiyatı güncellenir.*/

void stokDuzenle() {
    char meyvesebzeadi[80];
    cout << "Düzeltilecek Meyve-Sebzenin Adýný Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        yedek = yedek->link;
        system("cls");
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamadý" << endl;
        return;
    }

    cout << "Düzeltilecek Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Adý: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyatý: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin Þuanki Stoðu: " << yedek->gelenKilo << endl;
    cout << endl;

    char secim;
    cout << "Düzeltilecek Meyve-Sebze Bu mu? (e/h)" << endl;
    secim = getche();
    cout << endl;

    if (secim == 'e' || secim == 'E') {
        cout << "Yeni Meyve-Sebzenin Adýný Giriniz" << endl;
        cin >> yedek->meyvesebzeAdi;
        cout << "Yeni Meyve-Sebzenin Kilosunu Giriniz" << endl;
        cin >> yedek->gelenKilo;
        cout << "Yeni Meyve-Sebzenin 1 Kilosunun Fiyatýný Giriniz" << endl;
        cin >> yedek->fiyat;
        yedek->kalanKilo = yedek->gelenKilo;
        cout << "Stok Düzeltildi" << endl;
        dosyayaKaydet();
    } else {
        cout << "Stok Düzeltme Ýptal Edildi" << endl;
    }
}

void dashline() {
    cout << "|-------------------------------|" << endl;
}

// stok.dot dosyasındaki verileri alıp kullanmamıza yarayan fonksiyon

void dosyadanYukle() {
    ifstream file("stok.dat", ios::binary);
    if (!file.is_open()) return;

    while (true) {
        meyveSebze* yeni = new meyveSebze();
        file.read((char*)yeni, sizeof(meyveSebze));
        if (file.eof()) {
            delete yeni;
            break;
        }
        yeni->link = head;
        head = yeni;
    }
    file.close();
}

// stok.dot dosyasına verileri yazmamızı sağlayan fonksiyon

void dosyayaKaydet() {
    ofstream file("stok.dat", ios::binary | ios::trunc);
    meyveSebze* yedek = head;
    while (yedek != NULL) {
        file.write((char*)yedek, sizeof(meyveSebze));
        yedek = yedek->link;
    }
    file.close();
}

/* Kemal Sebzeci
   2312729009
   Veri Yapýlarý
   Manav Otomasyonu
*/
