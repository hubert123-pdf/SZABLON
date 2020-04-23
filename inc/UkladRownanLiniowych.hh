#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include "LZespolona.hh"
#include "rozmiar.h"
#include <iostream>
#include "Macierz.hh"
#include <math.h>
//uklad rownan skladajacy sie z 2 wektorow i jednej macierzy

template<typename STypU,int SWymiarU>
class SUkladRownanLiniowych {
     
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
  SWektor<STypU,SWymiarU>  getwyniki()const
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
  void setMacierz(int kolumna, int wiersz, double wartosc)
  {
    Macierz1.setMac(kolumna,wiersz,wartosc);
  }
  void setWektor(int wiersz, double wartosc)
  {
    Rozwiazanie.setSkladowa(wiersz,wartosc);
  }
  
  
  //funkcja wyznaczajaca niewiadome uklady rownan 
  STypU  ROZWIAZANIE(SUkladRownanLiniowych U);
  //funkcja liczaca bład obliczen
  void Epsilon(); 
};

//przeciazenie nierowiniete poniewaz uzyty zostal konstuktor dla klasy
//std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STypU,STypU2,SWymiarU> &UklRown);

/*operator wyswietlajacy macierz transponowana 
oraz wektor wyrazow wolnych */

template<typename STypU,int SWymiarU>
std::ostream& operator << (std::ostream &Strm, SUkladRownanLiniowych<STypU,SWymiarU> &UklRown)
 {
     Strm<<"Macierz A^T: \n";
     UklRown.getMacierz().Transponowana();
     Strm<<"Wektor wyrazow wolnych: \n";
     Strm<<UklRown.getwyniki()<<std::endl;
 return Strm;
 }
  /*funkcja liczaca wyznaczniki odpowiednich elementow 
  w oparciu o wzory Cramera*/
  template<typename STypU,int SWymiarU>
  double Wyznacznikx1(SUkladRownanLiniowych<STypU,SWymiarU> U);
  template<typename STypU,int SWymiarU>
  double Wyznacznikx2(SUkladRownanLiniowych<STypU,SWymiarU> U);
  template<typename STypU,int SWymiarU>
  double Wyznacznikx3(SUkladRownanLiniowych<STypU,SWymiarU> U);
  

#endif
