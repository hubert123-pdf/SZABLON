#include <iostream>
#include<string.h>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;


int main(int agrc,char*argv[])
{
 

  if(strcmp(argv[1],"r")==0)
  {
  SWektor<double,ROZMIAR> Wek;
  SMacierz<double,ROZMIAR> Mac;
  cin>>Mac;
  cin>>Wek;
  SUkladRownanLiniowych<double,ROZMIAR> URL(Mac,Wek); //inicjalizacja klasy uklad rownwan
  cout<<URL;

  }
}
