#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Anuncio;
class Produto;
class Compra;
class User;
class Admin;


int loginADM(vector<Admin> &admins);

int loginUser(vector<User> &usuarios);

void listarAnuncios(vector<Anuncio> &anuncios);

void listarFavoritos(vector<Anuncio> &anuncios, User &usuario);

void listarCompras(vector<Anuncio> &anuncios, vector<Compra> &compras, User &usuario);

void listarProdutos(vector<Produto> &produtos);

void listarUsuarios(vector<User> &usuarios);

void listarAdmins(vector<Admin> &admins);

Admin criarADM();

void criarUsuario(vector<User> &usuarios, Admin &adm);

void criarProduto(vector<Produto> &produtos, Admin &adm);

void criarAnuncio(vector<Anuncio> &anuncios,vector<Produto> &produtos, User &usuario);



void comprarAnuncio(vector<Anuncio> &anuncios,vector<Compra> &compras, User &usuario, int idAnuncio);


void excluirAnuncio(int idAnuncio, User &usuario, vector<Anuncio> &anuncios);

void excluirUsuario(vector<User> &usuarios, vector<Anuncio> &anuncios, Admin &admin);

void adicionarEstoque(vector<Produto> &produtos);
 

void listarAtributosUser(User &usuario);


void menuADM(vector<Admin> &admins, vector<User> &usuarios, vector<Produto> &produtos, vector<Anuncio> &anuncios, Admin &adm);

void menuUser(vector<User> &usuarios, vector<Produto> &produtos, vector<Anuncio> &anuncios,vector<Compra> &compras, User &usuario);

void menuAnuncio(vector<User> &usuarios, vector<Produto> &produtos, vector<Anuncio> &anuncios,vector<Compra> &compras, User &usuario, Anuncio &anuncio);
