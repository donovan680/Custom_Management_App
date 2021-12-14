#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string f_name;
	string l_name;
}name, temp_name;

struct Phone
{
	int reg_code;
	int home_code;
}phonenumber, temp_phonenumber;

struct customer
{
	int cust_number;
	Person name;
	string email;
	Phone phonenumber;
}client[10],temp_client;

void intro(); 
Person getting_temp_name();
Phone getting_temp_phonenumber();
customer temp(int c_num); 
int google(customer client[], int number_of_add, int target); 
void show_google(int temp_index); 
void list(customer client[], int i);


int main()
{
	int choice, c_num = 16001, number_of_add(0);

	do {
	intro();
	cin  >> choice;

		switch (choice)
		{
			case 1 :
				{
					int size(10), fin(1); 
					while((size > 0)&&(fin != 0))
					{	
						cout << "*** " << size << " Inserir  Cliente. ***" <<endl; 
						

						getting_temp_name();
						getting_temp_phonenumber();
						
						
						temp(c_num); 
					
						client[number_of_add] = temp_client;

						
						c_num = c_num + 1; 
						cout << "Para continuar adicionando clientes, digite 1. Para sair, digite 0. ." <<endl;
						cin  >> fin;
						number_of_add = number_of_add + 1; 
						size = size - 1; 

						if (size == 0) 
							{
			cout << "Para continuar adicionando clientes, digite 1. Para sair, digite 0." <<endl
	<< "Você atingiu o numero maximo que pode inserir" <<endl;   
		number_of_add = number_of_add - 1; 
										system ("pause");
										system ("cls");
							}
						else {
							if (fin == 0) 
							{
		cout << "Voltando ao menu principal." <<endl;
								number_of_add = number_of_add - 1;
								system ("pause");
								system ("cls");
							}}}}
			break;

			case 2 : 
				{
					int fin(1), temp_index; 
					do
					{
						int target; 

cout << "Procure um cliente pelo numero do cliente." <<endl
<< "Os numeros do cliente são iniciados em 16001"<<endl
 << "Entre com  numero  do Cliente : ";
						cin  >> target;

						google(client, number_of_add, target); 

						if(google(client, number_of_add, target) == -1) 
						{
							cout << "Nao haver resultado. Por favor, procure novamente." <<endl;
						}
						else 
						{
							temp_index = google(client, number_of_add, target); 
							 show_google(temp_index); 
							 cin >> fin;
						}
					}while(fin != 0);
				}


			break;

			case 3 :
				{
					cout <<" Numero  de Cliente " << "           Nome          " << "         Email        " <<" Número de  Telefone " <<endl
						 <<"-----------------" << "--------------------------" << "----------------------" <<"--------------" <<endl;

					for (int i=0; i<=number_of_add; i++)
						{
							list(client, i);
					    }

					system("pause");
				}

			break;

			case 4 : 
				{ 
					cout << "Tenha  um  bom dia!" <<endl;
					choice = 4;
					system ("pause");
				}
			break;

			default: 
				{
					system ("cls");
					cout << "Voce entrou com  numero errado" <<endl
						 << "Para terminar o programa, digite 4."<<endl
						 << "Para voltar ao menu principal, digite qualquer outro numero." <<endl;
					cin  >> choice;
					
				}



	
		}}while(choice != 4);

	return 0;
}

void intro()
{
		system ("cls");
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl
		     << "* * * *        Aplicacao de  Gerenciamento de  Clientes       * * * * " <<endl
			 << "*                                                           * " <<endl;
cout << "* 1:  Criar e adicionar um Cliente   * " <<endl
<< "* 2 :  Procurar um numero de  Cliente  * " <<endl
<< "*  3 : Exibir a lista de clientes  * " <<endl
<< "*   4 : Terminar  aplicacao     * " <<endl
 			 << "*                                                           * " <<endl
			 << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl
			 << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl;
}


Person getting_temp_name()
{
	cout << "Sobrenome  : " ;
	cin.ignore();
	getline(cin, temp_name.l_name);
	cout << "Primeiro  Nome	: " ;
	cin.ignore();
	getline(cin, temp_name.f_name);

	return temp_name;
}


Phone getting_temp_phonenumber()
{
	cout << "DDD (3 digits)			 : " ;
	cin >> temp_phonenumber.reg_code;
	cout << "Phone regional code (7 digits)			 : " ;
	cin >> temp_phonenumber.home_code;

	return temp_phonenumber;
}


customer temp(int c_num) 
{
	int index = 0; 
	cin.clear();
	cout << "Endereco de email 					   : " ;
	cin.ignore();
	getline(cin, temp_client.email);
	cout << "<< O numero do cliente ser gerado automaticamente >>" <<endl;
	cout << "Customer number                   : " << c_num <<endl; 
	temp_client.cust_number = c_num;
	temp_client.name = temp_name;
	temp_client.phonenumber = temp_phonenumber;
	
	
	return temp_client;
}

int google(customer client[], int number_of_add, int target)
{
	int index = 0;
	bool found = false; 
	while((found==false)&&(index <= number_of_add))
	{
		if (target == client[index].cust_number)
			{found = true;} 
				else {index++;} 
	}
	
	if (found == true) 
	{return index;} 
	else
	{return -1;}
}

void show_google(int temp_index)
{
	cout << "Resultado            : " << client[temp_index].name.f_name << " " << client[temp_index].name.l_name << "\n\n\n";
	cout << "Nome             : " << client[temp_index].name.f_name << " " << client[temp_index].name.l_name << endl;
	cout << "Numero de  Cliente   : " << client[temp_index].cust_number<<endl;
	cout << "Email             : " << client[temp_index].email<<endl;
	cout << "Número de  Telefone      : " << client[temp_index].phonenumber.reg_code<< " " << client[temp_index].phonenumber.home_code <<endl; 
	cout << "Para voltar ao menu principal, digite 0. \ nPara continuar pesquisando, digite 1."<<endl; 
}


void list(customer client[], int i) 
{
	cout.width(17);
	cout <<left << client[i].cust_number;
	cout.width(27);
	cout <<left << client[i].name.f_name <<" "<< client[i].name.l_name;
	cout.width(22);
	cout <<left << client[i].email; 
	cout.width(14);
	cout <<left << client[i].phonenumber.reg_code<<"-"<<phonenumber.home_code;
}