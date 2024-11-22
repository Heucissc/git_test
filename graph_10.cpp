#include <iostream>
#include <vector>  
#include <queue>
using namespace std;
/*此方法为时空复杂度爆炸的方法，每个点都要遍历是否能到第一、第二边界O(M*N)，并且要再遍历一遍visited
数组，O（M*N）*/
/*int ddx[4] = {1,0,-1,0};
int ddy[4] = {0,-1,0,1};
void dfs(vector<vector<int>>& graph,vector<vector<bool>>& visited, int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nextX = x+ddx[i];
        int nextY = y+ddy[i];
        if(nextX < 0||nextY<0|| nextX>=graph.size()||nextY>=graph[0].size())
        {
            continue;
        }
        if(graph[nextX][nextY] <= graph[x][y] && !visited[nextX][nextY])
        {
            dfs(graph,visited,nextX,nextY);
        }
    }

}
bool first(vector<vector<bool>>& visited,int N,int M)
{
    for(int i = 0; i < M;++i)
    {
        if(visited[0][i]) return true;
    }
    for(int j = 0; j <N;++j)
    {
        if(visited[j][0]) return true;
    }
    return false;
}
bool second(vector<vector<bool>>& visited,int N,int M)
{
    for(int i = 0; i < M;++i)
    {
        if(visited[N-1][i]) return true;
    }
    for(int j = 0; j <N;++j)
    {
        if(visited[j][M-1]) return true;
    }
    return false;
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
    for(int i = 0;i<N;++i)
    {
        for(int j=0;j <M;++j)
        {
            fill(visited.begin(), visited.end(), vector<bool>(M, false));
            dfs(graph,visited,i,j);
            if(first(visited,N,M) == true && second(visited,N,M) == true)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
*/
/*考虑从边界出发，逆着推出两个边界能到哪个位置，若某一位置可同时被到达，则输出*/
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void dfs(vector<vector<int>>& graph, vector<vector<bool>>& Board,int x, int y)
{
    Board[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nextX = x +dx[i];
        int nextY = y + dy[i];
        if(nextX<0||nextY<0||nextX>=graph.size()||nextY>=graph[0].size())
        {
            continue;
        }
        if(!Board[nextX][nextY] && graph[nextX][nextY] >= graph[x][y])
        {
            dfs(graph,Board,nextX,nextY);
        }
    }
    
}
int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<bool>> firstBoard(N, vector<bool>(M, false));
    vector<vector<bool>> secondBoard(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    //第一.二边界遍历
    for(int i = 0; i <M;++i)
    {
        dfs(graph,firstBoard,0,i);
        dfs(graph,secondBoard,N-1,i);
    }
    for(int j = 0; j <N;++j)
    {
        dfs(graph,firstBoard,j,0);
        dfs(graph,secondBoard,j,M-1);
    }
    for(int i = 0;i<N;++i)
    {
        for(int j = 0; j < M;++j)
        {
            if(firstBoard[i][j] && secondBoard[i][j])
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}