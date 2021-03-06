#include <iostream>


#include "lacze_do_gnuplota.hh"
#include "Macierz2D.hpp"
#include "Sciezka.hh"


using namespace std;


Sciezka::Sciezka()
{

//    Wys_Glob.DodajWierzcholek(0,0);                    /// zamiast dodwac za kazdym razem przy animacji wierzcholek, zapisaujemy wszystko na jeden, po kolei do pliku i wyswietlamy z pliku
    Wek_Przesuniecia[0]=0;
    Wek_Przesuniecia[1]=0;


}


void Sciezka::Rysuj_Sciezka(Wektor2D W , PzG::LaczeDoGNUPlota Lacze)
{
    Wys_Glob.DodajWierzcholek(W);



//    Wys_Glob.Wierzcholek[0][0]=W[0];
//    Wys_Glob.Wierzcholek[0][1]=W[1];

  //  Zapisz_Do_Pliku( "Sciezka.dat" , Lacze , W);
    Zapisz_Do_Pliku( Nazwa_Pliku.c_str() , Lacze );


}


bool Sciezka::Zapisz_Do_Pliku( const char  *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze)
{

    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

    int i;
    i= Wys_Glob.Sprawdz_ilosc();


    for(int k=0;k<i;k++)
    {
       StrmPlikowy << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[k][0] + Wek_Przesuniecia[0]               /////////////////////////////////////
                   << setw(16) << fixed << setprecision(10) << Wys_Glob.Wierzcholek[k][1] + Wek_Przesuniecia[1] << endl;
    }

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}


/*
bool Sciezka::Zapisz_Do_Pliku( const char  *sNazwaPliku, PzG::LaczeDoGNUPlota Lacze, Wektor2D W)  //funkcja dopisuje do pliku wierzcholki
{

    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku, ios::app);
    if (!StrmPlikowy.is_open())
    {
        cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
             << ":(  nie powiodla sie." << endl;
        return false;
    }

        StrmPlikowy << setw(16) << fixed << setprecision(10) << W[0]
                    << setw(16) << fixed << setprecision(10) << W[1] << endl;



    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

*/

void Sciezka::Resetuj_Plik(const char  *sNazwaPliku)
{
    ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    StrmPlikowy.close();
}
