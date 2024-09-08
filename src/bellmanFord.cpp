#include "bellamFord.h"

// Descrição: Construtor da classe GraphBellmanFord.
// Entrada: Número de vértices (V) e número de arestas (E) do grafo.
// Retorno: Nenhum
// Pré-condição: -
// Pós-condição: Cria um objeto GraphBellmanFord com V vértices e E arestas.
GraphBellamFord::GraphBellamFord(int V, int E) : V(V), E(E) {}

// Descrição: Construtor da classe GraphBellmanFord a partir de um grafo existente.
// Entrada: Objeto do tipo grafo (g) a ser utilizado para criar o GraphBellmanFord.
// Retorno: Nenhum
// Pré-condição: O grafo g deve estar corretamente inicializado.
// Pós-condição: Cria um objeto GraphBellmanFord com base no grafo g, mantendo as mesmas arestas e vértices.
GraphBellamFord::GraphBellamFord(grafo g) : V(g.getNumVertices()), E(g.getNumArestas()) {
    // Adiciona todas as arestas do grafo ao objeto GraphBellmanFord.
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b, ares.peso);
    }
}

// Descrição: Adiciona uma aresta ao grafo com peso.
// Entrada: Vértice de origem (src), vértice de destino (dest) e peso da aresta (weight).
// Retorno: Nenhum
// Pré-condição: Os vértices src e dest devem estar presentes no grafo.
// Pós-condição: Adiciona uma nova aresta com peso entre os vértices src e dest no grafo.
void GraphBellamFord::addEdge(int src, int dest, int weight) {
    edges.push_back({src, dest, weight});
}

// Descrição: Aplica o algoritmo de Bellman-Ford a partir de um vértice de origem.
// Entrada: Vértice de origem (src).
// Retorno: Nenhum
// Pré-condição: O grafo deve estar corretamente inicializado.
// Pós-condição: Calcula e imprime as distâncias mínimas e os caminhos mais curtos a partir do vértice de origem src.
void GraphBellamFord::BellmanFord(int src) {
    // Inicializa um vetor de distâncias com valores máximos.
    vector<int> dist(V, numeric_limits<int>::max());
    // Inicializa um vetor de pais com valores nulos.
    vector<int> parent(V, -1);
    // A distância da origem para ela mesma é 0.
    dist[src] = 0;

    // Executa o relaxamento das arestas V - 1 vezes.
    for (int i = 1; i < V; i++) {
        for (const auto &edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            // Se a distância até u mais o peso da aresta for menor que a distância atual até v, atualiza a distância e o pai de v.
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Verifica se há ciclos de peso negativo após o relaxamento.
    for (const auto &edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
            cout << "Existe ciclo de peso negativo\n";
            return;
        }
    }

    // Imprime os resultados.
    cout << "Origem: " << src << endl;
    for (int i = 0; i < V; i++) {
        cout << "Destino: " << i;
        cout << " | Distancia minima: " << dist[i];
        cout << " | Caminho: ";
        printPath(parent, i);
        cout << endl;
        cout << "-----------------------" << endl;
    }
}

// Descrição: Imprime o caminho de um vértice de destino até o vértice de origem.
// Entrada: Vetor de pais (parent) e vértice de destino (dest).
// Retorno: Nenhum
// Pré-condição: O vetor parent deve ser válido e conter os pais de cada vértice no caminho.
// Pós-condição: Imprime o caminho do vértice de destino até o vértice de origem.
void GraphBellamFord::printPath(const vector<int> &parent, int dest) {
    stack<int> path;
    while (dest != -1) {
        path.push(dest);
        dest = parent[dest];
    
    }
    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) {
            cout << " - ";
        }
    }
}