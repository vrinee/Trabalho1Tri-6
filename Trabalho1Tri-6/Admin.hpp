#include <iostream>
#include <vector>

using namespace std;

class User;
class Produto;

class Admin {
	public:
		string nome;

		Admin();
		~Admin();

		void setSenha(string _senha);
		string getSenha();

		User criarUsuario();
		Produto criarProduto();
		void excluirUsuario(vector<User> &Usuario);
		void excluirProduto(vector<Produto> &Produto);

	private:
		string senha;

};