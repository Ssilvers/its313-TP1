#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

#include "date.h"
#include "client.h"
#include "hotel.h"
#include "reservation.h"



Reservation::Reservation(int id, Date debut, Date fin,
int idHotel, int idChambre, int idClient,float montant) : 
_idReservation(id),_dateDebut(debut), _dateFin(fin),_idHotel(idHotel),
_idChambre (idChambre),_idClient(idClient),_montant(montant){
}


int Reservation::getIdReservation() const{
	return _idReservation;
}
Date Reservation::getDebut() const {
	return _dateDebut;
}
Date Reservation::getFin() const {
	return _dateFin;
}
int Reservation::getIdHotel() const{
	return _idHotel;
}
int Reservation::getIdChambre() const{
	return _idChambre;
}
int Reservation::getIdClient() const{
	return _idClient;
}
float Reservation::getMontant() const{
	return _montant;
}


void Reservation::setIdReservation(int idReservation){
	_idReservation=idReservation;
}
void Reservation::setDebut(Date dateDebut){
	_dateDebut=dateDebut;
}
void Reservation::setFin(Date dateFin){
	_dateFin=dateFin;
}
void Reservation::setIdHotel(int idHotel){
	_idHotel=idHotel;
}
void Reservation::setIdChambre(int idChambre){
	_idChambre=idChambre;
}
void Reservation::setIdClient(int idClient){
	_idClient=idClient;
}
void Reservation::setMontant(int montant){
	_montant=montant;
}


std::string Reservation::infoReservation() const {
    std::string str;
    str = "Reservation N° " + std::to_string(getIdReservation())
     + " du " + getDebut().toString()
     + " au " + getFin().toString() 
     + " " + std::to_string(getMontant()) 
     + "€ \n";
    return str;
}

/*

void Reservation::setIdReservation(int id){
	_idReservation=id;
}
void Reservation::setType(Type type){
	_type=type;
}
void Reservation::setPrix(float prix){
	_prix=prix;
}
void Reservation::modifier(int id, Type type, float prix){
	setIdReservation(id);
	setType(type);
	setPrix(prix);
}
*/

