#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int dest;  //numer wierzcho³ka
    int weight; //waga wierzcho³ka
    struct node* next;  //nastepny element listy
};

/*
 * Adjacency List
 */
struct AdjList
{
    struct node* head;
};


class sGraph
{
private:
    int V;
    struct AdjList* array;
public:
    sGraph(int V)
    {
        this->V = V;
        array = new AdjList[V];
        for (int i = 0; i < V; ++i)
            array[i].head = NULL;
    }
    
    node* newAdjListNode(int dest,int weight)
    {
        node* newNode = new node;
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = NULL;
       
        return newNode;
    }
   
    void insertEdgeL(int src, int dest,int weight )
    {
       if(weight!=0)
       {
        node* newNode = newAdjListNode(dest, weight);
           newNode->next = array[src].head;
            array[src].head = newNode;
            newNode = newAdjListNode(src, weight);
            newNode->next = array[dest].head;
            array[dest].head = newNode;
            newNode->weight = weight;
       }

    }

    void removeEdgeL(int src, int dest)
    {
    
            node* temp = array[dest].head;
            node* temp2 = array[src].head;
             node* prev = NULL;

                if (temp != NULL && temp->dest == src)
                {
                    array[dest-1].head = temp->next; // Changed head
                    delete temp;                // free old head

                }
                else
                {

                    while (temp != NULL && temp->dest != src)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    if (temp == NULL) return;
                    prev->next = temp->next;
                    delete temp;
                }

                if (temp2 != NULL && temp2->dest == dest)
                {
                    array[src].head = temp2->next; // Changed head
                    delete temp2;                // free old head

                }
                else
                {

                    while (temp2 != NULL && temp2->dest != dest)
                    {
                        prev = temp2;
                        temp2 = temp2->next;
                    }
                    if (temp2 == NULL) return;
                    prev->next = temp2->next;
                    delete temp2;
                }
            

        

    }

    void removeVertexL(int v)
    {
        
        for (int i = 0; i < V; ++i)
        {
            node* temp = array[i].head;
           while(temp)
           {
             temp = array[i].head;
            
            node* prev = NULL;
        
                if (temp != NULL && temp->dest == v)
                {
                    array[i].head = temp->next; // Changed head
                    delete temp;                // free old head
                    
                }
                else
                {

                    while (temp != NULL && temp->dest != v)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    if (temp == NULL) break;
                    prev->next = temp->next;
                    delete temp;
                }
           }
            
        }
        delete array[v].head;
        V-= 1;
    }
    
    void printGraph()
    {

        int v;
        for (v = 0; v < V; ++v)
        {
            node* pCrawl = array[v].head;
            cout << "\n Adjacency list of vertex " << v+1<< "\n head ";
            while (pCrawl)
            {
               
                    cout << "  " << pCrawl->dest+1;
                    cout << "_" << pCrawl->weight;


                    pCrawl = pCrawl->next;
                
            }
            cout << endl;
        }
    }

    int getWeightL(int src, int dest) 
    {
        node* temp = array[src].head;
        while(temp)
        { 
            if ( temp->dest == dest)
            {

                return temp->weight;

            }
            else temp=temp->next;
            
        }
        if(temp==NULL )return 0;
    };
   
    int getEdgesL(){ return V; };
    
};