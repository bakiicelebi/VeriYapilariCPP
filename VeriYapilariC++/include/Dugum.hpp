/** 
* Dugum.hpp
* Düğüm sınıfı
* Veri Yapıları 1B
* 1. Ödev
* 12.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include "Basamak.hpp"


class Dugum
{
public:
    Dugum(Basamak *veri);
    Basamak *veri;
    Dugum *sonraki;
};

#endif