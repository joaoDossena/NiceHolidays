#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //Talvez não seja necessária
#include "cliente.h"

using namespace std;

//STRUCTS
typedef struct morada //Struct para morada da agência e de clientes
{
    string rua;
    string nrPorta;
    string nrAndar;
    string codPostal;
    string localidade;
}morada_t;
typedef struct cliente //Struct para clientes
{
    string nome;
    string nif;
    string agregadoFamiliar;
    morada_t morada;
    vector<int> pacoteID;
    float compras;
}cliente_t;

//FUNÇÔES
//Menu
void menuClientes(void) /**Falta comentar */ //Permite ao usuário escolher o que fazer com clientes
{
    int escolha;
    cout << "CLIENTES" << endl << "####################" << endl << "[1] Adicionar cliente" << endl << "[2] Deletar cliente" << endl << "[3] Alterar cliente" << endl << "[4] Ver cliente" << endl;
    cout << "[5] Voltar" << endl <<"####################" << endl;
    do
    {
        cin >> escolha;
        if(escolha<1||escolha>5)
        {
            system("cls");
            cout << "CLIENTES" << endl << "####################" << endl << "[1] Adicionar cliente" << endl << "[2] Deletar cliente" << endl << "[3] Alterar cliente" << endl << "[4] Ver cliente" << endl;
            cout << "[5] Voltar" << endl <<"####################" << endl;
            cout << "Numero invalido! Digite outro numero: ";
        }

    }while(escolha<1||escolha>5);

    switch(escolha)
    {
        case 1:
            system("cls");
            addClient();
            break;
        case 2:
            system("cls");
            deleteClient();
            break;
        case 3:
            system("cls");
            alterClient();
            break;
        case 4:
            system("cls");
            readClient();
            break;
        case 5:
            system("cls");
            menu();
            break;
    }
}

//Criação/Adição
void addClient(void) /**Falta comentar*/ //Adiciona um cliente em um ficheiro de clientes dado pelo usuário
{
    int temp; //Declaração de variáveis
    bool terminar = false; // ciclo = false;
    string filename;
    ofstream outfile;
    cliente_t cliente;

    cout << "Digite o nome do ficheiro de clientes (+.txt): "; //Abertura do ficheiro dado pelo usuário
    cin.clear(); //Limpeza do buffer do teclado
    getline(cin, filename);

    outfile.open(filename.c_str(), ofstream::app);
    if(outfile.is_open())
    {
        do
        {
            cout << "Nome do cliente: ";
            getline(cin, cliente.nome);
            outfile << cliente.nome << endl;
            cout << "NIF do cliente: ";
            getline(cin, cliente.nif);
            outfile << cliente.nif << endl;
            cout << "Numero de pessoas no agregado familiar: ";
            getline(cin, cliente.agregadoFamiliar);
            outfile << cliente.agregadoFamiliar << endl;
            cout << "MORADA" << endl << "Rua de morada: ";
            getline(cin, cliente.morada.rua);
            outfile << cliente.morada.rua << " / ";
            cout << "Numero de porta: ";
            getline(cin, cliente.morada.nrPorta);
            outfile << cliente.morada.nrPorta << " / ";
            cout << "Numero de andar: ";
            getline(cin, cliente.morada.nrAndar);
            outfile << cliente.morada.nrAndar << " / ";
            cout << "Codigo postal: ";
            getline(cin, cliente.morada.codPostal);
            outfile << cliente.morada.codPostal << " / ";
            cout << "Localidade: ";
            getline(cin, cliente.morada.localidade);
            outfile << cliente.morada.localidade << endl;

            cout << "Pacotes (Ctrl-Z para terminar): ";
            do
            {
                cin >> temp;
                if(cin.fail() && cin.eof())
                {
                    terminar = true;
                    cin.clear();
                    break;
                }

                else
                {
                    cliente.pacoteID.push_back(temp);
                    cin.clear();
                }

            }while(!terminar);

            sort(cliente.pacoteID.begin(), cliente.pacoteID.end());

            for(unsigned int i =0; i<cliente.pacoteID.size(); i++)
            {
                outfile << cliente.pacoteID.at(i);
                if(i<cliente.pacoteID.size()-1)
                    outfile << " ; ";
                else
                    outfile << endl;
            }
            cout << "Compras totais: ";
            cin >> cliente.compras;
            outfile << cliente.compras << endl;
            outfile << "::::::::::" << endl;
        }while(!terminar);
        outfile.close();
    }
    else
        cout << "Erro ao abrir o ficheiro!" << endl;
    cout << endl << endl << "Pressione Enter para voltar ao menu de clientes.";
    cin.ignore();
    system("cls");
    menuClientes();
}

