#include <iostream>
#include <vector>


using namespace std;
class Anuncio;
class Compra;
class Produto;

class User {
	public:
		string login;
		vector<int> anuncios;
		vector<int> favoritos;
		vector<int> compras;

		User();
		~User();

		Anuncio criarAnuncio();
		void excluirAnuncio(int idAnuncio, vector<Anuncio> &anuncios);
		void listarAnuncios(vector<Anuncio> &anuncios);
		void adicionarFavorito(int idAnuncio);
		void removerFavorito(int idAnuncio);
		Compra comprar(int idAnuncio);

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