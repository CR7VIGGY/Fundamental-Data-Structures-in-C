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
	list<int>::iterator i;
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
	}

	void BFS(int u)
	{	
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
		{
			visited[i] = false;
		}

		list<int>bfsqueue;

		visited[u] = true;
		bfsqueue.push_back(u);

		while(bfsqueue.empty()!=true)
		{
			u = bfsqueue.front();
			cout<<u<<" ";

			bfsqueue.pop_front();

			for(i = adj[u].begin();i != adj[u].end();i++)
			{
				if(!visited[*i])
				{
					visited[*i] = true;
					bfsqueue.push_back(*i);
				}
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

    g.BFS(2);

	return 0;
}
