#ifndef CLIENT_H
#define CLIENT_H
#include <string>

class Client {
private:
   int _id;
   std::string _nom;
   std::string _prenom;
   int _nbreserv;
public: 
   
   Client(int id, std::string nom, std::string prenom, int nbreserv);
   int getId() const;
   std::string getNom() const;
   std::string getPrenom() const;
   int getNbreserv() const;

   std::string info() const;

   void setId(int id);
   void setNom(std::string nom);
   void setPrenom(std::string prenom);
   void setNbreserv(int nbreserv);
   void modifier(int id, std::string nom, std::string prenom, int nbreserv);
};
#endif // CLIENT_H