#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mystring.h"
#include <iostream>

using std::cout;
using std::cin;

myString::myString()
{
}
char* myString::stringOku()//geriye sýnýfýn str veri tipi doner...
{
    return str;
}
void myString::setString(char *metin)// str uyesine char * tipinde veri atanir...
{
    strcpy(str,metin);// strcpy kullanilarak gelen argüman str ye atanir
}
//Operatorler asiri yukleniyor...(strcmp fonksiyonu karsilastirma icin kullanilir..)
bool myString::operator==(const myString &karsilastirilan) const
{
    if(strcmp(str,karsilastirilan.str)==0)
        return true;
    else return false;
}
bool myString::operator>(const myString &karsilastirilan) const
{
    if(strcmp(str,karsilastirilan.str)>0)
        return true;
    else return false;
}
bool myString::operator<(const myString &karsilastirilan) const
{
    if(strcmp(str,karsilastirilan.str)<0)
        return true;
    else return false;
}
bool myString::operator==(const char *girilen) const
{
    if(strcmp(str,girilen)==0)
        return true;
    else return false;
}
bool operator==(char s1[],const myString &str)
{
    if(strcmp(s1,str.str)==0)
        return true;
    else return false;
}
