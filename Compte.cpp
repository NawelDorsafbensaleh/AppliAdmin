
#include <conio.h>
#include <string.h>
#include "Compte.h"



Compte::Compte()
{
	cout << "Saisir le nom : " << endl;;
	cin >> nom;

	cout << "Saisir le password : " << endl;

	std::string sPasswordappli;
	char ch;
	int i = 0;
	while ((ch = _getch()) != 13 && i < 10) //enter type
	{
		sPasswordappli += ch;
		std::cout << '*';
		i++;
	}

	strcpy(passwordappli, sPasswordappli.c_str());

	cout << endl <<  "Saisir le codesecret : " << endl;
	cin >> codesecret;

	cout << "Saisir votre mail : " << endl;
	cin >> mail;

}

Compte::Compte(const Compte &Admin){

	this->nom = Admin.nom;
	for (int i = 0; i < 10; i++) {
		this->passwordappli[i] = Admin.passwordappli[i];
	}

	this->mail = Admin.mail;
	this->codesecret = Admin.codesecret;
	this->id = Admin.id;
}

Compte::~Compte() {

}

/*5.	Ecrire une méthode qui permet de retourner le nom d’utilisateur d’un compte.
*/
string Compte::getNom() {
	return this->nom;
}

/*6.	Ecrire une méthode qui permet de modifier le nom d’utilisateur d’un compte.
*/

void Compte::setNom(string pnom) {
	this->nom = pnom;
}


/*	Ecrire une méthode qui permet de retourner le id d’utilisateur d’un compte.
*/
int Compte::getId() {
	return this->id;
}

/*	Ecrire une méthode qui permet de modifier le id d’utilisateur d’un compte.
*/
void Compte::setId(int pId) {
	this->id = pId;
}

/*	Ecrire une méthode qui permet de retourner le mail d’utilisateur d’un compte.
*/
string Compte::getMail() {
	return this->mail;
}

/*	Ecrire une méthode qui permet de modifier le mail d’utilisateur d’un compte.
*/
void Compte::setMail(string pmail) {
	this->mail = pmail;
}

/*7.	Ecrire une méthode qui permet de modifier le mot de passe d’un compte Admin.
*/
void Compte::setPasswordappli(string &pPasswordappli) {

	strcpy(this->passwordappli, pPasswordappli.c_str());

}


string Compte::getCodesecret() {

	return this->codesecret;
}

void Compte::setCodesecret(string pcodesecret) {

	this->codesecret = pcodesecret;

}

/*8.	Ecrire une méthode qui permet d’afficher le mot de passe d’un compte.
Cette fonction demande de verifier un code secret que l’utilisateur doit fournir avant d’afficher le mot de passe.*/

char * Compte::getPaswordappli(bool pbool) {

	string lcodesecret;

	if (pbool) {
		return passwordappli;
	}
	else  {
		cout << "saisir le codesecret pour obtrenir le password : " << endl;
		cin >> lcodesecret;
		if (this->codesecret.compare(lcodesecret) == 0) {

			return passwordappli;
		}
	}

	return NULL;
}
