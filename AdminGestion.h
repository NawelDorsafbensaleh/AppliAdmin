

#include "AdminAppl.h"
#include <map>
#include <vector>


/*13.	Ajouter une classe Responsable (� vous de d�terminer classe m�re ou fille ou amie)
	qui permet de g�rer les diff�rents comptes Admin ( � vous de d�terminer les diff�rentes
	fonctions membres et d�ajouter ce qui est n�cessaire).*/

class AdminGestion
{

private:

	/* d�clarer une map pour referencer les comptes admin*/

	std::map<int, AdminAppl*> mapAdmin;



	string SuperAdmin = "admin";
	string SuperPassword ="admin";
	string UserConnection;
	string PasswordConnection;

	/*  */

public:
	int numeroAdmin_G = 1;
	AdminGestion(string puserId, string puserPassword);
	AdminGestion(int a, string puserId, string puserPassword);
	~AdminGestion();

	//READ_ALL_USERS = 1, CREATE_USER = 2, UPDATE_USER = 3, UPDATE_PASSWORDADMIN = 4, READ_USER = 5 , MANAGE_FORGETPASSWORD = 6, DUPLICATE_USERADMIN = 7, DELETE_USER = 8, MANAGE_SECRET_CODE = 9, END_PROGRAMM = 10, LOGOUT = 11

	int getNumeroAdmin() {
		return this->numeroAdmin_G;
	}

	void setNumeroAdmin(int pnumeroAdmin_G) {
		numeroAdmin_G = pnumeroAdmin_G;
	}

	//friend AdminAppl;

	/* lister les compte admin*/
	void ListerCompteAdmin();

	/* cr�er un compte admin */
	void createUserAdmin(int id);

	/* modifi� un compte admin */
	void updateUserAdmin(int id);

	/* modifi� le password d'un compte admin */
	void updateUserPasswordAdmin(int id);

	/* read user admin*/
	void readUserAdmin(int id);

	/* g�rer le mot de passe oubli� */
	void manageForgetUserPasswordAdmin(int id);

	/* dupliquer un compte Admin */
	void duplicateUserAdmin(int id, int idcopie);

	/* supprimer un compte admin */
	void deleteUserAdmin(int id);

	/* gestion du code secret*/
	void manageCodeSecret(int id);

	/*gestion de sortie de fonction*/
	void manageExitfunct();

	bool AdminConnecte();

	//friend class AdminAppl;
};

