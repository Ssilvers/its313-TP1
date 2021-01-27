#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "chambre.h"

#include <list>

class Hotel{
private:
   int _idHotel;
   std::string _nomHotel;
   std::string _villeHotel;
   
   std::vector<Chambre> _listeChambre;

public:

   Hotel(int id, std::string nom, std::string ville);
   

   int getIdHotel() const;
   std::string getNom() const;
   std::string getVille() const;
  
   std::string infoHotel() const;

   

   void setIdHotel(int id);
   void setNom(std::string type);
   void setVille(std::string ville);
   void modifier(int id, std::string type, std::string ville);
   friend std::ostream& operator<<(std::ostream& os, const Chambre& chambre);

   void addChambre(Chambre chambre);
   void chambres();
   std::vector<Chambre> getChambres() const;
};

#endif // HOTEL_H