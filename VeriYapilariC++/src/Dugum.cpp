/** 
* Dugum.cpp
* Düğüm Sınıfının kurucu fonksiyonları atandı. 
* Veri Yapıları 1B
* 1. Ödev
* 12.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(Basamak *veri)
{
    this->veri = veri;
    this->sonraki = nullptr;
}
