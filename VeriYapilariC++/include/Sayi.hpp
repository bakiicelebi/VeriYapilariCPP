/** 
* Sayi.hpp
* Sayi sınıfı için fonksiyon referansları
* Veri Yapıları 1B
* 1. Ödev
* 13.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"

class Sayi
{
private:
    Basamak *ilk;

public:
    Sayi();
    Basamak *adresGetir();
    void basamakEkle(int veri);
    
};

#endif