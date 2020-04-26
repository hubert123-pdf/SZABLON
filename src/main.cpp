#include <iostream>
#include<string.h>
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
  cout<<"Wypelnij wektor wynikow układu rownan"<<endl;
  cin>>Wek;

  SUkladRownanLiniowych<typ,ROZMIAR> URL(Mac,Wek); //inicjalizacja klasy uklad rownwan
  cout<<URL;

  cout<<"Wektor Rozwiazan: "<<endl;
  cout<<URL.ROZWIAZANIE();
  }
  
  if(!strcmp(argv[1],"z"))
  {
   typedef LZespolona typ;

  SWektor<typ,ROZMIAR> Wek;
  SMacierz<typ,ROZMIAR> Mac;
  cout<<endl<<"Wypelnij Macierz wyrazow wolnych:"<<endl;
  cin>>Mac;
  cout<<"Wypelnij wektor wynikow układu rownan"<<endl;
  cin>>Wek;

  SUkladRownanLiniowych<typ,ROZMIAR> URL(Mac,Wek); //inicjalizacja klasy uklad rownwan
  cout<<URL;

  cout<<"Wektor Rozwiazan: "<<endl;
  cout<<URL.ROZWIAZANIE();
  }
}

