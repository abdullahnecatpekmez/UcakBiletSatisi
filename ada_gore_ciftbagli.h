#ifndef ADA_GORE_CIFTBAGLI_H
#define ADA_GORE_CIFTBAGLI_H

#include "ucus.h"
#include "mystring.h"

class ada_gore_ciftbagli
{
    private:
        Ucus *ilk;
    public:
        ada_gore_ciftbagli();
        void ada_gore_ciftbagli_ekle(Ucus *);
        void ada_gore_ciftbagli_cikar(int);
        void bir_yerden(myString);
        void bir_yerden_bir_yere(myString,myString);
        void bir_yere(myString);
        bool bos_mu();

};

#endif // ADA_GORE_CIFTBAGLI_H
