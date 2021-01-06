#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <vector>

class Client {
private:
   int _idClient;
   std::string _nom;
   std::string _prenom;
   int _nbreserv;
public: 
   
   Client(int id, std::string nom, std::string prenom, int nbreserv);
   int getIdClient() const;
   std::string getNom() const;
   std::string getPrenom() const;
   int getNbreserv() const;

   std::string infoClient() const;

   void setIdClient(int id);
   void setNom(std::string nom);
   void setPrenom(std::string prenom);
   void setNbreserv(int nbreserv);
   void modifier(int id, std::string nom, std::string prenom, int nbreserv);
};

/*
class Clients{
private:
   std::vector<Client> _clients;
public:
   Clients();
   void addClient(Client client);

   void liste();
};
*/

#endif // CLIENT_H