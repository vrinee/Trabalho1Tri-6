#include <iostream>
#include <vector>
#include <string>
#include "User.hpp"
#include "Produto.hpp"
#include "Compra.hpp"
#include "Admin.hpp"
#include "Anuncio.hpp"
#include "interactions.hpp"


using namespace std;


int loginADM(vector<Admin> &admins) {
	string nome;
	string senha;
	int op;
	cout << "Digite o nome do administrador: ";
	cin >> nome;
	cout << "Digite a senha do administrador: ";
	cin >> senha;
	for (int i = 0; i < admins.size(); i++)
	{
		if (admins[i].getSenha() == senha and admins[i].nome == nome) {
			return i;
		}
	}
	cout << "Administrador nao encontrado" << endl;
	cout << "1 - Tentar novamente" << endl;
	cout << "0 - Sair" << endl;
	cin >> op;
	if (op == 1) {
		return loginADM(admins);
	}
	return -1;
}

int loginUser(vector<User> &usuarios) {
	string login;
	string senha;
	int op;
	cout << "Digite o login do usuario: ";
	cin >> login;
	cout << "Digite a senha do usuario: ";
	cin >> senha;
	for (int i = 0; i < usuarios.size(); i++)
	{
		if (usuarios[i].getSenha() == senha and usuarios[i].login == login) {
			return i;
		}
	}
	cout << "Usuario nao encontrado" << endl;
	cout << "1 - Tentar novamente" << endl;
	cout << "0 - Sair" << endl;
	cin >> op;
	if (op == 1) {
		return loginUser(usuarios);
	}
	return -1;
}

void listarAnuncios(vector<Anuncio> &anuncios) {
	for (int i = 0; i < anuncios.size(); i++) {
		cout << "-----------------------------------" << endl;
		cout << "Anuncio " << i << endl;
		cout << "Título: " << anuncios[i].titulo << endl;
		cout << "Descrição: " << anuncios[i].descricao << endl;
		cout << "Preço: R$ " << anuncios[i].getValor() << endl;
		if (anuncios[i].getDisponivel()) {
			cout << "Disponivel" << endl;
		}
		else {
			cout << "Indisponivel" << endl;
		}
	}
}

void listarFavoritos(vector<Anuncio> &anuncios, User &usuario) {
	for (int i = 0; i < usuario.favoritos.size(); i++) {
		int id = usuario.favoritos[i];
		cout << "-----------------------------------" << endl;
		cout << "Anuncio " << i << endl;
		cout << "Título: " << anuncios[i].titulo << endl;
		cout << "Descrição: " << anuncios[i].descricao << endl;
		cout << "Preço: R$ " << anuncios[i].getValor() << endl;
		if (anuncios[i].getDisponivel()) {
			cout << "Disponivel" << endl;
		}
		else {
			cout << "Indisponivel" << endl;
		}
	}
}

void listarCompras(vector<Anuncio> &anuncios, vector<Compra> &compras, User &usuario) {
	for (int i = 0; i < usuario.compras.size(); i++) {
		int idAnuncio = compras[usuario.compras[i]].getIdAnuncio();
		cout << "-----------------------------------" << endl;
		cout << "Compra " << i << endl;
		cout << "Título: " << anuncios[idAnuncio].titulo << endl;
		cout << "Preço: R$ " << compras[usuario.compras[i]].getValorTotal() << endl;
	}
}

void listarProdutos(vector<Produto> &produtos) {
	for (int i = 0; i < produtos.size(); i++) {
		cout << "-----------------------------------" << endl;
		cout << "Produto " << i << endl;
		cout << "Nome: " << produtos[i].nome << endl;
		cout << "Cor: " << produtos[i].cor << endl;
		cout << "Descrição: " << produtos[i].descricao << endl;
		cout << "Tipo: " << produtos[i].tipo << endl;
		cout << "Preço: R$ " << produtos[i].getValor() << endl;
		cout << "Quantidade: " << produtos[i].getQuantidade() << endl;
		if (produtos[i].getDisponivel()) {
			cout << "Disponivel" << endl;
		}
		else {
			cout << "Indisponivel" << endl;
		}
	}
}

