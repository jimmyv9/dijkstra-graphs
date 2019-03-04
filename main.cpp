/*
 * João Pedro Veloso, Rhodes College
 * Project #5 – Shortest Pathfinding: Dijkstra Implementation using Adjacency Lists
 *
 * Asks user for a text file, with values of vertices and paths.
 *
 * Program will create adjacency list array and populate them with the directed connections between vertices.
 *
 * Then it will run Dijkstra's algorithm, which will return the shortest path from a user chosen initial vertex
 * to every point in the graph.
 *
 * The result is given by an outfile named by the user as well.
 */

#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    //user input for file
    string a;
    cout << "Enter filename to create graph: ";
    cin >> a;
    Graph g = Graph(a);

    //user input for vertex
    int val;
    cout << endl << "Enter the value of a valid vertex: ";
    cin >> val;
    while(val > g.getV() || val < 1) {
        cout << "Invalid value. Enter a valid one: ";
        cin >> val;
    }

    //user input outfile name
    string b;
    cout << "Enter output filename: ";
    cin >> b;

    long int s = clock(); //start time
    g.dijkstra(val, b);
    long int e = clock(); //end time

    cout << "Total time elapsed was: " << (e-s)/double(CLOCKS_PER_SEC)*1000 << " seconds." << endl;

    return 0;
}
