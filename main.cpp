#include <iostream>
#include "mystring.h"
#include "ucus.h"
#include "ucusno_liste.h"
#include "ada_gore_ciftbagli.h"
#include <string.h>
using namespace std;


int main()
{
    myString s1,s2;
    int secim,ucusNO;
    ada_gore_ciftbagli cift_bagli;
    ucusno_liste kodagore_tekbagli;
    Ucus *bir_ucus;
    char girilen_kalkis[20],girilen_varis[20];

    do{//menu
    cout<<"\n-----------------MENU-----------------------------------"<<endl;
    cout<<"1)  Lux koltuk icermeyen yeni bir ucusun eklenmesi     -\n";
    cout<<"2)  Lux koltuk iceren yeni bir ucusun eklenmesi        -\n";
    cout<<"3)  Bir ucusun lux koltuk sayisinin guncellenmesi      -\n";
    cout<<"4)  Bir ucusun iptal edilmesi                          -\n";
    cout<<"5)  Bir ucusun bilgilerinin goruntulenmesi             -\n";
    cout<<"6)  Lux koltuk iceren ucuslarin listelenmesi           -\n";
    cout<<"7)  Bir yere olan ucuslarin bilgilerinin listelenmesi  -\n";
    cout<<"8)  Bir yerden kalkan ucuslarin listelenmesi           -\n";
    cout<<"9)  Bir yerden bir yere olan ucuslarin listelenmesi    -\n";
    cout<<"10) Cikis!                                             -"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Seciminizi giriniz :";
    cin>>secim;
    switch (secim)
    {
        case 1://Lux koltuk olmayan ucus ekleme..
            cout<<"Yeni ucus icin ucus numarasini girin :";
            cin>>ucusNO;
            if((kodagore_tekbagli.kodagore_ara(ucusNO))==NULL){//ucus varsa ekleme yapilmaz(tek bagli liste taranir...)
            bir_ucus = new Ucus(ucusNO);
            bir_ucus->kalkis_yeri_gir();//Ucus bilgileri kullanicidan alinir
            bir_ucus->varis_yeri_gir();
            bir_ucus->kalkis_zamani_gir();
            bir_ucus->normal_koltuk_gir();
            kodagore_tekbagli.kodagore_ekle(bir_ucus);
            cift_bagli.ada_gore_ciftbagli_ekle(bir_ucus);
            }else cout<<"\nBu ucus numarasinda bir ucus zaten bulunmaktadir !\n";//Ucus varsa bulundugu belirtilir..
            break;
        case 2://Lux koltuk olan ucus ekleme...
            cout<<"Yeni ucus icin ucus numarasini girin :";
            cin>>ucusNO;
            if(kodagore_tekbagli.kodagore_ara(ucusNO)==NULL){//ucus varsa ekleme yapilmaz(tek bagli liste taranir...)
            bir_ucus = new Ucus(ucusNO);
            bir_ucus->kalkis_yeri_gir();
            bir_ucus->varis_yeri_gir();
            bir_ucus->kalkis_zamani_gir();
            bir_ucus->normal_koltuk_gir();
            bir_ucus->lux_koltuk_ata();
            kodagore_tekbagli.kodagore_ekle(bir_ucus);
            cift_bagli.ada_gore_ciftbagli_ekle(bir_ucus);
            }else cout<<"\nBu ucus numarasinda bir ucus zaten bulunmaktadir !\n";//Ucus varsa bulundugu belirtilir..
            break;
        case 3://Ucusun Lux koltuk sayisini guncelleme...
            cout<<"\nLux koltuk sayisi guncellenecek ucusun numarasini giriniz :";
            cin>>ucusNO;
            bir_ucus=kodagore_tekbagli.kodagore_ara(ucusNO);//Ucus taranir yoksa bir_ucus NULL olacaktir...
            if(bir_ucus!=NULL){//ucus varsa Lux koltuk sayisi guncellenir...
                cout<<"Yeni ";
                bir_ucus->lux_koltuk_ata();
                cout<<"Gunculleme Basariyla Gerceklestirilmistir"<<endl;
            }
            else cout<<"\nBu kod numarali bir ucus bulunamamistir!"<<endl;//ucus yoksa belirtilir...
            break;
        case 4://Ucus silinmesi
            cout<<"Silinecek ucusun numarasini girin : ";
            cin>>ucusNO;
            if(kodagore_tekbagli.kodagore_ara(ucusNO)!= NULL){//Ucus listede var mi yok mu bakilir..
                cift_bagli.ada_gore_ciftbagli_cikar(ucusNO);//cift baglidan cikarilir..
                kodagore_tekbagli.kodagore_cikar(ucusNO);//tek baglidan cikarilir...
            }else cout<<"\nBu kod numarali bir ucus bulunamamistir!"<<endl;
            break;
        case 5:
            cout<<"\nBilgilerini goruntulemek istediginiz ucusun numarasini giriniz :";
            cin>>ucusNO;
            bir_ucus=kodagore_tekbagli.kodagore_ara(ucusNO);//Ucus tek bagli listede aranir...
             if(bir_ucus!=NULL){
                cout<<endl;
                cout<<"UcusNO    Kalkisyeri    Varisyeri   Kalkis Zamani   Normal Koltuk    Lux Koltuk"<<endl;
                cout<<"-------------------------------------------------------------------------------\n";
                cout<<*bir_ucus;
             }else cout<<"\nBu kod numarali bir ucus bulunamamistir!"<<endl;//Ucus yoksa belirtilir...
             break;
        case 6://Lux koltuk sayisi 0 olmayan ucuslar listelenir
            kodagore_tekbagli.lux_koltuk_listele();
            break;
        case 7://Bir yere olan ucuslarin listelenmesi..
            cout<<"\nBir Varis yeri giriniz :";
            cin>>girilen_varis;
            strupr(girilen_varis);//girilen string ne olursa olsun harfleri buyutulerek arama  yapilir.(her yaziim girilebilir<Buyuk,kucuk>)..
            s1.setString(girilen_varis);
            cift_bagli.bir_yere(s1);//ciftbagli listenin ilgili fonksiyonu cagirilir..
            break;
        case 8://Bir yerden kalkan ucuslarin listelenmesi...
            cout<<"\nBir Kalkis yeri giriniz :";
            cin>>girilen_kalkis;
            strupr(girilen_kalkis);//girilen string ne olursa olsun harfleri buyutulerek arama  yapilir.(her yaziim girilebilir<Buyuk,kucuk>)..
            s1.setString(girilen_kalkis);
            cift_bagli.bir_yerden(s1);//ciftbagli listenin ilgili fonksiyonu cagirilir..
            break;
        case 9://Bir yerden bir yere olan ucuslarin listelenmesi..
            cout<<"\nBir Kalkis yeri giriniz :";
            cin>>girilen_kalkis;
            strupr(girilen_kalkis);//girilen string ne olursa olsun harfleri buyutulerek arama  yapilir.(her yaziim girilebilir<Buyuk,kucuk>)..
            s1.setString(girilen_kalkis);
            cout<<"\nBir Varis yeri giriniz :";
            cin>>girilen_varis;
            strupr(girilen_varis);//girilen string ne olursa olsun harfleri buyutulerek arama  yapilir.(her yaziim girilebilir<Buyuk,kucuk>)..
            s2.setString(girilen_varis);
            cift_bagli.bir_yerden_bir_yere(s1,s2);//ciftbagli listenin ilgili fonksiyonu cagirilir..
            break;
    }

    }while(secim!=10);
    return 0;
}
