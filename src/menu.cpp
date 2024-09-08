#include "menu.h"


// Descrição: Função para exibir uma mensagem de boas-vindas.
// Pré-condição: Nenhuma.
// Pós-condição: A mensagem de boas-vindas é exibida na saída padrão.
void welcome(){
	cout <<" __   __  __    _  ______   _______  ___________  _______  _______  ___      _______ " << endl;
	cout <<"|  | |  ||  |  | ||      | |       ||    ___    ||       ||   _   ||   |    |       |" << endl;
	cout <<"|  | |  ||   |_| ||  _    ||    ___||   |   |   ||_     _||  |_|  ||   |    |    ___|" << endl;
	cout <<"|  |_|  ||       || | |   ||   |___ |   |___|   |  |   |  |       ||   |    |   |___ " << endl;
	cout <<"|       ||  _    || |_|   ||    ___||     __   _|  |   |  |       ||   |___ |    ___|" << endl;
	cout <<"|       || | |   ||       ||   |___ |    |  |  |_  |   |  |   _   ||       ||   |___ " << endl;
	cout <<"|_______||_|  |__||______| |_______||____|  |____| |___|  |__| |__||_______||_______|" << endl;
	cout << endl;
}

// Descrição: Função para exibir os nomes dos desenvolvedores do trabalho.
// Pré-condição: Nenhuma.
// Pós-condição: Os nomes dos desenvolvedores são exibidos na saída padrão.
void desenvolvedores(){
	cout <<"O trabalho desenvolvido por:" << endl;
	cout <<" ->  Leticia Zanellatto de Oliveira" << endl;
	cout <<" ->  Renan de Lara Hipolito" << endl << endl;
}
// Descrição: Função para exibir o menu de opções do programa.
// Pré-condição: Nenhuma.
// Pós-condição: O menu de opções é exibido na saída padrão.
void print_option(){
    cout << "1 - Carregar Arquivo(.txt)" << endl;
    cout << "0 - Sair" << endl;
}

// Descrição: Função para exibir o menu de opções dos algortmos.
// Pré-condição: Nenhuma.
// Pós-condição: O menu de opções é exibido na saída padrão.c
void print_option_algorithm(){
    cout << endl <<"=============Menu options============   "<< endl;
	cout <<"1 - Desenhar Grafo                              "<< endl;
	cout <<"2 - Depth-First-Search's Algorithm              "<< endl;
	cout <<"3 - Breadth-First-Search's Algorithm            "<< endl;
    cout <<"4 - Bellman-Ford's Algorithm                    "<< endl;
    cout <<"5 - Kruskal's Algorithm                         "<< endl;
    cout <<"6 - Connected Components Algorithm              "<< endl;
    cout <<"7 - Strongly Connected Components Algorithm     "<< endl;
    cout <<"0 - Exit                                        "<< endl << endl;
	cout <<"Enter an option: ";
}