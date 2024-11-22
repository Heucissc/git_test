#include <iostream>
#include <vector>  
#include <queue>
#include <set>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int Scount = 0;
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& visited,int x,int y,int mark)
{
    Scount+=1;
    visited[x][y] = true;
    graph[x][y] = mark;
    for(int i = 0; i < 4; ++i)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < 0||nextY<0||nextX>=graph.size()||nextY>=graph[0].size())
        {
            continue;
        }
        if(!visited[nextX][nextY] && graph[nextX][nextY] == 1)
            {dfs(graph, visited,nextX,nextY, mark);}

    }
    
    
}
int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    unordered_map<int ,int> islandS;
    int mark = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(graph[i][j] == 1 && !visited[i][j])
            {
                Scount = 0;
                dfs(graph, visited, i, j, mark);
                islandS[mark] = Scount;
                mark++;
            }
        }
    }
    int result = 0;
    set<int> visitedGrid;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(graph[i][j] == 0)
            {
                int NewCount = 1;
                visitedGrid.clear();
                for(int k = 0; k < 4; ++k)
                {
                    int nexti = i+dx[k];
                    int nextj = j+dy[k];
                    if(nexti<0||nextj<0||nexti>=N||nextj>=M) continue;
                    if(visitedGrid.count(graph[nexti][nextj])) continue;
                    NewCount += islandS[graph[nexti][nextj]];
                    visitedGrid.insert(graph[nexti][nextj]);
                }
                result = max(result,NewCount);
            }
            
        }
    }
   // cout<<"最大面积变为:"<<endl;
    cout<<result<<endl;
    return 0;
}