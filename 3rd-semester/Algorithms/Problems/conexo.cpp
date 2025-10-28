#include <vector>
#include <iostream>
using namespace std;
#include <queue>



void bfs(vector<vector<int>> &graph, vector<bool> &marked, int start)
{
    queue<int> q;
    q.push(start);
    marked[start] = true;
    int n = graph.size();
    while (q.size() > 0)
    {
        int v = q.front();
        q.pop();
        for(int w: graph[v]){
            if(marked[w] == false){
                marked[w] = true;
                q.push(w);
            }
        }
    }
}

void transverse(vector<vector<int>> &graph, vector<bool> &marked)
{
    int n = graph.size();

    // Clear all vertices
    for (int i = 0; i < n; i++)
    {
        if (marked[i] == true)
        {
            marked[i] = false;
        }
    }
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (marked[j] == false)
        {
            count++;
            bfs(graph, marked, j);
        }
    }
    cout << count << endl;
}

int main()
{
    int c;
    int v;
    int e;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int v;
        int e;

        cin >> v;
        cin >> e;

        vector<vector<int>> graph(v);
        vector<bool> marked(v, false);

        for (int j = 0; j < e; j++)
        {
            int v1;
            int v2;

            cin >> v1;
            cin >> v2;

            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        transverse(graph, marked);
    }
}
