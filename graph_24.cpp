#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
//Bellman_Ford算法，动态规划思想，循环N-1次（N为有几个节点）
//每次找下一个点都要结合之前的情况
struct Edges
{
    int start;
    int end;
    int val;
};
int main()
{
    int N,M;
    cin>>N>>M;
    int S,E,V;
    vector<vector<int>> graph(N+1,vector<int>(N+1,INT_MAX));
    vector<int> minDist(N+1, INT_MAX);//数组第i个位置代表走到i所需的最短路程
    vector<bool> visited(N+1,false);
    vector<Edges> edges;
    while(M--)
    {
        cin>>S>>E>>V;
        edges.push_back({S,E,V});
        
    }
    minDist[1] = 0;
    for(int times = 1; times < N;++times)
    {
        for(auto &side: edges)
        {
            int start = side.start;
            int end = side.end;
            int price = side.val;
            if(minDist[start] != INT_MAX && minDist[end] > minDist[start] + price)
            {
                minDist[end] = minDist[start] + price;
            }
        }
    }
    if(minDist[N] == INT_MAX) cout<<""<<endl;
        else cout<<minDist[N]<<endl;


    return 0;
}