#include <iostream>

#include "date.h"
#include "client.h"
#include "vector"


Client::Client(int id, std::string nom, std::string prenom, int nbreserv) : 
_idClient(id), _nom(nom), _prenom(prenom), _nbreserv(nbreserv){}

int Client::getIdClient() const {
	return _idClient;
}
std::string Client::getNom() const {
	return _nom;
}
std::string Client::getPrenom() const {
	return _prenom;
}
int Client::getNbreserv() const {
	return _nbreserv;
}


std::string Client::infoClient() const {
    std::string str;
    str = "Client: " + std::to_string(getIdClient()) + " | " + getNom() + " " + getPrenom() + " | " + std::to_string(getNbreserv()) + " réservations";
    return str;
}


void Client::setIdClient(int id){
	_idClient=id;
}
void Client::setNom(std::string nom){
	_nom=nom;
}
void Client::setPrenom(std::string prenom){
	_prenom=prenom;
}
void Client::setNbreserv(int nbreserv){
	_nbreserv=nbreserv;
}
void Client::modifier(int id, std::string nom, std::string prenom, int nbreserv){
	setIdClient(id);
	setNom(nom);
	setPrenom(prenom);
	setNbreserv(nbreserv);
}



/*
Clients::Clients(){

}

void Clients::addClient(Client client){
	_clients.push_back(client);
}
std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << client.infoClient();
    return os;
}
std::ostream& operator<<(std::ostream& os, const std::vector<Client> clients) {
    auto i=clients.begin();
	while(i!=clients.end()) {       
		os << "   - " <<*i << "\n";
		++i;
	}
os << std::endl;
return os;
}

void Clients::liste(){
	std::cout << _clients;
}
*/