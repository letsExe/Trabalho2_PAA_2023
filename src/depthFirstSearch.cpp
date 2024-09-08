#include "depthFirstSearch.h"

// Descrição: Construtor da classe GraphDFS que inicializa o grafo com V vértices.
// Entrada: Número de vértices (V) do grafo.
// Retorno: -
// Pré-condição: -
// Pós-condição: Cria um objeto GraphDFS com V vértices.
GraphDFS::GraphDFS(int V) : adj(V), vertices(V, {Cor::BRANCO, -1, 0, 0}), timestamp(0) {}

// Descrição: Construtor da classe GraphDFS a partir de um grafo existente.
// Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphDFS.
// Retorno: -
// Pré-condição: O grafo g deve estar corretamente inicializado.
// Pós-condição: Cria um objeto GraphDFS com base no grafo g, mantendo as mesmas arestas e vértices.
GraphDFS::GraphDFS(grafo g) : directed(g.isOrientado()), adj(g.getNumVertices()), vertices(g.getNumVertices(), {Cor::BRANCO, -1, 0, 0}), timestamp(0) {
    // Adiciona todas as arestas do grafo ao objeto GraphDFS.
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b);
    }
}

// Descrição: Adiciona uma aresta ao grafo entre os vértices u e v.
// Entrada: Vértices u e v que formam a aresta.
// Retorno: -
// Pré-condição: Os vértices u e v devem estar presentes no grafo.
// Pós-condição: Adiciona uma nova aresta entre os vértices u e v no grafo.
void GraphDFS::addEdge(int u, int v) {
    adj[u].push_back(v);
    if (!this->directed) adj[v].push_back(u); // Para um grafo não direcionado, adicionamos as duas arestas
}

// Descrição: Inicia a busca em profundidade (DFS) a partir de um vértice de início.
// Entrada: Vértice de início da busca.
// Retorno: -
// Pré-condição: O grafo deve estar corretamente inicializado.
// Pós-condição: Realiza a busca em profundidade no grafo a partir do vértice de início, marcando os vértices visitados.
void GraphDFS::DFS(int startVertex) {
    // Inicializa os vértices com cor branca e pai nulo.
    for (int u = 0; u < adj.size(); u++) {
        vertices[u].cor = Cor::BRANCO;
        vertices[u].pi = -1;
    }
    timestamp = 0;
    // Ordena a lista de adjacências de cada vértice.
    for (auto& lista : adj) {
        sort(lista.begin(), lista.end());
    }
    // Inicia a DFS a partir do vértice de início.
    DFS_visit(startVertex);
    // Continua a DFS para os vértices não visitados.
    for (int u = 0; u < adj.size(); u++) {
        if (u != startVertex && vertices[u].cor == Cor::BRANCO) {
            cout << " | ";
            DFS_visit(u);
        }

            
    }
    cout << endl;
}

// Descrição: Visita recursivamente um vértice e seus vizinhos na busca em profundidade.
// Entrada: Vértice a ser visitado.
// Retorno: -
// Pré-condição: O vértice deve existir no grafo.
// Pós-condição: Marca o vértice como visitado e visita recursivamente seus vizinhos não visitados.
void GraphDFS::DFS_visit(int u) {
    vertices[u].cor = Cor::CINZA;
    timestamp++;
    vertices[u].d = timestamp;
    cout << u; // Imprime o vértice visitado
    for (int v : adj[u]) {
        if (vertices[v].cor == Cor::BRANCO) {
            vertices[v].pi = u;
            cout << " - ";
            DFS_visit(v);
        }
    }
    vertices[u].cor = Cor::PRETO;
    timestamp++;
    vertices[u].f = timestamp;
}