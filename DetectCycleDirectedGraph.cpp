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

	bool isCyclicUtil(int v, bool visited[], bool *reStack)
	{
		if(visited[v] == false)
		{
			visited[v] = true;
			reStack[v] = true;
			list<int>::iterator i;

			for(i=adj[v].begin();i!=adj[v].end();i++)
			{
				cout<<"cycle util"<<*i<<endl;
				if(visited[*i] == false and isCyclicUtil(*i,visited,reStack))
				{
					return true;
				}
				else if(reStack[*i] == true)
				{
					return true;
				}
			}
		}

		reStack[v]=false;
		return false;
	}

	bool isCyclic()
	{
		bool *visited = new bool[V];
		bool *reStack = new bool[V];

		for(int i=0;i<V;i++)
		{
			visited[i] = false;
			reStack[i] = false;
		}

		for(int i=0;i<V;i++)
		{
			cout<<"Cycle->"<<i<<endl;
			if(isCyclicUtil(i,visited,reStack))
			{
				return true;
			}
		}
		return false;

	}
	

	

};

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 

    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;
}
