#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "pacote.h"

using namespace std;

//STRUCTS
typedef struct data //Struct para datas dos pacotes
{
    int ano;
    int mes;
    int dia;
}data_t;
typedef struct pacote //Struct para pacotes turísticos
{
    string ID;
    vector<string> percurso; //String???
    data_t dataInicio;
    data_t dataFim;
    float precoIndiv;
    int maxPessoas;
    int nrVendidos;
}pacote_t;

//FUNÇÔES
//Menu
void menuPacotes(void) /**Falta comentar*/ //Permite ao usuário escolher o que fazer com pacotes
{
    int escolha;
    cout << "PACOTES" << endl << "####################" << endl << "[1] Adicionar pacote" << endl << "[2] Deletar pacote" << endl << "[3] Alterar pacote" << endl << "[4] Ver pacote" << endl << "[5] Vender pacote a cliente" << endl;
    cout << "[6] Voltar" << endl <<"####################" << endl;
    do
    {
        cin >> escolha;
        if(escolha<1||escolha>6)
        {
            system("cls");
            cout << "PACOTES" << endl << "####################" << endl << "[1] Adicionar pacote" << endl << "[2] Deletar pacote" << endl << "[3] Alterar pacote" << endl << "[4] Ver pacote" << endl << "[5] Vender pacote a cliente (FUNCAO INACABADA)" << endl;
            cout << "[6] Voltar" << endl <<"####################" << endl;
            cout << "Numero invalido! Digite outro numero: ";
        }

    }while(escolha<1||escolha>6);

    switch(escolha)
    {
        case 1:
            system("cls");
            addPack();
            break;
        case 2:
            system("cls");
            deletePack();
            break;
        case 3:
            system("cls");
            alterPack();
            break;
        case 4:
            system("cls");
            readPack();
            break;
        case 5:
            system("cls");
            //sellPack();
            break;
        case 6:
            system("cls");
            menu();
            break;
    }
}

//Criação/Adição
void addPack(void) /**Falta comentar*/ //Adiciona um pacote em um ficheiro de pacotes dado pelo usuário
{
    ofstream outfile; //Declaração de variáveis
    pacote_t pacote;
    string temp, filename;
    bool terminar = false;

    system("cls");
    cout << "Digite o nome do ficheiro de pacotes (+.txt): "; //Abertura do arquivo
    cin.ignore(); //Limpeza do buffer do teclado
    getline(cin, filename);

    outfile.open(filename.c_str(), ofstream::app);
    if(outfile.is_open())
    {
        cout << "Identificador do pacote: ";
        getline(cin, pacote.ID);
        outfile << endl << pacote.ID << endl;
        cout << "Itinerario do pacote (Ctrl-Z para terminar): ";
        do
        {
            getline(cin, temp);
            if(cin.fail() && cin.eof())
            {
                terminar = true;
                cin.clear();
                break;
            }

            else
            {
                pacote.percurso.push_back(temp);
                cin.clear();
            }

        }
        while(!terminar);

        for(unsigned int i =0; i<pacote.percurso.size(); i++)
        {
            outfile << pacote.percurso.at(i);
            if(i<pacote.percurso.size()-1)
                outfile << ", ";
            else
                outfile << endl;
        }

        cout << "Data de inicio:" << endl << "AAAA MM DD: ";
        cin >> pacote.dataInicio.ano >> pacote.dataInicio.mes >> pacote.dataInicio.dia;
        outfile << pacote.dataInicio.ano << "/" << pacote.dataInicio.mes << "/" << pacote.dataInicio.dia << endl;
        cout << "Data de fim:" << endl << "AAAA MM DD: ";
        cin >> pacote.dataFim.ano >> pacote.dataFim.mes >> pacote.dataFim.dia;
        outfile << pacote.dataFim.ano << "/" << pacote.dataFim.mes << "/" << pacote.dataFim.dia << endl;
        cout << "Preco por pessoa: ";
        cin >> pacote.precoIndiv;
        outfile << pacote.precoIndiv << endl;
        cout << "Numero maximo de pessoas: ";
        cin >> pacote.maxPessoas;
        outfile << pacote.maxPessoas << endl;
        cout << "Numero de pacotes vendidos: ";
        cin >> pacote.nrVendidos;
        outfile << pacote.nrVendidos << endl;
        outfile << "::::::::::" << endl;

        outfile.close();
    }
    else
        cout << "Erro ao abrir o ficheiro!" << endl;
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuPacotes();
}

