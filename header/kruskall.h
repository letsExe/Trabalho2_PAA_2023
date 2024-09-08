#ifndef KRUSKALL_H
#define KRUSKALL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "grafo.h"

using namespace std;

// Estrutura para representar uma aresta
struct EdgeKruskall {
    int src, dest, weight;
};

// Classe para representar um grafo
class GraphKruskall {
    int V, E;
    vector<EdgeKruskall> edges;
    vector<EdgeKruskall> result;

public:
    // Descrição: Construtor da classe GraphKruskall.
    // Entrada: Número de vértices V e número de arestas E do grafo.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphKruskall é inicializado com V vértices e E arestas.
    GraphKruskall(int V, int E);

    // Descrição: Construtor da classe GraphKruskall a partir de um grafo existente.
    // Entrada: Grafo g a ser utilizado.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: O objeto GraphKruskall é inicializado com os vértices e arestas do grafo g.
    GraphKruskall(grafo g);

    // Descrição: Adiciona uma aresta com peso entre os vértices src e dest.
    // Entrada: Vértices src e dest e o peso da aresta.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Uma aresta é adicionada ao vetor de arestas do grafo.
    void addEdge(int src, int dest, int weight);

    // Descrição: Encontra o representante do conjunto ao qual o vértice pertence.
    // Entrada: Vetor parent representando a relação entre vértices e seus pais, e o índice do vértice.
    // Retorno: O representante do conjunto ao qual o vértice pertence.
    // Pré-condição: Nenhuma.
    // Pós-condição: Nenhuma.
    int find(vector<int> &parent, int i);

    // Descrição: Une dois conjuntos em um único conjunto.
    // Entrada: Vetor parent representando a relação entre vértices e seus pais, e os índices dos vértices x e y.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: Os conjuntos contendo os vértices x e y são unidos em um único conjunto.
    void Union(vector<int> &parent, int x, int y);

    // Descrição: Implementação do algoritmo de Kruskal para encontrar a árvore geradora mínima do grafo.
    // Entrada: Nenhuma.
    // Retorno: Nenhum.
    // Pré-condição: Nenhuma.
    // Pós-condição: A árvore geradora mínima do grafo é encontrada e suas arestas são impressas.
    void Kruskal();

    // Descrição: Retorna o vetor de arestas resultantes do algoritmo de Kruskall.
    // Entrada: Nenhuma.
    // Retorno: Um vetor de objetos EdgeKruskall representando as arestas resultantes do algoritmo de Kruskall.
    // Pré-condição: Nenhuma.
    // Pós-condição: O vetor de arestas resultantes do algoritmo de Kruskall é retornado.
    vector<EdgeKruskall> getResult();

};

#endif