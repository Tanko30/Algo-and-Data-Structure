/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Graph Encapsulation (mother program, Program.cpp)
 * [Version]: 1.1 (last version)
 * 
 * *******************************************************************************************/

#include <iostream> 
#include <cstdlib>
#include <vector>

int main();
using namespace std;

/************************************************************************************************
  Definition of class graph
 * *********************************************************************************************/
class Graph {

	int n_v;// Number of vertex
	int** adj;// Adjacency matrix

public:
	Graph(int n_v);//contructor
	void InsertEdge(int start, int e);// Function to insert a new edge
	void Bfs(int start);// Function to display the BFS traversal
    void Dfs(int start, vector<bool>& visited);//Function to display the DFS traversal
};

// contructor, to initiate the adjancy matrix
Graph::Graph(int n_v)
{
	this->n_v = n_v;
	adj = new int*[n_v];
	for (int i = 0; i < n_v; i++) {
		adj[i] = new int[n_v];
		for (int j = 0; j < n_v; j++) {
			adj[i][j] = 0;
		}
	}
}

/************************************************************************************************
  Function to insert a new edge, considering as bidirectional
 * *********************************************************************************************/
void Graph::InsertEdge(int start, int e)
{
	adj[start][e] = 1;
	adj[e][start] = 1;
}

/************************************************************************************************
  The BFS function
 * *********************************************************************************************/
void Graph::Bfs(int start)
{
	vector<bool> visited(n_v, false); //key associate to vertex for visit purpose
	vector<int> q;//to record visiting
	q.push_back(start);
		visited[start] = true; // Set source as visited
	int vis;
	while (!q.empty()) {
		vis = q[0];
		cout << "(" <<vis << ") ";// Print the current vertex
		q.erase(q.begin());
		// For every adjacent vertex to the current vertex
		for (int i = 0; i < n_v; i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {
				q.push_back(i);	// Push the adjacent vertex to the queue
				visited[i] = true;// Set
			}
		}
	}
}

/************************************************************************************************
  The DFS function
 * *********************************************************************************************/
void Graph::Dfs(int start, vector<bool>& visited)
{
    cout <<"(" << start << ") "; // print the current vertex
	visited[start] = true; // Set current vertex as visited
		// For every vertex of the graph
		for (int i = 0; i < n_v; i++) {
			if (adj[start][i] == 1 && (!visited[i])) { //for adjacent vertices to the current vertex which are not yet visited
            Dfs(i, visited); 
            } 
		}
}


/************************************************************************************************
  The home menu of the program
 * *********************************************************************************************/
int homeGraph()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t GRAPH TRAVERSALS MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Depht First Search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2- Breadth First Search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >>choice;

    } while ((choice < 1 ) || (choice > 3));
    
    return choice;
}



/************************************************************************************************
  main of the program
 * *********************************************************************************************/
int MainGraph()
{

    int choice = homeGraph();

    //Example of Data set
    int v=8;
    Graph G(v);
    G.InsertEdge(0, 1);
    G.InsertEdge(0, 2);
    G.InsertEdge(0, 3);
    G.InsertEdge(0, 4);
    G.InsertEdge(2, 5);
    G.InsertEdge(2, 6);
    G.InsertEdge(3, 7);
    vector<bool> visited(v, false);//for DFS recursivity


    switch (choice)
    {
        case 1:
            cout << "\tDepht First Search: ";
            G.Dfs(0, visited);
            MainGraph();
            break;
        case 2:
            cout << "\tBreadth First Search: ";
            G.Bfs(0);
            MainGraph();
            break;
        case 3:
            main();
            break;
       default:
           break;
       }
    return 0;
}