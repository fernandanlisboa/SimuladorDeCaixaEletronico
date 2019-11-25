#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <time.h>
#include <random>

using namespace std;

//estrutura
typedef struct{
	string nome;
	string conta;
	string senha;
	string agencia;
	string dinheiro;
}CONTA;

//criando lista
list <CONTA> Contas;

CONTA criarConta(string nome, string agencia, string conta, string valor, string senha);



/////////////////////////////////////////////////////////////////funcoes
//criar verificação de numeros repetidos
CONTA criarConta(string nome, string agencia, string conta, string valor, string senha){
	CONTA c;
	c.nome = nome;
	c.agencia = agencia;
	c.conta = conta;
	c.dinheiro = valor;
	c.senha = senha;
	return c;
}


bool existe_na_lista(string ag, string conta);

string sorteiaAg(){
	srand(time(NULL));
	int numero1 = 1000 + rand() % (1000 - 9000 + 1);
	int numero2 = ( rand() % 9 ) + 1;
	string ag = to_string(1000 + rand() % (1000 - 9000 + 1)); 
	ag += "-" + to_string(numero2);
	return ag;
}

string sorteiaConta(string ag, string conta){
	srand(time(NULL));
	do{
		int numero1 = 10000 + rand() % (10000 - 90000 + 1);
		int numero2 = ( rand() % 9 ) + 1;
		string conta = to_string(numero1);
		conta += "-" + to_string(numero2); 
	}while(existe_na_lista(ag, conta)); //enquanto encontrar uma conta igual na mesma agencia
	
	return conta;	
}

void printa_menu(){
	cout << "\t\t\t\t\t\t\tBem vindo(a) ao CAIXA CIPROG!" << endl << endl; 
	cout << "\tOPCOES:" << endl;
	cout << "[1] SAQUE" << endl;
	cout << "[2] SALDO" << endl;
	cout << "[3] TRANSFERENCIA" << endl;
	cout << "[4] DEPOSITO" << endl;
	cout << "[5] CONFIGURACOES DA CONTA" << endl;
	cout << "[6] SAIR" << endl;
}

void mostra_config(){
	cout << "\t[1] MUDAR SENHA" << endl;
	cout << "\t[2] ADICIONAR CONTA" << endl;
	cout << "\t[3] IMPRIMIR CODIGO"<< endl; 
}

	//inicio banco
void cria_arquivo(){
	fstream arquivo; //tipo arq
	string contas;
	arquivo.open("contas.txt", ios :: out); //criando
	arquivo << "\t\t\t CONTAS BANCARIAS:" << endl;
	arquivo.close();
}

void adiciona_ao_arquivo(fstream arquivo){ //essa funcao adiciona dados das contas bancarias ao arquivo sobreescrevendo-o
	list<CONTA> contas;
	list<CONTA>:: iterator it = contas.begin(); //posicionando ponteiro iterator
	arquivo.open("contas.txt", ios :: in, ios :: out);
	string palavras;
	arquivo << "\t\t\t\t\t\tCONTAS CADASTRADAS" << endl << endl; //titulo
	while( it != contas.end() ){
		palavras = it->nome;
		arquivo << "Nome: " << it->nome << endl;
		arquivo << "Agencia: " << it->agencia << endl;
		arquivo << "Conta: " << it->conta << endl;	
		arquivo << "Valor: R$" << it->dinheiro << endl << endl << endl;
		
		
	arquivo << "////////////////////////////////////////////////////" << endl;
		it++;
	}
		
	arquivo.close();
	
}

bool senha_valida(string senha, CONTA a){
	if(a.senha == senha){
		return true;
	}
	return false;
}

bool permissao(CONTA origem, string valor){
	if(valor > origem.dinheiro){

		return false; //nao ha dinheiro suficiente
	}
	return true;
}

void transferir(CONTA origem, string valor, CONTA destino){ //no caso de permissao possivel
	origem.dinheiro -= valor;
	destino.dinheiro += valor; //tentar copiar informações do arquivo anterior e no lugar colocar a lista jah atualizada
	
}

void deposito(CONTA desejada, string valor){
	desejada.dinheiro += valor;
}

void sacar(CONTA a, string valor){
	a.dinheiro -= valor;
	
}

/*
bool busca(fstream arquivo, string ag, string conta){ //busca no arquivo
	arquivo.open("contas.txt", ios :: in);
	string palavras;
	int cont = 0;
	while(getline(arquivo, palavras) && ( palavras != ag || palavras != conta ) ){
		cont++;
		if(palavras == nome){
			cont = 0;
			break;
			//ja existe essa conta, nao eh possivel cadastrar
		} 
	}
	if(cont != 0){
		cout << "Nao eh possivel encontrar essa conta!" << endl;
		return false;
	}
	else{
		//valor encontrado
		return true;
	}	
	arquivo.close();
}*/

bool existe_na_lista(string ag, string conta){
	list<CONTA>:: iterator it;
	for(it = Contas.begin(); it != Contas.end(); it++){
		if(it->agencia == ag && it->conta == conta){
			return true; //valor encontrado;
		}
	}
	return false; //valor nao enocntrado
}

CONTA busca_lista(string ag, string conta){
	list<CONTA>:: iterator it;
	for(it = Contas.begin();; it != Contas.end(); it++){
		if(it->agencia == ag){
			return it; //valor encontrado;
		}
	}
}


void muda_senha(string nova, CONTA a){
	list<CONTA>:: iterator it;
	for(it = contas.begin();; it != Contas.end(); it++){
		if(it->agencia == ag){
			it -> senha = a.senha; //nova senha; 
		}
	}	
}

void muda_dinheiro(CONTA a, string valor){
	list<CONTA>:: iterator it;
	for(it = Contas.begin(); it != Contas.end(); it++){
		if(it->agencia == ag){
			it -> senha = a.senha; //nova senha; 
		}
	}	
}

bool menor_nome(const CONTA& a, const CONTA& b){ //funcao especifica de ordenacao
	return ( a.nome < b.nome );
}



//ordenando inicialmente


//insere e ordena
void inserir_ordenado(CONTA a){
	list<CONTA> contas;
	list<CONTA>:: iterator it = contas.begin();
	contas.push_back(a); //insere
	sort(it = Contas.begin(), it = Contas.end(), menor_nome()); //ordena
}


