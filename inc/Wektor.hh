#ifndef WEKTOR_HH
#define WEKTOR_HH
#include <iostream>
#include "rozmiar.h"


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
  STyp operator[](int index)const
  {
    return skladowe[index];
  }
  /*
      metody umozliwiające dostęp do danych klasy oraz zmieniania ich wartosci
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
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek)
{
    STyp x;
    for(int i=0; i<SWymiar;i++)
    {
          Strm>>x;  Wek.setSkladowa(i,x);
    }
    std::cout<<std::endl;
    return Strm;
}
/*
   operator wypisyania Wektora na strumien wyjsciowy
 */

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm,const SWektor<STyp,SWymiar> &Wek)
{
    for(int i=0;i<SWymiar;i++)
    {

        Strm<<Wek[i]<<' ';
    }
    Strm<<std::endl;
    return Strm;
}
#endif
