/* Kemal Sebzeci
   2312729009
   Veri Yap�lar�
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
        cout << "|************Ana Men�***********|" << endl;
        dashline();
        cout << "|   Yapaca��n�z ��lemi Se�iniz  |" << endl;
        dashline();
        cout << "|    1 - Meyve-Sebze Ekleme     |" << endl;
        dashline();
        cout << "|    2 - Stok Listeleme         |" << endl;
        dashline();
        cout << "|    3 - Meyve-Sebze Sat��      |" << endl;
        dashline();
        cout << "|    4 - Stok Silme             |" << endl;
        dashline();
        cout << "|    5 - Stok D�zenleme         |" << endl;
        dashline();
        cout << "|    6 - Meyve-Sebze Arama      |" << endl;
        dashline();
        cout << "|    7 - ��k��                  |" << endl;
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
                cout << "Programdan ��kt�n�z!" << endl;
				break;
			}
        }
        if(islemSecme!='7'){
        cout << "Ana men�ye d�nmek istiyorsan�z (e), ��kmak istiyorsan�z (h) bas�n�z." << endl;
        menu = getche();
		}
    } while (menu == 'e' || menu == 'E');
    
/* Kemal Sebzeci
   2312729009
   Veri Yap�lar�
   Manav Otomasyonu
*/
    dosyadanYukle();
    return 0;
}

