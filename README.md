# its313-TP1
TP1 DESCHAMPS - EL ALAOUI

Compte Rendu TP C++
Sujet n°1 : Ne vous endormez pas

L’objectif de ce sujet de TP était de concevoir une application de gestion des réservations d’un hôtel.
Nous avons réalisé les 11 questions composant ce sujet. Quelques indications sur notre démarche sont données plus bas.
Partie 1 : Création des classes (Questions 1 à 5)
Nous avons commencé par la création des classes comme indiquées dans le sujet. Ainsi, nous avons obtenu les classes Client, Chambre, Hôtel, Réservation, plus la classe Date récupérée dans le cours.
Ces 5 classes possèdent toutes des setters pour modifier les valeurs des variables membres, et des getters pour les récupérer.

Question 1 : La clase Date est récupérée du cours.

Question 2 : Pour la classe Client : Aucune remarque particulière

Question 3 : Pour la classe Chambre : Nous avons choisi arbitrairement de prendre 4 types de chambres : 
Simple (n°0), Double (n°1), Familiale (n°2) et Deluxe (n°3)

Question 4 : Pour la classe Hôtel : Aucune remarque particulière
Question 5 : Pour la classe Réservation : 
Pour les informations sur l’hôtel, la chambre, et le client, nous avons eu des difficultés à utiliser des pointeurs pour accéder directement aux objets associés, donc nous avons choisi d’utiliser des entiers représentants les ID des objets, que nous pourrons par la suite récupérer grâce aux vecteurs contenant toutes les chambres/clients/…
Pour le calcul du montant, nous avons choisi une réduction de 1% pour chaque réservation déjà enregistrée pour le client (variable membre de client _nbreserv dans notre cas)







Partie 2 : Utilisation des classes dans une application (Questions 6 à 11)

Question 6 : Nous avons créé 10 chambres que nous avons associées à un même hôtel grâce à la fonction « addChamre » permettant d’ajouter une chambre au vecteur de chambre qui est une variable membre de la classe Hôtel. Ces chambres sont réparties en 3 Simple / 5 Double / 2 Deluxe / 0 Familiale.
Puis nous avons réalisé les surcharges d’opérateur << pour faciliter l’affichage des informations.

Question 7 : Pour les dates, il est demandé à l’utilisateur d’entrer le jour, puis le mois, puis l’année (ex : 16 puis 8 puis 2021), pour la date de Début puis pour la date de Fin. On teste ensuite : si la date de début se situe après la date de fin, si les 2 dates ne sont pas déjà passés, et si leur format est correct (30 ou 31 jours / 12 mois / …). En cas de problème, il est demandé de ressaisir ces informations.
Pour le calcul du nombre de nuit, on incrémente la date de début jusqu’à ce qu’elle soit égale à la date de fin et on compte le nombre d’itération qui correspondra donc au nombre de nuit.

Question 8 : On demande à l’utilisateur de sélectionner le type de chambre en entrant une valeur numérique (0 pour simple, …). On effectue ensuite une vérification sur la saisit pour redemander en cas de problème.
Pour la vérification de la disponibilité de la chambre, nous avons choisit de procéder en 2 étapes :
- On regarde toutes les chambres occupées sur la période donnée : grâce à la fonction « checkDispo » à laquelle on entre en paramètres le vecteur de réservations et les dates de début et de fin. Cette fonction retourne un vecteur contenant les ID des chambres occupées sur la période.
- On utilise le vecteur retourné précédemment ainsi que le type de chambre saisit pour trouver une chambre disponible (donc on passe aussi en paramètre le vecteur des chambres). On regarde à l’aide d’une boucle si l’ID de la 1ère chambre est libre ou pas grâce au vecteur des chambres occupées, puis, si elle ne l’est pas, on regarde son type. Si ces 2 informations sont bonnes, on retourne l’ID de la chambre en question, sinon on retourne 0 pour indiquer qu’aucune chambre de ce type c’est disponible.
	Des réservations factices permettent de tester cette fonctionnalité (après saisit des dates): elles occupent toutes les chambres de type 0 (Simple) sur la période du 10/10/2021 au 15/10/2021. Il suffit donc de demander une chambre simple sur cette période pour voir qu’aucune chambre n’est disponible.

Question 9 : On demande à l’utilisateur de rentrer un nom. (Dans notre cas, 8 personnes s’appellent Jean et 2 Patrick)
On affiche ensuite la liste des clients avec ce nom grâce au vecteur de client que l’on compare à la saisit. L’utilisateur peut ensuite choisir la bonne personne grâce à un système de chiffre.
Puis on affiche les informations grâce la surcharge faite à la question 6.

Question 10 : On créer d’abord la nouvelle réservation puis on calcule le montant grâce à la fonction « calculMontant » de la question 5, à laquelle on entre en paramètre le nombre de nuit, le prix de la chambre et la fidélité du client.
On « push_back() » ensuite cette réservation dans le vecteur de réservation.
Une boucle permet de recommencer la création d’un réservation (ligne ≈ 367), il suffit de modifier la valeur du while pour augmenter le nombre d’itération.

Question 11 : La fonction « afficherReservations » permet d’afficher toutes les réservations à l’aide d’une boucle while.
La fonction « afficherReservationsN » fonctionne de la même manière, mais compare l’ID entré en paramètre avec l’ID de chaque réservation pour afficher seulement le bon élément.
La fonction « afficherReservationCN » prend en paramètre l’ID du client dont on souhaite afficher les réservations et fonctionne pareil que la fonction précédente. Cependant, l’utilisateur peut saisir directement l’ID mais aussi le nom du client. On passe donc pas une conversion string -> int pour voir le type saisit : si la conversion est bonne, il a entré un nombre, sinon, un nom, que l’on va utiliser dans la fonction « clientNom » de la question 9 afin de récupérer le bon ID.
La fonction de modification est dans la classe Réservation.
La fonction d’annulation recherche la bonne réservation comme la 2ème fonction de cette question, puis utilise « vecteur.erase(i) » pour supprimer la ième case
