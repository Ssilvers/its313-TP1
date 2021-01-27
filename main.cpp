#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <ctime>
#include <cstdlib>

#include "date.h"
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "reservation.h"
#include "algorithm"


using namespace date;
using std::cout;
using std::endl;

//Surchage d'opérateur pour aficcher les info d'un client
std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << client.infoClient();
    return os;
}

//Fonction pour vérifier type saisit
int checkType(std::string saisit){
	int verifType;

	//conversion de la saisit en chiffres
	verifType=atoi(saisit.c_str());

	//On traite différemment selon si la conversion a fonctionné 
	// (!=0 donc saisit un chiffre)
	// ou non(==0 saisit autre chose)
	if(verifType!=0){
		return verifType;
	}else{
		return 0;
	}
}


//Fonction pour améliorer l'affichage
void trait(){
	int p=0;
	cout << endl;
	cout << endl;
	while(p<10){
		cout << "-";
		p=p+1;
	}
	cout << endl;
	cout << endl;
}

//Fonction qui calcule le nombre de jours entre 2 dates
int nombrenuit(Date dateDebut, Date dateFin){
	Date dateCalcul = dateDebut;
	int k=0;
	while(dateCalcul != dateFin){
		k=k+1;
		dateCalcul.nextDay();
	}
	return k;
}

//Retourne un vecteur contenant les IDs des
//chambres occupées sur une période donnée 
//(selon réservations)
std::vector<int> checkDispo(Date debut, Date fin, std::vector<Reservation> reservations){
	int boucle=reservations.size();
	int i = 0;
	std::vector<int> indisponible;
	while(i<boucle){
		if(((reservations.at(i).getDebut()<debut)
			&&(reservations.at(i).getFin()<debut))
			||((reservations.at(i).getDebut()>fin)
			&&(reservations.at(i).getFin()>fin))){

		}else{
			indisponible.push_back(reservations.at(i).getIdChambre());
		}
		i++;
	}
	return indisponible;
}

//Retourne l'id d'une chambre en fonction 
//des dispos et du type souhaité
int checkChambre(std::vector<int> paslibre, std::vector<Chambre> hotel, int typeChambre){
	int fin=hotel.size();
	int i = 0;

	while(i<fin){
		int id=hotel.at(i).getIdChambre();

		auto it = find(paslibre.begin(), paslibre.end(), id);

		if(it!=paslibre.end()){

		}else{
			if(hotel.at(i).getType()==typeChambre){
				cout << hotel.at(i).infoChambre() << endl;
				return id;
			}
		}
	i++;
	}
	cout << "Aucune chambre de ce type n'est disponible"<<endl;
	cout << "Veuillez choisir un autre type" << endl << endl;
	return 0;
}

//Retourne l'objet chambre correspondant à un ID donné
Chambre rechercheChambre(std::vector<Chambre> listeChambre,int idChambre){
	int fin=listeChambre.size();
	int i = 0;

	while(i<fin){

		if(idChambre==listeChambre.at(i).getIdChambre()){
				return listeChambre.at(i);
		}
	i++;
	}
}


//Affiche la liste des clients possédant le nom
//entré en paramètre
//Puis demande de sélectionner le bon nom
//afin de retourner l'ID du client correspondant
int clientNom(std::string nom, std::vector<Client> clients){
	int verif;

	cout << endl << "Liste des clients avec ce nom:" << endl;

	int boucle = clients.size();
	int i=0;
	bool erreur=true;
	while (i < boucle){
		if(clients.at(i).getPrenom()==nom){
			cout << clients.at(i).getIdClient() 
			<< "- " << clients.at(i).getNom() 
			<< " " << clients.at(i).getPrenom() << endl;
			erreur=false;
		}
	i++;
	}
	if(erreur==true){
		cout<<"Aucun client de possède ce nom"<<endl;
		return 0;
	}
	cout << endl;


	std::string selection1;

	goto selectionumero;
	selectionumero:

	cout << "Entrez le numéro vous correspondant" << endl;
	
	std::cin >> selection1;

	int selection = checkType(selection1);
	if(selection==0){
		cout<<"Numéro invalide, réessayez"<<endl<<endl;
		goto selectionumero;
	}

	i=0;
	erreur=true;
	boucle = clients.size();

	while (i < boucle){
		if(clients.at(i).getIdClient()==selection){
			cout << clients.at(i);
			erreur=false;
			return clients.at(i).getIdClient();
		}
	i++;
	}
	if(erreur==true){
		cout<<"Pas de numéro correspondant, réessayez"<<endl<<endl;
		goto selectionumero;
	}
	cout << endl;
	return 0;
}	


