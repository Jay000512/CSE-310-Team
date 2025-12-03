#include "Vertex.h"

Vertex::Vertex(){
    
    index = 0;
    degree = 0;
}

int Vertex::getIndex(){
    return index;
}

int Vertex::getDegree(){
    return degree;
}

void Vertex::setIndex(int i){
    index = i;
}

void Vertex::setDegree(int deg){
    degree = deg;
}