#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

enum Type{Simple,Double,Familiale,Deluxe};

class Chambre{
private:
   int _idChambre;
   Type _type;
   float _prix;
public:

   Chambre(int id, Type type, float prix);
   

   int getIdChambre() const;
   Type getType() const;
   float getPrix() const;
  
  std::string infoChambre() const;


   void setIdChambre(int id);
   void setType(Type type);
   void setPrix(float prix);
   void modifier(int id, Type type, float prix);
};

#endif // CHAMBRE_H