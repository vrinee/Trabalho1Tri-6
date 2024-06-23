#include <iostream>

using namespace std;

class Produto {
	public:
		string tipo;
		string nome;
		string cor;
		string descricao;

		Produto();
		~Produto();

		
		void setValor(float _valor);
		float getValor();
		void setQuantidade(int _quantidade);
		void adicionarQuantidade(int _quantidade);
		void removerQuantidade(int _quantidade);
		int getQuantidade();
		void setDisponivel();
		bool getDisponivel();
		void setId(int _id);
		int getId();

		
	private:
		float valor;
		int quantidade;
		bool disponivel;
		int id;
};
