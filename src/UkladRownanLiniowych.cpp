#include "UkladRownanLiniowych.hh"
/*
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
*/