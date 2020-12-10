#include <iostream>
#include <string>

#include "date.h"
#include "chambre.h"

Chambre::Chambre(int id, Type type, float prix) : 
_idChambre(id), _type(type), _prix(prix){}


int Chambre::getIdChambre() const{
	return _idChambre;
}
Type Chambre::getType() const{
	return _type;
}
float Chambre::getPrix() const{
	return _prix;
}

std::string Chambre::infoChambre() const {
    std::string str;
    str = "Chambre: " + std::to_string(getIdChambre()) + " | " + std::to_string(getType()) + " " + std::to_string(getPrix()) + "€/nuit ";
    return str;
}



void Chambre::setIdChambre(int id){
	_idChambre=id;
}
void Chambre::setType(Type type){
	_type=type;
}
void Chambre::setPrix(float prix){
	_prix=prix;
}
void Chambre::modifier(int id, Type type, float prix){
	setIdChambre(id);
	setType(type);
	setPrix(prix);
}