//Alteração
void alterPack(void) /**Falta comentar*/ //Altera um pacote num ficheiro de pacotes
{
    string pacoteAlt, line, filename, temp1;
    pacote_t pacote;
    ifstream fin;
    ofstream fout;
    int temp;
    bool terminar = false;

    cout << "Nome do ficheiro de pacotes (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());
    fout.open("temp.txt");
    if(!fin.is_open()||!fout.is_open())
        cout << "Erro ao abrir o ficheiro!" << endl;
    else
    {
        cout << "Insira o nome do pacote a ser alterado: ";
        getline(cin, pacoteAlt);
        while(getline(fin, line))
        {
            if(line==pacoteAlt)
            {
                for(unsigned int i=0; i<6; i++)
                    fin.ignore(1000, '\n');
                cout << "Novo ID do pacote: ";
                getline(cin, pacote.ID);
                fout << pacote.ID << endl;
                cout << "Itinerario do pacote (Ctrl-Z para terminar): ";
                do
                {
                    getline(cin, temp1);
                    if(cin.fail() && cin.eof())
                    {
                        terminar = true;
                        cin.clear();
                        break;
                    }

                    else
                    {
                        pacote.percurso.push_back(temp1);
                        cin.clear();
                    }

                }
                while(!terminar);

                for(unsigned int i =0; i<pacote.percurso.size(); i++)
                {
                    fout << pacote.percurso.at(i);
                    if(i<pacote.percurso.size()-1)
                        fout << ", ";
                    else
                        fout << endl;
                }

                cout << "Data de inicio:" << endl << "AAAA MM DD: ";
                cin >> pacote.dataInicio.ano >> pacote.dataInicio.mes >> pacote.dataInicio.dia;
                fout << pacote.dataInicio.ano << "/" << pacote.dataInicio.mes << "/" << pacote.dataInicio.dia << endl;
                cout << "Data de fim:" << endl << "AAAA MM DD: ";
                cin >> pacote.dataFim.ano >> pacote.dataFim.mes >> pacote.dataFim.dia;
                fout << pacote.dataFim.ano << "/" << pacote.dataFim.mes << "/" << pacote.dataFim.dia << endl;
                cout << "Preco por pessoa: ";
                cin >> pacote.precoIndiv;
                fout << pacote.precoIndiv << endl;
                cout << "Numero maximo de pessoas: ";
                cin >> pacote.maxPessoas;
                fout << pacote.maxPessoas << endl;
                cout << "Numero de pacotes vendidos: ";
                cin >> pacote.nrVendidos;
                fout << pacote.nrVendidos << endl;
            }
            else
                fout << line << endl;
        }
        fin.close();
        fout.close();
        const char * p = filename.c_str();
        remove(p);
        rename("temp.txt", p);
        cout << "Pacote " << pacoteAlt << " alterado com sucesso!" << endl;
    }
    cout << endl << endl << "Pressione Enter para voltar ao menu de pacotes.";
    cin.ignore();
    cin.ignore();
    system("cls");
    menuPacotes();
}
void sellPack(void) /**Falta tudo*/ //Vende um pacote a um cliente
{

}

//Deleção
void deletePack(void) /**Falta comentar*/ //Apaga um pacote de um ficheiro de pacotes dado pelo usuário
{
    string pacoteDel, line, filename;
    ifstream fin;
    ofstream fout;

    system("cls");
    cout << "Nome do ficheiro de pacotes (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());
    fout.open("temp.txt");
    if(!fin.is_open()||!fout.is_open())
        cout << "Erro ao abrir o ficheiro!" << endl;
    else
    {
        cout << "Insira o identificador do pacote a ser deletado: ";
        getline(cin, pacoteDel);
        while(getline(fin, line))
        {
            if(line==pacoteDel)
            {
                for(unsigned int i=0; i<8; i++)
                    fin.ignore(256, '\n');
            }
            else
                fout << line << endl;
        }
        fin.close();
        fout.close();
        const char * p = filename.c_str();
        remove(p);
        rename("temp.txt", p);
        cout << "Pacote " << pacoteDel << " deletado com sucesso!" << endl;
    }
    cout << endl << endl << "Pressione Enter para voltar ao menu de agencias.";
    cin.ignore();
    system("cls");
    menuPacotes();
}

//Leitura
void readPack(void) /**Falta comentar*/ //Lê um pacote de um ficheiro de pacote
{
    ifstream fin;
    string filename, teste = "";
    pacote_t pacote;

    cout << "Digite o nome do ficheiro que quer ler (+.txt): ";
    cin.ignore();
    getline(cin, filename);
    fin.open(filename.c_str());

    if(fin.is_open())
    {
        cout << "Digite o ID do pacote que quer ler: ";
        getline(cin, pacote.ID);
        while((pacote.ID != teste)&& !fin.eof())
        {
            getline(fin, teste);
        }
        if(pacote.ID == teste)
        {
            system("cls");
            cout << pacote.ID << endl;
            getline(fin, teste); //Itinerário
            cout << teste <<endl;
            getline(fin, teste); //Data início
            cout << teste <<endl;
            getline(fin, teste); //Data fim
            cout << teste <<endl;
            getline(fin, teste);
            cout << teste <<endl;
            getline(fin, teste);
            cout << teste <<endl;
            getline(fin, teste);
            cout << teste <<endl;
        }
        else
            cout << "Pacote nao encontrado!";
        fin.close();
        }
    else
        cout << "Erro ao abrir ficheiro!";

    cout << endl << endl << "Pressione Enter para voltar ao menu de pacotes.";
    cin.ignore();
    system("cls");
    menuPacotes();
}

