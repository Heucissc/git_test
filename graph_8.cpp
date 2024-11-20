#include <iostream>
#include <vector>  
#include <queue>
using namespace std;
void bfs(vector<vector<int>>& graph,vector<vector<bool>>& visited
, int x, int y)
{
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while(!Q.empty())
    {
    auto [curX,curY] = Q.front();
    Q.pop();
    visited[curX][curY] = true;
    graph[curX][curY] = 2;
    for(int i = 0; i < 4; ++i)
    {
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];
        //界外不判断跳过
        if(nextX < 0||nextY<0||nextX>=graph.size()||nextY>=graph[0].size())
        {
            continue;
        }
        if((graph[nextX][nextY] == 1 ||graph[nextX][nextY]==2) && !visited[nextX][nextY])
        {
            visited[nextX][nextY] = true;
            graph[nextX][nextY] = 2;
            Q.push({nextX, nextY});
        }
    }
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
    
    for(int i = 0; i < N;++i)//查找第一列和最后一列的陆地并将它们全部赋值为2，2仅为区分标记
    {
        if((graph[i][0] == 1 || graph[i][0] == 2 ) && !visited[i][0]) bfs(graph, visited, i,0);
        if((graph[i][M-1] == 1  || graph[i][M-1] == 2) && !visited[i][M-1]) bfs(graph,visited, i , M-1);
    }
    for(int j = 0; j < M;++j)
    {
        if((graph[0][j] == 1 || graph[0][j] == 2)&& !visited[0][j]) bfs(graph,visited, 0,j);
        if((graph[N-1][j] == 1 || graph[N-1][j] == 2)&& !visited[N-1][j]) bfs(graph,visited, N-1,j);
    }
    int result = 0;
    //cout<<"------------------"<<endl;
    for(auto a: graph)
    {
        for(auto b: a)
        {
            if(b==1) result++; 
            //cout<<b<<" ";
        }
        cout<<endl;
    }
    cout<<result<<endl;
    return 0;
}