# 📌 Algoritmos em Grafos — Projeto e Análise de Algoritmos

Este projeto foi desenvolvido em **C++** como parte da disciplina de **Projeto e Análise de Algoritmos**.  
O programa implementa diversos algoritmos clássicos em grafos, permitindo visualizar, percorrer, analisar caminhos mínimos, gerar árvores geradoras mínimas e identificar componentes conexas e fortemente conexas.

---

## 📖 Sobre o Projeto

Grafos são estruturas fundamentais na Ciência da Computação, sendo utilizados para representar redes, rotas, dependências, conexões entre objetos e diversos outros problemas do mundo real.

Este trabalho tem como objetivo implementar e demonstrar o funcionamento de algoritmos importantes para análise de grafos, reforçando conceitos como:

- Representação de grafos;
- Percursos em grafos;
- Caminhos mínimos;
- Árvores geradoras mínimas;
- Conectividade;
- Componentes fortemente conexas.

---

## ⚙️ Algoritmos Implementados

O programa contempla os seguintes algoritmos e funcionalidades:

### 1. Desenhar Grafo

Permite exibir a estrutura do grafo, mostrando seus vértices e arestas.

---

### 2. Busca em Profundidade — DFS

A **Busca em Profundidade**, conhecida como **DFS** (*Depth-First Search*), percorre o grafo explorando o máximo possível um caminho antes de retroceder.

A busca é realizada a partir de um vértice de origem informado pelo usuário.

---

### 3. Busca em Largura — BFS

A **Busca em Largura**, ou **BFS** (*Breadth-First Search*), percorre o grafo visitando primeiro todos os vizinhos de um vértice antes de avançar para os próximos níveis.

A busca também é realizada a partir de um vértice de origem informado pelo usuário.

---

### 4. Bellman-Ford

O algoritmo de **Bellman-Ford** é utilizado para encontrar os menores caminhos a partir de um vértice de origem em grafos ponderados.

Diferentemente de outros algoritmos, como Dijkstra, o Bellman-Ford permite trabalhar com arestas de peso negativo, desde que não existam ciclos negativos alcançáveis a partir da origem.

---

### 5. Kruskal

O algoritmo de **Kruskal** é utilizado para encontrar a **Árvore Geradora Mínima** de um grafo conexo, não direcionado e ponderado.

Ele seleciona as arestas de menor peso, evitando a formação de ciclos, até conectar todos os vértices do grafo.

---

### 6. Componentes Conexas

Essa funcionalidade identifica as **componentes conexas** de um grafo não direcionado.

Uma componente conexa é um conjunto de vértices no qual existe um caminho entre qualquer par de vértices pertencentes ao conjunto.

---

### 7. Componentes Fortemente Conexas

As **Componentes Fortemente Conexas** são aplicadas em grafos direcionados.

Uma componente fortemente conexa é um conjunto de vértices em que todos os vértices são alcançáveis entre si, respeitando a direção das arestas.
