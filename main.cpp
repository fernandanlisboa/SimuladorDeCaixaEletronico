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

//criando contas
CONTA c1, c2, c3, c4;
c1 = criarConta("Fernanda Lisboa", "30202-2", "2110-4", "300,00", "010101", );
Contas.push_back(c1);
c2 = criarConta("Lucia Cristina", "33245-0", "2110-4", "100,00", "10101" );
Contas.push_back(c2);
c3 = criarConta("Juliana Oliveira", "34566-9", "2304-8", "200,00", "202020"); 
Contas.push_back(c3);
c4 = criarConta("Maria Oliveira", "38766-8", "2323-3", "110,00", "102030");
Contas.push_back(c4);


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
	string ag = to_string(numero1); 
	ag += "-" + to_string(numero2);
	return ag;
}

string sorteiaConta(string ag){
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
}

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




int main()
{
	int opcao;
	string nome, agencia, conta, valor, senha;
	do
	{
		printa_menu();
		switch(opcao)
		{
		case 1: //saque

			cout << "Digite a agência: ";
			cin >> agencia;
			cout << "Digite a conta: ";
			cin >> conta;
			cout << "Digite o valor: ";
			cin >> valor;
			if( existe_na_lista(agencia, conta) )
			{
				cout << "Digite a senha de 6 digitos: ";
				cin >> senha;

				if( senha_valida(senha, permissao(busca_lista(agencia, conta) ) )  //senha valida
			{
				if( permissao(busca_lista(agencia, conta), valor) )  //
					{
						sacar(busca_lista(agencia, conta), valor); //sacando
						cout << "SAQUE REALIZADO COM SUCESSO!!!" << endl;
					}
					else
					{
						cout << "NAO EH POSSIVEL REALIZAR SAQUE!" << endl; //nao ha saldo suficiente
					}
				}

				else
				{
					cout << "SENHA INVALIDA!" << endl;
				}
			}
			else
			{
				cout << "Nao existe essa conta!" << endl; //conta inexistente
			}

			break;

		
		
		case 2: //saldo
			cout << "Digite a agencia: ";
			cin >> agencia;
			cout << "Digite a conta: ";
			cin >> conta;
			if( existe_na_lista(agencia, conta) )
			{
				cout << "Digite a senha de 6 digitos: ";
				cin >> senha;

				if( senha_valida(senha, permissao(busca_lista(agencia, conta) ) )  //senha valida
			{

				CONTA encontrada = busca_lista(agencia, conta);
					cout << "Saldo: " << encontrada.dinheiro << endl; //saldo
				}

				else
				{
					cout << "SENHA INVALIDA!" << endl;
				}
			}
			else
			{
				cout << "Nao existe essa conta!" << endl; //conta inexistente
			}
			break;

		case 3: //transferencia
			string agDestinada, contaDestinada;
			CONTA saida, chegada;
			cout << "Digite sua agencia: ";
			cin >> agencia;
			cout << "Digite sua conta: ";
			cin >> conta;
			if( existe_na_lista(agencia, conta) )
			{
				cout << "Agora, digite a agencia destinaria: ";
				cin >> agDestinada;
				cout << "Digite a conta e destino: ";
				cin >> contaDestinada;
				if( existe_na_lista(agDestinada, contaDestinada) )  //conta destinada existe
				{
					chegada = busca_lista(agDestinada, contaDestinadaa);
					cout << chegada.nome << endl << chegada.conta << endl << chegada.agencia;
					cout << "Digite o valor desejado: ";
					cin >> valor;
					cout << "Digite sua senha de 6 digitos: ";
					cin >> senha;

					if( senha_valida(senha, permissao(busca_lista(agencia, conta) ) )  //senha valida
				{

					if( permissao(busca_lista(agencia, conta), valor) ){
							CONTA saida = busca_lista(agencia, conta);
							transferir(saida, valor, encontrada);
							cout << "Transferencia concluida com sucesso!" << endl;
						}

						else
						{
							cout << "NAO EH POSSIVEL REALIZAR TRANSFERENCIA!" << endl; //nao ha saldo suficiente
						}
					}

					else
					{
						cout << "SENHA INVALIDA!" << endl;
					}
				}
			}

			else
			{
				cout << "Nao existe essa conta!" << endl; //conta inexistente
			}
			break;

		
		
		case 4: //deposito
			CONTA destinada;
			cout << "Digite a agencia: ";
			cin >> agencia;
			cout << "Digite a conta: ";
			cin >> conta;
			if( existe_na_lista(agencia, conta) )
			{
				if( existe_na_lista(agDestinada, contaDestinada) )  //conta destinada existe
				{
					destinada = busca_lista(agencia, conta);
					do
					{
						if(((opcao != 1) && (opcao != 2) ))
						{
							cout << "Opcao invalida!!! Tente novamente!" << endl;
						}
						cout << destinada.nome << " conta correta? Digite 1 para sim e 2 para nao. " << endl;
						cin >> opcao;
					}
					while((opcao != 1) && (opcao != 2) );

					if(opcao == 1)
					{
						cout << "Digite o valor desejado: ";
						cin >> valor;
						deposito(destinada, valor);
						cout << "Deposito realizado com sucesso!" << endl;
					}
					else
					{
						//volta ao menu
					}
				}
			}

			else
			{
				cout << "Nao existe essa conta!" << endl; //conta inexistente
			}
			break;

		
		
		case 5: //configuracoes da conta
			//ABRIR MENU
			CONTA encontrada;
			string newSenha;
			cout << "Digite a agencia: ";
			cin >> agencia;
			cout << "Digite a conta: ";
			cin >> conta;
			if( existe_na_lista(agDestinada, contaDestinada) )
			{
				mostra_config();
				cin >> opcao;
				if(opcao == 1)
				{
					encontrada = busca_lista(agencia, conta);
					do
					{
						if(senha != newSenha)
						{
							cout << "As senhas nao conferem, por favor tente novamente!" << endl << endl;
						}
						cout << "Digite a nova senha: ";
						cin >> senha;
						cout << "Digite novamente a nova senha: ";
						cin >> newSenha;
					}
					while(senha != newSenha);
					encontrada.senha = newSenha;
					cout << "Senha alterada com sucesso!" << endl;
				}

				else if(opcao == 2)
				{
					CONTA nova;
					cout << "Digite seu nome completo: ";
					cin.ignore();
					geline(cin, nome);
					nova.nome = nome;
					nova.agencia = sorteiaAg();
					nova.agencia = sorteiaConta(nova.agencia);
					cout << "Agora, digite sua senha: ";
					do
					{
						cin >> senha;
						cout << "Repita a senha: ";
						cin >> newSenha;
						if(senha != newSenha)
						{
							cout << "As senhas nao conferem, por favor tente novamente!" << endl << endl;
							cout << "Digite a senha mais uma vez: ";
						}
					}
					while(senha != newSenha);
					nova.senha = senha;

					cout << "Conta cadastrada com sucesso!!! Como um beneficio inicial, voce ja possui o valor de R$100,00 em sua conta! Aproveite!" << endl;
					inserir_ordenado(nova);
				}
			}
			else
			{
				cout << "CONTA INEXISTENTE!" << endl;
			}
			break;

		default: //invalido
			cout << "OPCAO INVALIDA! POR FAVOR, TENTE OUTRA VEZ!" << endl;
			break;
		}
	}
	while(opcao != 0 || opcao > 5);
	return 0;
}
