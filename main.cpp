#include <iostream>
#include <cmath>

#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"

using namespace date;
using std::cout;
using std::endl;
/*std::ostream& operator<<(std::ostream& os, const std::vector<Livre> livres) {
    auto i=livres.begin();
	while(i!=livres.end()) {       
		os << *i << "|";
		++i;
	}
os << endl;
return os;
}
*/

int main(){

//Q1
Date aniv(2001,02,12);
cout << aniv.toString() << endl;

//Q2
Client Jean(1,"Castex","Jean",5);
cout << Jean.info() << endl;

Jean.setNom("Balkany");
Jean.setPrenom("Patrick");
cout << Jean.info() << endl;
Jean.modifier(1,"Castex","Jean",5);
cout << Jean.info() << endl;

//Q3
Chambre A(1,Deluxe,80);
cout<< A.infoChambre() <<endl;
A.setType(Familiale);
A.setPrix(150);
cout<< A.infoChambre() <<endl;
A.modifier(1,Deluxe,100);
cout<< A.infoChambre() <<endl;



//Q4

Hotel Calif(1,"California","Paris");
cout << Calif.infoHotel() << endl;
Calif.modifier(0,"Bellagio","Las Vegas");
cout << Calif.infoHotel() << endl;

Hotel.addChambre(A);
cout << "Chambres du" << Calif.getNom() << ":" << endl;
cout << Calif.chambres()<< endl;

return 0;
}