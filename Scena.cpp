#include <iostream>
#include <vector>
#include <sstream>   //dodawanie stringow

#include "Obiekt_graficzny.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include "Robot.hh"
#include "Scena.hh"


using namespace std;


void Scena::Dodaj_Robota( PzG::LaczeDoGNUPlota Lacze, Wektor2D W)
{
    Robot RR( W );
    RRR.push_back( RR );



    string nazwa;

    int i;
    i=RRR.size();
    ostringstream ss;
    ss << i;
    string str = ss.str();              ///str zawiera numer robota

    RRR[ i-1 ].numer_robota=i;

    nazwa = "Robot";               //tworzy nazwe robota = "Robot[numer_robota].dat "
    nazwa += str;
    nazwa +=".dat";

    RRR[ i-1 ].Nazwa_Pliku = nazwa;





    Lacze.DodajNazwePliku( RRR[ i-1 ].Nazwa_Pliku.c_str(), PzG::RR_Ciagly, 2 );      ///c_str zwraca lancuch char const




    RRR[ i-1 ].Zapisz_Do_Pliku( RRR[ i-1 ].Nazwa_Pliku.c_str(), Lacze );         //resetuje plik robota





    nazwa = "Sciezka";               //tworzy nazwe robota = "Sciezka[numer_robota].dat "
    nazwa += str;
    nazwa +=".dat";

    RRR[ i-1 ].R_Sciezka.Nazwa_Pliku = nazwa;                   //przydziela atrybutowi Nazwa_Pliku nazwe pliku sciezki

    Lacze.DodajNazwePliku( RRR[ i-1 ].R_Sciezka.Nazwa_Pliku.c_str(), PzG::RR_Ciagly, 2 );      ///c_str zwraca lancuch char const

    RRR[i-1].R_Sciezka.Rysuj_Sciezka( RRR[ i-1 ].Pokaz_Wektor_Translacji(),Lacze);      //resetuje plik sciezki

}




void Scena::Dodaj_Przeszkode( PzG::LaczeDoGNUPlota Lacze, Wektor2D W1, Wektor2D W3)
{
    Przeszkoda TMP;
    TMP.Buduj_Przeszkode( W1, W3 );


    string nazwa;

    P.push_back( TMP );

    int i;
    i=P.size();
    ostringstream ss;
    ss << i;
    string str = ss.str();              ///str zawiera numer przeszkody


    nazwa = "Przeszkoda";               //tworzy nazwe robota = "Przeszkoda[numer_robota].dat "
    nazwa += str;
    nazwa +=".dat";

    P[ i-1 ].Nazwa_Pliku = nazwa;

    Lacze.DodajNazwePliku( P[ i-1 ].Nazwa_Pliku.c_str(), PzG::RR_Ciagly, 2 );      ///c_str zwraca lancuch char const

    P[ i-1 ].Zapisz_Do_Pliku( P[ i-1 ].Nazwa_Pliku.c_str(), Lacze );         //resetuje plik przeszkody

}


void Nowa_Scena(shared_ptr<Scena> &SSS)                                                
{                                                                                         
    shared_ptr<Scena> WW(new Scena());                                                   
    SSS=WW;                                                                             
}
