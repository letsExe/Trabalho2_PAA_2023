#include "breadthFirstSearch.h"

// Descrição: Construtor da classe GraphBFS que recebe um grafo e inicializa um novo grafo com base nele.
// Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphBFS.
// Retorno: -
// Pré-condição: O grafo g deve estar corretamente inicializado.
// Pós-condição: Cria um objeto GraphBFS com base no grafo g, mantendo as mesmas arestas e vértices.
GraphBFS::GraphBFS(grafo g) : numVertices(g.getNumVertices()), directed(g.isOrientado()) {
    adjLists = new list<int>[numVertices];

    // Adiciona todas as arestas do grafo ao objeto GraphBFS.
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b);
    }
}

// Descrição: Construtor da classe GraphBFS que cria um grafo com um número específico de vértices.
// Entrada: Número de vértices (vertices) do grafo.
// Retorno: -
// Pré-condição: O número de vértices deve ser não negativo.
// Pós-condição: Cria um objeto GraphBFS com vertices vértices e sem arestas.
GraphBFS::GraphBFS(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

// Descrição: Adiciona uma aresta não direcionada ao grafo.
// Entrada: Vértice de origem (src) e vértice de destino (dest) da aresta.
// Retorno: -
// Pré-condição: Os vértices src e dest devem estar presentes no grafo.
// Pós-condição: Adiciona uma nova aresta entre os vértices src e dest no grafo.
void GraphBFS::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    if (!this->directed) adjLists[dest].push_back(src);
}

// Descrição: Executa a busca em largura (BFS) a partir de um vértice de origem.
// Entrada: Vértice de origem (startVertex) da busca.
// Retorno: -
// Pré-condição: O vértice de origem deve estar presente no grafo.
// Pós-condição: Imprime a ordem de visitação dos vértices a partir do vértice de origem.
void GraphBFS::BFS(int startVertex) {
    // Inicializa um vetor de visitados com valores falsos.
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;
    bool first = true;

    while (!queue.empty()) {
        int currVertex = queue.front();

        // Imprime o vértice visitado.
        if (first ) cout << currVertex;
        else cout <<  " - " << currVertex  ;
     
        queue.pop_front();
        first = false;

        // Percorre todos os vértices adjacentes ao vértice atual.
        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}