void listarUsuarios(vector<User> &usuarios) {
	for (int i = 0; i < usuarios.size(); i++) {
		cout << "-----------------------------------" << endl;
		cout << "Usuario " << i << endl;
		cout << "Login: " << usuarios[i].login << endl;
		cout << "Email: " << usuarios[i].getEmail() << endl;
	}
}

void listarAdmins(vector<Admin> &admins) {
	for (int i = 0; i < admins.size(); i++) {
		cout << "-----------------------------------" << endl;
		cout << "Admin " << i << endl;
		cout << "Nome: " << admins[i].nome << endl;
	}
}

Admin criarADM() {
	Admin admin;
	string nome;
	string senha;
	cout << "Digite o nome do administrador: ";
	cin >> nome;
	cout << "Digite a senha do administrador: ";
	cin >> senha;
	admin.nome = nome;
	admin.setSenha(senha);
	return admin;
}

void criarUsuario(vector<User> &usuarios, Admin &adm) {
	usuarios.push_back(adm.criarUsuario());
	usuarios.back().setId(usuarios.size() - 1);
	string login;
	string senha;
	string email;
	string telefone;
	string endereco;
	string cpf;
	cout << "Digite o login do usuario(sem espaços): ";
	cin >> login;
	cout << "Digite a senha do usuario: ";
	cin >> senha;
	cout << "Digite o email do usuario: ";
	cin >> email;
	cout << "Digite o telefone do usuario: ";
	cin >> telefone;
	cout << "Digite o endereco do usuario: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, endereco);
	cout << "Digite o cpf do usuario: ";
	cin >> cpf;

	usuarios.back().login = login;
	usuarios.back().setSenha(senha);
	usuarios.back().setEmail(email);
	usuarios.back().setTelefone(telefone);
	usuarios.back().setEndereco(endereco);
	usuarios.back().setCpf(cpf);
}

void criarProduto(vector<Produto> &produtos, Admin &adm) {
	produtos.push_back(adm.criarProduto());
	produtos.back().setId(produtos.size() - 1);
	string nome;
	string cor;
	string descricao;
	string tipo;
	float preco;
	int quantidade;
	cout << "Digite o nome do produto: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, nome);
	cout << "Digite a cor do produto: ";
	cin >> cor;
	cout << "Digite a descricao do produto: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, descricao);
	cout << "Digite o tipo do produto: ";
	cin >> tipo;
	cout << "Digite o preco do produto: ";
	cin >> preco;
	cout << "Digite a quantidade do produto: ";
	cin >> quantidade;

	produtos.back().nome = nome;
	produtos.back().cor = cor;
	produtos.back().descricao = descricao;
	produtos.back().tipo = tipo;
	produtos.back().setValor(preco);
	produtos.back().setQuantidade(quantidade);
	produtos.back().setDisponivel();
	
}

