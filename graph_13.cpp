#include <iostream>
#include <vector>  
#include <queue>
#include <set>
using namespace std;
/*第一种dfs写法，每次进入首先判断是否访问*/
// void dfs(vector<vector<int>>& graph,vector<bool>& reach,int curPoint)
// {
//     if(reach[curPoint]) return;
//     reach[curPoint] = true;
//     vector<int> curLine = graph[curPoint];
//     for(int i = 1; i <= graph[0].size();++i)
//     {
//         if(!reach[i] && graph[curPoint][i] == 1)
//             dfs(graph, reach, i);
//     }

// }
// bool checkFalse(vector<bool>& reach)
// {
//     for(auto it: reach)
//     {
//         if(it == false) return false;
//     }
//     return true;
// }
// int main()
// {
//     int N,K;
//     cin>>N>>K;
//     vector<vector<int>> graph(N+1,vector<int>(N+1,0));
//     vector<bool> reach(N+1,false);
//     reach[0]= true;
//     for(int i = 1; i <=K;++i)
//     {
//         int a,b;
//         cin>>a>>b;
//         graph[a][b] = 1;
//     }
//     dfs(graph, reach, 1);
//     bool result = checkFalse(reach);
//     cout<<result<<endl;
//     return 0;
// }
/*第二种写法，先进入再判断*/
void dfs(vector<vector<int>>& graph, vector<bool>& reach,int curPoint)
{
    //if(reach[curPoint]) return;
    vector<int> curLine = graph[curPoint];
    for(int i = 1; i <= graph[0].size();++i)
    {
        if(!reach[i])
        {
            reach[i] =true;
            dfs(graph,reach, i);
        }
    }
}
int main()
{
    int N,K;
    cin>>N>>K;
    vector<vector<int>> graph(N+1,vector<int>(N+1,0));
    vector<bool> reach(N+1,false);
    reach[0]= true;
    for(int i = 1; i <=K;++i)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
    }
    return 0;
}