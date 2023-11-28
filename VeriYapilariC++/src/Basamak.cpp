/** 
* Basamak.cpp
* Basamak sınfının kurucu fonksiyonu kodları yazılarak düğüm sınıfı hazır hale geldi
* Veri Yapıları 1B
* 1. Ödev
* 12.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#include "Basamak.hpp"

Basamak::Basamak(int veri)
{
    this->veri = veri;
    this->sonraki = nullptr;
}
