#include "Wektor.hh"

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
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar> &Wek)
{
    for(int i=0;i<ROZMIAR;i++)
    {

        Strm<<Wek.getSkladowa(i)<<' ';
    }
    Strm<<std::endl;
    return Strm;
}
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator+(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2)
{
    SWektor<STyp,SWymiar> wynik;
    for (int i=0;i<ROZMIAR;i++)
    {
        wynik.setSkladowa(i,Wek1.getSkladowa(i)+Wek2.getSkladowa(i));
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator-(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2)
{
    SWektor<STyp,SWymiar> wynik;
    for (int i=0;i<ROZMIAR;i++)
    {
        wynik.setSkladowa(i,Wek1.getSkladowa(i)-Wek2.getSkladowa(i));
    }
    return wynik;
}
template <typename STyp, int SWymiar>
STyp operator*(SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2)
{
    STyp wynik;
    SWektor<STyp,SWymiar> wynik2;
    for(int i=0;i<ROZMIAR;i++)
    {
    wynik2.setSkladowa(i,Wek1.getSkladowa(i)*Wek2.getSkladowa(i));
    wynik+=wynik2.getSkladowa(i);
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator*(SWektor<STyp,SWymiar> Wek1,double Wek2)
{
    SWektor<STyp,SWymiar> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
     wynik.setSkladowa(i,Wek1.getSkladowa(i)*Wek2);   
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> operator/(SWektor<STyp,SWymiar> Wek1,double Wek2)
{
    SWektor<STyp,SWymiar> wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
     wynik.setSkladowa(i,Wek1.getSkladowa(i)/Wek2);   
    }
    return wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> iloczynWektorowy( SWektor<STyp,SWymiar> Wek1,SWektor<STyp,SWymiar> Wek2)
{
    /*działanie na wzorze 
    i j k
    a1 a2 a3
    b1 b2 b3
    a x b = (a2*b3-a3*b2)i-(a1*b3-a3*b1)j+(a1*b2-a2*b1)k*/
    SWektor<STyp,SWymiar> Wek3;
    double i=(Wek1.getSkladowa(1)*Wek2.getSkladowa(2))-(Wek1.getSkladowa(2)*Wek2.getSkladowa(1));
    double j=Wek1.getSkladowa(0)*Wek2.getSkladowa(2)-Wek1.getSkladowa(2)*Wek2.getSkladowa(0);
    double k=Wek1.getSkladowa(0)*Wek2.getSkladowa(1)-Wek1.getSkladowa(1)*Wek2.getSkladowa(0);
    Wek3.setSkladowa(0,i);  Wek3.setSkladowa(1,-j);  Wek3.setSkladowa(2,k);  //przypisanie wartosci
    return Wek3;
   
}
