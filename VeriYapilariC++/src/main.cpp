/** 
* main.cpp
* Ekran çıktısı için yazılması gerekenler yazıldı. Dosya okunmak için yazıldı. Ve menü arayüzü burada oluşturuldu.
* Veri Yapıları 1B
* 1. Ödev
* 17.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <windows.h>
#include "SayilarListesi.hpp"
using namespace std;

void dosyaOlustur();
void dosyaSil();

int main()
{
    dosyaOlustur();
    SayilarListesi sayilar;
    sayilar.sayilarOku();
    while (true)
    {
        sayilar.yazdir();
        cout << "1. Tek Basamaklari Basa Al" << endl;
        cout << "2. Basamaklari Tersle" << endl;
        cout << "3. En Buyuk Cikar" << endl;
        cout << "4. Cikis" << endl;
        int secim;
        cout << "Seciminiz: ";
        cin >> secim;
        if (secim == 1)
        {
            sayilar.tekleriBasaAl();
        }
        else if (secim == 2)
        {
            sayilar.basamaklariTersle();
        }
        else if (secim == 3)
        {
            sayilar.buyukSayiCikar();
        }
        else if (secim == 4)
        {
            break;
        }
        else
        {
            cout << "--HATA !!!! Yanlis Tuslama. Tekrar Tuslayiniz..." << endl;
            Sleep(2300);
        }
    }
    dosyaSil();
    return 0;
}

void dosyaSil()
{
    remove("Sayilar.txt");
}
void dosyaOlustur()
{
    ofstream dosyaYaz("Sayilar.txt");
    if (dosyaYaz.is_open())
    {
        dosyaYaz << 5654 << " " << 453267 << " " << 587 << " " << 2 << " " << 49357148 << " " << 7465 << " " << 975136 << " " << 67 << " " << 812246;
        dosyaYaz.close();
    }
    else
    {
        cout << "Dosya Acilamadi!!!";
    }
}
