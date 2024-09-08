
#include "graphviz.h"

using namespace std;

#ifdef _WIN32
    const string os = "Windows";

#else
    const string os = "Linux/Mac";

#endif

// Descrição: Gera um arquivo DOT representando um grafo a partir de um arquivo de entrada.
// Entrada: Grafo a ser representado no arquivo DOT.
// Retorno: Retorna true se o arquivo DOT foi gerado com sucesso, caso contrário retorna false.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é criado com a representação do grafo.

bool generateDotFile(grafo grafo)
{
    int vertex1, vertex2, weight;
    string line;
    string separator = grafo.isOrientado() ? "->" : "--";
    string graphType = grafo.isOrientado() ? "digraph" : "graph";

    ofstream dotFile("graph.dot");

    if (!dotFile)
    {
        cerr << "Erro ao criar arquivo DOT.";
        return false;
    }

    dotFile << " " << graphType << " G {" << endl;

    dotFile << "rankdir=LR;" << endl;
    dotFile << "ranksep=1.0;" << endl;
    dotFile << "nodesep=0.5;" << endl;
    dotFile << endl;
    dotFile << "node [shape=circle];" << endl;
    dotFile << endl;

    for (aresta aresta : grafo.getArestas())
    {
        vertex1 = aresta.a;
        vertex2 = aresta.b;
        weight = aresta.peso;

        dotFile << "    " << vertex1 << separator << vertex2 << " [label=\"" << weight << "\"];" << endl;
    }
    dotFile << "}" << endl;

    dotFile.close();

    return true;
}

// Descrição: Gera a imagem do grafo usando o Graphviz.
// Entrada: Nenhuma.
// Retorno: Nenhum.
// Pré-condição: O arquivo DOT do grafo foi gerado com sucesso.
// Pós-condição: Uma imagem do grafo é gerada e salva no mesmo diretório com o nome graph.png.

void generateGraphImage()
{
    // Caminho para o executável do Graphviz
    string graphvizPath = (os == "Windows") ? "\"C:\\Program Files\\Graphviz\\bin\\dot\"" : "dot";

    // Comando completo com argumentos
    string command = graphvizPath + " -Tpng graph.dot -o graph.png";

    // Executar o comando
    system(command.c_str());
}

// Descrição: Gera um arquivo DOT para representar um grafo com componentes fortemente conectados (SCCs) e atribui cores aos vértices com base nos SCCs. Escreve as arestas com seus pesos no arquivo DOT.
// Entrada: Um objeto grafo e uma lista de SCCs.
// Retorno: Verdadeiro se o arquivo DOT foi gerado com sucesso, falso caso contrário.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é gerado com sucesso representando o grafo com cores atribuídas aos vértices e suas arestas, pronto para ser utilizado com o Graphviz para gerar uma imagem do grafo.
bool generateSCCGraph(grafo grafo, vector<vector<int>> SCCs)
{
    int vertex1, vertex2, weight;
    string line;
    string separator = grafo.isOrientado() ? "->" : "--";
    string graphType = grafo.isOrientado() ? "digraph" : "graph";

    ofstream dotFile("graph.dot");

    if (!dotFile)
    {
        cerr << "Erro ao criar arquivo DOT.";
        return false;
    }

    dotFile << " " << graphType << " G {" << endl;

    dotFile << "rankdir=LR;" << endl;
    dotFile << "ranksep=1.0;" << endl;
    dotFile << "nodesep=0.5;" << endl;
    dotFile << endl;
    dotFile << "node [shape=circle];" << endl;
    dotFile << endl;

    vector<string> colors{"yellow", "purple", "blue", "red", "green"};
    vector<string> components;
    string component = "";

    for (auto i = 0; i < SCCs.size(); i++)
    {
        for (auto j = 0; j < SCCs[i].size(); j++)
        {
            component += to_string(SCCs[i][j]) + ",";
        }
        components.push_back(component);
        component = "";
    }

    for (aresta aresta : grafo.getArestas())
    {
        vertex1 = aresta.a;
        vertex2 = aresta.b;
        weight = aresta.peso;

        for (int i = 0; i < components.size(); i++)
        {

            if (components[i].find((to_string(vertex1) + ",")) != -1)
                dotFile << "    " << vertex1 << " [color=" << colors[i] << "];" << endl;

            if ((components[i].find((to_string(vertex2) + ",")) != -1))
                dotFile << "    " << vertex2 << " [color=" << colors[i] << "];" << endl;
        }
        dotFile << "    " << vertex1 << separator << vertex2 << " [label=\"" << weight << "\"];" << endl;
    }
    dotFile << "}" << endl;

    dotFile.close();

    return true;
}

// Descrição: Gera um arquivo DOT para representar um grafo com arestas destacadas, onde as arestas selecionadas pelo algoritmo de Kruskall são coloridas de uma maneira específica. Escreve as arestas com seus pesos no arquivo DOT.
// Entrada: Um objeto grafo e um objeto GraphKruskall contendo o resultado do algoritmo de Kruskall.
// Retorno: Verdadeiro se o arquivo DOT foi gerado com sucesso, falso caso contrário.
// Pré-condição: Nenhuma.
// Pós-condição: Um arquivo DOT é gerado com sucesso representando o grafo, com as arestas selecionadas pelo algoritmo de Kruskall destacadas com uma cor específica e prontas para serem visualizadas com o Graphviz.
bool generateKruskallGraph(grafo grafo, GraphKruskall k)
{
    int vertex1, vertex2, weight;
    string line;
    string separator = grafo.isOrientado() ? "->" : "--";
    string graphType = grafo.isOrientado() ? "digraph" : "graph";

    ofstream dotFile("graph.dot");

    if (!dotFile)
    {
        cerr << "Erro ao criar arquivo DOT.";
        return false;
    }

    dotFile << " " << graphType << " G {" << endl;

    dotFile << "rankdir=LR;" << endl;
    dotFile << "ranksep=1.0;" << endl;
    dotFile << "nodesep=0.5;" << endl;
    dotFile << endl;
    dotFile << "node [shape=circle];" << endl;
    dotFile << endl;

    vector<string> colors{"yellow", "purple", "blue", "red", "green"};
    vector<string> arestasColoridas;
    string ar = "";

    for (auto krusk : k.getResult())
    {
        ar += to_string(krusk.src) + ",";
        ar += to_string(krusk.dest);

        arestasColoridas.push_back(ar);
        ar = "";
    }
    bool colored = false;

    for (aresta aresta : grafo.getArestas())
    {
        vertex1 = aresta.a;
        vertex2 = aresta.b;
        weight = aresta.peso;
        colored = false;

        for (auto ar : arestasColoridas)
        {

            if (ar.find((to_string(vertex1) + "," + to_string(vertex2))) != -1)
            {
                dotFile << "    " << vertex1 << separator << vertex2 << "[color=" << colors[2] << " ,label=\"" << weight << "\"];" << endl;
                colored = true;
            }
        }

        if (!colored)
            dotFile << "    " << vertex1 << separator << vertex2 << " [label=\"" << weight << "\"];" << endl;
    }
    dotFile << "}" << endl;

    dotFile.close();

    return true;
}
