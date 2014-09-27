#ifndef UCUSNO_LISTE_H
#define UCUSNO_LISTE_H
#include "ucus.h"
#include "mystring.h"

class ucusno_liste
{
    private:
        Ucus *ilk;
    public:
        ucusno_liste();
        void kodagore_ekle(Ucus *);
        Ucus *kodagore_ara(int);
        void kodagore_cikar(int);
        bool bos_mu();
        void lux_koltuk_listele();
};

#endif // UCUSNO_LISTE_H
