// ApplicationAdmin.cpp : Définit le point d'entrée pour l'application console.
//


#include "AdminGestion.h"
#include <map>

enum Options {
	READ_ALL_USERS = 1, CREATE_USER = 2, UPDATE_USER = 3, UPDATE_PASSWORDADMIN = 4, READ_USER = 5, MANAGE_FORGETPASSWORD = 6, DUPLICATE_USERADMIN = 7, DELETE_USER = 8 , MANAGE_SECRET_CODE = 9, END_PROGRAM = 10, LOGOUT = 11
};



int mainMenu(string puserid)
{
	system("cls");
	cout << "\nMenu Options User connecte " << puserid <<  endl
		<< endl << "1  - Liste les comptes Admin" << endl
		<< "2  - Creation de nouveau Comptes" << endl
		<< "3  - Mise a jour Comptes" << endl
		<< "4  - Mise a jour password de Compte" << endl
		<< "5  - Afficher les info Compte" << endl
		<< "6  - gestion du mot passe oublie" << endl
		<< "7  - Dupliquer un compte Admin" << endl
		<< "8  - supprimer un compte Admin" << endl
		<< "9  - Gestion du code Secret" << endl
		<< "10 - Quitter l application" << endl ;



	// stores the choice the user made
	string sch;
	cout << "Votre Choix: ";
	cin >> sch;

	int ch;
	ch = stoi(sch);

	while (ch > 11 || ch < 1)
	{
		system("cls");
		cout << "INVALID INPUT!" << endl;

		cout << "\nMenu Options User connecte : " << puserid << endl
			<< endl << "1  - Liste les comptes Admin" << endl
			<< "2  - Creation de nouveau Comptes" << endl
			<< "3  - Mise a jour Comptes" << endl
			<< "4  - Mise a jour password de Compte" << endl
			<< "5  - Afficher les info Compte" << endl
			<< "6  - gestion du mot passe oublie" << endl
			<< "7  - Dupliquer un compte Admin" << endl
			<< "8  - supprimer un compte Admin" << endl
			<< "9  - Gestion du code Secret" << endl
			<< "10 - Quitter l application" << endl ;

		cout << "Votre Choix: ";
		cin >> ch;
	}
	return ch;

}

