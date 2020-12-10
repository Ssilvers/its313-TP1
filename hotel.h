#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "chambre.h"

class Hotel{
private:
   int _idHotel;
   std::string _nomHotel;
   std::string _villeHotel;
   std::vector<Chambre> _listeChambre;

public:

   Hotel(int id, std::string nom, std::string ville);
   

   int getId() const;
   std::string getNom() const;
   std::string getVille() const;
  
   std::string infoHotel() const;


   void setId(int id);
   void setNom(std::string type);
   void setVille(std::string ville);
   void modifier(int id, std::string type, std::string ville);
};

#endif // HOTEL_H