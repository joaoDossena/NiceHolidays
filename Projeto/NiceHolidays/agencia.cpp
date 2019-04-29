#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "agencia.h"

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
typedef struct agencia //Struct para agência
{
    string nome;
    string nif;
    morada_t morada;
    string url;
    string pacotes; //vector<pacote_t>???
    string clientes; //vector<cliente_t>???
}agencia_t;

//FUNÇÔES
//Menu
void menuAgencias(void) /**Falta comentar*/ //Permite ao usuário escolher o que fazer com agências
{
    int escolha;
    cout << "AGENCIAS" << endl << "####################" << endl << "[1] Criar agencia" << endl << "[2] Deletar agencia" << endl << "[3] Alterar agencia" << endl << "[4] Ver agencia" << endl;
    cout << "[5] Voltar" << endl <<"####################" << endl;
    do
    {
        cin >> escolha;
        if(escolha<1||escolha>5)
        {
            system("cls");
            cout << "AGENCIAS" << endl << "####################" << endl << "[1] Criar agencia" << endl << "[2] Deletar agencia" << endl << "[3] Alterar agencia" << endl << "[4] Ver agencia" << endl;
            cout << "[5] Voltar" << endl <<"####################" << endl;
            cout << "Numero invalido! Digite outro numero: ";
        }
    }while(escolha<1||escolha>5);

    switch(escolha)
    {
        case 1:
            system("cls");
            createAgency();
            break;
        case 2:
            system("cls");
            deleteAgency();
            break;
        case 3:
            system("cls");
            alterAgency();
            break;
        case 4:
            system("cls");
            readAgency();
            break;
        case 5:
            system("cls");
            menu();
            break;
    }
}
//Criação/Adição
void createAgency(void) /**Falta comentar*/ //Cria um ficheiro de agência
{
    ofstream outfile;
    string filename, clientFile, packFile;
    agencia_t agencia;
    cout << "Digite o nome do ficheiro que quer criar (+.txt): ";
    //cin.clear();
    //cin.ignore();
    getline(cin, filename);

    outfile.open(filename.c_str());
    if(outfile.is_open())
    {
        system("cls");
        cout << "Nome da agencia: ";
        getline(cin, agencia.nome);
        outfile << agencia.nome << endl;
        cout << "NIF: ";
        getline(cin, agencia.nif);
        outfile << agencia.nif << endl;
        cout << "URL: ";
        getline(cin, agencia.url);
        outfile << agencia.url << endl;
        cout << "MORADA" << endl << "Rua de morada: ";
        getline(cin, agencia.morada.rua);
        outfile << agencia.morada.rua << " / ";
        cout << "Numero de porta: ";
        getline(cin, agencia.morada.nrPorta);
        outfile << agencia.morada.nrPorta << " / ";
        cout << "Numero de andar: ";
        getline(cin, agencia.morada.nrAndar);
        outfile << agencia.morada.nrAndar << " / ";
        cout << "Codigo postal: ";
        getline(cin, agencia.morada.codPostal);
        outfile << agencia.morada.codPostal << " / ";
        cout << "Localidade: ";
        getline(cin, agencia.morada.localidade);
        outfile << agencia.morada.localidade << endl;

        cout << "Nome do ficheiro de clientes: ";
        getline(cin, clientFile);
        outfile << clientFile << endl;
        cout << "Nome do ficheiro de pacotes: ";
        getline(cin, packFile);
        outfile << packFile << endl;

        outfile.close();
    }
    else
        cout <<  "Erro ao abrir o ficheiro!" << endl;
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuAgencias();
}
//Alteração
void alterAgency(void) /**Falta comentar*/ //Altera um ficheiro de agencia
{
    ofstream outfile;
    string filename, clientFile, packFile;
    agencia_t agencia;
    cout << "Digite o nome do ficheiro que quer alterar (+.txt): ";
    cin.ignore();
    getline(cin, filename);

    outfile.open(filename.c_str());
    if(outfile.is_open())
    {
        system("cls");
        cout << "Nome da agencia: ";
        getline(cin, agencia.nome);
        outfile << agencia.nome << endl;
        cout << "NIF: ";
        getline(cin, agencia.nif);
        outfile << agencia.nif << endl;
        cout << "URL: ";
        getline(cin, agencia.url);
        outfile << agencia.url << endl;
        cout << "MORADA" << endl << "Rua de morada: ";
        getline(cin, agencia.morada.rua);
        outfile << agencia.morada.rua << " / ";
        cout << "Numero de porta: ";
        getline(cin, agencia.morada.nrPorta);
        outfile << agencia.morada.nrPorta << " / ";
        cout << "Numero de andar: ";
        getline(cin, agencia.morada.nrAndar);
        outfile << agencia.morada.nrAndar << " / ";
        cout << "Codigo postal: ";
        getline(cin, agencia.morada.codPostal);
        outfile << agencia.morada.codPostal << " / ";
        cout << "Localidade: ";
        getline(cin, agencia.morada.localidade);
        outfile << agencia.morada.localidade << endl;

        cout << "Nome do ficheiro de clientes: ";
        getline(cin, clientFile);
        outfile << clientFile << endl;
        cout << "Nome do ficheiro de pacotes: ";
        getline(cin, packFile);
        outfile << packFile << endl;

        outfile.close();
    }
    else
        cout <<  "Erro ao abrir o ficheiro!" << endl;
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuAgencias();
}
//Deleção
void deleteAgency(void) /**Falta comentar*/ //Apaga uma agência dum ficheiro de agência. Como cada ficheiro de agência possui apenas uma agência, apaga ficheiro
{
    string filename; //Declaração de variáveis

    cout << "Ficheiro da agencia a ser deletada (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    const char * p = filename.c_str();
    remove(p);
    cout << "Ficheiro de agencia deletado com sucesso!" << endl;
    //cin.clear();
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuAgencias();
}
//Leitura
void readAgency(void) /**Falta comentar*/ //Lê um ficheiro de agência
{
    ifstream fin;
    string filename, morada;
    agencia_t agencia;

    cout << "Digite o nome do ficheiro que quer ler (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());

    if(fin.is_open())
    {
        system("cls");
        getline(fin, agencia.nome);
        cout << agencia.nome << endl;
        getline(fin, agencia.nif);
        cout << agencia.nif<< endl;
        getline(fin, agencia.url);
        cout << agencia.url<< endl;
        getline(fin, morada);
        cout << morada<< endl;
        getline(fin, agencia.clientes);
        cout << agencia.clientes<< endl;
        getline(fin, agencia.pacotes);
        cout << agencia.pacotes<< endl;

        fin.close();
    }
    else
        cout <<  "Erro ao abrir o ficheiro!" << endl;
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuAgencias();
}

