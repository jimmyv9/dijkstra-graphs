# dijkstra-graphs
Written for Data Structures and Algorithms class. An implementation of the Dijkstra algorithm.

Program takes in an input file used to build a directed graph.

INPUT FORMAT EXAMPLE:

3

1 2 2

1 3 5

2 3 4

Above, a graph with 3 nodes is constructed, as indicated by the first line of the text file. The other lines of describe the directed edges of the graph in this fashion: (node_A, node_B, distance).

Once the graph is built, the program outputs a .txt file with the shortest path from the chosen node to all other nodes in the graph.
For example, when looking at Node 1 using the input above, we get...

OUTPUT FORMAT EXAMPLE:

1: 0 [1]

2: 2 [1, 2]

3: 5 [1, 3]

