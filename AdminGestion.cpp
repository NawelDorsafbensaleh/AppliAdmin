
#include "AdminGestion.h"
#include <conio.h>
#include <string.h>



/*13.	Ajouter une classe Responsable (à vous de déterminer classe mère ou fille ou amie)
qui permet de gérer les différents comptes Admin ( à vous de déterminer les différentes
fonctions membres et d’ajouter ce qui est nécessaire).*/

AdminGestion::AdminGestion(string puserId, string puserPassword)
{
	cout << "Creation AdminGestion " << endl;
	this->UserConnection = puserId;
	this->PasswordConnection = puserPassword;


}

AdminGestion::AdminGestion(int a, string puserId, string puserPassword)
{
	cout << "Creation AdminGestion : val : " << a << endl;
	this->UserConnection = puserId;
	this->PasswordConnection = puserPassword;

}


AdminGestion::~AdminGestion()
{
}


bool AdminGestion::AdminConnecte() {

	cout << "verifictation de connection" << endl;


	if ((UserConnection.compare(SuperAdmin) == 0) && (PasswordConnection.compare(SuperPassword)) == 0 ){
		return true;
	}

	return false;
}

void AdminGestion::manageExitfunct() {

	char ch;
	cout << endl <<endl << "Enter to return Menu : " << endl;
	while ((ch = _getch()) != 13) //enter type
	{
		cout << "Enter to return Menu : " << endl;
	}
}

void AdminGestion::ListerCompteAdmin() {


	system("cls");
	cout << "Liste des Comptes Admin" << endl;


	cout << "-----------------------------------------------------------" << endl;
	cout << " ID              |      Nom                                " << endl;
	for (std::map<int, AdminAppl*>::const_iterator itMap = mapAdmin.begin(); itMap != mapAdmin.end(); ++itMap)
	{
		// itMap est un pointeur. Vous pouvez accéder à la clé avec itMap->first, et la valeur avec itMap->second
		cout <<"   " <<  itMap->first <<"                     "<< mapAdmin[itMap->first]->getNom() << endl;

	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "Fin de la liste " << endl;
	cout << "-----------------------------------------------------------" << endl;

	manageExitfunct();
}


void AdminGestion::createUserAdmin(int id) {

	system("cls");
	cout << "createUserAdmin : createUserAdmin" << endl;

	mapAdmin[id] = new AdminAppl();

	manageExitfunct();

}

void AdminGestion::updateUserAdmin(int id) {

	system("cls");
	string lnom;
	cout << "updateUserAdmin" << endl;
	cout << "Nom actuel : " << mapAdmin[id]->getNom() << endl;
	cout << "updateUserAdmin: mettre à jour Nom" << endl;
	cin >> lnom;

	mapAdmin[id]->setNom(lnom);
	manageExitfunct();

}

void AdminGestion::updateUserPasswordAdmin(int id) {

	system("cls");
	string codesecret;
	cout << "updateUserPasswordAdmin" << endl;
	cout << "Modification du password " << endl;
	cout << "updateUserPasswordAdmin: saisir le code secret" << endl;
	cin >> codesecret;

	if (mapAdmin.find(id) != mapAdmin.end()) {
		if (mapAdmin[id]->codesecret.compare(codesecret)) {
			cout << "code secret erronée" << endl;
		}
		else {
			cout << "vous pouvez modifier votre password" << endl;
			std::string sPasswordappli;
			char ch;
			int i = 0;
			while ((ch = _getch()) != 13 && i < 10) //enter type
			{
				sPasswordappli += ch;
				std::cout << '*';
				i++;
			}

			strcpy(mapAdmin[id]->passwordappli, sPasswordappli.c_str());

			cout << "saisie effectué" << endl;
		}
	}
	else {
		cout << "Id non present" << endl;
	}


	manageExitfunct();
}

void AdminGestion::readUserAdmin(int id) {

	system("cls");
	cout << "readUserAdmin: readUserAdmin" << endl;

	if (mapAdmin.find(id) != mapAdmin.end()) {
		cout << "Nom : " << mapAdmin[id]->getNom() << endl;
		cout << "mail: " << mapAdmin[id]->getMail() << endl;
		cout << "numAdmin " << mapAdmin[id]->numeroAdmin << endl;
	}
	else {
		cout << "Id non present" << endl;
	}


	manageExitfunct();
}

void AdminGestion::manageForgetUserPasswordAdmin(int id) {

	system("cls");

	if (mapAdmin.find(id) != mapAdmin.end()) {

		string lcodesecret;
		string lmail;
		cout << "manageForgetUserPasswordAdmin" << endl;
		cout << "Password oublie " << endl;
		cout << "manageForgetUserPasswordAdmin: saisir le code secret" << endl;
		cin >> lcodesecret;

		if (mapAdmin[id]->codesecret.compare(lcodesecret) == 0) {
			cout << "code secret OK" << endl;

			cout << "manageForgetUserPasswordAdmin: saisir le mail" << endl;
			cin >> lmail;

			if (mapAdmin[id]->mail.compare(lmail) == 0) {
				cout << "mail OK" << endl;

				cout << "vous pouvez modifier votre password" << endl;
				std::string sPasswordappli;
				char ch;
				int i = 0;
				while ((ch = _getch()) != 13 && i < 10) //enter type
				{
					sPasswordappli += ch;
					std::cout << '*';
					i++;
				}

				strcpy(mapAdmin[id]->passwordappli, sPasswordappli.c_str());

				cout << "saisie effectué" << endl;
			}
			else {
				cout << "les saisies n ont pas de correspondance" << endl;
			}
		}
		else {
			cout << "les saisies n ont pas de correspondance" << endl;

		}
	}
	else {
		cout << "Id non present" << endl;
	}


	manageExitfunct();
}

void AdminGestion::duplicateUserAdmin(int id, int idcopie) {
	system("cls");


	if (mapAdmin.find(idcopie) != mapAdmin.end()) {

		mapAdmin[id] = new AdminAppl(*mapAdmin[idcopie]);

		cout << "id duplique" << endl;
	}
	else {
		cout << "Id non present" << endl;
	}

	manageExitfunct();
}

void AdminGestion::deleteUserAdmin(int id) {
	system("cls");
	cout << "deleteUserAdmin : deleteUserAdmin" << endl;

	if (mapAdmin.find(id) != mapAdmin.end()) {
		delete mapAdmin[id];
		mapAdmin.erase(id);
	}
	else {
		cout << "Id non present" << endl;
	}

	manageExitfunct();
}

void AdminGestion::manageCodeSecret(int id) {
	system("cls");
	string lcodesecret;

	if (mapAdmin.find(id) != mapAdmin.end()) {
		cout << "manageCodeSecret" << endl;
		cout << "Vérification code secret " << endl;
		cout << "manageCodeSecret: saisir le code secret pour controle" << endl;
		cin >> lcodesecret;

		if (mapAdmin[id]->codesecret.compare(lcodesecret) == 0) {
			cout << "code secret OK" << endl;

			cout << "manageCodeSecret: saisir le nouveau code secret" << endl;
			cin >> lcodesecret;

			mapAdmin[id]->codesecret = lcodesecret;

		}
		else {
			cout << "manageCodeSecret: code saisi erroné " << endl;
		}
	}
	else {
		cout << "Id non present" << endl;
	}
	manageExitfunct();
}