//Retourne l'objet Client possédant l'ID en paramètre
Client rechercheClient(std::vector<Client> listeClient,int idClient){
	int fin=listeClient.size();
	int i = 0;

	while(i<fin){

		if(idClient==listeClient.at(i).getIdClient()){
				return listeClient.at(i);
		}
	i++;
	}
}

//Affiche toutes les réservations
void afficherReservations(std::vector<Reservation> reservations){
	int fin=reservations.size();
	int i = 0;

	cout << "Liste des Réservations" << endl;
	
	while(i<fin){
		cout << reservations.at(i).infoReservation();
		cout << endl;
		i++;
	}
}

//Affiche la réservation possédant l'ID en paramètre
void afficherReservationsN(std::vector<Reservation> reservations, int idReservation){
	int fin=reservations.size();
	int i = 0;

	while(i<fin){
		if(reservations.at(i).getIdReservation() == idReservation){
			cout << reservations.at(i).infoReservation();
			cout << endl;
		}
		i++;
	}
}

//Affiche les réservations au nom d'un client 
//OU de son ID
void afficherReservationsCN(std::vector<Reservation> reservations,  int recherche){
	int fin=reservations.size();
	int i = 0;
	cout << "Reservations du client n°" << recherche << " :" <<endl;
	while(i<fin){
		if(reservations.at(i).getIdClient() == recherche){
			cout << reservations.at(i).infoReservation();
		}
		i++;
	}
	cout << endl;
}

//Efface la réservation possédant l'ID en praramètre
std::vector<Reservation> annulerReservation(std::vector<Reservation> reservations, int reservation){
	int fin=reservations.size();
	int i = 0;

	while(i<fin){
		if(reservations.at(i).getIdReservation() == reservation){
			reservations.erase(reservations.begin() + i);
			return reservations;
		}
		i++;
	}
	cout << "Aucune réservation avec cet ID" << endl;
	return reservations;

}



