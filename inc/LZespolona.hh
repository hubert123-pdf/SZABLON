#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator %(LZespolona Skle1,LZespolona Skl2);
std::istream& operator>>(std::istream&tekst,LZespolona &odpowiedz);
std::ostream& operator<<(std::ostream&tekst,LZespolona odpowiedz);
bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona Sprzezenie(LZespolona Lz);
double modul(LZespolona Lz);
LZespolona  operator / (LZespolona  Skl1,double Skl3);
LZespolona operator%(LZespolona A, LZespolona B);
#endif
