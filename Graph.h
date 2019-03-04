//
// Created by João Pedro Veloso on 12/7/17.
//

#ifndef VELOSO_JOAO_5_GRAPH_H
#define VELOSO_JOAO_5_GRAPH_H

#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int dest;
    int weight;
    int id;
    Node * next;

    //constructor for node
    Node (int i, int d, int w) {
        id = i;
        dest = d;
        weight = w;
        next = nullptr;
    }
};

struct AdjList {
    Node* head;
    //constructor for AdjList
    AdjList() {
        head = nullptr;
    }
};

class Graph {
public:
    Graph(string filename);
    ~Graph();

    int getV() const; //returns value of v, total vertices in array

    void addEdge (int id, int dest, int weight);
    void dijkstra(int start, string filename);
    bool empty(bool *v, int *d);
    int tableDQ(bool *v, int *d);
    void printTable(int s, int *d, int *prev, bool *b, string filename);
    void printTableAux(int s, int i, int *prev, ofstream &file);
    void print() const;

private:
    int v;
    AdjList * a;
};

#endif //VELOSO_JOAO_5_GRAPH_H
