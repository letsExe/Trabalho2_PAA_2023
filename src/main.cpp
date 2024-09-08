#include <iostream>
#include <string>
#include <filesystem>

#include "menu.h"
#include "depthFirstSearch.h"
#include "breadthFirstSearch.h"
#include "bellamFord.h"
#include "kruskall.h"
#include "componetesConexas.h"
#include "kosaraju.h"
#include "file.h"
#include "graphviz.h"
#include "grafo.h"
using namespace std;


int main (){
    int op, op1, op2, src;
    string fileName;
    grafo grafo;

    welcome();
    desenvolvedores();

    do{
        print_option();
        cin >> op;
        cin.ignore();

        if(op == 1){
            cout << "Digite o nome do arquivo..." << endl;
            cin >> fileName;
            if (readFile(fileName, grafo)){
                do{
                    print_option_algorithm();
                    cin >> op1;
                    cin.ignore();

                    switch(op1){
                        case 1: {
                            cout << "desenha grafo" << endl;

                            generateDotFile(grafo);
                            generateGraphImage();

                            break;
                        }

                        case 2: {
                            cout << endl << "Depth-First-Search's Algorithm" << endl;
                            
                            GraphDFS graph(grafo);

                            cout << "Digite o Vertice de origem:"  << endl;

                            cin >> src;

                            graph.DFS(src);

                            break;
                        }

                        case 3: {
                            cout << endl << "Breadth-First-Search's Algorithm" << endl;

                            GraphBFS graph(grafo);


                            cout << "Digite o Vertice de origem:"  << endl;

                            cin >> src;
                         
                            graph.BFS(src);
                            break;
                        }

                        case 4: {
                            cout << endl << "Bellman Ford Algorithm" << endl;

                            if (!grafo.isOrientado()){
                                cout << endl << "Nao sera possivel executar o Bellman Ford Algorithm " << endl;
                                cout << endl << "Motivo: grafo nao orientado " << endl;
                                break;

                            }
                            GraphBellamFord graph(grafo);

                            cout << "Digite o Vertice de origem:"  << endl;

                            cin >> src;

                            graph.BellmanFord(src);

                            break;
                        }
                        case 5: {
                            cout << endl << "Kruskall's Algorithm" << endl;
                            
                             if (grafo.isOrientado()){
                                cout << endl << "Nao sera possivel executar o Kruskall's Algorithm " << endl;
                                cout << endl << "Motivo: grafo orientado " << endl;
                                break;

                            }

                            GraphKruskall graph(grafo);

                            graph.Kruskal();

                            generateKruskallGraph(grafo, graph);

                            generateGraphImage();

                            break;
                        }

                        case 6:{
                            cout << "Componentes Conexas Algarithm" << endl;

                                if (grafo.isOrientado()){
                                    cout << endl << "Nao sera possivel executar o Componentes Conexas Algarithm " << endl;
                                    cout << endl << "Motivo: grafo orientado " << endl;
                                    break;
                                }


                                GraphCC graph(grafo); 

                                graph.findConnectedComponents();
                                break;
                        }
                            
                        case 7: {   
                            if (!grafo.isOrientado()){
                                    cout << endl << "Nao sera possivel executar o Strongly Connected Components " << endl;
                                    cout << endl << "Motivo: grafo nao orientado " << endl;
                                    break;
                            }

                            GraphCFC graph(grafo); 

                            vector<vector<int>> SCCs = graph.stronglyConnectedComponents();

                            graph.showComponents(SCCs);

                            generateSCCGraph(grafo, SCCs);

                            generateGraphImage();

                            break;
                        }  
                    }
                } while (op1 != 0);
            }

           
        }
    } while(op != 0);

    return 0;
}