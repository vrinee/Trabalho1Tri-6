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
		int excluirUsuario(vector<User> &Usuario);

	private:
		string senha;

};