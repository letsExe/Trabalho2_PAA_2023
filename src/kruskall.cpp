#include "kruskall.h"

// Descrição: Construtor da classe GraphKruskall.
// Entrada: Número de vértices V e número de arestas E do grafo.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphKruskall é inicializado com V vértices e E arestas.
GraphKruskall::GraphKruskall(int V, int E) : V(V), E(E) {}

// Descrição: Construtor da classe GraphKruskall a partir de um grafo existente.
// Entrada: Grafo g a ser utilizado.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphKruskall é inicializado com os vértices e arestas do grafo g.
GraphKruskall::GraphKruskall(grafo g): V(g.getNumVertices()), E(g.getNumArestas()) {
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b, ares.peso);
    }
}

// Descrição: Adiciona uma aresta com peso entre os vértices src e dest.
// Entrada: Vértices src e dest e o peso da aresta.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Uma aresta é adicionada ao vetor de arestas do grafo.
void GraphKruskall::addEdge(int src, int dest, int weight) {
    edges.push_back({src, dest, weight});
}

// Descrição: Encontra o representante do conjunto ao qual o vértice pertence.
// Entrada: Vetor parent representando a relação entre vértices e seus pais, e o índice do vértice.
// Retorno: O representante do conjunto ao qual o vértice pertence.
// Pré-condição: Nenhuma.
// Pós-condição: Nenhuma.
int GraphKruskall::find(vector<int> &parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Descrição: Une dois conjuntos em um único conjunto.
// Entrada: Vetor parent representando a relação entre vértices e seus pais, e os índices dos vértices x e y.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Os conjuntos contendo os vértices x e y são unidos em um único conjunto.
void GraphKruskall::Union(vector<int> &parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Descrição: Implementação do algoritmo de Kruskal para encontrar a árvore geradora mínima do grafo.
// Entrada: Nenhuma.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: A árvore geradora mínima do grafo é encontrada e suas arestas são impressas.
void GraphKruskall::Kruskal() {
    vector<int> parent(V, -1);
    int totalWeight = 0;

    // Ordena as arestas em ordem não decrescente de peso
    sort(edges.begin(), edges.end(), [](EdgeKruskall &a, EdgeKruskall &b) {
        return a.weight < b.weight;
    });

    for (const auto &edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        // Se incluir esta aresta não forma um ciclo
        if (x != y) {
            result.push_back(edge);
            totalWeight += edge.weight;
            Union(parent, x, y);
        }
    }

    // Verifica se o grafo é conexo
    if (result.size() == V - 1) {
        cout << "O grafo eh conexo." << endl;
        cout << "Peso total: " << totalWeight << endl;
        cout << "Arestas: ";
        for (const auto &edge : result) {
            cout << "(" << edge.src << ", " << edge.dest << ") ";
        }
    } else {
        cout << "O grafo nao eh conexo." << endl;
        result.clear();  
    }

    // Imprime as arestas da árvore geradora mínima
   
}

// Descrição: Retorna o vetor de arestas resultantes do algoritmo de Kruskall.
// Entrada: Nenhuma.
// Retorno: Um vetor de objetos EdgeKruskall representando as arestas resultantes do algoritmo de Kruskall.
// Pré-condição: Nenhuma.
// Pós-condição: O vetor de arestas resultantes do algoritmo de Kruskall é retornado.
vector<EdgeKruskall> GraphKruskall::getResult(){
    return result;
}