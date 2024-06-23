#include <iostream>
#include <vector>
#include "Anuncio.hpp"
#include "Produto.hpp"

using namespace std;

Anuncio::Anuncio() {

}

Anuncio::~Anuncio() {

}

void Anuncio::setValor() {
	valor = 0;
	for(int i = 0; i < produtos.size(); i++)
	{
		valor += produtos[i].getValor();
	}
}

float Anuncio::getValor() {
	setValor();
	return valor;
}

void Anuncio::mudarVezes() {
	vezesComprado++;
}

int Anuncio::getVezes() {
	return vezesComprado;
}

void Anuncio::setDisponivel() {
	for (int i = 0; i < produtos.size(); i++)
	{
		if (produtos[i].getDisponivel() == false) {
			disponivel = false;
			return;
		}
	}
	disponivel = true;
}

bool Anuncio::getDisponivel() {
	setDisponivel();
	return disponivel;
}

void Anuncio::setIdUsuario(int _idUsuario) {
	idUsuario = _idUsuario;
}

int Anuncio::getIdUsuario() {
	return idUsuario;
}

void Anuncio::setId(int _id) {
	id = _id;
}

int Anuncio::getId() {
	return id;
}

void Anuncio::adicionarProduto(Produto &_produto) {
	produtos.push_back(_produto);
}

