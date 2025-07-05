#ifndef GRAFO_STRING_H
#define GRAFO_STRING_H

#include <vector>
#include <string>
using namespace std;

class CGrafoString {
private:
    class CArco {
    public:
        string info;
        int v; // índice del vértice de llegada
        CArco(int vLlegada) {
            info = "";
            v = vLlegada;
        }
    };

    class CVertice {
    public:
        string info;
        vector<CArco*>* ady; // Lista de adyacencia
        CVertice() {
            info = "";
            ady = new vector<CArco*>();
        }
    };

    // Lista de vértices
    vector<CVertice*>* vertices;

public:
    CGrafoString() {
        vertices = new vector<CVertice*>();
    }

    // Operaciones del Grafo
    int adicionarVertice(string info) {
        CVertice* vert = new CVertice();
        vert->info = info;
        vertices->push_back(vert);
        return vertices->size() - 1;
    }

    int cantidadVertices() {
        return vertices->size();
    }

    string obtenerVertice(int v) {
        return (vertices->at(v))->info;
    }

    void modificarVertice(int v, string info) {
        (vertices->at(v))->info = info;
    }

    // Operaciones del arco
    int adicionarArco(int v, int vLlegada) {
        CVertice* ver = vertices->at(v);
        // Crear el objeto ARCO
        CArco* arc = new CArco(vLlegada);
        ver->ady->push_back(arc);
        return ver->ady->size() - 1;
    }

    int cantidadArcos(int v) {
        return (vertices->at(v))->ady->size();
    }

    string obtenerArco(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->info;
    }

    void modificarArco(int v, int apos, string info) {
        CVertice* ver = vertices->at(v);
        (ver->ady->at(apos))->info = info;
    }

    int obtenerVerticeLlegada(int v, int apos) {
        CVertice* ver = vertices->at(v);
        return (ver->ady->at(apos))->v; // índice del vértice de llegada
    }
};

#endif // GRAFO_STRING_H