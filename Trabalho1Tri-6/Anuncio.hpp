#include <iostream>
#include <vector>

using namespace std;

class Produto;

class Anuncio {
	public:
		string titulo;
		string descricao;

		Anuncio();
		~Anuncio();

		void setValor(float _valor);
		float getValor();
		void setDisponivel();
		bool getDisponivel();
		void setIdUsuario(int _idUsuario);
		int getIdUsuario();
		void setId(int id);
		int getId();
		void adicionarProduto(Produto _produto);



	private:
		float valor;
		vector<Produto> produtos;
		bool disponivel;
		int idUsuario;
		int id;
};