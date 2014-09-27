#include "ucusno_liste.h"
#include <iostream>
#include <string.h>
#include "ucus.h"
#include "mystring.h"


using namespace std;

ucusno_liste::ucusno_liste()
{
    ilk=NULL;
}
void ucusno_liste::kodagore_ekle(Ucus *yeni)//ucus kodu alinir ve ona gore ekleme yapilir
{
    Ucus *gecici, *onceki;

    if(ilk==NULL || yeni->ucusNo_oku() < ilk->ucusNo_oku()){//eklenecek yeri basta olma durumu..
        yeni->kodagore_sonraki_ayarla(ilk);
        ilk=yeni;
    }else{
        onceki=ilk;
        gecici=ilk->kodagore_sonraki_oku();
        while((gecici!=NULL) && gecici->ucusNo_oku() < yeni->ucusNo_oku()){//ucus koduna gore artan sirada listeye eklenir..
            onceki=gecici;
            gecici=gecici->kodagore_sonraki_oku();
        }
        yeni->kodagore_sonraki_ayarla(gecici);
        onceki->kodagore_sonraki_ayarla(yeni);
    }
}
void ucusno_liste::kodagore_cikar(int ucusNO)//ucus kodu alinir ve varsa listeden cikarilir.
{
    Ucus *gecici, *onceki;

    onceki=ilk;
    gecici=ilk->kodagore_sonraki_oku();
    if(ilk->ucusNo_oku()==ucusNO){
        ilk=ilk->kodagore_sonraki_oku();
    }
    else {
        while((gecici!=NULL) && gecici->ucusNo_oku() < ucusNO){
        onceki=gecici;
        gecici=gecici->kodagore_sonraki_oku();
        }
        if(gecici==NULL || gecici->ucusNo_oku() != ucusNO)//ucus yoksa olmadigi belirtilir...
            cout<<"Bu ucus numarasinda bir ucus bulunamamistir !\n";
        else
            onceki->kodagore_sonraki_ayarla(gecici->kodagore_sonraki_oku());//ucus varsa baglar degistirilir...
    }
}
bool ucusno_liste::bos_mu()//listenini bos olup olmadigina bakilir...
{
    return ilk==NULL;
}
void ucusno_liste::lux_koltuk_listele()//Lux koltuk sayisi 0 olmayan ucuslar koda gore artan sirada listelenir..
{
    Ucus *gecici;
    gecici=ilk;
    cout<<endl;
    cout<<"UcusNO    Kalkisyeri    Varisyeri   Kalkis Zamani   Normal Koltuk    Lux Koltuk"<<endl;
    cout<<"-------------------------------------------------------------------------------\n";
    while(gecici!=NULL)
    {
        if(gecici->lux_koltuk_oku() != 0)
            cout<<*gecici<<endl;
        gecici=gecici->kodagore_sonraki_oku();
    }
}
Ucus *ucusno_liste::kodagore_ara(int ucusNO)//Ucus kodu alinarak bu ucus var olup olmadigi kontrol edilir..
{
        Ucus *gecici;
        gecici=ilk;

        while(gecici!=NULL)
        {
            if(gecici->ucusNo_oku() == ucusNO)//ucus varsa iþaretcisi dondorulur..
                return gecici;
            gecici=gecici->kodagore_sonraki_oku();

        }
        return NULL;//yoksa NULL dondurulur..
}
