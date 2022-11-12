//Alan Patricio González Bernal
//A01067546
//Sab 12 nov 2022

#include <iostream>
#include <stack>
#include <list>

using namespace std;

//Tenemos que usar DFS y BFS
//Depth First Search
//Breath First Search

//Haremos 2 clases, una para cada método el cual al finalizar será llamado por el main.

//El DFS necesita stack para poder funcionar, el DBS utilizará listas regulares.

// Primero el algoritmo de BFS

int entrada;
int nodo;
int arista;
int ContArista;
int ContNodo;

class Graphbfs {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graphbfs(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

Graphbfs::Graphbfs(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

void Graphbfs::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}


void Graphbfs::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}


//Ahora toca el algoritmo DFS

class Graphdfs {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graphdfs(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

Graphdfs::Graphdfs(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

void Graphdfs::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

void Graphdfs::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
};

//Ahora, crearemos los métodos de llamada de ambos algoritmos
void métodoBFS(int nodo, int arista){

  Graphbfs g(arista);

      for(int i; i < nodo; i++){

        ContNodo = i;
        for(int j; j < arista; j++){

        ContArista = j;

        g.addEdge(ContNodo, ContArista);
    };

    
  g.BFS(nodo);


}
}

void métodoDFS(int nodo, int arista){

  Graphdfs g(arista);
       for(int i; i < nodo; i++){

        ContNodo = i;
        for(int j; j < arista; j++){

        ContArista = j;

        g.addEdge(ContNodo, ContArista);
    };



  g.DFS(nodo);

}
}

int main() {

 //Deben entrar 2 enteros, uno para la cantidad de vertices y otro para la cantidad de arcos.

    cout << "Por favor, ingrese los nodos: ";
    cin >> nodo;
    cout << "\n\nPor favor, ingrese las aristas: ";
    cin >> arista;

    métodoBFS(nodo, arista);
    métodoDFS(nodo, arista);

  return 0;
}
