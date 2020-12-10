#include <iostream>
#include <string>

#include "hotel.h"
#include "chambre.h"


Hotel::Hotel(int id, std::string nom, std::string ville) : 
_idHotel(id), _nomHotel(nom), _villeHotel(ville){}


int Hotel::getId() const{
	return _idHotel;
}
std::string Hotel::getNom() const{
	return _nomHotel;
}
std::string Hotel::getVille() const{
	return _villeHotel;
}

std::string Hotel::infoHotel() const {
    std::string str;
    str = "Hotel: " + std::to_string(getId()) + " | " + getNom() + " " + getVille();
    return str;
}


void Hotel::setId(int id){
	_idHotel=id;
}
void Hotel::setNom(std::string nom){
	_nomHotel=nom;
}
void Hotel::setVille(std::string ville){
	_villeHotel=ville;
}
void Hotel::modifier(int id, std::string nom, std::string ville){
	setId(id);
	setNom(nom);
	setVille(ville);
}


void Hotel::addChambre(Chambre chambre){
	_listeChambre.push_back(chambre);
}
std::ostream& operator<<(std::ostream& os, const Chambre& chambre) {
    os << chambre.getId() << " " << chambre.getType();
    return os;
}
void Hotel::chambres(){
	cout << _listeChambre;
}