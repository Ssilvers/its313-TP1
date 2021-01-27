#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

using namespace date;

class Reservation{
private:
   int _idReservation;
   Date _dateDebut;
   Date _dateFin;
   int _idHotel;
   int _idChambre;
   int _idClient;
   float _montant;
public:

   Reservation(int id, Date debut, Date fin, int idHotel,
   int idChambre, int idClient ,float montant);
   
   void CalculMontant(int nbrenuit, int nbreserv, float prix);

   int getIdReservation() const;
   Date getDebut() const;
   Date getFin() const;
   int getIdHotel() const;
   int getIdChambre() const;
   int getIdClient() const;
   float getMontant() const;

   void setIdReservation(int idReservation);
   void setDebut(Date dateDebut) ;
   void setFin(Date dateFin) ;
   void setIdHotel(int idHotel);
   void setIdChambre(int idChambre) ;
   void setIdClient(int idClient) ;
   void setMontant(int montant);
   void calculMontant(int nbrenuit,float prix,int fidelite);
  
   std::string infoReservation() const;

/*
   void setIdChambre(int id);
   void setType(Type type);
   void setPrix(float prix);
   void modifier(int id, Type type, float prix);
*/
};

#endif // CHAMBRE_H