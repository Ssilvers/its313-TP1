#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <string>

enum Type{Simple,Double,Familiale,Deluxe};

class Chambre{
private:
   int _id;
   Type _type;
   float _prix;
public:

   Chambre(int id, Type type, float prix);
   

   int getId() const;
   Type getType() const;
   float getPrix() const;
  
  std::string info() const;


   void setId(int id);
   void setType(Type type);
   void setPrix(float prix);
   void modifier(int id, Type type, float prix);
};

#endif // CHAMBRE_H