#include <iostream>
#include <vector>
#include <cmath>
#include <list>

#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"

using namespace date;
using std::cout;
using std::endl;

std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << client.infoClient();
    return os;
}

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

/*


Client Client1(1,"Castex","Jean",5);
Client Client2(2,"Patrick","Balkany",0);
cout << Client1.infoClient() << endl;
cout << Client2.infoClient() << endl;
cout << endl;



Chambre Chambre1(1,Deluxe,200);
Chambre Chambre2(2,Simple,50);
cout << Chambre1.infoChambre() << endl;
cout << Chambre2.infoChambre() << endl;
cout << endl;

Hotel Hotel1(1,"Bellagio","Las Vegas");
cout << Hotel1.infoHotel() << endl;
Hotel1.addChambre(Chambre1);
Hotel1.addChambre(Chambre2);
cout << "Chambres du " << Hotel1.getNom() << ":" << endl;
Hotel1.chambres();
cout << endl;



Date debut(2010,10,10);
Date fin(2010,10,20);
Reservation test(1,debut,fin,1,1,1,50);




cout << test.infoReservation() << endl;
*/

//PARTIE 2

Chambre A(1,Simple,100);
Chambre B(2,Simple,100);
Chambre C(3,Simple,100);
Chambre D(4,Double,125);
Chambre E(5,Double,125);
Chambre F(6,Double,125);
Chambre G(7,Double,125);
Chambre H(8,Double,125);
Chambre I(9,Deluxe,210);
Chambre J(10,Deluxe,210);

Hotel Hotel1(1,"Bellagio","Las Vegas");
cout << Hotel1.infoHotel() << endl;
Hotel1.addChambre(A);
Hotel1.addChambre(B);
Hotel1.addChambre(C);
Hotel1.addChambre(D);
Hotel1.addChambre(E);
Hotel1.addChambre(F);
Hotel1.addChambre(G);
Hotel1.addChambre(H);
Hotel1.addChambre(I);
Hotel1.addChambre(J);
cout << "Chambres du " << Hotel1.getNom() << ":" << endl;
Hotel1.chambres();
cout << endl;

std::vector<Client> Clients;
Client Client1(1,"Moulin","Jean",5);
Client Client2(2,"Castex","Jean",5);
Client Client3(3,"Dujardin","Jean",5);
Client Client4(4,"Ledain","Jean",5);
Client Client5(5,"Pierre","Jean",5);
Client Client6(6,"Jean","Jean",5);
Client Client7(7,"Valjean","Jean",5);
Client Client8(8,"Lewis","Jean",5);
Client Client9(9,"Tuc","Jean",5);
Client Client10(10,"Bidule","Jean",5);

Clients.push_back(Client1);
Clients.push_back(Client2);
Clients.push_back(Client3);
Clients.push_back(Client4);
Clients.push_back(Client5);
Clients.push_back(Client6);
Clients.push_back(Client7);
Clients.push_back(Client8);
Clients.push_back(Client9);
Clients.push_back(Client10);

auto it = Clients.begin();
while (it != Clients.end()){
	cout << *it << endl;
	++it;
}
goto debut;
debut:
	cout << "Entrez date de début:" << endl;
	cout << "Jour:" << endl;
	int jour;
	std::cin >> jour;
	cout << "Mois" << endl;
	int mois;
	std::cin >> mois;
	cout << "Année" << endl;
	int annee;
	std::cin >> annee;

	Date dateDebut(annee,mois,jour);
	if(dateDebut.checkDate(annee,mois,jour)==false){
		goto debut;
	}

goto fin;
fin:
	cout << "Entrez date de fin:" << endl;
	cout << "Jour:" << endl;
	int jour2;
	std::cin >> jour2;
	cout << "Mois" << endl;
	int mois2;
	std::cin >> mois2;
	cout << "Année" << endl;
	int annee2;
	std::cin >> annee2;

	Date dateFin(annee2,mois2,jour2);
	if(dateFin.checkDate(annee2,mois2,jour2)==false){
		goto fin;
	}

if(dateDebut>=dateFin){
	cout << "La date de début se situe après la date d'arrivé, merci de rentrer à nouveau les dates du séjour:" << endl;
	goto debut;
}

nbrenuit(Date Debut, Date Fin){}

return 0;
}