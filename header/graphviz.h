
#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H

#include <iostream>
#include <fstream>
#include <string>
#include "grafo.h"
#include "kruskall.h"

using namespace std;

// Descrição: Gera um arquivo DOT representando um grafo a partir de um arquivo de entrada.
// Entrada: Grafo a ser representado no arquivo DOT.
// Retorno: Retorna true se o arquivo DOT foi gerado com sucesso, caso contrário retorna false.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é criado com a representação do grafo.
bool generateDotFile(grafo grafo);

// Descrição: Gera a imagem do grafo usando o Graphviz.
// Entrada: Nenhuma.
// Retorno: Nenhum.
// Pré-condição: O arquivo DOT do grafo foi gerado com sucesso.
// Pós-condição: Uma imagem do grafo é gerada e salva no mesmo diretório com o nome graph.png.
void generateGraphImage();

// Descrição: Gera um arquivo DOT para representar um grafo com componentes fortemente conectados (SCCs) e atribui cores aos vértices com base nos SCCs. Escreve as arestas com seus pesos no arquivo DOT.
// Entrada: Um objeto grafo e uma lista de SCCs.
// Retorno: Verdadeiro se o arquivo DOT foi gerado com sucesso, falso caso contrário.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é gerado com sucesso representando o grafo com cores atribuídas aos vértices e suas arestas, pronto para ser utilizado com o Graphviz para gerar uma imagem do grafo.
bool generateSCCGraph(grafo grafo, vector<vector<int>> SCCs);

// Descrição: Gera um arquivo DOT para representar um grafo com arestas destacadas, onde as arestas selecionadas pelo algoritmo de Kruskall são coloridas de uma maneira específica. Escreve as arestas com seus pesos no arquivo DOT.
// Entrada: Um objeto grafo e um objeto GraphKruskall contendo o resultado do algoritmo de Kruskall.
// Retorno: Verdadeiro se o arquivo DOT foi gerado com sucesso, falso caso contrário.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é gerado com sucesso representando o grafo, com as arestas selecionadas pelo algoritmo de Kruskall destacadas com uma cor específica e prontas para serem visualizadas com o Graphviz.
bool generateKruskallGraph(grafo grafo, GraphKruskall k);

#endif
