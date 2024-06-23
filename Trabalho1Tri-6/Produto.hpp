#include <iostream>

using namespace std;

class Produto {
	public:
		string tipo;
		string nome;
		string cor;

		Produto();
		~Produto();

		
		void setValor(float _valor);
		float getValor();
		void setQuantidade(int _quantidade);
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
