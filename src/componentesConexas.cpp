#include "componetesConexas.h"

// Descrição: Construtor da classe GraphCC.
// Entrada: Número de vértices V do grafo.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphCC é inicializado com V vértices, cores brancas para todos os vértices e sem componentes conectados.

GraphCC::GraphCC(int V) : V(V), adj(V), colors(V, "white"), numComponents(0) {}

// Descrição: Construtor da classe GraphCC a partir de um grafo existente.
// Entrada: Grafo g a ser utilizado.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphCC é inicializado com os vértices e arestas do grafo g.

GraphCC::GraphCC(grafo g): V(g.getNumVertices()), adj(g.getNumVertices()), colors(g.getNumVertices(), "white"), numComponents(0) {
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b);
    }
}

// Descrição: Adiciona uma aresta entre os vértices u e v.
// Entrada: Vértices u e v a serem conectados pela aresta.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Uma aresta é adicionada entre os vértices u e v.

void GraphCC::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Descrição: Realiza uma busca em profundidade a partir do vértice u.
// Entrada: Vértice u a ser visitado e vetor component para armazenar os vértices do componente conectado.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O vértice u e seus vizinhos são visitados e adicionados ao componente.

void GraphCC::DFS(int u, vector<int>& component) {
    colors[u] = "gray";
    component.push_back(u);
    for (auto v : adj[u]) {
        if (colors[v] == "white") {
            DFS(v, component);
        }
    }
    colors[u] = "black";
}

// Descrição: Encontra todos os componentes conectados do grafo.
// Entrada: Nenhuma.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Todos os componentes conectados do grafo são identificados e exibidos na saída padrão.

void GraphCC::findConnectedComponents() {
    numComponents = 0;
    for (int u = 0; u < V; u++) {
        if (colors[u] == "white") {
            numComponents++;
            vector<int> component;
            DFS(u, component);
            cout << "Componente " << numComponents << ": ";
            for (int i = 0; i < component.size(); i++) {
                cout << component[i];
                if (i < component.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
}

// Descrição: Obtém o número de componentes conectados no grafo.
// Entrada: Nenhuma.
// Retorno: Número de componentes conectados.
// Pré-condição: Nenhuma.
// Pós-condição: Nenhuma.

int GraphCC::getNumComponents() {
    return numComponents;
}