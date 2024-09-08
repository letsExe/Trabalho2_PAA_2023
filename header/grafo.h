#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
using namespace std;

// Definição de uma struct aresta para representar uma aresta em um grafo, contendo os vértices a e b que a aresta conecta, e o peso da aresta.
typedef struct aresta{
    int a; // Vértice de origem da aresta.
    int b; // Vértice de destino da aresta.
    int peso; // Peso da aresta.

    // Descrição: Construtor da struct aresta.
    // Entrada: Vértice de origem da aresta, vértice de destino da aresta.
    // Retorno: -
    // Pré-condição: -
    // Pós-condição: Cria um objeto aresta.
    aresta(int a, int b, int peso) : a(a), b(b), peso(peso) {}
} aresta;

// Definição da classe grafo para representar um grafo, com informações sobre se é orientado ou não, o número de vértices e arestas, e um vetor de arestas.
class grafo {
private:
    bool orientado; // Indica se o grafo é orientado (true) ou não (false).
    int numVertices; // Número de vértices do grafo.
    int numArestas; // Número de arestas do grafo.
    vector<aresta> arestas; // Vetor contendo as arestas do grafo.
    public:
        // Descrição: Construtor padrão da classe grafo.
        // Entrada: -
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Cria um objeto grafo sem especificar o número de vértices.
        grafo();

        // Descrição: Construtor da classe grafo com especificação do número de vértices.
        // Entrada: Número de vértices (numVertices).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Cria um objeto grafo com o número de vértices especificado.
        grafo(int numVertices);

        // Descrição: Adiciona uma aresta ao grafo com os vértices de origem (a) e destino (b) e o peso da aresta (peso).
        // Entrada: Vértice de origem (a), vértice de destino (b) e peso da aresta (peso).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Adiciona uma nova aresta ao grafo.
        void addAresta(int a, int b, int peso);

        // Descrição: Retorna o número de vértices do grafo.
        // Entrada: -
        // Retorno: Número de vértices do grafo.
        // Pré-condição: -
        // Pós-condição: Retorna o número de vértices do grafo.
        int getNumVertices() const;

        // Descrição: Define o número de vértices do grafo.
        // Entrada: Número de vértices (numVertices).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Define o número de vértices do grafo.
        void setNumVertices(int numVertices);

        // Descrição: Retorna o número de arestas do grafo.
        // Entrada: -
        // Retorno: Número de arestas do grafo.
        // Pré-condição: -
        // Pós-condição: Retorna o número de arestas do grafo.
        int getNumArestas() const;

        // Descrição: Define o número de arestas do grafo.
        // Entrada: Número de arestas (numArestas).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Define o número de arestas do grafo.
        void setNumArestas(int numArestas);

        // Descrição: Limpa o vetor de arestas do grafo.
        // Entrada: -
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Limpa o vetor de arestas do grafo.
        void clearArestas();

        // Descrição: Retorna o vetor de arestas do grafo.
        // Entrada: -
        // Retorno: Vetor de arestas do grafo.
        // Pré-condição: -
        // Pós-condição: Retorna o vetor de arestas do grafo.
        const vector<aresta> &getArestas() const;

        // Descrição: Define o vetor de arestas do grafo.
        // Entrada: Vetor de arestas (arestas).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Define o vetor de arestas do grafo.
        void setArestas(const vector<aresta> &arestas);

        // Descrição: Verifica se o grafo é orientado.
        // Entrada: -
        // Retorno: Valor booleano que indica se o grafo é orientado (true) ou não (false).
        // Pré-condição: -
        // Pós-condição: Retorna true se o grafo for orientado, false caso contrário.
        bool isOrientado() const;

        // Descrição: Define se o grafo é orientado.
        // Entrada: Valor booleano que indica se o grafo é orientado (orientado).
        // Retorno: -
        // Pré-condição: -
        // Pós-condição: Define se o grafo é orientado com base no valor booleano passado.
        void setOrientado(bool orientado);

};


#endif
