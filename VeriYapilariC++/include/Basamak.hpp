/** 
* Basamak.hpp
* Basamak adlı düğüm sınıfı
* Veri Yapıları 1B
* 1. Ödev
* 12.11.2023
* Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
*/
#ifndef Basamak_hpp
#define Basamak_hpp
#include <iostream>

using namespace std;

class Basamak
{
public:
    Basamak *sonraki;
    int veri;
    Basamak(int veri);
};

#endif