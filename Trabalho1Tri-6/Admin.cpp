#include <iostream>
#include <vector>
#include <string>
#include "Admin.hpp"
#include "User.hpp"
#include "Produto.hpp"

using namespace std;

Admin::Admin() {

}

Admin::~Admin() {

}

void Admin::setSenha(string _senha) {
	senha = _senha;
}

string Admin::getSenha() {
	return senha;
}

User Admin::criarUsuario() {
	User usuario;
	return usuario;
}

Produto Admin::criarProduto() {
	Produto produto;
	return produto;
}

int Admin::excluirUsuario(vector<User> &Usuario) {
	string login;
	string email;
	int op;
	cout << "Digite o login do usuario que deseja excluir: ";
	cin >> login;
	cout << "Digite o email do usuario que deseja excluir: ";
	cin >> email;
	for (int i = 0; i < Usuario.size(); i++)
	{
		if (Usuario[i].login == login && Usuario[i].getEmail() == email) {
			Usuario.erase(Usuario.begin() + i);
			return i;
		}
	}

	cout << "Usuario nao encontrado" << endl;
	cout << "1 - Tentar novamente" << endl;
	cout << "0 - Sair" << endl;
	cin >> op;
	if (op == 1) {
		return excluirUsuario(Usuario);
	}
	return -1;

}


 