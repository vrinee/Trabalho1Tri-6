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
	anuncios.push_back(anuncio);
	anuncios.back().setIdUsuario(id);
	return anuncio;
}

void User::excluirAnuncio(Anuncio _anuncio) {
	for (int i = 0; i < anuncios.size(); i++)
	{
		if (anuncios[i].getId() == _anuncio.getId()) {
			anuncios.erase(anuncios.begin() + i);
			return;
		}
	}
}

void User::adicionarFavorito(Anuncio _anuncio) {
	favoritos.push_back(_anuncio);
}

void User::removerFavorito(Anuncio _anuncio) {
	for (int i = 0; i < favoritos.size(); i++)
	{
		if (favoritos[i].getId() == _anuncio.getId()) {
			favoritos.erase(favoritos.begin() + i);
			return;
		}
	}
}

Compra User::comprar(Anuncio _anuncio) {
	Compra compra;
	compras.push_back(compra);
	compras.back().setIdUsuario(id);
	compras.back().setIdAnuncio(_anuncio.getId());
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
