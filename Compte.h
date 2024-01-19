#include <string>
#include <iostream>


/*
Class Compte. Déclaration d'un compte utilisateur simple
*/

using namespace std;

class Compte {


protected:
	string nom;
	int id;
	string mail;
	char passwordappli[10];
	string codesecret;


public:

	Compte();

	Compte(const Compte &Admin);

	~Compte();


	/*5.	Ecrire une méthode qui permet de retourner le nom d’utilisateur d’un compte */
	string getNom();

	/*6.	Ecrire une méthode qui permet de modifier le nom d’utilisateur d’un compte .*/
	void setNom(string pnom);

	/*	Ecrire une méthode qui permet de retourner le id d’utilisateur d’un compte*/
	int getId();

	/*	Ecrire une méthode qui permet de modifier le id d’utilisateur d’un compte.*/
	void setId(int pId);

	/*	Ecrire une méthode qui permet de retourner le mail d’utilisateur d’un compte */
	string getMail();

	/*	Ecrire une méthode qui permet de modifier le mail d’utilisateur d’un compte .*/
	void setMail(string pmail);

	/*7.	Ecrire une méthode qui permet de modifier le mot de passe d’un compte .*/
	void setPasswordappli(string &pPasswordappli);

	/* gestion de secret*/
	string getCodesecret();

	void setCodesecret(string pcodesecret);

	/*8.	Ecrire une méthode qui permet d’afficher le mot de passe d’un compte .
	Cette fonction demande de verifier un code secret
	que l’utilisateur doit fournir avant d’afficher le mot de passe.*/

	char * getPaswordappli(bool pbool);




};
