#include <vector>
#include <iostream>
using namespace std;
#include <queue>
# include <algorithm>

void path(vector<int> &predecessor, int e, int s){
    if(predecessor[e] == -1 && e!=s){
        cout<<-1;
        return;
    }
    vector<int> path;
    for(int cur = e; cur != -1; cur = predecessor[cur]){
        path.push_back(cur);
    }

    reverse(path.begin(), path.end());
    for(size_t i = 0; i < path.size(); ++i){
        cout << path[i] << " ";
    }
    cout << endl;
}

void bfs(vector<vector<int>> &graph, vector<bool> &marked, int start, int end)
{   
    vector<int> predecessor(graph.size(), -1);

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
                predecessor[w] = v;
            }
        }

    }
    path(predecessor, end, start);
}

void transverse(vector<vector<int>> &graph, vector<bool> &marked, int start, int end)
{
    int n = graph.size();
    
    int count = 0;

    for (int j = 0; j < n; j++){
        if (marked[j] == true)
        {
           marked[j] = false;
            
        }    
    }     
        bfs(graph, marked, start, end);

}

int main(){
    int c;
    cin>>c;
    for(int i = 0; i< c; i++){
        cout<<"caso "<<i<<endl;
        int v;
        int a;

        cin>>v;
        cin>>a;

        vector<vector<int>> graph(v);
        vector<bool> marked(v, false);
        
        for(int j = 0; j<a; j++){
            int v1;
            int v2;
            cin>>v1;
            cin>>v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        // Sort adjacency lists to ensure lexicographically smallest path
        for (int j = 0; j < v; ++j) {
            sort(graph[j].begin(), graph[j].end());
        }

        int p;
        cin>>p;
        for(int k = 0; k< p; k++){
            int s;
            int t;
            cin >> s;
            cin >> t;
            transverse(graph, marked, s, t);
        }

    }
}