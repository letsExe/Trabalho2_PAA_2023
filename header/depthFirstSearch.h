#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include <iostream>
#include <vector>

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "grafo.h"

using namespace std;

// Descrição: Enumeração que representa as cores dos vértices durante a busca em profundidade.
enum class Cor { BRANCO, CINZA, PRETO };

// Descrição: Estrutura que representa um vértice em um grafo durante a busca em profundidade.
typedef struct Vertice {
    Cor cor;    // Cor do vértice (BRANCO, CINZA ou PRETO).
    int pi;     // Pai do vértice na árvore de busca.
    int d;      // Tempo de descoberta do vértice.
    int f;      // Tempo de finalização do vértice.
} Vertice;

// Descrição: Classe que representa um grafo e implementa a busca em profundidade.
class GraphDFS {
private:
    vector<vector<int>> adj;    // Lista de adjacências do grafo.
    vector<Vertice> vertices;  // Lista de vértices do grafo.
    int timestamp;            // Contador de tempo para marcação dos vértices.
    bool directed; //Booleano para diferenciar grafos direcionados de não direcionados


public:
    // Descrição: Construtor da classe GraphDFS que inicializa o grafo com V vértices.
    // Entrada: Número de vértices (V) do grafo.
    // Retorno: -
    // Pré-condição: -
    // Pós-condição: Cria um objeto GraphDFS com V vértices.
    GraphDFS(int V);
    
    // Descrição: Construtor da classe GraphDFS a partir de um grafo existente.
    // Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphDFS.
    // Retorno: -
    // Pré-condição: O grafo g deve estar corretamente inicializado.
    // Pós-condição: Cria um objeto GraphDFS com base no grafo g, mantendo as mesmas arestas e vértices.
    GraphDFS(grafo g);

    // Descrição: Adiciona uma aresta ao grafo entre os vértices u e v.
    // Entrada: Vértices u e v que formam a aresta.
    // Retorno: -
    // Pré-condição: Os vértices u e v devem estar presentes no grafo.
    // Pós-condição: Adiciona uma nova aresta entre os vértices u e v no grafo.
    void addEdge(int u, int v);

    // Descrição: Inicia a busca em profundidade (DFS) a partir de um vértice de início.
    // Entrada: Vértice de início da busca.
    // Retorno: -
    // Pré-condição: O grafo deve estar corretamente inicializado.
    // Pós-condição: Realiza a busca em profundidade no grafo a partir do vértice de início, marcando os vértices visitados.
    void DFS(int startVertex);

    // Descrição: Visita recursivamente um vértice e seus vizinhos na busca em profundidade.
    // Entrada: Vértice a ser visitado.
    // Retorno: -
    // Pré-condição: O vértice deve existir no grafo.
    // Pós-condição: Marca o vértice como visitado e visita recursivamente seus vizinhos não visitados.
    void DFS_visit(int u);
};


#endif