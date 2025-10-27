using namespace std;
#include <iostream>
#include <vector>

int first(vector<vector<int>> graph, int v){
    if(graph[v].size() > 0){
        return graph[v][0];
    }
    return graph.size();
}

int next(vector<vector<int>> graph, int v){
    if(graph[v].size() > 1){//Implement unmarked vector logic
        return graph[v][1];
    }
    return graph.size();
}

//Insere o vértice ao mesmo tempo em cada subvetor
void setEdge(vector<vector<int>> graph, int i, int j){
    graph[i].push_back(j);
    graph[j].push_back(i);
}


void delEdge(vector<vector<int>> graph, int i, int j){
    //Encontra i em j, deleta i
    //Encontra j em i, deleta j
    //Deleta o vetor na lista de marcações
    
}
void setMark(int v, bool visited, vector<bool> &visits){
    visits[v] = visited;
}

bool getMark(int v, vector<bool> &visits){
    return visits[v];
}

void DFS(vector<vector<int>> graph, vector<bool> &visits, int v, int n){
    //preVisit(g,v)
    setMark(v, true, visits );
    int w = first(graph, v);
    while(w < n){
        
    }
}

void BFS(){
    
}

int graphTransverse(vector<vector<int>> graph, int n, vector<bool> &visits){
    //If necessary, reset to false array of visits
        int subgraphs = 0;
        for(int v = 0; v < n-1; v++){
            setMark(v, false, visits);
        }
        for(int v = 0; v < n-1; v++){
            if(getMark(v, visits)){
                subgraphs++;
                DFS(graph, visits, v, n);
            }
        }
        return subgraphs;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int c;
    cin>>c;

    for(int i = 0; i<c; i++){
        int v;
        int e;
        cin>>v;
        cin>>e;

        vector<vector<int>> graph(v);
        vector<bool> marked(v, false);

        for(int k = 0; k < e; k++){
            int v1;
            int v2;
            cin>>v1;
            cin>>v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
            if(v1 || v2){
                int i = 1;
            }
        }

        
    }


}