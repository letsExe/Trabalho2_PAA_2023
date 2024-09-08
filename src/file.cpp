
#include "file.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <utility>


using namespace std;

// Descrição: Função que lê um arquivo contendo informações sobre um grafo e o carrega em um objeto grafo.
// Entrada: Nome do arquivo de entrada (inputFile) e um objeto grafo (grafo) para armazenar os dados lidos.
// Retorno: Verdadeiro se o arquivo foi lido e os dados foram carregados com sucesso, falso caso contrário.
// Pré-condição: O arquivo de entrada deve existir e estar no formato correto.
// Pós-condição: O grafo é atualizado com os vértices, arestas e orientação conforme descrito no arquivo.
bool readFile(string inputFile, grafo &grafo) {
    string line, subs; // Strings para armazenar as linhas e substrings lidas do arquivo.
    int vertex1, vertex2, weight; // Variáveis para armazenar os vértices e pesos das arestas.
    int start_index, end_index; // Índices de início e fim para extrair substrings.

    ifstream file(inputFile); // Abre o arquivo de entrada.

    // Verifica se o arquivo foi aberto corretamente.
    if (!file.is_open()) {
        cerr << "Erro ao abrir arquivo de entrada.\n";
        return false;
    }

    // Limpa as arestas do grafo antes de carregar novos dados.
    grafo.clearArestas();

    // Lê cada linha do arquivo.
    while (getline(file, line)) {
        // Verifica se a linha contém informações sobre a orientação do grafo.
        if (line.find("orientado") != -1) {
            grafo.setOrientado(line.find("sim") != -1);

        // Verifica se a linha contém informações sobre o número de vértices do grafo.
        } else if (line.find("V=") != -1) {
            start_index = line.find("V=") + 2;
            end_index = line.size();
            subs = line.substr(start_index, end_index - start_index);
            grafo.setNumVertices(stoi(subs));

        // Verifica se a linha contém informações sobre uma aresta do grafo.
        } else if (line.find("(") != -1) {
            // Extrai o primeiro vértice da aresta.
            start_index = line.find("(") + 1;
            end_index = line.find(",");
            subs = line.substr(start_index, end_index - start_index);
            vertex1 = stoi(subs);

            // Extrai o segundo vértice da aresta.
            start_index = end_index + 1;
            end_index = line.find(")");
            subs = line.substr(start_index, end_index - start_index);
            vertex2 = stoi(subs);

            // Extrai o peso da aresta.
            start_index = line.find(":") + 1;
            end_index = line.size();
            subs = line.substr(start_index, end_index - start_index);
            weight = stoi(subs);

            // Adiciona a aresta ao grafo.
            grafo.addAresta(vertex1, vertex2, weight);
        }
    }

    file.close(); // Fecha o arquivo após a leitura.

    return true; // Retorna verdadeiro indicando que a leitura foi bem-sucedida.
}