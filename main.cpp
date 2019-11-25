#include "funcoes_caixa.h"

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
