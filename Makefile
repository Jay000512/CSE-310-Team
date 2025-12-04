CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

TARGET = dijkstra
OBJS = Main.o Graph.o Vertex.o Edge.o 

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

Main.o: Main.cpp Graph.h Vertex.h Edge.h
Graph.o: Graph.cpp Graph.h Vertex.h Edge.h
Vertex.o: Vertex.cpp Vertex.h
Edge.o: Edge.cpp Edge.h 
clean:
	rm -f *.o $(OBJS)