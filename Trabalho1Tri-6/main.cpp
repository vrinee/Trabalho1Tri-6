#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include "Admin.hpp"
#include "Anuncio.hpp"
#include "Compra.hpp"
#include "Produto.hpp"
#include "User.hpp"
#include "interactions.hpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");

	vector<Admin> admins;
	vector<User> users;
	vector<Produto> produtos;
	vector<Anuncio> anuncios;
	vector<Compra> compras;

	int running = 1;
	int idAdmin = -1;
	int idUsuario = -1;

	while (running) {
		cout << "1 - Login" << endl;
		cout << "2 - Criar conta Admin" << endl;
		cout << "3 - Sair" << endl;
		int op;
		int op2;
		cin >> op;
		switch (op) {
		case 1:
			cout << "1 - Admin" << endl;
			cout << "2 - Usuario" << endl;
			cin >> op2;
			switch (op2) {
			case 1:
				idAdmin = loginADM(admins);
				if (idAdmin != -1) {
					menuADM(admins, users, produtos, anuncios, admins[idAdmin]);
					break;
				}
				cout << "Login invalido" << endl;
				break;
			case 2:
				idUsuario = loginUser(users);
				if (idUsuario != -1) {
					menuUser(users, produtos, anuncios, compras, users[idUsuario]);
					break;
				}
				cout << "Login invalido" << endl;
				break;
			default:
				cout << "Opcao invalida" << endl;
				break;
			}
			break;

		case 2:
			admins.push_back(criarADM());
			break;

		case 3:
			running = 0;
			break;
		default:
			cout << "Opcao invalida" << endl;
			break;

		}

	}

}