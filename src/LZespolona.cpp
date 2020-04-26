#include "LZespolona.hh"
#include<math.h>
#include<iostream>


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;

  return Wynik;
}
/*Relaizuje odejmowanie dwoch liczb zespolonych 
i zwraca ich różnice*/
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*Relaizuje mnożenie dwoch liczb zespolonych 
i zwraca ich iloczyn*/
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im = Skl1.im * Skl2.re + Skl1.re*Skl2.im;
  return Wynik;
}
/*Relaizuje proces wpisywania liczby zespolonej */
std::istream& operator>>(std::istream&tekst,LZespolona &odpowiedz)
{
  char lznak,pznak,i;
  tekst>>lznak>>odpowiedz.re>>odpowiedz.im>>i>>pznak;
  return tekst;
}
/*Relaizuje proces wyświetlania liczby zespolonej */
std::ostream& operator<<(std::ostream&tekst,LZespolona odpowiedz)
{
  tekst<<'('<<odpowiedz.re<<std::showpos<<odpowiedz.im<<std::noshowpos<<"i)";
  return tekst;

}
/*zwraca sprzężoną liczbe zepoloną */
LZespolona Sprzezenie(LZespolona Lz)
{
  LZespolona Wynik;
  Wynik.re=Lz.re;
  Wynik.im=-Lz.im;

return Wynik;
}
/*zwraca kwadrat z modulu liczby zepolonej*/

double modul(LZespolona Lz)
{
  double wynik;
  wynik = (Lz.re*Lz.re)+(Lz.im*Lz.im);
  return wynik;
}
/*Realizuje proces dzielenia liczby
 zespolonej przez liczbe typu double i zwraca ich iloraz*/
LZespolona  operator / (LZespolona  Skl1,double Skl3)
{
  LZespolona wynik;
  wynik.re=Skl1.re/Skl3;
  wynik.im=Skl1.im/Skl3;
  return wynik;
}

