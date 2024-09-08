#include "kosaraju.h"

// Descrição: Construtor da classe GraphCFC.
// Entrada: Número de vértices V do grafo.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphCFC é inicializado com V vértices e as listas de adjacências do grafo e seu transposto são criadas.

GraphCFC::GraphCFC(int V) : V(V), adj(V), adjT(V) {}

// Descrição: Construtor da classe GraphCFC a partir de um grafo existente.
// Entrada: Grafo g a ser utilizado.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: O objeto GraphCFC é inicializado com os vértices e arestas do grafo g, e as listas de adjacências do grafo e seu transposto são criadas.

GraphCFC::GraphCFC(grafo g): V(g.getNumVertices()), adj(g.getNumVertices()), adjT(g.getNumVertices()) {
    for (aresta ares : g.getArestas()){
        this->addEdge(ares.a, ares.b);
    }
}

// Descrição: Adiciona uma aresta entre os vértices u e v nas listas de adjacências do grafo e do seu transposto.
// Entrada: Vértices u e v a serem conectados pela aresta.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Uma aresta é adicionada nas listas de adjacências do grafo e do seu transposto.

void GraphCFC::addEdge(int u, int v) {
    adj[u].push_back(v);
    adjT[v].push_back(u);
}

// Descrição: Função utilitária para realizar a busca em profundidade a partir do vértice u e preencher a pilha Stack com os vértices visitados.
// Entrada: Vértice u a ser visitado, vetor de vértices visitados e pilha Stack.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Os vértices são visitados e adicionados à pilha Stack.
void GraphCFC::DFSUtil(int u, vector<bool>& visited, stack<int>& Stack) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            DFSUtil(v, visited, Stack);
    Stack.push(u);
}

// Descrição: Função utilitária para realizar a busca em profundidade a partir do vértice u e preencher o vetor component com os vértices do componente conectado.
// Entrada: Vértice u a ser visitado, vetor de vértices visitados e vetor component.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Os vértices são visitados e adicionados ao vetor component.
void GraphCFC::DFSUtilTranspose(int u, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adjT[u])
        if (!visited[v])
            DFSUtilTranspose(v, visited, component);
}

// Descrição: Encontra os componentes fortemente conectados do grafo.
// Entrada: Nenhuma.
// Retorno: Vetor de vetores representando os componentes fortemente conectados.
// Pré-condição: Nenhuma.
// Pós-condição: Os componentes fortemente conectados do grafo são identificados e retornados.
vector<vector<int>> GraphCFC::stronglyConnectedComponents() {
    stack<int> Stack;
    vector<bool> visited(V, false);

    // Preenche a pilha Stack de acordo com o tempo de finalização dos vértices
    for (int u = 0; u < V; u++)
        if (!visited[u])
            DFSUtil(u, visited, Stack);

    // Cria um grafo reverso (transposto do grafo original)
    // Preenche a pilha Stack de acordo com o tempo de finalização dos vértices
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> SCCs;
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        if (!visited[u]) {
            vector<int> component;
            DFSUtilTranspose(u, visited, component);
            SCCs.push_back(component);
        }
    }
    return SCCs;
}

// Descrição: Exibe os componentes fortemente conectados do grafo.
// Entrada: Vetor de vetores representando os componentes fortemente conectados.
// Retorno: Nenhum.
// Pré-condição: Nenhuma.
// Pós-condição: Os componentes fortemente conectados do grafo são exibidos na saída padrão.

void GraphCFC::showComponents(vector<vector<int>> SCCs){
    cout << "Strongly Connected Components:\n";
    for (auto i = 0; i < SCCs.size(); i++) {
        cout << "Componente " << i + 1 << ": ";
        for (auto j = 0; j < SCCs[i].size(); j++) {
            cout << SCCs[i][j];
            if (j < SCCs[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}