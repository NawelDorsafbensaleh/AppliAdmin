
#include <conio.h>
#include "AdminAppl.h"

/*variable numeroAdmin
*/

int AdminAppl::numeroAdmin = 10;

/*On souhaite cr�er une application qui utilise un compte Admin.
Cr�er une classe Admin poss�dant deux attributs priv�s : 
le nom d�utilisateur compos� de caract�res alphanum�riques (string), 
un mot de passe compos� au maximum de 10 caract�res alphanum�riques (char*) et 
un attribut publique qui repr�sente le num�ro de compte Admin initialis� � 10 et
qui sera auto incr�ment�/d�cr�ment� � chaque fois qu�un compte Admin sera cr��/supprim�.*/

/*D�finir un constructeur par d�faut de la classe Admin.*/
AdminAppl::AdminAppl() : Compte()
{
	this->numeroAdmin++;
}


/*2.	D�finir un constructeur param�tr� par  le num�ro d�utilisateur d�un objet Admin.
Le nom d�utilisateur et le mot de passe sont saisis par l�utilisateur et le mot de passe est masqu� par des � * �. */
 
AdminAppl::AdminAppl(int pnumeroAdmin) : Compte () {
	
	this->numeroAdmin = pnumeroAdmin;

}

/*3.	D�finir un constructeur de copie de la classe Admin.*/
AdminAppl::AdminAppl(const AdminAppl &Admin):Compte(Admin) {
	
	this->numeroAdmin++;
	
}


/*4.	D�finir un destructeur.*/
AdminAppl::~AdminAppl()
{
	this->numeroAdmin--;

}


/*9.	Surcharger l�op�rateur d�affectation.*/
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

/*10.	Ecrire une m�thode qui permet de surcharger l�op�rateur ==  
et qui retourne true si deux objets Admin poss�dent m�me nom d�utilisateur et m�me mot de passe ; false sinon. */

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

/*11.	Surcharger l�op�rateur !=.*/

bool AdminAppl::operator!=(const AdminAppl &source) const {

	if (this->nom != source.nom) {
		cout << "nom diff�rent " << endl;

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

/*12.	Surcharger l�op�rateur << qui permet d�afficher le nom d�utilisateur
et le mot de passe d�un objet Admin non masqu� si le code secret est correct.*/

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
