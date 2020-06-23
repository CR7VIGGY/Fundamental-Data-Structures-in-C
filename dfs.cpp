#include"bits/stdc++.h" 
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
typedef long long int ll;
const int N=1e5+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

class Graph
{
public:
	int V;
	list<int> *adj;
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}
	void DFSTraversal(int v, bool visited[])
	{
		visited[v] = true;
		cout<<v<<" ";
		list<int>::iterator i;

		for(i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(!visited[*i])
			{
				DFSTraversal(*i,visited);
			}
		}

	}

	void DFS()
	{
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i] = false;
		}

		for(int i=0;i<V;i++)
		{
			if(visited[i]!=true)
			{
				DFSTraversal(i,visited);
			}
		}
	}

};

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    g.DFS();

	return 0;
}
