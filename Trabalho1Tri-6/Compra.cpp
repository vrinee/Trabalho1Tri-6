#include <iostream>
#include <vector>
#include "Compra.hpp"

using namespace std;

Compra::Compra() {
}

Compra::~Compra() {
}

void Compra::setTipoPagamento(bool _tipoPagamento) {
	tipoPagamento = _tipoPagamento;
}

bool Compra::getTipoPagamento() {
	return tipoPagamento;
}

void Compra::setValorTotal(float _valorTotal) {
	valorTotal = _valorTotal;
}

float Compra::getValorTotal() {
	return valorTotal;
}

void Compra::setIdAnuncio(int _idAnuncio) {
	idAnuncio = _idAnuncio;
}

int Compra::getIdAnuncio() {
	return idAnuncio;
}

void Compra::setIdUsuario(int _idUsuario) {
	idUsuario = _idUsuario;
}

int Compra::getIdUsuario() {
	return idUsuario;
}

void Compra::setId(int _id) {
	id = _id;
}

int Compra::getId() {
	return id;
}

void Compra::setData(vector<int> _data) {
	data = _data;
}

vector<int> Compra::getData() {
	return data;
}

