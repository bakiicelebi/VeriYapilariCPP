/** 
* SayilarListesi.hpp
* SayilarListesi sınıfı için fonksiyon referansları
* Veri Yapıları 1B
* 1. Ödev
* 16.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include <iomanip>
#include <fstream>
#include "Sayi.hpp"
#include "Dugum.hpp"

class SayilarListesi
{
private:
    Dugum *ilk;
    int sayiGetir(int sira);
    string sonUcAdresiGetir(Basamak *gecici);

public:
    SayilarListesi();
    ~SayilarListesi();

    void basamaklariTersle();
    void tekleriBasaAl();
    void buyukSayiCikar();
    void sayilarOku();
    void sayiEkle(Basamak *adres);
    void yazdir();
};
#endif