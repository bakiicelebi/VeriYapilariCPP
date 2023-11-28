/**
 * Sayi.cpp
 * Sayi sınıfından oluşturulacak nesneler için ilk değişkeni atandı ve adresi gerektiği yere götüren fonksiyon yazıldı. basamakEkle Fonksiyonuna gelen veriyi basamak düğümlerine yerleştirerek bağlı liste oluşturuldu.
 * Veri Yapıları 1B
 * 1. Ödev
 * 15.11.2023
 * Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
 */
#include "Sayi.hpp"

Sayi::Sayi()
{
    ilk = 0;
}

Basamak *Sayi::adresGetir()
{
    return Sayi::ilk;
}

void Sayi::basamakEkle(int veri)
{
    Basamak *yeni = new Basamak(veri);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Basamak *gec = ilk;
        yeni->sonraki = gec;
        ilk = yeni;
    }
}