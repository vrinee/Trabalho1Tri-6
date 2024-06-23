#include <iostream>
#include <vector>
#include "Produto.hpp"

using namespace std;

Produto::Produto() {
}

Produto::~Produto() {
}

void Produto::setValor(float _valor) {
	valor = _valor;
}

float Produto::getValor() {
	return valor;
}

void Produto::setQuantidade(int _quantidade) {
	quantidade = _quantidade;
}

void Produto::adicionarQuantidade(int _quantidade) {
	quantidade += _quantidade;
}

void Produto::removerQuantidade(int _quantidade) {
	quantidade -= _quantidade;
}

int Produto::getQuantidade() {
	return quantidade;
}

void Produto::setDisponivel() {
	if (quantidade > 0) {
		disponivel = true;
	} else {
		disponivel = false;
	}
}

bool Produto::getDisponivel() {
	setDisponivel();
	return disponivel;
}

void Produto::setId(int _id) {
	id = _id;
}

int Produto::getId() {
	return id;
}



