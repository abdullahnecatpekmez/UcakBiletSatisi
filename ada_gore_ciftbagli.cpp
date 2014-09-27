#include "ada_gore_ciftbagli.h"
#include "ucus.h"
#include "mystring.h"
#include "ucusno_liste.h"
#include <string.h>
#include <iostream>
using namespace std;

ada_gore_ciftbagli::ada_gore_ciftbagli()//il islemler yapiliyor
{
    Ucus *liste_basi;//listebasi dugumu iþaretci seklinde yapilmistir(kolaylik olmasi icin)
    liste_basi=new Ucus(0);
    ilk=liste_basi;
    ilk->adagore_onceki_ayarla(ilk);//dairesel olmasi saglaniyor..
    ilk->adagore_sonraki_ayarla(ilk);//iki bag da dieresel olmustur...
}
void ada_gore_ciftbagli::ada_gore_ciftbagli_ekle(Ucus *yeni)//yeni ucusu kalkis yerine(ayni ise zamanina gore) ekler...
{
    Ucus *gecici;

    gecici=ilk->adagore_sonraki_oku();

    //gecici sona gelip gelmedigi ve kalkis yerinini buyuklugune bakilir esitse kalkis zamani kriteri devreye girer..
    while ((gecici!=ilk && gecici->kalkis_yeri_oku2() < yeni->kalkis_yeri_oku2()) || (gecici->kalkis_yeri_oku2()==yeni->kalkis_yeri_oku2() && gecici->kalkis_zamani_oku2() < yeni->kalkis_zamani_oku2()))
        gecici=gecici->adagore_sonraki_oku();
    //ucus sinifinin fonksiyonlari yardimiyla baglar olusturulur...
    yeni->adagore_sonraki_ayarla(gecici);
    yeni->adagore_onceki_ayarla(gecici->adagore_onceki_oku());
    (gecici->adagore_onceki_oku())->adagore_sonraki_ayarla(yeni);
    gecici->adagore_onceki_ayarla(yeni);
    cout<<"Ucus Basariyla Eklenmistir"<<endl;
}
void ada_gore_ciftbagli::ada_gore_ciftbagli_cikar(int ucusNO)//ucus varsa bu fonksiyon cagirlir(olup olmadýgý cagirilmadan kontrol edilmistir.)
{
    Ucus *gecici;
    gecici=ilk->adagore_sonraki_oku();

    while(gecici!=ilk && (gecici->ucusNo_oku() != ucusNO))
           gecici=gecici->adagore_sonraki_oku();
    //ucus listeden cikarilir.
    (gecici->adagore_onceki_oku())->adagore_sonraki_ayarla(gecici->adagore_sonraki_oku());
    (gecici->adagore_sonraki_oku())->adagore_onceki_ayarla(gecici->adagore_onceki_oku());
    cout<<"Ucus Basariyla Iptal Edilmistir"<<endl;
}
bool ada_gore_ciftbagli::bos_mu()//cift bagli listenin bos olup olmadigi kontrol edilir.
{
    return ilk==ilk->adagore_sonraki_oku();
}
void ada_gore_ciftbagli::bir_yerden(myString kalkis)//kalkis yeri girilene esit olan ucuslar listelenir...
{
    Ucus *gecici;

    gecici=ilk->adagore_sonraki_oku();
    cout<<endl;
    cout<<"UcusNO    Kalkisyeri    Varisyeri   Kalkiszamani   Normal Koltuk     Lux Koltuk"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    while(gecici!=ilk)
    {
        if(gecici->kalkis_yeri_oku()==kalkis)
            cout<<*gecici<<endl;
        gecici=gecici->adagore_sonraki_oku();
    }
}
void ada_gore_ciftbagli::bir_yere(myString varis)//varis yeri girilene esit olan ucuslar listelenir...
{

    Ucus *gecici;

    gecici=ilk->adagore_sonraki_oku();
    cout<<endl;
    cout<<"UcusNO    Kalkisyeri    Varisyeri   Kalkiszamani   Normal Koltuk     Lux Koltuk"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    while(gecici!=ilk)
    {
        if(gecici->varis_yeri_oku()==varis)
            cout<<*gecici<<endl;
        gecici=gecici->adagore_sonraki_oku();
    }

}
void ada_gore_ciftbagli::bir_yerden_bir_yere(myString kalkis,myString varis)//liste tersten dolasilir(saatlerin azalan olmasi icin)
{
    Ucus *gecici;

    gecici=ilk->adagore_onceki_oku();
    cout<<endl;
    cout<<"UcusNO    Kalkisyeri    Varisyeri   Kalkiszamani   Normal Koltuk     Lux Koltuk"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    while(gecici!=ilk)
    {
        if((gecici->kalkis_yeri_oku()==kalkis) && (gecici->varis_yeri_oku()== varis))//hem kalkis hem de varis yeri kontrol edilir..
            cout<<*gecici<<endl;
        gecici=gecici->adagore_onceki_oku();
    }
}
