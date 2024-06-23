#include <iostream>
#include <vector>
#include "User.hpp"
#include "Anuncio.hpp"
#include "Produto.hpp"
#include "Compra.hpp"

using namespace std;

User::User() {

}

User::~User() {

}

Anuncio User::criarAnuncio() {
	Anuncio anuncio;
	anuncio.setIdUsuario(id);
	return anuncio;
}

void User::excluirAnuncio(int idAnuncio, vector<Anuncio> &anuncios) {
	for (int i = 0; i < this->anuncios.size(); i++)
	{
		if (this->anuncios[i] == idAnuncio) {
			this->anuncios.erase(this->anuncios.begin() + i);
			anuncios.erase(anuncios.begin() + idAnuncio);
			return;
		}
	}
}

void User::listarAnuncios(vector<Anuncio> &anuncios) {
	for (int i = 0; i < anuncios.size(); i++)
	{
		if (anuncios[i].getIdUsuario() == id) {
			cout << "ID: " << anuncios[i].getId() << endl;
			cout << "Valor: " << anuncios[i].getValor() << endl;
			cout << "Disponivel: " << anuncios[i].getDisponivel() << endl;
			cout << "Vezes comprado: " << anuncios[i].getVezes() << endl;
		}
	}
}

void User::adicionarFavorito(int idAnuncio) {
	favoritos.push_back(idAnuncio);
}

void User::removerFavorito(int idAnuncio) {
	for (int i = 0; i < favoritos.size(); i++)
	{
		if (favoritos[i] == idAnuncio) {
			favoritos.erase(favoritos.begin() + i);
			return;
		}
	}
}

Compra User::comprar(int idAnuncio) {
	Compra compra;
	compra.setIdAnuncio(idAnuncio);
	compra.setIdUsuario(id);
	return compra;
}

void User::setSenha(string _senha) {
	senha = _senha;
}

string User::getSenha() {
	return senha;
}

void User::setEmail(string _email) {
	email = _email;
}

string User::getEmail() {
	return email;
}

void User::setTelefone(string _telefone) {
	telefone = _telefone;
}

string User::getTelefone() {
	return telefone;
}

void User::setEndereco(string _endereco) {
	endereco = _endereco;
}

string User::getEndereco() {
	return endereco;
}

void User::setCpf(string _cpf) {
	cpf = _cpf;
}

string User::getCpf() {
	return cpf;
}

void User::setId(int _id) {
	id = _id;
}

int User::getId() {
	return id;
}
