
#include <string>
#include <iostream>
#include "Compte.h"

/*On souhaite créer une application qui utilise un compte Admin.
Créer une classe Admin possédant deux attributs privés :
le nom d’utilisateur composé de caractères alphanumériques (string),
un mot de passe composé au maximum de 10 caractères alphanumériques (char*).



Un attribut publique qui représente le numéro de compte Admin initialisé à 10
et qui sera auto incrémenté/décrémenté à chaque fois qu’un compte Admin sera créé/supprimé.*/



using namespace std;

class AdminAppl  : public Compte
{

public:
	static  int numeroAdmin;

	/* Définir un constructeur par défaut de la classe Admin.*/

	AdminAppl();

	/*2.	Définir un constructeur paramétré par  le numéro d’utilisateur d’un objet Admin.
	Le nom d’utilisateur et le mot de passe sont saisis par l’utilisateur et le mot de passe est masqué par des « * ». */

	AdminAppl(int pnumeroAdmin);

	/*3.	Définir un constructeur de copie de la classe Admin*/

	AdminAppl(const AdminAppl &Admin);

	/*4.	Définir un destructeur.*/
	~AdminAppl();


	/*9.	Surcharger l’opérateur d’affectation.*/

	AdminAppl & operator=(const AdminAppl &source);

	/* 10.	Ecrire une méthode qui permet de surcharger
	l’opérateur ==  et qui retourne true si deux objets Admin
	possèdent même nom d’utilisateur et même mot de passe ; false sinon. */

	bool operator==(const AdminAppl &source) const;

	/*11.	Surcharger l’opérateur != . */

	bool operator!=(const AdminAppl &source) const;

	/*12.	Surcharger l’opérateur << qui permet d’afficher le nom d’utilisateur
	et le mot de passe d’un objet Admin non masqué si le code secret est correct.*/

		/* fait directement dans AdminAppl.cpp*/


	friend std::ostream& operator<<(std::ostream &out, AdminAppl &source);

	friend class AdminGestion;

};


