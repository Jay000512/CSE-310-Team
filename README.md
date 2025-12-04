# CSE-310-Team
Team project 2 for CSE 310 Fall 25

This program reads a weighted undirected graph and performs the following tasks:

1. Builds an adjacency matrix
2. Finds all vertices with odd degree 
3. Run Dijktra's algorithm from each odd-degree vertex
4. Prints the shortest path distances 

The project is written in C++ using multiple files (Graph, Vertex, Edge, and Main).
A Makefile is also included to compile the project.

## How to Compile
Run the following commands:

make clean
make 

This will create and executable name 'dijkstra'.

## How to Run
Use input redirection:

./dijkstra < input.txt

You can also save the output:

./dijkstra < input.txt > output.txt

# Notes
The program was tested with the instructor - provided test cases. 
