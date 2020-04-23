#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>


/*
  klasa wektor jako podstawa budowy Macierzy
  oraz wektoru wyrazow szukanych i wynikow
 */
 template <typename STyp, int SWymiar>
class SWektor {
  /*
      Wektor jako tablica 3 elementow dobule 
   */

  STyp skladowe[SWymiar];
  public:
  /*
      metody umozliwiające dostęp do danych klasy
   */ 
   void setSkladowa(unsigned int index, STyp wartosc) 
   {
     skladowe[index]=wartosc;
   }  
   STyp getSkladowa(unsigned int index)const
   {return skladowe[index];}
   
};

/*
   operator wczytywania Wektora na strumien wejsciowy 
   kazdemu miejscu w tablicy przypisywana jest wartosc
 */

/*
   operator wypisyania Wektora na strumien wyjsciowy
 */
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek);

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar> &Wek);

//operator dodawania Wektorów
 template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator+(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2);
//operator dodawania Wektorów
 template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator-(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2);
//operator mnożenia Wektorów wektorowo
 template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator*(SWektor<STyp,SWymiar> Wek1,double Wek2);
//operator dodawania Wektorów skalarnie
 template <typename STyp, int SWymiar>
STyp operator*(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2);
//operator dzielenia Wektorów
 template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator/(SWektor<STyp,SWymiar> Wek1,double Wek2);
 template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> iloczynWektorowy( SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar>Wek2);
#endif
