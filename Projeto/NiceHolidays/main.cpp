//Bibliotecas
#include <iostream> //Input e output de dados
#include <cstdlib> //Contém função que apaga a consola
#include <string> /**TALVEZ NÃO SEJA NECESSÁRIA NA MAIN*/ //Uso e manipulação de strings
#include <vector> /**TALVEZ NÃO SEJA NECESSÁRIA NA MAIN*/ //Uso e manipulação de vetores
#include <fstream> /**TALVEZ NÃO SEJA NECESSÁRIA NA MAIN*/ //Uso e manipulação de arquivos
#include <algorithm> /**TALVEZ NÃO SEJA NECESSÁRIA NA MAIN*/ //Uso do algoritmo de sorting

#include "agencia.h" //Funções e structs relacionadas a agências
#include "cliente.h" //Funções e structs relacionadas a clientes
#include "pacote.h" //Funções e structs relacionadas a pacotes

//Namespace
using namespace std; //Standard Namespace

//FUNÇÕES
//Menu
void menu(void) //É o menu do programa: coordena as demais funções utilizadas
{
    int escolha; //Número que vai decidir para qual menu saltar
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
    }while(escolha<1||escolha>4); //Faz um loop até que se digite um número válido
    switch(escolha)
    {
        case 1: //Agências
            system("cls"); //Apaga a consola
            menuAgencias(); //Chama o menu de agências
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
int main() //Coordena as demais funções
{
    menu(); //Chama o menu principal do programa, que chama outros menus específicos, que chamam funções específicas

    return 0; //Caso terminado corretamente, retorna 0 na consola
}
