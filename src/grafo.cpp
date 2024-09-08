#include "grafo.h"

// Descrição: Construtor padrão da classe grafo.
// Entrada: -
// Retorno: -
// Pré-condição: -
// Pós-condição: Cria um objeto grafo sem especificar o número de vértices.
grafo::grafo(){}

// Descrição: Construtor da classe grafo com especificação do número de vértices.
// Entrada: Número de vértices (numVertices).
// Retorno: -
// Pré-condição: -
// Pós-condição: Cria um objeto grafo com o número de vértices especificado.
grafo::grafo(int numVertices): numVertices(numVertices) {}

// Descrição: Adiciona uma aresta ao grafo com os vértices de origem (a) e destino (b) e o peso da aresta (peso).
// Entrada: Vértice de origem (a), vértice de destino (b) e peso da aresta (peso).
// Retorno: -
// Pré-condição: -
// Pós-condição: Adiciona uma nova aresta ao grafo.
void grafo::addAresta(int a, int b, int peso){
    aresta arest(a, b, peso);
    this->arestas.push_back(arest);
    numArestas += 1;
}

// Descrição: Retorna o número de vértices do grafo.
// Entrada: -
// Retorno: Número de vértices do grafo.
// Pré-condição: -
// Pós-condição: Retorna o número de vértices do grafo.
int grafo::getNumVertices() const {
    return numVertices;
}

// Descrição: Define o número de vértices do grafo.
// Entrada: Número de vértices (numVertices).
// Retorno: -
// Pré-condição: -
// Pós-condição: Define o número de vértices do grafo.
void grafo::setNumVertices(int numVertices) {
    grafo::numVertices = numVertices;
}

// Descrição: Retorna o número de arestas do grafo.
// Entrada: -
// Retorno: Número de arestas do grafo.
// Pré-condição: -
// Pós-condição: Retorna o número de arestas do grafo.
int grafo::getNumArestas() const {
    return numArestas;
}

// Descrição: Define o número de arestas do grafo.
// Entrada: Número de arestas (numArestas).
// Retorno: -
// Pré-condição: -
// Pós-condição: Define o número de arestas do grafo.
void grafo::setNumArestas(int numArestas) {
    grafo::numArestas = numArestas;
}

// Descrição: Retorna o vetor de arestas do grafo.
// Entrada: -
// Retorno: Vetor de arestas do grafo.
// Pré-condição: -
// Pós-condição: Retorna o vetor de arestas do grafo.
const vector<aresta> &grafo::getArestas() const {
    return arestas;
}

// Descrição: Limpa o vetor de arestas do grafo.
// Entrada: -
// Retorno: -
// Pré-condição: -
// Pós-condição: Limpa o vetor de arestas do grafo.
void grafo::clearArestas(){
    arestas.clear();
}

// Descrição: Define o vetor de arestas do grafo.
// Entrada: Vetor de arestas (arestas).
// Retorno: -
// Pré-condição: -
// Pós-condição: Define o vetor de arestas do grafo.
void grafo::setArestas(const vector<aresta> &arestas) {
    grafo::arestas = arestas;
}

// Descrição: Verifica se o grafo é orientado.
// Entrada: -
// Retorno: Valor booleano que indica se o grafo é orientado (true) ou não (false).
// Pré-condição: -
// Pós-condição: Retorna true se o grafo for orientado, false caso contrário.
bool grafo::isOrientado() const {
    return orientado;
}

// Descrição: Define se o grafo é orientado.
// Entrada: Valor booleano que indica se o grafo é orientado (orientado).
// Retorno: -
// Pré-condição: -
// Pós-condição: Define se o grafo é orientado com base no valor booleano passado.
void grafo::setOrientado(bool orientado) {
    grafo::orientado = orientado;
}
