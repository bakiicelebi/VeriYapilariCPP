/**
 * SayilarListesi.cpp
 * Okunan sayılar basamaklara eklendikten sonra işaretçileri düğüm sınıfından oluşturulan bağlı listeye eklendi. Daha sonra ekran çıktısının içeriği yazıldı ve ekranda istenilen fonksiyonlarla çıkış yapınca gerekli olan hafıza serbest bırakma işlemleri için yıkıcı fonksiyon yazıldı.
 * Veri Yapıları 1B
 * 1. Ödev
 * 16.11.2023
 * Abdulbaki Çelebi abdulbaki.celebi@ogr.sakarya.edu.tr
 */
#include "SayilarListesi.hpp"
#include <sstream>
int SayilarListesi::sayiGetir(int sira)
{
    Dugum *gec = ilk;
    int sayac = 0;
    int sonuc = 0;
    for (; gec != nullptr; gec = gec->sonraki)
    {
        if (sira == sayac)
        {
            Basamak *gecici = gec->veri;
            while (gecici != 0)
            {
                sonuc = 10 * sonuc + gecici->veri;
                gecici = gecici->sonraki;
            }
        }
        ++sayac;
    }
    return sonuc;
}

string SayilarListesi::sonUcAdresiGetir(Basamak *gecici)
{
    stringstream ss;
    ss << gecici;
    string adres = ss.str();
    string adresSonUcHane = adres.substr(adres.length() - 3);
    return adresSonUcHane;
}

SayilarListesi::SayilarListesi()
{
    SayilarListesi::ilk = 0;
}

SayilarListesi::~SayilarListesi()
{
    Dugum *gec = ilk;
    while (gec != nullptr)
    {
        Basamak *gecici = gec->veri;
        while (gecici != nullptr)
        {
            Basamak *sil = gecici;
            gecici = gecici->sonraki;
            delete sil;
        }
        Dugum *silGecici = gec;
        gec = gec->sonraki;
        delete silGecici;
        silGecici = nullptr;
    }
    remove("Sayilar.txt");
}
void SayilarListesi::sayilarOku()
{
    ifstream dosya("Sayilar.txt");
    if (!dosya.is_open())
    {
        cout << "Dosya acamadi!" << endl;
    }
    int okunanSayi;
    while (dosya >> okunanSayi)
    {
        Sayi *sayi = new Sayi();
        while (okunanSayi > 0)
        {
            int basamak = okunanSayi % 10;
            sayi->basamakEkle(basamak);
            okunanSayi /= 10;
        }
        sayiEkle(sayi->adresGetir());
        delete sayi;
    }
    dosya.close();
}

void SayilarListesi::sayiEkle(Basamak *adres)
{
    Dugum *yeni = new Dugum(adres);
    if (ilk == 0)
    {
        ilk = yeni;
    }
    else
    {
        Dugum *gec = ilk;
        while (gec->sonraki != 0)
            gec = gec->sonraki;

        gec->sonraki = yeni;
    }
}

void SayilarListesi::basamaklariTersle()
{
    Dugum *gec = ilk;
    for (; gec != nullptr; gec = gec->sonraki)
    {
        Basamak *onceki = nullptr;
        Basamak *gecici = gec->veri;
        Basamak *sonraki = nullptr;
        while (gecici != 0)
        {
            sonraki = gecici->sonraki;
            gecici->sonraki = onceki;
            onceki = gecici;
            gecici = sonraki;
        }
        gec->veri = onceki;
    }
}

void SayilarListesi::tekleriBasaAl()
{
    Dugum *gec = ilk;
    for (; gec != nullptr; gec = gec->sonraki)
    {
        Basamak *gecici = gec->veri;
        Basamak *ciftTutucuBasi = nullptr;
        Basamak *ciftTutucuSonu = nullptr;
        Basamak *tekTutucuBasi = nullptr;
        Basamak *tekTutucuSonu = nullptr;
        int tekSayac = 0;
        int ciftSayac = 0;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            if (gecici->veri % 2 != 0)
            {
                if (tekTutucuBasi == nullptr)
                {
                    tekTutucuBasi = gecici;
                    tekTutucuSonu = gecici;
                }
                else
                {
                    tekTutucuSonu->sonraki = gecici;
                    tekTutucuSonu = tekTutucuSonu->sonraki;
                }
                ++tekSayac;
            }
            else
            {
                if (ciftTutucuBasi == nullptr)
                {
                    ciftTutucuBasi = gecici;
                    ciftTutucuSonu = gecici;
                }
                else
                {
                    ciftTutucuSonu->sonraki = gecici;
                    ciftTutucuSonu = ciftTutucuSonu->sonraki;
                }
                ++ciftSayac;
            }
        }

        if (tekTutucuBasi != 0)
        {
            tekTutucuSonu->sonraki = ciftTutucuBasi;
            ciftTutucuSonu->sonraki = nullptr;
            gec->veri = tekTutucuBasi;
        }
    }
}

void SayilarListesi::buyukSayiCikar()
{
    Dugum *gec = ilk;
    Dugum *buyukDugum = 0;
    int sayac = 0;
    int buyukSayi = -99999999;
    while (gec != 0)
    {
        if (sayiGetir(sayac) > buyukSayi)
        {
            buyukSayi = sayiGetir(sayac);
            buyukDugum = gec;
        }
        gec = gec->sonraki;
        ++sayac;
    }
    Basamak *gecici = buyukDugum->veri;
    while (gecici != 0)
    {
        Basamak *sil = gecici;
        gecici = gecici->sonraki;
        delete sil;
    }
    if (buyukDugum == ilk)
    {
        ilk = buyukDugum->sonraki;
    }
    else
    {
        Dugum *gecis = ilk;
        while (gecis != 0 && gecis->sonraki != buyukDugum)
        {
            gecis = gecis->sonraki;
        }
        if (gecis != 0)
        {
            gecis->sonraki = buyukDugum->sonraki;
        }
    }
    delete buyukDugum;
}

void SayilarListesi::yazdir()
{

    int sira = 0;
    for (Dugum *gec = ilk; gec != nullptr; gec = gec->sonraki)
    {

        cout << "########## ";
        Basamak *gecici = gec->veri;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            cout << " *******";
        }
        cout << endl;
        cout << "#" << gec << "# ";
        gecici = gec->veri;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            cout << " * " << sonUcAdresiGetir(gecici) << " *";
        }
        cout << endl;
        cout << "#--------# ";
        gecici = gec->veri;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            cout << " *******";
        }
        cout << endl;
        cout << "#" << setw(8) << sayiGetir(sira) << "# ";
        gecici = gec->veri;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            cout << " *   " << gecici->veri << " *";
        }
        cout << endl;
        cout << "########## ";
        gecici = gec->veri;
        for (; gecici != nullptr; gecici = gecici->sonraki)
        {
            cout << " *******";
        }
        cout << endl;
        cout << endl;
        ++sira;
    }
}
