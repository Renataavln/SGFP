#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <fstream>
#include "Funcionario.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"
#include "Diretor.h"
#include "HistoricoArquivo.h"
#include <vector>
#include "TentativaAbrirArquivo.h"
#include "InvalidoArgumentoArquivoException.h"

#define QUANTIA_ARQUIVOS 4

#define TAMANHO_MAX 20

class Arquivo{
	
	public:
		
		// O construtor irá inicializar o arquivo recebendo o nome dos 4 tipo de arquivos
		Arquivo();

		void mostraHistorico(int tipoFuncionario, int codigo); 

		void criaArquivoCsv(std::vector < Funcionario *> &funcionariosVec);

		void adicionaArquivoCsv(Funcionario *); //armazena somente do presidente

		void criaBaseDadosCsv(const std::vector < Funcionario * >&funcionariosVec);
		void addPresidenteBaseDadosCsv(Funcionario *);
		void criaArquivoBaseDadosZerado();
		void carregaDadosCsv(std::vector < Funcionario * > &operadores, std::vector < Funcionario * > &gerentes, std::vector < Funcionario * > &diretores, Funcionario **presidente);
			
	private:
		/* Arquivos para saida de dados	*/
		std::ofstream arquivoFuncionariosSaida[QUANTIA_ARQUIVOS];
	
		/* Contém os nomes dos arquivos	*/
		std::string nomeArquivos[QUANTIA_ARQUIVOS];
		/* Arquivos para entrada de dados	*/
		std::ifstream arquivosEntradas[QUANTIA_ARQUIVOS];
	

		
		/*3 = Presidente; 2 = Diretor; 1 = Gerente; 0 = Operador*/

		std::string path = "../.gitignore/Dados/"; // path de armazenamento
		


};
















#endif
