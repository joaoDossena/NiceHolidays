//Bibliotecas
#include <iostream> //Input e output de dados
#include <cstdlib> //Cont�m fun��o que apaga a consola
#include <string> /**TALVEZ N�O SEJA NECESS�RIA NA MAIN*/ //Uso e manipula��o de strings
#include <vector> /**TALVEZ N�O SEJA NECESS�RIA NA MAIN*/ //Uso e manipula��o de vetores
#include <fstream> /**TALVEZ N�O SEJA NECESS�RIA NA MAIN*/ //Uso e manipula��o de arquivos
#include <algorithm> /**TALVEZ N�O SEJA NECESS�RIA NA MAIN*/ //Uso do algoritmo de sorting

#include "agencia.h" //Fun��es e structs relacionadas a ag�ncias
#include "cliente.h" //Fun��es e structs relacionadas a clientes
#include "pacote.h" //Fun��es e structs relacionadas a pacotes

//Namespace
using namespace std; //Standard Namespace

//FUN��ES
//Menu
void menu(void) //� o menu do programa: coordena as demais fun��es utilizadas
{
    int escolha; //N�mero que vai decidir para qual menu saltar
    cout << "BEM VINDO A NICEHOLIDAYS!" << endl;
    cout << "O que deseja fazer?" << endl << endl << "####################"<< endl << "[1] Agencias" << endl << "[2] Clientes" << endl << "[3] Pacotes" << endl << "[4] Sair" << endl <<"####################" << endl;
    do
    {
        cin >> escolha; //Entrada de dados
        if(escolha<1||escolha>4) //Tem de estar entre 1 e 4
        {
            system("cls"); //Apaga a consola
            cout << "BEM VINDO A NICEHOLIDAYS!" << endl;
            cout << "O que deseja fazer?" << endl << endl << "####################"<< endl << "[1] Agencias" << endl << "[2] Clientes" << endl << "[3] Pacotes" << endl << "[4] Sair" << endl <<"####################" << endl;
            cout << "Numero invalido! Digite outro: ";
        }
    }while(escolha<1||escolha>4); //Faz um loop at� que se digite um n�mero v�lido
    switch(escolha)
    {
        case 1: //Ag�ncias
            system("cls"); //Apaga a consola
            menuAgencias(); //Chama o menu de ag�ncias
            break;
        case 2: //Clientes
            system("cls"); //Apaga a consola
            menuClientes(); //Chama o menu de clientes
            break;
        case 3: //Pacotes
            system("cls"); //Apaga a consola
            menuPacotes(); //Chama o menu de pacotes
            break;
        case 4: //Sair
            break;
    }
}

//Main
int main() //Coordena as demais fun��es
{
    menu(); //Chama o menu principal do programa, que chama outros menus espec�ficos, que chamam fun��es espec�ficas

    return 0; //Caso terminado corretamente, retorna 0 na consola
}
