#pragma once
#include <iostream>
using namespace std;

class mGraph
{
    int V, E;
    bool DiGraph;
    bool MultiGraph;
    int** GMatrix;
public:
    mGraph(int _V, bool _di, bool _mu);
    ~mGraph();
    bool insertEdge(int v, int u, int o);
    bool removeEdge(int v, int u);
    bool insertVertex(int v);
    bool removeVertex(int v);
    int incidentEdges(int v);
    bool areAdjacent(int v, int u);
    void print(int v, int u) {cout << GMatrix[v][u];};
    int getWeight(int v, int u) { return GMatrix[v][u];};
};


mGraph::mGraph(int _V, bool _di, bool _mu) : V(_V), DiGraph(_di), MultiGraph(_mu)
{
    GMatrix = new int* [_V];
    for (int i = 0; i < V; ++i)
    {
        GMatrix[i] = new int[V];
        for (int j = 0; j < V; ++j)
        {
            GMatrix[i][j] = 0;
        }
    }
}

mGraph::~mGraph()
{
    for (int i = 0; i < V; ++i)
        delete[] GMatrix[i];
    delete[] GMatrix;
}

bool mGraph::insertEdge(int v, int u, int o)
{
   if (!MultiGraph && (GMatrix[v-1][u-1] > 0)) return false;
    GMatrix[v-1][u-1] = o;
    if (!DiGraph) GMatrix[u-1][v-1] = o;
    return true;
}

bool mGraph::removeEdge(int v, int u)
{
    if (GMatrix[v-1][u-1] == 0) return false;
    GMatrix[v-1][u-1] = 0;
    if (!DiGraph) GMatrix[u-1][v-1] = 0;
    return true;
}

bool mGraph::insertVertex(int v)
{
    v++;
    int** GMatrixbig = new int* [v];
    for (int i = 0; i < v; ++i)
    {
        GMatrixbig[i] = new int[v];
        for (int j = 0; j < v; ++j)
        {
            GMatrixbig[i][j] = 0;
        }
    }
    for (int i = 0; i < v - 1; ++i)
    {
        for (int j = 0; j < v - 1; ++j)
        {

            GMatrixbig[i][j] = GMatrix[i][j];

        }
    }

    for (int i = 0; i < v; ++i)
    {
        GMatrixbig[i][v - 1] = 0;
        GMatrixbig[v - 1][i] = 0;

    }

   
    GMatrix = GMatrixbig;

    V = v;
    return true;
}

bool mGraph::removeVertex(int v)
{
    int size = V;
    size--;
    int** GMatrixbig = new int* [size];
    for (int i = 0; i < size; ++i)
    {
        GMatrixbig[i] = new int[size];
        for (int j = 0; j < size; ++j)
        {
            GMatrixbig[i][j] = 0;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        { 
            if (i < v-1) {
                if (j < v-1)
                {
                    GMatrixbig[i][j] = GMatrix[i][j];
                }
                else { GMatrixbig[i][j] = GMatrix[i][j+1]; }
            }
            else 
            {
                if (j < v-1)
                {
                    GMatrixbig[i][j] = GMatrix[i+1][j];
                } else
                { 
                    GMatrixbig[i][j] = GMatrix[i + 1][j+1]; 
                }
            
            
            }
          
        }
    }

    delete[] GMatrix;
    GMatrix = GMatrixbig;
    V -= 1;
    return true;
}

int mGraph::incidentEdges(int v)
{
    int Result = 0;
    for (int i = 0; i < V; ++i)
    {
        if (GMatrix[v-1][i] != 0) { Result += 1; }
    }
    return Result;
}

bool mGraph::areAdjacent(int v, int u)
{
    if (GMatrix[v-1][u-1] > 0) return true;
    else return false;
}