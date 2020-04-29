#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include <math.h>


template<typename STypU,int SWymiarU>
class SUkladRownanLiniowych 
{
     
  SWektor<STypU,SWymiarU> Wyniki; 
  SMacierz<STypU,SWymiarU> Macierz1;
  SWektor<STypU,SWymiarU> Rozwiazanie;

  public:
    //konstruktor klasy
  SUkladRownanLiniowych(SMacierz<STypU,SWymiarU> Macierz2, SWektor<STypU,SWymiarU> Wyniki2)
  {
    Wyniki=Wyniki2;
    Macierz1=Macierz2;
  }
  /*
  funkcje umozliwiajace dostep do odpowiednich elemetnow klasy
  */
  SWektor<STypU,SWymiarU>  getWyniki()const
  {
    return Wyniki;
  }
  SMacierz<STypU,SWymiarU>  getMacierz()const
  {
    return Macierz1;
  }
  SWektor<STypU,SWymiarU>  getRozwiazanie()const
  {
    return Rozwiazanie;
  }
 /*
 funkcje zmieniajce elementy klasy
 */
  void setMacierz(int kolumna, int wiersz, STypU wartosc)
  {
    Macierz1.setMac(kolumna,wiersz,wartosc);
  }
  void setWektor(int wiersz, STypU wartosc)
  {
    Rozwiazanie.setSkladowa(wiersz,wartosc);
  }
  
  
  //funkcja wyznaczajaca niewiadome ukladu rownan i wektor bledu
  SWektor<STypU,SWymiarU>   ROZWIAZANIE();
  void Epsilon(); 
};



template<typename STypU,int SWymiarU>
std::ostream& operator << (std::ostream &Strm, SUkladRownanLiniowych<STypU,SWymiarU> &UklRown)
 {
     Strm<<"Macierz A^T: \n";
     Transponowana(UklRown.getMacierz());
     Strm<<"Wektor wyrazow wolnych: \n";
     Strm<<UklRown.getWyniki()<<std::endl;
 return Strm;
 }
  /*funkcja liczaca wyznaczniki odpowiednich elementow 
  w oparciu o wzory Cramera*/
  template <typename STypU, int SWymiarU>
  SWektor<STypU,SWymiarU>  SUkladRownanLiniowych<STypU,SWymiarU>::ROZWIAZANIE()
 {  
    SMacierz<STypU,SWymiarU> Macierz2;
   for(int i=0;i<SWymiarU;i++)
   {
     Macierz2=Macierz1;
     for(int j=0;j<SWymiarU;j++)
     {
       Macierz2.setMac(j,i,getWyniki().getSkladowa(j)); 
     }
     setWektor(i,znajdzWyznacznik(Macierz2)/znajdzWyznacznik(Macierz1));
   }
   
  return Rozwiazanie;
 }

#endif