//Alteração
void alterClient(void) /**Falta comentar*/ //Altera um cliente num ficheiro de clientes
{
    string clienteAlt, line, filename;
    cliente_t cliente;
    ifstream fin;
    ofstream fout;
    int temp;
    bool terminar = false;

    cout << "Nome do ficheiro de clientes (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());
    fout.open("temp.txt");
    if(!fin.is_open()||!fout.is_open())
        cout << "Erro ao abrir o ficheiro!" << endl;
    else
    {
        cout << "Insira o nome do cliente a ser alterado: ";
        getline(cin, clienteAlt);
        while(getline(fin, line))
        {
            if(line==clienteAlt)
            {
                for(unsigned int i=0; i<5; i++)
                    fin.ignore(1000, '\n');
                cout << "Novo nome do cliente: ";
                getline(cin, cliente.nome);
                fout << cliente.nome << endl;
                cout << "NIF do cliente: ";
                getline(cin, cliente.nif);
                fout << cliente.nif << endl;
                cout << "Numero de pessoas no agregado familiar: ";
                getline(cin, cliente.agregadoFamiliar);
                fout << cliente.agregadoFamiliar << endl;
                cout << "MORADA" << endl << "Rua de morada: ";
                getline(cin, cliente.morada.rua);
                fout << cliente.morada.rua << " / ";
                cout << "Numero de porta: ";
                getline(cin, cliente.morada.nrPorta);
                fout << cliente.morada.nrPorta << " / ";
                cout << "Numero de andar: ";
                getline(cin, cliente.morada.nrAndar);
                fout << cliente.morada.nrAndar << " / ";
                cout << "Codigo postal: ";
                getline(cin, cliente.morada.codPostal);
                fout << cliente.morada.codPostal << " / ";
                cout << "Localidade: ";
                getline(cin, cliente.morada.localidade);
                fout << cliente.morada.localidade << endl;

                cout << "Pacotes (Ctrl-Z para terminar): ";
                do
                {
                    cin >> temp;
                    if(cin.fail() && cin.eof())
                    {
                        terminar = true;
                        cin.clear();
                        break;
                    }

                    else
                    {
                        cliente.pacoteID.push_back(temp);
                        cin.clear();
                    }
                }
                while(!terminar);

                sort(cliente.pacoteID.begin(), cliente.pacoteID.end());

                for(unsigned int i =0; i<cliente.pacoteID.size(); i++)
                {
                    fout << cliente.pacoteID.at(i);
                    if(i<cliente.pacoteID.size()-1)
                        fout << " ; ";
                    else
                        fout << endl;
                }
                cout << "Compras totais: ";
                cin >> cliente.compras;
                fout << cliente.compras << endl;
            }
            else
                fout << line << endl;
        }
        fin.close();
        fout.close();
        const char * p = filename.c_str();
        remove(p);
        rename("temp.txt", p);
        cout << "Cliente " << clienteAlt << " alterado com sucesso!" << endl;
    }
    cout << endl << endl << "Pressione Enter para voltar ao menu de clientes.";
    cin.ignore();
    cin.ignore();
    system("cls");
    menuClientes();
}

//Deleção
void deleteClient(void) /**Falta comentar*/ //Apaga um cliente de um ficheiro de clientes dado pelo usuário
{
    string clienteDel, line, filename;
    ifstream fin;
    ofstream fout;

    cout << "Nome do ficheiro de clientes (+.txt): ";
    //cin.clear();
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());
    fout.open("temp.txt");
    if(!fin.is_open()||!fout.is_open())
        cout << "Erro ao abrir o ficheiro!" << endl;
    else
    {
        cout << "Insira o nome do cliente a ser deletado: ";
        getline(cin, clienteDel);
        while(getline(fin, line))
        {
            if(line==clienteDel)
            {
                for(unsigned int i=0; i<=5; i++)
                    fin.ignore(1000, '\n');
            }
            else
                fout << line << endl;
        }
        fin.close();
        fout.close();
        const char * p = filename.c_str();
        remove(p);
        rename("temp.txt", p);
        cout << "Cliente " << clienteDel << " deletado com sucesso!" << endl;
    }
    cout << endl << endl << "Pressione Enter para voltar ao menu de clientes.";
    cin.ignore();
    system("cls");
    menuClientes();
}

//Leitura
void readClient(void) /**Falta comentar*/ //Lê um cliente de um ficheiro de cliente
{
    ifstream fin;
    string filename, morada, teste = "";
    cliente_t cliente;

    cout << "Digite o nome do ficheiro que quer ler (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());

    if(fin.is_open())
    {
        cout << "Digite o nome do cliente que quer ler: ";
        getline(cin, cliente.nome);
        while((cliente.nome != teste)&& !fin.eof())
        {
            getline(fin, teste);
        }
        if(cliente.nome == teste)
        {
            system("cls");
            cout << cliente.nome << endl;
            getline(fin, cliente.nif);
            cout << cliente.nif <<endl;
            getline(fin, cliente.agregadoFamiliar);
            cout << cliente.agregadoFamiliar <<endl;
            getline(fin, teste);
            cout << teste <<endl;
            getline(fin, teste);
            cout << teste <<endl;
        }
        else
            cout << "Cliente nao encontrado!";
        fin.close();
        }
    else
        cout << "Erro ao abrir ficheiro!";

    cout << endl << endl << "Pressione Enter para voltar ao menu de clientes.";
    cin.ignore();
    system("cls");
    menuClientes();
}

