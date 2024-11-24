#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
//Dijkstra朴素版
int main()
{
    int N,M;
    cin>>N>>M;
    int S,E,V;
    vector<vector<int>> graph(N+1,vector<int>(N+1,INT_MAX));
    vector<int> minDist(N+1, INT_MAX);//数组第i个位置代表走到i所需的最短路程
    vector<bool> visited(N+1,false);
    while(M--)
    {
        cin>>S>>E>>V;
        graph[S][E] = V;
    }
    for(int times = 1; times < N;++times)
    {
        int cur = -1;
        int minVal = INT_MAX;
        minDist[1] = 0;
        for(int j = 1; j < N+1; ++j)
        {
            if(!visited[j] && minVal > minDist[j])
            {
                minVal =minDist[j];
                cur = j;
            }
        }
        visited[cur] = true;
        for(int j = 1; j < N+1;++j)
        {
            if(!visited[j] && graph[cur][j] != INT_MAX 
                                        && minDist[cur] + graph[cur][j]<minDist[j])
                                        {
                                            minDist[j] = minDist[cur] + graph[cur][j];
                                        }
        }

    }
    cout<<minDist[V]<<endl;


    return 0;
}