int main(int argc, char *argv[])
{
	/* *******************************************/

	int choice;
	// data of the user logged in
	string userId, userEmail, userPassword;
	bool isAdmin = false;
	bool loggedIn = true;


	string id;

	/*  ******************************************/

	/* Connection de l'utilisateur admin de gestion avec id et password*/

	cout << "Connection User" << endl;
	cout << "Saisir le nom : ";
	cin >> userId;

	cout << "Saisir le password : ";
	cin >> userPassword;

	AdminGestion adminUserGestion(userId, userPassword);

	cout << "=========" << endl;
	cout << "LOGIN" << endl;
	cout << "=========" << endl;

	isAdmin = adminUserGestion.AdminConnecte();

	if (isAdmin)
	{
		cout << "=========" << endl;
		cout << "ADMIN MODE" << endl;
		cout << "Your ID: " << userId << endl;
		cout << "=========" << endl;

	}
	else
	{
		cout << "==========================" << endl;
		cout << "USER MODE (limited access)" << endl;
		cout << "Your ID: " << userId << endl;
		cout << "==========================" << endl;
	}

	loggedIn = true;
	while (1)
	{
		if (loggedIn)
		{
			choice = mainMenu(userId);
			if (choice == END_PROGRAM)
			{
				break;
			}
			switch (choice)
			{
				// more information visible if user is also an admin
			case READ_ALL_USERS:

					adminUserGestion.ListerCompteAdmin();

				break;

			case CREATE_USER:
				// only user with admin privilege can create users
				if (isAdmin)
				{
					cout << "=========" << endl;
					cout << "CREATION DE COMPTE" << endl;
					cout << "=========" << endl;
					cin.ignore();


					adminUserGestion.createUserAdmin(adminUserGestion.getNumeroAdmin());
					adminUserGestion.setNumeroAdmin(adminUserGestion.getNumeroAdmin() + 1);

					cout << "Compte cree!" << endl;
				}
				else
				{
					cout << "=================" << endl;
					cout << "RESTRICTED ACCESS" << endl;
					cout << "=================" << endl;
					cout << "VOUS AVEZ BESOIN DE DROITS!" << endl;
				}
				break;

			case UPDATE_USER:
				cout << "=========" << endl;
				cout << "MISE A JOUR" << endl;
				cout << "=========" << endl;


				if (isAdmin)
				{
					cout << "Choisir un Id du compte que vous voulez modifier: " << endl;
					// to ignore the \n entered earlier which is still in the buffer
					cin.ignore();
					getline(cin, id);

					while (id.length() == 0)
					{
						cout << "Id invalide . Recommencer!" << endl;
						getline(cin, id);
					}
					stoi(id);
					adminUserGestion.updateUserAdmin(stoi(id));

				}
				else
				{
					cout << "Vous n avez pas les droits pour modifier ce compte" << endl;
					//adminUserGestion.updateUserAdmin();
				}
				break;

			case UPDATE_PASSWORDADMIN:

				cout << "=========" << endl;
				cout << "Mise à jour " << endl;
				cout << "=========" << endl;


				if (isAdmin)
				{
					cout << "Choisir un Id du compte pour lequel que vous voulez modifier le password: " << endl;
					// to ignore the \n entered earlier which is still in the buffer
					cin.ignore();
					getline(cin, id);

					while (id.length() == 0)
					{
						cout << "Id invalide . Recommencer!" << endl;
						getline(cin, id);
					}

					adminUserGestion.updateUserPasswordAdmin(stoi(id));

				}
				else
				{
					cout << "Vous n avez pas les droits pour modifier ce compte" << endl;

				}

				break;

			case READ_USER:

				// looking up a single user through their id
				cout << "Choisir un Id du compte pour lequel que vous voulez les infos:" << endl;
				cin.ignore();
				getline(cin, id);

				adminUserGestion.readUserAdmin(stoi(id));



				break;
			case MANAGE_FORGETPASSWORD:

				// looking up a single user through their id
				cout << "Choisir un Id du compte pour lequel que vous avez oublié le password:" << endl;
				cin.ignore();
				getline(cin, id);


				if (isAdmin)
				{
					adminUserGestion.manageForgetUserPasswordAdmin(stoi(id));
				}
				else
				{
					cout << "Vous n avez pas les droits pour modifier ce compte" << endl;
				}

				break;

			case DUPLICATE_USERADMIN:

				// looking up a single user through their id
				cout << "Choisir un Id du compte pour lequel que vous avez dupliquer le compte:" << endl;
				cin.ignore();
				getline(cin, id);


				if (isAdmin)
				{
					adminUserGestion.setNumeroAdmin(adminUserGestion.getNumeroAdmin() + 1);
					adminUserGestion.duplicateUserAdmin(adminUserGestion.getNumeroAdmin(),stoi(id));

				}
				else
				{
					cout << "Vous n avez pas les droits pour modifier ce compte" << endl;
				}

				break;


			case DELETE_USER:
				// only admin can delete users
				if (isAdmin)
				{
					cout << "Choisir un Id du compte pour que vous voulez suprrimer: " << endl;
					// to ignore the \n entered earlier which is still in the buffer
					cin.ignore();
					getline(cin, id);

					adminUserGestion.deleteUserAdmin(stoi(id));
				}
				else
				{
					cout << "=================" << endl;
					cout << "DROITS RESTREINT " << endl;
					cout << "=================" << endl;
					cout << "VOUS BESOIN DE DROITS!" << endl;
				}
				break;

			case MANAGE_SECRET_CODE:

				if (isAdmin)
				{
					cout << "Choisir un Id du compte pour que vous voulez gerer le code secret: " << endl;
					// to ignore the \n entered earlier which is still in the buffer
					cin.ignore();
					getline(cin, id);


					adminUserGestion.manageCodeSecret(stoi(id));
				}
				else
				{
					cout << "=================" << endl;
					cout << "DROITS RESTREINT " << endl;
					cout << "=================" << endl;
					cout << "VOUS BESOIN DE DROITS!" << endl;
				}
				break;



			case LOGOUT:
				cout << "=================" << endl;
				cout << "LOGGING OUT" << endl;
				cout << "=================" << endl;

				loggedIn = false;
				break;

			default:
				cerr << "Choix Invalide !" << endl;
				break;
			}
		}
		else
		{
			cout << "=========" << endl;
			cout << "LOGIN AGAIN" << endl;
			cout << "=========" << endl;

			cin.ignore();

			/* connection du gestionnaire des comptes Admin*/

			if (isAdmin)
			{
				cout << "=========" << endl;
				cout << "ADMIN MODE" << endl;
				cout << "Your ID: " << userId << endl;
				cout << "=========" << endl;


			}
			else
			{
				cout << "==========================" << endl;
				cout << "USER MODE (limited access)" << endl;
				cout << "Your ID: " << userId << endl;
				cout << "==========================" << endl;
			}

			loggedIn = true;
		}
	}
	return 0;
}

