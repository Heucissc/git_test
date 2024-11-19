#include <iostream>
#include <vector>  
#include <queue>
using namespace std;
int bfs(vector<vector<int>>& graph,vector<vector<bool>>& visited
, int x, int y)
{
    int count = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty())
    {
        auto [curX, curY] = Q.front();
        count++;
        Q.pop();
        visited[curX][curY] = true;
        for(int i = 0; i < 4; ++i)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX < 0 || nextX >= graph.size()
            || nextY < 0 || nextY >= graph[0].size())
            {
                continue;
            }
            if(!visited[nextX][nextY] && graph[nextX][nextY]==1)
            {
                
                Q.push({nextX,nextY});
                visited[nextX][nextY] = true;
            }
        }

    }
    return count;
        
}
int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    int maxCount = 0;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == false && graph[i][j] == 1) 
            {
                maxCount = max(maxCount, bfs(graph,visited,i,j)); 
            }
        }
    }
    cout<< "result: "<<maxCount<<endl;

    return 0;
}