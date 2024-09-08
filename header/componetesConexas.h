#ifndef COMPONETESCONEXAS_H
#define COMPONETESCONEXAS_H

#include <iostream>
#include <vector>
#include "grafo.h"

using namespace std;

// Descrição: Definição da classe GraphCC para encontrar componentes conectados em um grafo não direcionado.
class GraphCC {
    int V; // Número de vértices do grafo.
    vector<vector<int>> adj; // Lista de adjacências para representar as arestas do grafo.
    vector<string> colors; // Cores dos vértices durante a busca em profundidade.
    int numComponents; // Número de componentes conectados no grafo.

public:
    // Descrição: Construtor da classe GraphCC.
    // Entrada: Número de vértices V do grafo.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphCC é inicializado com V vértices, cores brancas para todos os vértices e sem componentes conectados.

    GraphCC(int V);

    // Descrição: Construtor da classe GraphCC a partir de um grafo existente.
    // Entrada: Grafo g a ser utilizado.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphCC é inicializado com os vértices e arestas do grafo g.

    GraphCC(grafo g);

    // Descrição: Adiciona uma aresta entre os vértices u e v.
    // Entrada: Vértices u e v a serem conectados pela aresta.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Uma aresta é adicionada entre os vértices u e v.

    void addEdge(int u, int v) ;

    // Descrição: Realiza uma busca em profundidade a partir do vértice u.
    // Entrada: Vértice u a ser visitado e vetor component para armazenar os vértices do componente conectado.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O vértice u e seus vizinhos são visitados e adicionados ao componente.

    void DFS(int u, vector<int>& component);

    // Descrição: Encontra todos os componentes conectados do grafo.
    // Entrada: Nenhuma.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Todos os componentes conectados do grafo são identificados e exibidos na saída padrão.

    void findConnectedComponents();

    // Descrição: Obtém o número de componentes conectados no grafo.
    // Entrada: Nenhuma.
    // Retorno: Número de componentes conectados.
    // Pré-condição: Nenhuma.
    // Pós-condição: Nenhuma.

    int getNumComponents();
};


#endif