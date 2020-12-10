#include <iostream>
#include <vector>
#include <cmath>

#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"

using namespace date;
using std::cout;
using std::endl;



int main(){

/* TEST

//Q1
Date aniv(2001,02,12);
cout << aniv.toString() << endl;
cout << endl;

//Q2
Client Jean(1,"Castex","Jean",5);
cout << Jean.info() << endl;

Jean.setNom("Balkany");
Jean.setPrenom("Patrick");
cout << Jean.info() << endl;
Jean.modifier(1,"Castex","Jean",5);
cout << Jean.info() << endl;
cout << endl;

//Q3
Chambre A(1,Deluxe,80);
cout<< A.infoChambre() <<endl;
A.setType(Familiale);
A.setPrix(150);
cout<< A.infoChambre() <<endl;
A.modifier(1,Deluxe,100);
cout<< A.infoChambre() <<endl;
cout << endl;



//Q4

Hotel Calif(1,"California","Paris");
cout << Calif.infoHotel() << endl;
Calif.modifier(1,"Bellagio","Las Vegas");
cout << Calif.infoHotel() << endl;

Calif.addChambre(A);
cout << "Chambres du " << Calif.getNom() << ":" << endl;
Calif.chambres();
cout << endl;


TEST */

//Q5
Client Jean(1,"Castex","Jean",5);
Client Pat(2,"Patrick","Balkany",0);
cout << Jean.infoClient() << endl;
cout << Pat.infoClient() << endl;
cout << endl;

Chambre A(1,Deluxe,200);
Chambre B(2,Simple,50);
cout << A.infoChambre() << endl;
cout << B.infoChambre() << endl;
cout << endl;

Hotel Bella(1,"Bellagio","Las Vegas");
cout << Bella.infoHotel() << endl;
Bella.addChambre(A);
Bella.addChambre(B);
cout << "Chambres du " << Bella.getNom() << ":" << endl;
Bella.chambres();
cout << endl;

return 0;
}