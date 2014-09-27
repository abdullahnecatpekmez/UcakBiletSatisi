#include "ucus.h"
#include <iostream>
#include "mystring.h"
#include <string.h>
#include <iomanip>

using std::setw;
using std::ostream;
using namespace std;

Ucus::Ucus(int NO=0):ucus_numarasi(NO)//constructor da il degerler atanir...
{
    lux_koltuk=0;
    adagore_onceki=NULL;
    adagore_sonraki=NULL;
    kodagore_sonraki=NULL;
}
ostream &operator<<(ostream &cikti,Ucus &bir_ucus)// cikti operatoru asiri yuklenir...
{
    cikti<<setw(5)<<bir_ucus.ucusNo_oku()<<setw(13)<<bir_ucus.kalkis_yeri_oku()<<setw(14)<<bir_ucus.varis_yeri_oku()<<setw(13)
    <<bir_ucus.kalkis_zamani_oku()<<setw(14)<<bir_ucus.normal_koltuk_oku()<<setw(15)<<bir_ucus.lux_koltuk_oku()<<endl;
    return cikti;
}
void Ucus::kodagore_sonraki_ayarla(Ucus *yeni)//tek bagli liste icin sonraki ayarlaniyor
{
    kodagore_sonraki=yeni;
}
void Ucus::adagore_sonraki_ayarla(Ucus *yeni)//cift bagli listr icin sonraki ayarlaniyor
{
    adagore_sonraki=yeni;
}
void Ucus::adagore_onceki_ayarla(Ucus *yeni)// cift bagli liste icin onceki ayarlanir
{
    adagore_onceki=yeni;
}
Ucus *Ucus::kodagore_sonraki_oku()//tek bagli listede sonraki elde edilir
{
    return kodagore_sonraki;
}
Ucus *Ucus::adagore_sonraki_oku()//cift bagli listede sonraki elde edilir
{
    return adagore_sonraki;
}
Ucus *Ucus::adagore_onceki_oku()//cift bagli liste icin onceki elde edilir
{
    return adagore_onceki;
}
void Ucus::lux_koltuk_ata()//ucus icin lux koltuk sayisi belirlenir
{
    cout<<"Lux koltuk sayisini giriniz  :";
    cin>>lux_koltuk;
}
int Ucus::lux_koltuk_oku()// ucus icin lux koltuk sayisi elde edilir
{
    return lux_koltuk;
}
void Ucus::normal_koltuk_gir()//ucus icin normal koltuk sayisi belirlenir
{
    cout<<"Normal koltuk sayisini girin :";
    cin>>normal_koltuk;
}
void Ucus::kalkis_zamani_gir()//ucus icin kalkis zamani girilir
{
    char metin[6];

    cout<<"Kalkis zamanini giriniz      :";
    cin>>metin;
    kalkis_zamani.setString(metin);
}
char *Ucus::kalkis_zamani_oku()//ucus icin kalkis zamani okunur (char * tipinde geri doner yazdirma icin)
{
    return kalkis_zamani.stringOku();//myString sýnýfýnýn str uyesine(char *)ulasilir.
}
char *Ucus::kalkis_yeri_oku()//ucus icin kalkis yeri okunur (char * tipinde geri doner yazdirma icin)
{
    return kalkis_yeri.stringOku();//myString sýnýfýnýn str uyesine(char *)ulasilir.
}
char *Ucus::varis_yeri_oku()//ucus icin kalkis yeri okunur (char * tipinde geri doner yazdirma icin)
{
    return varis_yeri.stringOku();//myString sýnýfýnýn str uyesine(char *)ulasilir.
}
int Ucus::ucusNo_oku()//Ucus icin ucus numarasi elde edilir
{
    return ucus_numarasi;
}
void Ucus::kalkis_yeri_gir()//ucus icin kalkis yeri girilir
{
    char metin[21];

    cout<<"Kalkis yerini girin          :";
    cin>>metin;
    strupr(metin);//eklenirken girilen string ne olrsa olsun tum harfleri buyutulur(arama da sorun cikmamasi icin)
    kalkis_yeri.setString(metin);
}
void Ucus::varis_yeri_gir()//ucus icin varis yeri girilir..
{
    char metin[21];
    cout<<"Varis yerini giriniz         :";
    cin>>metin;
    strupr(metin);//eklenirken girilen string ne olrsa olsun tum harfleri buyutulur(arama da sorun cikmamasi icin)
    varis_yeri.setString(metin);
}
int Ucus::normal_koltuk_oku()//ucus icin normal koltuk sayisi elde edilir
{
    return normal_koltuk;
}
myString Ucus::kalkis_yeri_oku2()//Asiri yuklenmis karsilastirma operatorleri icin kalkis yeri(myString sýnýfý olarak)dondurulur
{
    return kalkis_yeri;
}
myString Ucus::kalkis_zamani_oku2()//Asiri yuklenmis karsilastirma operatorleri icin kalkis zamani(myString sýnýfý olarak)dondurulur
{
    return kalkis_zamani;
}
