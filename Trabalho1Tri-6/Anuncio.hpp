#include <iostream>
#include <vector>

using namespace std;

class Produto;

class Anuncio {
	public:
		string titulo;
		string descricao;
		vector<Produto> produtos;

		Anuncio();
		~Anuncio();

		void setValor();
		float getValor();
		void mudarVezes();
		int getVezes();
		void setDisponivel();
		bool getDisponivel();
		void setIdUsuario(int _idUsuario);
		int getIdUsuario();
		void setId(int id);
		int getId();
		void adicionarProduto(Produto &_produto);



	private:
		float valor = 0;
		int vezesComprado = 0;
		bool disponivel = true;
		int idUsuario;
		int id;
};