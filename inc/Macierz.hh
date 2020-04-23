#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

// klasa macierz skladajaca sie z 3 tablic typu wektor
 template <typename STypM, int SWymiarM>
class SMacierz {
   SWektor<STypM,SWymiarM> kolumny[SWymiarM];
  public:
  /*
      metody umozliwiające dostęp do danych klasy
   */ 

  template <typename STyp, int SWymiar>
   SWektor<STyp,SWymiar> getKolumna(int index)
   {
     return kolumny[index];
   }

   double getMac(int kolumna, int wiersz)const
   {
     return kolumny[kolumna].getSkladowa(wiersz);
   }
   void setMac(int kolumna,int wiersz,STypM wartosc) 
  {
    kolumny[kolumna].setSkladowa(wiersz,wartosc);
  }

    STypM znajdzWyznacznik(); //funkcja liczaca wyznacznik danej macierzy
    
   //funkcja wyswietlajaca macierz transonowana
     void Transponowana();
};

/*
   operator wczytywania Macierzy na strumien wejsciowy,
   wczytanie 3 tablic sklaajacych sie z tablic 3 elemetnowych
 */

template <typename STypM, int SWymiarM>
std::istream& operator >> (std::istream &Strm, SMacierz<STypM,SWymiarM> &Mac)
{
    double x;
    for(int i=0;i<SWymiarM;i++)
    {
        for(int j=0;j<SWymiarM;j++)
        {
        Strm>>x;
        Mac.setMac(i,j,x);
        }
    }
    std::cout<<std::endl;
    return Strm;
}

template <typename STypM, int SWymiarM>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STypM,SWymiarM> &Mac)
{
    for(int i=0;i<SWymiarM;i++)
    {
        for(int j=0;j<SWymiarM;j++)
        Strm<<Mac.getMac(i,j)<<' ';
        Strm<<std::endl;
    }
    Strm<<std::endl;
    return Strm;
}
#endif