int main(){

int verif; // Varibale utilisée pour vérifier les types dans la suite du programme

//PARTIE 2


//on créer 10 chambres selon le cdc
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


//On créer un hotel puis on lui attribue les 10 chambres
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


//On créer 10 clients
Client Client1(1,"Moulin","Jean",5);
Client Client2(2,"Castex","Jean",5);
Client Client3(3,"Dujardin","Jean",5);
Client Client4(4,"Lasalle","Jean",5);
Client Client5(5,"Pierre","Jean",5);
Client Client6(6,"Jean","Jean",5);
Client Client7(7,"Valjean","Jean",5);
Client Client8(8,"Pierre","Jean",5);
Client Client9(9,"Reno","Jean",5);
Client Client10(10,"Pierrepernaut","Jean",5);

//Vecteur regroupant tous les clients
std::vector<Client> Clients;
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

//On affiche le contenu de ce vecteur grâce à 
//une boucle et à la surchage sur les clients
//(Voir ligne 19)
auto it = Clients.begin();
while (it != Clients.end()){
	cout << *it << endl;
	++it;
}
cout << endl;

//On créer un vecteur qui contiendra, à l'avenir,
//toutes les réservations
std::vector<Reservation> reservations;

//On récupère la date du jour qu'on stocke dans des variables
time_t actuel = time(0);
tm *ltm = localtime(&actuel);

int anneeA = 1900 +ltm->tm_year;
int moisA = 1 + ltm->tm_mon;
int jourA = ltm->tm_mday;
Date dateActuelle(anneeA,moisA,jourA);


trait();


//DEBUT CREATION RESERVATION



//Indique le nombre de réservations que l'on
//souhaite créer (il faut changer nbre dans while)
int repetition=1;
while(repetition<=1){

//CHOIX DES DATES
goto debut; 
debut: // Marqueur pour entrer la date de début

//On demande à l'utilisateur d'entrer 
//la date de début
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

//On créer un objet dateDebut reprenant ces infos
	Date dateDebut(annee,mois,jour);

	system("clear"); //Efface le terminal


//Si la date n'est pas valide, on recommence la saisit
//Grâce au marqueur plus haut
	if(dateDebut.checkDate(annee,mois,jour)==false){
		cout << endl;
		goto debut;
	}
//Si la date est située après la date du jour,
//on redemande la saisit de la date (date Invalide)
	if(dateActuelle>dateDebut){
		cout << "La date entrée est déjà passé, Réessayer." << endl;
		goto debut; 
	}

goto fin;
fin: // Marqueur pour entrer la date de fin

//On demande à l'utilisateur d'entrer 
//la date de fin
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

//On créer un objet dateFin avec ces infos
	Date dateFin(annee2,mois2,jour2);

	system("clear"); //Efface le terminal

//On test la validité des infos entrées
//et on redemande saisit si erreur grâce marqueur situé plus haut
	if(dateFin.checkDate(annee2,mois2,jour2)==false){
		cout << endl;
		goto fin;
	}

	//Si la chronologie des dates ne va pas, 
	//on reccomence la saisit depuis le début
	if(dateDebut>=dateFin){
		cout << "La date de début se situe après la date de fin, merci de rentrer à nouveau les dates du séjour:" << endl << endl;
		goto debut;
	}


//Lorsque les dates entrées sont valide:

//Calcul puis affichage du nombre de nuit
int nbrenuit = nombrenuit(dateDebut,dateFin);
cout << "Nombre de nuit: "<< nbrenuit << endl << endl;

// FIN DES DATES


// Test de compatibilité date réservations (à commenter)
Date debut(2010,10,10);
Date fin(2010,10,20);
Reservation test(3,debut,fin,1,2,1,50);
Date debut2(2010,10,10);
Date fin2(2010,10,20);
Reservation test2(4,debut,fin,1,1,1,50);
Date debut3(2010,10,10);
Date fin3(2010,10,20);
Reservation test3(5,debut,fin,1,3,1,50);


reservations.push_back(test);
reservations.push_back(test2);
reservations.push_back(test3);
//(fin commentaire)


//CHOIX DE LA CHAMBRE PAR TYPE
goto type;
type: // Marqueur sélection type de chambre
cout << "Entrez un type de chambre" << endl;
cout << "0-Simple | 1-Double | 2-Familiale | 3-Deluxe"<< endl << endl;
int typeChambre;
std::cin >> typeChambre; // On récupère le type souhaité
system("clear"); //Efface le terminal
switch(typeChambre){
	case 0:
		cout << "Simple" << endl;
		break;
	case 1:
		cout << "Double" << endl;
		break;
	case 2:
		cout << "Familiale" << endl;
		break;
	case 3:
		cout << "Deluxe" << endl;
		break;
	default:
		cout << "Erreur dans la sélection du type, réessayez" << endl << endl;
		goto type; //Si saisit non valide, on recommence (Marqueur plus haut)
}

//On récupère l'id de la 1ère chambre disponible
//Grâce à la fonction "checkChambre" en utilisant
//également la fonction checkDispo pour voir les chambres occupées
int nchambre = checkChambre(checkDispo(dateDebut, dateFin, reservations),Hotel1.getChambres(),typeChambre);
if(nchambre==0){
	goto type; // Si aucune chambre dispo, on demande un nouveau type
}else{
	//On affiche les infos de la chamre sinon
	cout << "Cette chambre est disponible"<<endl;
}
//On récupère l'objet chambre avec la fonction rechercheChambre
Chambre chambre = rechercheChambre(Hotel1.getChambres(), nchambre);


//FIN CHOIX CHAMBRE



//CHOIX DU CLIENT
goto client;
client://Marqueur entrer nom client

cout << endl;
cout << "Quelle nom pour la réservation ?" << endl;
std::string nom;
std::cin >> nom;

verif = checkType(nom);

if(verif!=0){
	cout << " Veuillez saisir un nom svp" << endl;
	goto client;
}
	//On affiche appelle la fonction clientNom
	//qui affiche les clients avec le nom saisit 
	//et demande une sélection (Gestion homonyme)
	//et on récupère l'ID du client souhaité
	int clientReservation = clientNom(nom, Clients);
	if(clientReservation==0){
		cout << "Aucun client avec ce nom, vérifiez la saisit et réeassayez" << endl;
		system("clear"); //Efface le terminal
		goto client; // Si aucun client avec ce nom, on resaisit
	}


//On récupère l'objet Client correspondant
Client client = rechercheClient(Clients, clientReservation);


//FIN CHOIX CLIENT


//CALCUL MONTANT SEJOUR + CREATION RESERVATION

//Calcul de la réduction en fonction de la 
//fidelité du client (1%/réservation déjà passées)


cout << endl << endl;

//Création de la réservation
Reservation reservation1(repetition,dateDebut, dateFin,1,nchambre,clientReservation,0);
reservation1.calculMontant(nbrenuit,chambre.getPrix(),client.getNbreserv());
trait();
//Affichage des infos sur la réservation
system("clear");
cout << "Résumé de votre séjour:" << endl;
cout << client << endl;
cout << reservation1.infoReservation();
cout << chambre.infoChambre();
trait();

//On augmente le nombre de réservation du client qui réserve
client.setNbreserv(client.getNbreserv()+1);

reservations.push_back(reservation1);
cout << endl;


//FIN RESERVATION

//FIN


repetition = repetition + 1;
}

//Affiche toutes les réservations
afficherReservations(reservations);

trait();

//Variables pour vérification de saisit
int verifReservation;
std::string reservationN;

goto recherchereservation;
recherchereservation: // Marqueur pour revenir à la saisit si erreur

cout << "Numéro de la réservation ?" << endl;
std::cin >> reservationN;

//conversion de la saisit en chiffres
verifReservation=atoi(reservationN.c_str());

//On traite différemment selon si la conversion a fonctionné 
// (!=0 donc saisit un chiffre)
// ou non(==0 saisit autre chose)
if(verifReservation!=0){
	afficherReservationsN(reservations, verifReservation);
}else{
	cout << "Erreur, veuillez saisir un numéro de réservation" << endl;
	goto recherchereservation;
}


trait();

cout << "Nom/Numéro de la personne dont vous voulez afficher réservations ?"<<endl;
std::string recherche;
std::cin >> recherche;
int conversionID;
//Permet de convertir un string en int afin de pouvoir
//traité les 2 types de saisit (nom ou ID)
conversionID=atoi(recherche.c_str());

//On traite différemment selon si 
//la conversion a fonctionné (!=0 donc saisit un chiffre)
// ou non(==0 saisit un nom)
if(conversionID!=0){
	afficherReservationsCN(reservations, conversionID);
}else{
	int clientRecherche= clientNom(recherche, Clients);
	cout << endl;
	if(clientRecherche==0){
		cout << " Aucune réservation à ce nom" << endl;
	}else{
		afficherReservationsCN(reservations, clientRecherche);
	}
}

trait();

cout << "Voulez vous annuler une réservation ? (Oui/Non)" << endl;
std::string choix;
std::cin >> choix;
if(choix=="Oui","oui","O","o"){
	
	goto recherchereservation2;
	recherchereservation2: // Marqueur pour revenir à la saisit si erreur

	cout << "Numéro de la réservation à annuler ?" << endl;
	std::cin >> reservationN;

	//conversion de la saisit en chiffres
	verifReservation=atoi(reservationN.c_str());

	//Vérif de saisit
	if(verifReservation!=0){
		reservations = annulerReservation(reservations, verifReservation);
	}else{
		cout << "Erreur, veuillez saisir un numéro de réservation" << endl;
		goto recherchereservation2;
	}

	
}
cout << endl << endl;
afficherReservations(reservations);

return 0;
}