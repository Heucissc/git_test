#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Prin算法，主要维护顶点
// int main()
// {
//     int Vertex, Edges, start, end, val;
//     cin>>Vertex>>Edges;
//     vector<vector<int>> graph(Vertex+1, vector<int>(Vertex+1, 10001));
//     //最小距离
//     vector<int> minDist(Vertex+1, 10001);
//     //判断顶点是否在最小生成树
//     vector<bool> isInPrim(Vertex+1,false);
//     while(Edges--)
//     {
//         cin>>start>>end>>val;
//         graph[start][end] = val;
//         graph[end][start] = val;
//     }
//     minDist[1] = 0;
//     for(int times = 1; times < Vertex; ++times)
//     {
//         int minVal = INT_MAX;
//         int cur = -1;
//         //找出本轮最小值
//         for(int j = 1; j < Vertex+1; ++j)
//         {
//             if(!isInPrim[j] && minDist[j] < minVal)
//             {
//                 minVal = minDist[j];
//                 cur = j;
//             }
//         }
//         isInPrim[cur] = true;
//         for(int j = 1; j < Vertex+1; ++j)
//         {
//             if(!isInPrim[j] && graph[cur][j] < minDist[j])
//             {
//                 minDist[j] = graph[cur][j];
//             }
//         }

//     }
//     int sum = 0;
//     for(int j = 2; j <= Vertex; ++j)
//     {
//         sum += minDist[j];
//     }
//     cout<<sum<<endl;



//     return 0;
// }
//Kruskal方法，主要维护边,需要用到并查集
int fat[10005];
void init_fn()
{
    for(int i = 1; i < 10004;++i)
    {
        fat[i] = i;
    }
}
int find_fn(int x)
{
    return x == fat[x] ? x:fat[x] = find_fn(fat[x]);
}
bool haveCommenParent(int x,int y)
{
    int fa_x = find_fn(x);
    int fa_y = find_fn(y);
    return fa_x == fa_y;
}
void union_fn(int x, int y)
{
    int fa_x = find_fn(x);
    int fa_y = find_fn(y);   
    if(fa_x == fa_y) return;
    fat[fa_x] = fa_y;
}
struct Edges
{
    int start;
    int end;
    int val;
};
bool compare(Edges& a, Edges& b)
{
    return a.val < b.val;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<Edges> edges(E+1);
    int tmp1, tmp2, tmp3;
    while(E--)
    {
        cin>>tmp1>>tmp2>>tmp3;
        edges.push_back({tmp1,tmp2,tmp3});
    }
    sort(edges.begin(),edges.end(), compare);
    init_fn();
    int result;
    for(auto edge: edges)
    {
        int fa_start = find_fn(edge.start);
        int fa_end = find_fn(edge.end);
        if(fa_end!= fa_start)
        {
            result += edge.val;
            union_fn(fa_start,fa_end);
        }
    }
    cout<<result<<endl;
    return 0;
}