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

void Admin::excluirUsuario(vector<User> &Usuario) {
	string login;
	string email;
	cout << "Digite o login do usuario que deseja excluir: ";
	cin >> login;
	cout << "Digite o email do usuario que deseja excluir: ";
	cin >> email;
	for (int i = 0; i < Usuario.size(); i++)
	{
		if (Usuario[i].login == login && Usuario[i].getEmail() == email) {
			Usuario.erase(Usuario.begin() + i);
			return;
		}
	}
}

void Admin::excluirProduto(vector<Produto> &Produto) {
	string nome;
	string cor;
	cout << "Digite o nome do produto que deseja excluir: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nome);
	cout << "Digite a cor do produto que deseja excluir: ";
	cin >> cor;

	for (int i = 0; i < Produto.size(); i++)
	{
		if (Produto[i].nome == nome && Produto[i].cor == cor) {
			Produto.erase(Produto.begin() + i);
			return;
		}
	}
}

