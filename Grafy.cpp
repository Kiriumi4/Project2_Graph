// Grafy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "mGraph.h"
#include "SGraph.h"
#include <iostream>
#include <chrono>  
#include <stdlib.h> 
using namespace std::chrono;
using namespace std;


int main()
{
	float  duration1[100];
	float  duration2[100];
	
	float  time1 = 0;
	float  time2 = 0;
	


	int V=30;
	int V2 = 1;
	int multi=0;
	int digraf=1;

	mGraph *Tree = new mGraph(V2, digraf, multi);
	mGraph* Tree2 = new mGraph(V, digraf, multi);
	sGraph *gh= new sGraph(V);
	sGraph* t = new sGraph(V);
	sGraph* t2 = new sGraph(V);


	int list_matrix[1000][3];
	int list_list[1000][3];

	Tree->insertVertex(V2);
	Tree2->insertVertex(V);
	//___________________________TESTY______________________________________//
	//_________________________Algorytm Prima____________________________//
	int licznik = V * 0.75;

	/*
	for (int b = 0; b < 100; b++)
	{
		mGraph* G = new mGraph(V, digraf, multi);
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (i < licznik)
				{
					G->insertEdge(i+1, j, 0);
					G->insertEdge(j, i+1, 0);


				}else if (i < j && i!=licznik+1)
				{

					int x = rand() % 9 + 1; //pełne
					if (i == j)
					{
						G->insertEdge(i, j, 0);


					}
					else
					{

						G->insertEdge(i, j, x);
						G->insertEdge(j, i, x);


					}

					gh->insertEdgeL(i - 1, j - 1, x);

				}

			}
		}
		
		int k = 0;
		int l = 0;
		int temp = 11;
		int temp1 = 0;
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (G->getWeight(i, j) != 0)
				{

					list_matrix[k][0] = i + 1;
					list_matrix[k][1] = j + 1;
					list_matrix[k][2] = G->getWeight(i, j);

					if (temp > list_matrix[k][2])
					{
						temp = list_matrix[k][2];
						temp1 = j + 1;
						l = k;

					}

					k++;
				}
			}

			Tree->insertVertex(2 + i);
			Tree->insertEdge(i + 1, temp1, temp);
			list_matrix[l][0] = 0;
			list_matrix[l][1] = 0;
			list_matrix[l][2] = 0;
			temp1 = 0;
			temp = 11;

		}
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		

		//LIST
		int x = 0;
		int y = 0;
		int temp2 = 11;
		int temp3 = 0;
		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{


				list_list[x][0] = i;
				list_list[x][1] = j;
				list_list[x][2] = gh->getWeightL(i, j);



				if (temp2 > list_list[x][2] && list_list[x][2] != 0)
				{
					temp2 = list_list[x][2];
					temp3 = j;
					y = x;

				}

				x++;

			}
			cout << endl;
			t->insertEdgeL(i, temp3, temp2);
			list_list[y][0] = 0;
			list_list[y][1] = 0;
			list_list[y][2] = 0;
			temp3 = 0;
			temp2 = 11;

		}
		high_resolution_clock::time_point t4 = high_resolution_clock::now();

		duration1[b] = duration_cast<microseconds>(t2 - t1).count();    //messuring time of matrix
		duration2[b] = duration_cast<microseconds>(t4 - t3).count();    //messuring time of list

		time1 += duration1[b];
		time2 += duration2[b];

	}

	*/

	//___________________________TESTY______________________________________//
	//_________________________Algorytm KRUKSALA____________________________//

for (int b = 0; b < 100; b++)
{
	mGraph* G = new mGraph(V, digraf, multi);
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i < licznik)
			{
				G->insertEdge(i + 1, j, 0);
				G->insertEdge(j, i + 1, 0);


			}
			else if (i < j && i != licznik + 1)
			{

				int x = rand() % 9 + 1; //pełne
				if (i == j)
				{
					G->insertEdge(i, j, 0);


				}
				else
				{

					G->insertEdge(i, j, x);
					G->insertEdge(j, i, x);


				}

				gh->insertEdgeL(i - 1, j - 1, x);

			}

		}
	}

	/*int k = 0;
	int l = 0;
	int temp = 11;
	int temp1 = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (G->getWeight(i, j) != 0)
			{

				list_matrix[k][0] = i + 1;
				list_matrix[k][1] = j + 1;
				list_matrix[k][2] = G->getWeight(i, j);


				k++;
			}
		}

	}


	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < k; j++)
		{

			if (temp > list_matrix[j][2] && list_matrix[j][2] != 0)
			{

				temp = list_matrix[j][2];
				temp1 = j;


			}
			else temp = temp;
		}

		Tree2->insertEdge(list_matrix[temp1][0], list_matrix[temp1][1], temp);
		list_matrix[temp1][0] = 0;
		list_matrix[temp1][1] = 0;
		list_matrix[temp1][2] = 0;
		temp1 = 0;
		temp = 11;

	}

	high_resolution_clock::time_point tb = high_resolution_clock::now();
	*/

	//LIST
	int x = 0;
	int y = 0;
	int temp2 = 11;
	int temp3 = 0;
	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (gh->getWeightL(i, j) != 0)
			{

				list_list[x][0] = i;
				list_list[x][1] = j;
				list_list[x][2] = gh->getWeightL(i, j);


				x++;
			}
		}

	}



	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < x; j++)
		{

			if (temp2 > list_list[j][2] && list_list[j][2] != 0)
			{

				temp2 = list_list[j][2];
				temp3 = j;

			}
			
		}

		t2->insertEdgeL(list_list[temp3][0], list_list[temp3][1], temp2);
		list_list[temp3][0] = 0;
		list_list[temp3][1] = 0;
		list_list[temp3][2] = 0;
		temp3 = 0;
		temp2 = 11;

	}
	high_resolution_clock::time_point t4 = high_resolution_clock::now();

	//duration1[b] = duration_cast<microseconds>(tb - t1).count();    //messuring time of matrix
	duration2[b] = duration_cast<microseconds>(t4 - t3).count();    //messuring time of list

	//time1 += duration1[b];
	time2 += duration2[b];

}

	cout << "Success" << endl << endl;

	cout << "Matrix time for Prime Algorithm:" << endl;
	//cout << time1 << " micro s" << endl;
	cout << "List time for Prime Algorithm:"  << endl;
	cout << time2 << " micro s" << endl;



