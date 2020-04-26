#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

// klasa macierz skladajaca sie z 3 tablic typu wektor
 template <typename STypM, int SWymiarM>
class SMacierz
 {
   SWektor<STypM,SWymiarM> kolumny[SWymiarM];
  public:
  
  //metody umozliwiające dostęp do danych klasy
  template <typename STyp, int SWymiar>
   SWektor<STyp,SWymiar> getKolumna(int index)
   {
     return kolumny[index];
   }
   STypM getMac(int kolumna, int wiersz)const
   {
     return kolumny[kolumna].getSkladowa(wiersz);
   }
   //Metoda zmieniajaca wartosc macierzy
   void setMac(int kolumna,int wiersz,STypM wartosc) 
  {
    kolumny[wiersz].setSkladowa(kolumna,wartosc);
  }

//funkcja liczaca wyznacznik danej macierzy
    STypM znajdzWyznacznik(); 
    
   
};


template <typename STypM, int SWymiarM>
std::istream& operator >> (std::istream &Strm, SMacierz<STypM,SWymiarM> &Mac)
{
    STypM x;
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
        Strm<<Mac.getMac(j,i)<<' ';
        Strm<<std::endl;
    }
    Strm<<std::endl;
    return Strm;
}
 template <typename STypM, int SWymiarM>
 void Transponowana(const SMacierz<STypM,SWymiarM> &Mac)
 {
    for(int i=0;i<SWymiarM;i++)
    {
        for(int j=0;j<SWymiarM;j++)
        std::cout<<Mac.getMac(i,j)<<' ';
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
 }

 template <typename STypM, int SWymiarM>
STypM SMacierz<STypM,SWymiarM>::znajdzWyznacznik()
{
 STypM det=kolumny[0].getSkladowa(0);
  for(int k=0;k<SWymiarM-1;k++)
  {
    for(int i=k+1;i<SWymiarM;i++)
    {
      for(int j=k+1;j<SWymiarM;j++)
      {
        kolumny[i].setSkladowa(j,kolumny[i].getSkladowa(j)-kolumny[i].getSkladowa(k)/kolumny[k].getSkladowa(k)*kolumny[k].getSkladowa(j));
      }
    }
  }
 
  for(int i=1;i<SWymiarM;i++)
  {
    det=det*kolumny[i].getSkladowa(i);
  }
 
return det;
} 
#endif
