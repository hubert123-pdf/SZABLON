#include <iostream>
#include<string.h>
#include <iomanip>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"
#include "LZespolona.hh"


using namespace std;


int main(int agrc,char*argv[])
{
 
  if(!strcmp(argv[1],"r"))
  {
    typedef double typ;

  SWektor<typ,ROZMIAR> Wek;
 
  SMacierz<typ,ROZMIAR> Mac;
  cout<<endl<<"Wypelnij Macierz wyrazow wolnych:"<<endl;
  cin>>Mac;
  cout<<Mac.getWiersz(0);
  cout<<"Wypelnij wektor wynikow układu rownan"<<endl;
  cin>>Wek;

  SUkladRownanLiniowych<typ,ROZMIAR> URL(Mac,Wek); //inicjalizacja klasy uklad rownwan
  cout<<URL;

  cout<<"Wektor Rozwiazan: "<<endl;
  if(znajdzWyznacznik(Mac))
  {
    cout<<fixed<<setprecision(2)<<URL.ROZWIAZANIE();
    cout<<scientific<<setprecision(1)<<URL.Epsilon();
    return 0;
  }
  else
  {
    cout<<endl<<"Wyznacznik rowny zero brak rozwiazan"<<endl;
    return 1;
  }
  }
  
   if(!strcmp(argv[1],"z"))
  {
    typedef LZespolona typ;
   LZespolona zerowyWyznacznik{false,false};
  SWektor<typ,ROZMIAR> Wek;
 
  SMacierz<typ,ROZMIAR> Mac;
  cout<<endl<<"Wypelnij Macierz wyrazow wolnych:"<<endl;
  cin>>Mac;
  cout<<"Wypelnij wektor wynikow układu rownan"<<endl;
  cin>>Wek;

  SUkladRownanLiniowych<typ,ROZMIAR> URL(Mac,Wek); //inicjalizacja klasy uklad rownwan
  cout<<URL;

  cout<<"Wektor Rozwiazan: "<<endl;
  
  if((znajdzWyznacznik(Mac)==zerowyWyznacznik)!=true)
  {
  cout<<fixed<<setprecision(2)<<URL.ROZWIAZANIE();
  cout<<scientific<<setprecision(1)<<URL.Epsilon();
  return 0;
  }
  else
  {
    cout<<endl<<"Wyznacznik rowny zero brak rozwiazan"<<endl;
    return 1;
  }
}
}