/*
	//graf tworzenie grafu pełnego pełny 
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			G->insertEdge(i, j, 0);
		}

	}
	//digraf
	for (int i = 1; i <= V; i++) 
	{
		for (int j = 1; j <= V; j++)
		{
			if (i < j)
			{
				int x = rand() % 10;
				if (i == j) 
				{
				G->insertEdge(i, j, 0);
				
					
				}
				else 
				{
					
				G->insertEdge(i, j, x);
				G->insertEdge(j, i, x);
				
						
				}
				
				 gh->insertEdgeL(i-1 , j-1, x);
				
			}
				
		}
	}
	
	
	//wyświetlanie
	gh->printGraph();
	cout << endl;
	cout << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			G->print(i, j);
		}
		cout << endl;
	}

	cout << endl;
	cout <<"____________________________________________________________" <<endl;
	cout << endl;
	*/

//_________________________Algorytm Prima____________________________//
	//MATRIX
/*
	int k = 0;
	int l = 0;
	int temp = 11;
	int temp1 = 0;
	for (int i = 0; i < V ; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (G->getWeight(i, j) != 0)
			{

				list_matrix[k][0] = i + 1;
				list_matrix[k][1] = j + 1;
				list_matrix[k][2] = G->getWeight(i, j);

				if (temp > list_matrix[k][2])
				{
					temp = list_matrix[k][2];
					temp1 = j + 1;
					l = k;
					
				}

				k++;
			}
		}
		
		Tree->insertVertex(2 + i);
		Tree->insertEdge(i+1, temp1, temp);
		list_matrix[l][0] = 0;
		list_matrix[l][1] = 0;
		list_matrix[l][2] = 0;
		temp1 = 0;
		temp = 11;
		
	} 


	//LIST
	int x = 0;
	int y= 0;
	int temp2 = 11;
	int temp3 = 0;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			

				list_list[x][0] = i;
				list_list[x][1] = j;
				list_list[x][2] = gh->getWeightL(i, j);
				


				if (temp2 > list_list[x][2] && list_list[x][2]!=0)
				{
					temp2 = list_list[x][2];
					temp3 = j ;
					y = x;

				}

				x++;
			
		}
		cout << endl;
		t->insertEdgeL(i , temp3, temp2);
		list_list[y][0] = 0;
		list_list[y][1] = 0;
		list_list[y][2] = 0;
		temp3 = 0;
		temp2 = 11;

	}
	
	t->printGraph();

	*/

	//_________________________KRUKSALA____________________________//
	//MATRIX
	/*int k = 0;
	int temp = 11;
	int temp1 = 0;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (G->getWeight(i, j) != 0)
			{

				list_matrix[k][0] = i + 1;
				list_matrix[k][1] = j + 1;
				list_matrix[k][2] = G->getWeight(i, j);


				k++;
			}
		}

	}

	

for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < k; j++)
		{
			
			if (temp > list_matrix[j][2] && list_matrix[j][2] != 0)
			{

				temp = list_matrix[j][2];
				temp1 = j;
				

			}
			else temp = temp;
		}

		cout << temp1 << endl;
		Tree2->insertEdge( list_matrix[temp1][0], list_matrix[temp1][1], temp);
		list_matrix[temp1][0] = 0;
		list_matrix[temp1][1] = 0;
		list_matrix[temp1][2] = 0;
		temp1 = 0;
		temp = 11;

	}


	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			Tree2->print(i, j);
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	//LIST

	int x = 0;
	int temp2 = 11;
	int temp3 = 0;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (gh->getWeightL(i, j) != 0)
			{

				list_list[x][0] = i ;
				list_list[x][1] = j ;
				list_list[x][2] = gh->getWeightL(i, j);


				x++;
			}
		}

	}

	for (int j = 0; j < x; j++)
	{
		cout << list_list[j][0];
		cout << list_list[j][1];
		cout << list_list[j][2];
		cout << endl;
	}



	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < x; j++)
		{

			if (temp2 > list_list[j][2] && list_list[j][2] != 0)
			{

				temp2 = list_list[j][2];
				temp3 = j;

			}
			else temp = temp;
		}

		cout << temp3 << endl;
		t2->insertEdgeL(list_list[temp3][0], list_list[temp3][1], temp2);
		list_list[temp3][0] = 0;
		list_list[temp3][1] = 0;
		list_list[temp3][2] = 0;
		temp3 = 0;
		temp2 = 11;

	}
	t2->printGraph();
	*/



	return 0;
}


