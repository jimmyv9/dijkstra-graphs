#include "Graph.h"

//constructs graph by using an input file
Graph::Graph(string filename) {
    int N, id, weight, dest; //where N is the number of vertices in the graph,
                             //weight is the weight between edges and
                             //dest is the destination of the node
    ifstream infile;
    infile.open(filename);

    //checks for inexistent file
    if(!infile.is_open()) {
        cerr << "File does not exist. Try rerunning your program." << endl;
    }

    //read in values from text file and initiates an array of Adjacency Lists
    infile >> N;
    v = N;
    a = new AdjList[v];

    while (infile.good()) {
        infile >> id >> dest >> weight;
        addEdge(id, dest, weight);
    }

    infile.close();
}

Graph::~Graph() {

}

//used to calculate shortest path from a single node and all the other nodes in the graph
//Standard implementation of Dijkstra, with a call to printTable that will serve to output a file:
void Graph::dijkstra(int start, string filename) {
    bool * visited = new bool[v + 1];
    int * dist = new int[v + 1];
    int * prev = new int [v + 1];

    for(int i = 1; i <= v; i++) {
        dist[i] = 32767;
        visited[i] = false;
    }
    dist[start] = 0;

    while (!empty(visited, dist)) {
        int v = tableDQ(visited, dist);
        visited[v] = true;

        Node * temp = a[v - 1].head;
        while (temp) {
            int w = temp->dest;
            int c = temp->weight;
            if (!visited[w]) {
                int alt = dist[v] + c;
                if (alt < dist[w]) {
                    dist[w] = alt;
                    prev[w] = v;
                }
            }
            temp = temp->next;
        }
    }

    printTable(start, dist, prev, visited, filename);
}

//checks if adjacency list is empty, written in class
bool Graph::empty(bool *b, int *d) {

    for (int i = 1; i <= v; i++) {
        if (!b[i] && d[i] != 32767)
            return false;
    }
    return true;
}

//written in class
int Graph::tableDQ(bool *b, int *d) {

    int minSoFar = 32767;
    int ans;
    for (int i = 1; i <= v; i++) {
        if (!b[i] && d[i] != 32767) {
            if (d[i] < minSoFar) {
                minSoFar = d[i];
                ans = i;
            }
        }
    }
    return ans;
}

//getter for number of vertices
int Graph::getV() const {
    return v;
}

//adds a connection into adjacency list
void Graph::addEdge(int id, int dest, int weight) {
    Node* n =  new Node(id, dest, weight);
    //add to beginning of linked list because O(1)
    n->next = a[id-1].head;
    a[id-1].head = n;
}

//used for debugging
void Graph::print() const {
    for (int i = 0; i < v; i++) {
        cout << i+1 << ": [";
        if (a[i].head == nullptr) {
            cout << "NO PATH]" << endl;
        }
        else {
            Node* curr;
            curr = a[i].head;
            while(curr != nullptr) {
                cout << curr->dest << " ";
                curr = curr->next;
            }
            cout << "]" << endl;
        }
    }
    cout << endl;
}

//outfiles solution to shortest path to another file
void Graph::printTable(int s, int *d, int *prev, bool *b, string filename) {
    ofstream file;
    file.open(filename);
    for (int i = 1; i < v + 1; i++) {
        if (!b[i]) {
            file << i << ": ";
            file << "NO PATH" << endl;
        }
        else if (d[i] == 0)
            file << i << ": " << "0 [" << i << "] " << endl;
        else {
            file << i << ": " << d[i] << " ";
            printTableAux(s, i, prev, file);
            file << "]" << endl;
        }
    }
    file.close();
}

//auxiliary function to printTable
void Graph::printTableAux(int s, int i, int *prev, ofstream &file) {
    if (s == i) {
        file << "[" << i;
        return;
    }
    printTableAux(s, prev[i], prev, file);
    file << ", " << i;
}