void arama() {
    char aranan[80];
    cout << "Aranacak Meyve-Sebze Ad�n� Giriniz: ";
    cin >> aranan;

    meyveSebze* yedek = head;
    bool bulundu = false;
    while (yedek != NULL) {
        if (strcasecmp(yedek->meyvesebzeAdi, aranan) == 0) {
            cout << "Meyve-Sebzenin Ad�: " << yedek->meyvesebzeAdi << endl;
            cout << "Meyve-Sebzenin Fiyat�: " << yedek->fiyat << endl;
            cout << "Meyve-Sebzenin �uanki Sto�u: " << yedek->gelenKilo << endl;
            cout << "--------------------------------------" << endl;
            bulundu = true;
            break;
        }
        yedek = yedek->link;
    }

    if (!bulundu) {
        cout << "Aranan meyve veya sebze bulunamad�." << endl;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yap�lar�
   Manav Otomasyonu
*/

void stokEkle() {
    char secim;
    int cesit = 0;

    do {
        meyveSebze* yeni = new meyveSebze();
        cout << "Sto�a Girilecek Meyve-Sebzenin Ad�n� Giriniz" << endl;
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
        cout << "Sto�a Girilecek Meyve-Sebzenin Kilosunu Giriniz" << endl;
        cin >> yeni->gelenKilo;
        cout << "Sto�a Girilecek Meyve-Sebzenin 1 Kilosunun Fiyat�n� Giriniz" << endl;
        cin >> yeni->fiyat;
        yeni->kalanKilo = yeni->gelenKilo;
        yeni->link = head;
        head = yeni;
        cesit++;
        cout << "Sto�a Ba�ka Bir Kay�t Yapacak m�s�n�z? (e/h)" << endl;
        secim = getche();
        cout << endl;
        dosyayaKaydet();
    }else{cout << "Stokta Zaten Var!" << endl; break;}
	} while (secim == 'e' || secim == 'E');
	if(cesit!=0){
    cout << cesit << " �e�it Meyve-Sebze Sto�a Girildi.." << endl;}
}

void stokListeleme() {
    meyveSebze* yedek = head;
    int index = 1;

    if (yedek == NULL) {
        cout << "Stok Bulunamad�" << endl;
        return;
    }

    while (yedek != NULL) {
        cout << index++ << ". Meyve-Sebzenin Bilgileri" << endl;
        cout << "Meyve-Sebzenin Ad�: " << yedek->meyvesebzeAdi << endl;
        cout << "Meyve-Sebzenin Fiyat�: " << yedek->fiyat << endl;
        cout << "Meyve-Sebzenin �uanki Sto�u: " << yedek->gelenKilo << endl;
        cout << "--------------------------------------" << endl;
		yedek = yedek->link;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yap�lar�
   Manav Otomasyonu
*/

void meyvesebzeSatis() {
    char meyvesebzeadi[80];
    cout << "Sat�lacak Meyve-Sebzenin Ad�n� Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;
    meyveSebze* once = NULL;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        once = yedek;
        yedek = yedek->link;
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamad�" << endl;
        return;
    }

    cout << "Sat�lacak Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Ad�: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyat�: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin �uanki Sto�u: " << yedek->gelenKilo << endl;
    cout << endl;

    int satis;
    cout << "Ka� Kilo Sat�laca��n� Giriniz: ";
    cin >> satis;
    cout << endl;

    int ucret = 0;

    if (satis > yedek->gelenKilo) {
        cout << "�stenilen kilodan az stok var. T�m stok sat�ld�." << endl;
        ucret = yedek->gelenKilo * yedek->fiyat;
        cout << "Sat�� Tutar�: " << ucret << endl;
        yedek->gelenKilo = 0;
        dosyayaKaydet();
    } else {
        ucret = satis * yedek->fiyat;
        cout << "Sat�� Tutar�: " << ucret << endl;
        yedek->gelenKilo -= satis;
        dosyayaKaydet();
    }

    if (yedek->gelenKilo == 0) {
        cout << "Stok s�f�rland��� i�in �r�n silindi." << endl;
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
   Veri Yap�lar�
   Manav Otomasyonu
*/

void stokSilme() {
    char meyvesebzeadi[80];
    cout << "Silinecek Meyve-Sebzenin Ad�n� Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;
    meyveSebze* once = NULL;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        once = yedek;
        yedek = yedek->link;
        system("cls");
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamad�" << endl;
        return;
    }
    cout << "Silinecek Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Ad�: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyat�: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin �uanki Sto�u: " << yedek->gelenKilo << endl;
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
        cout << "Stok Silme �ptal Edildi" << endl;
    }
}

/* Kemal Sebzeci
   2312729009
   Veri Yap�lar�
   Manav Otomasyonu
*/

void stokDuzenle() {
    char meyvesebzeadi[80];
    cout << "D�zeltilecek Meyve-Sebzenin Ad�n� Giriniz" << endl;
    cin >> meyvesebzeadi;

    meyveSebze* yedek = head;

    while (yedek != NULL && strcasecmp(yedek->meyvesebzeAdi, meyvesebzeadi) != 0) {
        yedek = yedek->link;
        system("cls");
    }

    if (yedek == NULL) {
        cout << "Stok Bulunamad�" << endl;
        return;
    }

    cout << "D�zeltilecek Meyve-Sebzenin Bilgileri" << endl;
    cout << "Meyve-Sebzenin Ad�: " << yedek->meyvesebzeAdi << endl;
    cout << "Meyve-Sebzenin Fiyat�: " << yedek->fiyat << endl;
    cout << "Meyve-Sebzenin �uanki Sto�u: " << yedek->gelenKilo << endl;
    cout << endl;

    char secim;
    cout << "D�zeltilecek Meyve-Sebze Bu mu? (e/h)" << endl;
    secim = getche();
    cout << endl;

    if (secim == 'e' || secim == 'E') {
        cout << "Yeni Meyve-Sebzenin Ad�n� Giriniz" << endl;
        cin >> yedek->meyvesebzeAdi;
        cout << "Yeni Meyve-Sebzenin Kilosunu Giriniz" << endl;
        cin >> yedek->gelenKilo;
        cout << "Yeni Meyve-Sebzenin 1 Kilosunun Fiyat�n� Giriniz" << endl;
        cin >> yedek->fiyat;
        yedek->kalanKilo = yedek->gelenKilo;
        cout << "Stok D�zeltildi" << endl;
        dosyayaKaydet();
    } else {
        cout << "Stok D�zeltme �ptal Edildi" << endl;
    }
}

void dashline() {
    cout << "|-------------------------------|" << endl;
}

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
   Veri Yap�lar�
   Manav Otomasyonu
*/
