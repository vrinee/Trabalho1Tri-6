#include <iostream>
#include <vector>


using namespace std;
class Anuncio;
class Compra;
class Produto;

class User {
	public:
		string login;
		vector<Anuncio> anuncios;
		vector<Anuncio> favoritos;
		vector<Compra> compras;

		User();
		~User();

		Anuncio criarAnuncio();
		void excluirAnuncio(Anuncio _anuncio);
		void adicionarFavorito(Anuncio _anuncio);
		void removerFavorito(Anuncio _anuncio);
		Compra comprar(Anuncio _anuncio);

		void setSenha(string _senha);
		string getSenha();
		void setEmail(string _email);
		string getEmail();
		void setTelefone(string _telefone);
		string getTelefone();
		void setEndereco(string _endereco);
		string getEndereco();
		void setCpf(string _cpf);
		string getCpf();
		void setId(int _id);
		int getId();


	protected:
		string email;
		string telefone;
		string endereco;
		string cpf;

	private:
		string senha;
		int id;

};