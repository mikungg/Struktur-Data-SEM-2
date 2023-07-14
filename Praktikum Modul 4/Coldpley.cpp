#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

typedef struct graph{
    public:
    int vertex, edge;
    vector<vector<int>> adjList;

    void init(int v){
        for(int i=1; i <= v; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(int vertex1, int vertex2){
        if(find(adjList[vertex1].begin(), adjList[vertex1].end(), vertex2) != adjList[vertex1].end())
        {
            return; // check if vertex already inserted
        }

        adjList[vertex1].push_back(vertex2);
    }
}Graph;

int main(){
    int n;
    Graph g;
    
    scanf("%d", &n);
    g.init(n);

    int p1, p2;
    deque<int> p1deque;

    while(1)
    {
        scanf("%d %d", &p1, &p2);

        if(p1 == -1 && p2 == -1)
        {
            break;
        }

        g.add_edge(p1, p2);

        if(find(p1deque.begin(),p1deque.end(),p1) == end(p1deque))
        {
            p1deque.push_back(p1);
        }
    }

    int arr[n] = {0};
    int minimal = n/2;

    for(int i=0; i < p1deque.size(); i++)
    {
        for(int j=0; j < g.adjList[p1deque[i]].size(); j++)
        {
            arr[g.adjList[p1deque[i]][j]]++;

            if(arr[g.adjList[p1deque[i]][j]] > minimal)
            {
                if(find(p1deque.begin(), p1deque.end(), g.adjList[p1deque[i]][j]) == end(p1deque))
                {
                    printf("pilih ini aja chris %d", g.adjList[p1deque[i]][j]);
                    return 0;
                }
            }
        }
    }

    printf("ga ada yang direkomen");
}