void criarAnuncio(vector<Anuncio> &anuncios, vector<Produto> &produtos, User &usuario) {
	anuncios.push_back(usuario.criarAnuncio());
	anuncios.back().setId(anuncios.size() - 1);
	string titulo;
	string descricao;
	int idProduto;
	int op;
	int run = 1;


	while (run == 1) {
		cout << "Você deseja digitar o nome do produto(0) ou listar os produtos(1)?" << endl;
		cin >> op;
		if (op == 0) {
			string nome;
			string cor;
			cout << "Digite o nome do produto: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, nome);
			cout << "Digite a cor do produto: ";
			cin >> cor;
			for (int i = 0; i < produtos.size(); i++)
			{
				if (produtos[i].nome == nome and produtos[i].cor == cor) {
					anuncios.back().adicionarProduto(produtos[i]);
					break;
				}
			}
		}
		else if (op == 1) {
			listarProdutos(produtos);
			cout << "Digite o id do produto que deseja adicionar ao anuncio: ";
			cin >> idProduto;
			anuncios.back().adicionarProduto(produtos[idProduto]);
		}
		cout << "Deseja adicionar mais produtos ao anuncio?(1 - sim 0 - não)" << endl;
		cin >> run;	
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Digite o titulo do anuncio: ";
	getline(cin, titulo);
	cout << "Digite a descricao do anuncio: ";
	getline(cin, descricao);

	anuncios.back().titulo = titulo;
	anuncios.back().descricao = descricao;

}

void comprarAnuncio(vector<Anuncio> &anuncios, vector<Compra> &compras, User &usuario, int idAnuncio) {
	compras.push_back(usuario.comprar(idAnuncio));
	compras.back().setId(compras.size() - 1);
	anuncios[idAnuncio].mudarVezes();
	int tipo;
	int aux;
	vector<int> data;

	cout << "Digite o dia da compra: ";
	cin >> aux;
	data.push_back(aux);
	cout << "Digite o mes da compra: ";
	cin >> aux;
	data.push_back(aux);
	cout << "Digite o ano da compra: ";
	cin >> aux;
	data.push_back(aux);
	compras.back().setData(data);

	cout << "Digite o tipo de pagamento(1 - parcelado, 2 - a vista): " << endl;
	cin >> tipo;

	compras.back().setTipoPagamento(tipo);
	compras.back().setValorTotal(anuncios);

	for (int i = 0; i < anuncios[idAnuncio].produtos.size(); i++)
	{
		anuncios[idAnuncio].produtos[i].removerQuantidade(1);
	}

	usuario.compras.push_back(compras.size() - 1);
}

void excluirAnuncio(int idAnuncio, User &usuario, vector<Anuncio> &anuncios) {
	for (int i = 0; i < usuario.anuncios.size(); i++)
	{
		if (usuario.anuncios[i] == idAnuncio) {
			usuario.anuncios.erase(usuario.anuncios.begin() + i);
			anuncios.erase(anuncios.begin() + idAnuncio);
			return;
		}
	}

	anuncios.erase(anuncios.begin() + idAnuncio);
	
}

void excluirUsuario(vector<User> &usuarios, vector<Anuncio> &anuncios, Admin &admin) {
	int idUsuario = admin.excluirUsuario(usuarios);
	if (idUsuario != -1) {
		for (int i = 0; i < anuncios.size(); i++)
		{
			if (anuncios[i].getIdUsuario() == idUsuario) {
				anuncios.erase(anuncios.begin() + i);
			}
		}
	}
}

void adicionarEstoque(vector<Produto> &produtos) {
	int idProduto;
	int quantidade;
	int op;
	cout << "Você deseja listar os produtos(1) ou digitar o id do produto(0)?" << endl;
	cin >> op;
	if (op == 1) {
		listarProdutos(produtos);
	}
	cout << "Digite o id do produto que deseja adicionar ao estoque: ";
	cin >> idProduto;
	cout << "Digite a quantidade que deseja adicionar ao estoque: ";
	cin >> quantidade;
	produtos[idProduto].adicionarQuantidade(quantidade);
}

void listarAtributosUser(User &usuario) {
	cout << "-----------------------------------" << endl;
	cout << "Login: " << usuario.login << endl;
	cout << "Email: " << usuario.getEmail() << endl;
	cout << "Telefone: " << usuario.getTelefone() << endl;
	cout << "Endereco: " << usuario.getEndereco() << endl;
	cout << "CPF: " << usuario.getCpf() << endl;
}

void menuADM(vector<Admin> &admins, vector<User> &usuarios, vector<Produto> &produtos, vector<Anuncio> &anuncios, Admin &adm) {
	int op;
	int idUsuario;
	int run = 1;
	while (run == 1) {
		cout << "1 - Listar usuarios" << endl;
		cout << "2 - Listar produtos" << endl;
		cout << "3 - Listar anuncios" << endl;
		cout << "4 - Listar admins" << endl;
		cout << "5 - Criar usuario" << endl;
		cout << "6 - Criar produto" << endl;
		cout << "7 - Excluir usuario" << endl;
		cout << "8 - Adicionar estoque" << endl;
		cout << "9 - Listar atributos de um usuario" << endl;
		cout << "10 - Sair" << endl;
		cin >> op;
		switch (op) {
			case 1:
				listarUsuarios(usuarios);
				break;
			case 2:
				listarProdutos(produtos);
				break;
			case 3:
				listarAnuncios(anuncios);
				break;
			case 4:
				listarAdmins(admins);
				break;
			case 5:
				criarUsuario(usuarios, adm);
				break;
			case 6:
				criarProduto(produtos, adm);
				break;
			case 7:
				excluirUsuario(usuarios, anuncios, adm);
				break;
			case 8:
				adicionarEstoque(produtos);
				break;
			case 9:
				cout << "Digite o id do usuario que deseja ver os atributos: ";
				cin >> idUsuario;
				listarAtributosUser(usuarios[idUsuario]);
				break;
			case 10:
				run = 0;
				break;

			default:
				cout << "Opcao invalida" << endl;
				break;
		}
	}
}

void menuUser(vector<User> &usuarios, vector<Produto> &produtos, vector<Anuncio> &anuncios, vector<Compra> &compras, User& usuario) {
	int op;
	int run = 1;

	while (run == 1) {
		cout << "1 - Listar seus anuncios" << endl;
		cout << "2 - Listar favoritos" << endl;
		cout << "3 - Listar compras" << endl;
		cout << "4 - Criar anuncio" << endl;
		cout << "5 - Ver anuncios" << endl;
		cout << "6 - acessar anuncio" << endl;
		cout << "7 - Sair" << endl;
		cin >> op;
		switch (op) {
		case 1:
			usuario.listarAnuncios(anuncios);
			break;
		case 2:
			listarFavoritos(anuncios, usuario);
			break;
		case 3:
			listarCompras(anuncios, compras, usuario);
			break;
		case 4:
			criarAnuncio(anuncios, produtos, usuario);
			break;
		case 5:
			listarAnuncios(anuncios);
			break;
		case 6:
			int idAnuncio;
			cout << "Digite o id do anuncio que deseja acessar: ";
			cin >> idAnuncio;
			menuAnuncio(usuarios, produtos, anuncios, compras, usuario, anuncios[idAnuncio]);
			break;
		case 7:
			run = 0;
			break;
		default:
			cout << "Opcao invalida" << endl;
			break;
		}
	}
}

void menuAnuncio(vector<User>& usuarios, vector<Produto>& produtos, vector<Anuncio>& anuncios, vector<Compra>& compras, User& usuario, Anuncio& anuncio) {
	cout << "Id: " << anuncio.getId() << endl;
	cout << "Titulo: " << anuncio.titulo << endl;
	cout << "Descricao: " << anuncio.descricao << endl;
	cout << "Valor: " << anuncio.getValor() << endl;
	cout << "Disponivel: " << anuncio.getDisponivel() << endl;
	cout << "Vezes comprado: " << anuncio.getVezes() << endl;
	int op;
	int run = 1;
	int access = 0;

	while (run == 1) {
		cout << "1 - Comprar anuncio" << endl;
		cout << "2 - favoritar anuncio" << endl;
		if (anuncio.getIdUsuario() == usuario.getId()) {
			cout << "3 - Excluir anuncio" << endl;
			access = 1;
		}
		cout << "4 - Sair" << endl;
		cin >> op;
		switch (op) {
		case 1:
			comprarAnuncio(anuncios, compras, usuario, anuncio.getId());
			break;
		case 2:
			usuario.adicionarFavorito(anuncio.getId());
			break;
		case 3:
			if (access == 1) {
				excluirAnuncio(anuncio.getId(), usuario, anuncios);
			}
			else {
				cout << "Voce nao tem permissao para excluir esse anuncio" << endl;
			}
			break;
		case 4:
			run = 0;
			break;
		default:
			cout << "Opcao invalida" << endl;
			break;
		}
	}
}



