
#include <conio.h>
#include "AdminAppl.h"

/*variable numeroAdmin
*/

int AdminAppl::numeroAdmin = 10;

/*On souhaite créer une application qui utilise un compte Admin.
Créer une classe Admin possédant deux attributs privés : 
le nom d’utilisateur composé de caractères alphanumériques (string), 
un mot de passe composé au maximum de 10 caractères alphanumériques (char*) et 
un attribut publique qui représente le numéro de compte Admin initialisé à 10 et
qui sera auto incrémenté/décrémenté à chaque fois qu’un compte Admin sera créé/supprimé.*/

/*Définir un constructeur par défaut de la classe Admin.*/
AdminAppl::AdminAppl() : Compte()
{
	this->numeroAdmin++;
}


/*2.	Définir un constructeur paramétré par  le numéro d’utilisateur d’un objet Admin.
Le nom d’utilisateur et le mot de passe sont saisis par l’utilisateur et le mot de passe est masqué par des « * ». */
 
AdminAppl::AdminAppl(int pnumeroAdmin) : Compte () {
	
	this->numeroAdmin = pnumeroAdmin;

}

/*3.	Définir un constructeur de copie de la classe Admin.*/
AdminAppl::AdminAppl(const AdminAppl &Admin):Compte(Admin) {
	
	this->numeroAdmin++;
	
}


/*4.	Définir un destructeur.*/
AdminAppl::~AdminAppl()
{
	this->numeroAdmin--;

}


/*9.	Surcharger l’opérateur d’affectation.*/
AdminAppl &AdminAppl::operator=(const AdminAppl &source)
{
	if (&source != this)
	{
		this->nom = source.nom;
		for (int i = 0; i < 10; i++) {
			this->passwordappli[i] = source.passwordappli[i];
		}

		this->id = source.id;
		this->mail = source.mail;
		this->codesecret = source.codesecret;

	}
	return *this;
}

/*10.	Ecrire une méthode qui permet de surcharger l’opérateur ==  
et qui retourne true si deux objets Admin possèdent même nom d’utilisateur et même mot de passe ; false sinon. */

bool AdminAppl::operator==(const AdminAppl &source) const {

	if (this->nom == source.nom) {
		cout << "nom identique " << endl;

		for (int i = 0; i < 10; i++) {
			if (this->passwordappli[i] == source.passwordappli[i]) {
	
			}
			else {
				return false;
			}
		}	
	}
	else {
		return false;
	}

	return true;
}

/*11.	Surcharger l’opérateur !=.*/

bool AdminAppl::operator!=(const AdminAppl &source) const {

	if (this->nom != source.nom) {
		cout << "nom différent " << endl;

		for (int i = 0; i < 10; i++) {
			if (this->passwordappli[i] == source.passwordappli[i]) {
				return false;
			}
			
		}
	}
	else {
		return false;
	}

	return true;

}

/*12.	Surcharger l’opérateur << qui permet d’afficher le nom d’utilisateur
et le mot de passe d’un objet Admin non masqué si le code secret est correct.*/

std::ostream& operator<<(std::ostream &out, AdminAppl &source) {

	string lcodesecret;
	cout << "saisir le codesecret pour afficher le nom et password : " << endl;
	cin >> lcodesecret;
	if (source.codesecret.compare(lcodesecret) == 0) {
		out << "Nom : " << source.getNom() << endl << "Password : " << source.getPaswordappli(true) << endl;
		return out;
	}
	else {
		out << "Nom : " << source.getNom() << endl << "Password : *****************" << endl;
		return out;
	}
	
}
