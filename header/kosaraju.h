#ifndef KOSARAJU_H
#define KOSARAJU_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include "grafo.h"
using namespace std;

// Descrição: Classe GraphCFC que representa um grafo direcionado.
class GraphCFC {
    int V; // Número de vértices do grafo.
    vector<vector<int>> adj, adjT; // adj: lista de adjacências, adjT: transposto da lista de adjacências.


public:
    // Descrição: Construtor da classe GraphCFC.
    // Entrada: Número de vértices V do grafo.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphCFC é inicializado com V vértices e as listas de adjacências do grafo e seu transposto são criadas.
    GraphCFC(int V);

    // Descrição: Construtor da classe GraphCFC a partir de um grafo existente.
    // Entrada: Grafo g a ser utilizado.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphCFC é inicializado com os vértices e arestas do grafo g, e as listas de adjacências do grafo e seu transposto são criadas.
    GraphCFC(grafo g);

    // Descrição: Adiciona uma aresta entre os vértices u e v nas listas de adjacências do grafo e do seu transposto.
    // Entrada: Vértices u e v a serem conectados pela aresta.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Uma aresta é adicionada nas listas de adjacências do grafo e do seu transposto.
    void addEdge(int u, int v);

    // Descrição: Função utilitária para realizar a busca em profundidade a partir do vértice u e preencher a pilha Stack com os vértices visitados.
    // Entrada: Vértice u a ser visitado, vetor de vértices visitados e pilha Stack.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Os vértices são visitados e adicionados à pilha Stack.
    void DFSUtil(int u, vector<bool>& visited, stack<int>& Stack);

    // Descrição: Função utilitária para realizar a busca em profundidade a partir do vértice u e preencher o vetor component com os vértices do componente conectado.
    // Entrada: Vértice u a ser visitado, vetor de vértices visitados e vetor component.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Os vértices são visitados e adicionados ao vetor component.
    void DFSUtilTranspose(int u, vector<bool>& visited, vector<int>& component);

    // Descrição: Encontra os componentes fortemente conectados do grafo.
    // Entrada: Nenhuma.
    // Retorno: Vetor de vetores representando os componentes fortemente conectados.
    // Pré-condição: Nenhuma.
    // Pós-condição: Os componentes fortemente conectados do grafo são identificados e retornados.
    void showComponents(vector<vector<int>> SCCs);

    // Descrição: Exibe os componentes fortemente conectados do grafo.
    // Entrada: Vetor de vetores representando os componentes fortemente conectados.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Os componentes fortemente conectados do grafo são exibidos na saída padrão.
    vector<vector<int>> stronglyConnectedComponents();
};


#endif