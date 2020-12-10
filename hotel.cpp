#include <iostream>
#include <string>
#include <vector>

#include "hotel.h"
#include "chambre.h"
using std::cout;
using std::endl;

Hotel::Hotel(int id, std::string nom, std::string ville) : 
_idHotel(id), _nomHotel(nom), _villeHotel(ville){}


int Hotel::getIdHotel() const{
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
    str = "Hotel: " + std::to_string(getIdHotel()) + " | " + getNom() + " " + getVille();
    return str;
}


void Hotel::setIdHotel(int id){
	_idHotel=id;
}
void Hotel::setNom(std::string nom){
	_nomHotel=nom;
}
void Hotel::setVille(std::string ville){
	_villeHotel=ville;
}
void Hotel::modifier(int id, std::string nom, std::string ville){
	setIdHotel(id);
	setNom(nom);
	setVille(ville);
}


void Hotel::addChambre(Chambre chambre){
	_listeChambre.push_back(chambre);
}


std::ostream& operator<<(std::ostream& os, const Chambre& chambre) {
    os << chambre.infoChambre();
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<Chambre> chambres) {
    auto i=chambres.begin();
	while(i!=chambres.end()) {       
		os << "   - " <<*i << "\n";
		++i;
	}
os << endl;
return os;
}
	
void Hotel::chambres(){
	std::cout << _listeChambre;
}
