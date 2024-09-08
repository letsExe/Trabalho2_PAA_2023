#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <iostream>
#include <vector>
#include <limits>
#include <stack>
#include "grafo.h"


using namespace std;

// Descrição: Estrutura que representa uma aresta em um grafo ponderado.
struct Edge{
    int src, dest, weight;
};

// Descrição: Classe que representa um grafo para aplicação do algoritmo de Bellman-Ford.
class GraphBellamFord{
    int V, E; //Número de vértices (V) e arestas (E) do grafo.
    vector<Edge> edges; // Vetor de arestas do grafo.

    public:
        // Descrição: Construtor da classe GraphBellmanFord.
        // Entrada: Número de vértices (V) e número de arestas (E) do grafo.
        // Retorno: Nenhum
        // Pré-condição: -
        // Pós-condição: Cria um objeto GraphBellmanFord com V vértices e E arestas.
        GraphBellamFord(int V, int E);

        // Descrição: Construtor da classe GraphBellmanFord a partir de um grafo existente.
        // Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphBellmanFord.
        // Retorno: Nenhum
        // Pré-condição: O grafo g deve estar corretamente inicializado.
        // Pós-condição: Cria um objeto GraphBellmanFord com base no grafo g, mantendo as mesmas arestas e vértices.
        GraphBellamFord(grafo g);

        // Descrição: Adiciona uma aresta ao grafo com peso.
        // Entrada: Vértice de origem (src), vértice de destino (dest) e peso da aresta (weight).
        // Retorno: Nenhum
        // Pré-condição: Os vértices src e dest devem estar presentes no grafo.
        // Pós-condição: Adiciona uma nova aresta com peso entre os vértices src e dest no grafo.
        void addEdge(int src, int dest, int weight);

        // Descrição: Aplica o algoritmo de Bellman-Ford a partir de um vértice de origem.
        // Entrada: Vértice de origem (src).
        // Retorno: Nenhum
        // Pré-condição: O grafo deve estar corretamente inicializado.
        // Pós-condição: Calcula e imprime as distâncias mínimas e os caminhos mais curtos a partir do vértice de origem src.
        void BellmanFord(int src);

        // Descrição: Imprime o caminho de um vértice de destino até o vértice de origem.
        // Entrada: Vetor de pais (parent) e vértice de destino (dest).
        // Retorno: Nenhum
        // Pré-condição: O vetor parent deve ser válido e conter os pais de cada vértice no caminho.
        // Pós-condição: Imprime o caminho do vértice de destino até o vértice de origem.
        void printPath(const vector<int> &parent, int dest);
};

#endif