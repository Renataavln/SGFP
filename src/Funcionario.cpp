#include "Funcionario.h"
#include "TelefoneException.h"
#include <cstdlib>
#include <ctime>

Funcionario::Funcionario(){
    /* ... */
}

Funcionario::Funcionario(int designacao, double taxa)/*:Empresa(nome, CNPJ, data)*/{
    this->designacao = designacao;
    this->taxaAumento = taxa;
}

/* Inicio dos Get */
int Funcionario::getHorasTrabalhadas(){
    return this->horasTrabalhadas;
}

int Funcionario::getCodigo(){
    return this->codigoFuncionario;
}

int Funcionario::getIdade(){
    return this->idade;
}

double Funcionario::getSalario(){
    return this->salario;
}

double Funcionario::getTaxaAumento(){
    return this->taxaAumento;
}

Endereco Funcionario::getEndereco(){
    return this->endereco;
}

std::string Funcionario::getTelefone(){
    return this->telefone;
}

std::string Funcionario::getDesignacao(){
    switch(this->designacao){
        case 1:
            return "Presidente";
            break;
        case 2:
            return "Diretor";
            break;
        case 3:
            return "Gerente";
            break;
        case 4:
            return "Operador";
            break;
        default:
            break;
    }
}

std::string Funcionario::getNomeFuncionario(){
    return this->nomeFuncionario;
}

Data Funcionario::getDataIngresso(){
    return this->dataIngresso;
}
/* Fim dos Get */

/* Inicio dos Set */
void Funcionario::setHorasTrabalhadas(int horas){
    horasTrabalhadas = horas;
}

void Funcionario::setSalario(double salario){
    this->salario = salario;
}

void Funcionario::setDesignacao(int designacao){
    this->designacao = designacao;
}

void Funcionario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Funcionario::setTelefone(std::string telefone){
    if(telefone.size() == 11){
        for(int i = 0; i < 11; i++){
            if(telefone[i] < '0' || telefone[i] > 9){
                throw TelefoneException("Numero invalido digitado");
            }
        }
        int j = 0;
        for(int i = 0; i < 16; i++){
            if(i == 0){
                this->telefone[i] = '(';
                continue;
            }
            if(i == 3){
                this->telefone[i] = ')';
                continue;
            }
            if(i == 9){
                this->telefone[i] = '-';
                continue;
            }
            this->telefone[i] = telefone[j++];
        }
    }else{
        throw TelefoneException("Quantidade insuficiente de caracteres");
    }
}

void Funcionario::setNomeFuncionario(std::string nome){
    this->nomeFuncionario = nome;
}

void Funcionario::setDataIngresso(Data data){
    this->dataIngresso = data;
}

void Funcionario::setCodigoFuncionario(int codigo){
    this->codigoFuncionario = codigo;
}

/* Fim dos Set */

int Funcionario::gerarAleatorio(int intervaloMax){
    srand(time(NULL));

    return (rand() % (intervaloMax+1));
}
