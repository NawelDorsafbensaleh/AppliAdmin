
#include <string>
#include <iostream>
#include "Compte.h"

/*On souhaite cr�er une application qui utilise un compte Admin.
Cr�er une classe Admin poss�dant deux attributs priv�s :
le nom d�utilisateur compos� de caract�res alphanum�riques (string),
un mot de passe compos� au maximum de 10 caract�res alphanum�riques (char*).



Un attribut publique qui repr�sente le num�ro de compte Admin initialis� � 10
et qui sera auto incr�ment�/d�cr�ment� � chaque fois qu�un compte Admin sera cr��/supprim�.*/



using namespace std;

class AdminAppl  : public Compte
{

public:
	static  int numeroAdmin;

	/* D�finir un constructeur par d�faut de la classe Admin.*/

	AdminAppl();

	/*2.	D�finir un constructeur param�tr� par  le num�ro d�utilisateur d�un objet Admin.
	Le nom d�utilisateur et le mot de passe sont saisis par l�utilisateur et le mot de passe est masqu� par des � * �. */

	AdminAppl(int pnumeroAdmin);

	/*3.	D�finir un constructeur de copie de la classe Admin*/

	AdminAppl(const AdminAppl &Admin);

	/*4.	D�finir un destructeur.*/
	~AdminAppl();


	/*9.	Surcharger l�op�rateur d�affectation.*/

	AdminAppl & operator=(const AdminAppl &source);

	/* 10.	Ecrire une m�thode qui permet de surcharger
	l�op�rateur ==  et qui retourne true si deux objets Admin
	poss�dent m�me nom d�utilisateur et m�me mot de passe ; false sinon. */

	bool operator==(const AdminAppl &source) const;

	/*11.	Surcharger l�op�rateur != . */

	bool operator!=(const AdminAppl &source) const;

	/*12.	Surcharger l�op�rateur << qui permet d�afficher le nom d�utilisateur
	et le mot de passe d�un objet Admin non masqu� si le code secret est correct.*/

		/* fait directement dans AdminAppl.cpp*/


	friend std::ostream& operator<<(std::ostream &out, AdminAppl &source);

	friend class AdminGestion;

};


