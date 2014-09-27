#ifndef UCUS_H
#define UCUS_H
#include "mystring.h"
#include <iostream>
using std::ostream;

class Ucus
{
    friend ostream &operator<<(ostream &,Ucus &);
    private:
        const int ucus_numarasi;
        myString kalkis_zamani;
        myString kalkis_yeri;
        myString varis_yeri;
        int normal_koltuk;
        int lux_koltuk;
        Ucus *kodagore_sonraki;
        Ucus *adagore_onceki;
        Ucus *adagore_sonraki;
    public:
        Ucus(int);
        Ucus *kodagore_sonraki_oku();
        Ucus *adagore_sonraki_oku();
        Ucus *adagore_onceki_oku();
        int normal_koltuk_oku();
        void kodagore_sonraki_ayarla(Ucus *);
        void adagore_sonraki_ayarla(Ucus *);
        void adagore_onceki_ayarla(Ucus *);
        int ucusNo_oku();
        char *kalkis_zamani_oku();
        char *varis_yeri_oku();
        int lux_koltuk_oku();
        void normal_koltuk_gir();
        void lux_koltuk_ata();
        void kalkis_zamani_gir();
        void kalkis_yeri_gir();
        void varis_yeri_gir();
        char *kalkis_yeri_oku();
        myString kalkis_yeri_oku2();
        myString kalkis_zamani_oku2();
};

#endif // UCUS_H
