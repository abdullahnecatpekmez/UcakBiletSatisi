#ifndef MYSTRING_H
#define MYSTRING_H


class myString//String s�n�f� olusturuluyor...
{
    friend bool operator==(char [],const myString &);//== operatoru asiri yukleniyor...
    private:
       char str[21];
    public:
        myString();
        char *stringOku();//geriye s�n�f�n str veri tipi doner...
        void setString(char *);// str uyesine char * tipinde veri atanir...
        bool operator==(const myString &) const;//== operatoru asiri yukleniyor...
        bool operator>(const myString &)const;// > operatoru asiri yukleniyor..
        bool operator<(const myString &)const;//< operatoru asiri yukleniyor...
        bool operator==(const char *)const;//== operatoru asiri yukleniyor...
};

#endif // MYSTRING_H
