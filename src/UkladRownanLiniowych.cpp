#include "UkladRownanLiniowych.hh"



template<typename STypU,int SWymiarU>
  STypU Wyznacznikx1(SUkladRownanLiniowych<STypU,SWymiarU> U)
 {
  STypU a=U.getwyniki().getSkladowa(0);
  STypU b=U.getwyniki().getSkladowa(1);
  STypU c=U.getwyniki().getSkladowa(2);
  U.setMacierz(0,0,a);
  U.setMacierz(1,0,b);
  U.setMacierz(2,0,c);
  return U.getMacierz().znajdzWyznacznik();
 }
 template<typename STypU,int SWymiarU>
  double Wyznacznikx2(SUkladRownanLiniowych<STypU,SWymiarU> U)
 {
  double a=U.getwyniki().getSkladowa(0);
  double b=U.getwyniki().getSkladowa(1);
  double c=U.getwyniki().getSkladowa(2);
  U.setMacierz(0,1,a);
  U.setMacierz(1,1,b);
  U.setMacierz(2,1,c);
  return U.getMacierz().znajdzWyznacznik();
 }
 template<typename STypU,int SWymiarU>
  double Wyznacznikx3(SUkladRownanLiniowych<STypU,SWymiarU> U)
 {
  double a=U.getwyniki().getSkladowa(0);
  double b=U.getwyniki().getSkladowa(1);
  double c=U.getwyniki().getSkladowa(2);
  U.setMacierz(0,2,a);
  U.setMacierz(1,2,b);
  U.setMacierz(2,2,c);
  return U.getMacierz().znajdzWyznacznik();
 }

 template<typename STypU,int SWymiarU>
STypU SUkladRownanLiniowych<STypU,SWymiarU>::ROZWIAZANIE(SUkladRownanLiniowych U)
 {  
     double x1,x2,x3;
     x1=Wyznacznikx1(U)/U.getMacierz().znajdzWyznacznik();
     x2=Wyznacznikx2(U)/U.getMacierz().znajdzWyznacznik();
     x3=Wyznacznikx3(U)/U.getMacierz().znajdzWyznacznik();
    setWektor(0,x1);
    setWektor(1,x2);
    setWektor(2,x3);
return getRozwiazanie();
}
 template<typename STypU,int SWymiarU>
 void SUkladRownanLiniowych<STypU,SWymiarU>::Epsilon()
 {
     STypU Epsilon;
     STypU Epsilon2;
     Epsilon.setSkladowa(0,(getMacierz().getKolumna(0)*getRozwiazanie()-getwyniki().getSkladowa(0)));
     Epsilon.setSkladowa(1,(getMacierz().getKolumna(1)*getRozwiazanie()-getwyniki().getSkladowa(1)));
     Epsilon.setSkladowa(2,(getMacierz().getKolumna(2)*getRozwiazanie()-getwyniki().getSkladowa(2)));
     std::cout<<"Wektor bledu: Ax-b = "<<Epsilon<<std::endl;
    
     std::cout<<"Dlugosc wektora bledu |Ax-b| = ";
     Epsilon2=iloczynWektorowy(Epsilon,Epsilon);
     Epsilon2.setSkladowa(0,sqrt(Epsilon2.getSkladowa(0)));
     Epsilon2.setSkladowa(0,sqrt(Epsilon2.getSkladowa(1)));
     Epsilon2.setSkladowa(0,sqrt(Epsilon2.getSkladowa(2)));
     std::cout<<Epsilon2;

 }
