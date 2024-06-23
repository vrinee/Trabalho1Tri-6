#include <iostream>
#include <vector>

using namespace std;


class Compra {
	public:

		Compra();
		~Compra();

		void setTipoPagamento(bool _tipoPagamento);
		bool getTipoPagamento();
		void setValorTotal(float _valorTotal);
		float getValorTotal();
		void setIdAnuncio(int _idAnuncio);
		int getIdAnuncio();
		void setIdUsuario(int _idUsuario);
		int getIdUsuario();
		void setId(int _id);
		int getId();
		void setData(vector<int> _data);
		vector<int> getData();


	private:
		bool tipoPagamento;
		float valorTotal;
		int idAnuncio;
		int idUsuario;
		int id;
		vector<int> data;
};