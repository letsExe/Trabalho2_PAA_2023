#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>
#include <fstream>
#include "grafo.h"

using namespace std;

// Descrição: Função que lê um arquivo contendo informações sobre um grafo e o carrega em um objeto grafo.
// Entrada: Nome do arquivo de entrada (inputFile) e um objeto grafo (grafo) para armazenar os dados lidos.
// Retorno: Verdadeiro se o arquivo foi lido e os dados foram carregados com sucesso, falso caso contrário.
// Pré-condição: O arquivo de entrada deve existir e estar no formato correto.
// Pós-condição: O grafo é atualizado com os vértices, arestas e orientação conforme descrito no arquivo.
bool readFile(string fileName, grafo &grafo);

#endif
