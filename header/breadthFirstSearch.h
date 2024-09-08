#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <iostream>
#include <list>
#include "grafo.h"

using namespace std;

// Descrição: Classe que representa um grafo e implementa a busca em largura (BFS).
class GraphBFS {
    int numVertices; // Número de vértices no grafo.
    list<int>* adjLists; // Lista de adjacência para representar as arestas do grafo.
    bool* visited; // Vetor para marcar os vértices visitados durante a BFS.
    bool directed; //Booleano para diferenciar grafos direcionados de não direcionados

    public:
    // Descrição: Construtor da classe GraphBFS que recebe um grafo e inicializa um novo grafo com base nele.
    // Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphBFS.
    // Retorno: -
    // Pré-condição: O grafo g deve estar corretamente inicializado.
    // Pós-condição: Cria um objeto GraphBFS com base no grafo g, mantendo as mesmas arestas e vértices.
    GraphBFS(int vertices);

    // Descrição: Construtor da classe GraphBFS que cria um grafo com um número específico de vértices.
    // Entrada: Número de vértices (vertices) do grafo.
    // Retorno: -
    // Pré-condição: O número de vértices deve ser não negativo.
    // Pós-condição: Cria um objeto GraphBFS com vertices vértices e sem arestas.
    GraphBFS(grafo g);

    // Descrição: Adiciona uma aresta não direcionada ao grafo.
    // Entrada: Vértice de origem (src) e vértice de destino (dest) da aresta.
    // Retorno: -
    // Pré-condição: Os vértices src e dest devem estar presentes no grafo.
    // Pós-condição: Adiciona uma nova aresta entre os vértices src e dest no grafo.
    void addEdge(int src, int dest);

    // Descrição: Executa a busca em largura (BFS) a partir de um vértice de origem.
    // Entrada: Vértice de origem (startVertex) da busca.
    // Retorno: -
    // Pré-condição: O vértice de origem deve estar presente no grafo.
    // Pós-condição: Imprime a ordem de visitação dos vértices a partir do vértice de origem.
    void BFS(int startVertex);
};

#endif