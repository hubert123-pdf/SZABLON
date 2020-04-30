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
  SWektor<STypM,SWymiarM> operator[](int index)const
  {
    return kolumny[index];
  }
  STypM getMac(int kolumna, int wiersz)const
  {
     return kolumny[kolumna].getSkladowa(wiersz);
  }
  SWektor<STypM,SWymiarM> getWiersz(int index)
  {
    SWektor<STypM,SWymiarM> Wynik;
       for(int i=0;i<SWymiarM;i++)
       {
         Wynik.setSkladowa(i,kolumny[i][index]);
       }
   return Wynik; 
  }

  //Metoda zmieniajaca wartosc macierzy
  void setMac(int kolumna,int wiersz,STypM wartosc) 
  {
    kolumny[wiersz].setSkladowa(kolumna,wartosc);
  }

};

//Ustawienie Macierzy
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
//Wyświetlenie macierzy
template <typename STypM, int SWymiarM>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STypM,SWymiarM> &Mac)
{
    for(int i=0;i<SWymiarM;i++)
    {
        for(int j=0;j<SWymiarM;j++)
        Strm<<Mac[j][i]<<' ';
        Strm<<std::endl;
    }
    Strm<<std::endl;
    return Strm;
}
//Wyświetlenie macierzy transponowanej
template <typename STypM, int SWymiarM>
void Transponowana(const SMacierz<STypM,SWymiarM> &Mac)
 {
    for(int i=0;i<SWymiarM;i++)
    {
        for(int j=0;j<SWymiarM;j++)
        std::cout<<Mac[i][j]<<' ';
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
 }
 
//funkcja licząca wyznacznik macierzy korzystając z algorytmu eliminacji gaussa
template <typename STypM, int SWymiarM>
STypM znajdzWyznacznik(SMacierz<STypM,SWymiarM> Mac)
{
 STypM det=Mac[0][0];
  for(int k=0;k<SWymiarM-1;k++)
  {
    for(int i=k+1;i<SWymiarM;i++)
    {
      for(int j=k+1;j<SWymiarM;j++)
      {
                Mac.setMac(i,j,Mac[j][i]-(Mac[k][i]/Mac[k][k])*Mac[j][k]);
      }
    }
  }
 
  for(int i=1;i<SWymiarM;i++)
  {
    det=det*Mac[i][i];
  }
return det;
} 
#endif
