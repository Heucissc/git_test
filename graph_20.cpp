#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int S,T;
    vector<int> inDegree(N+1,0);
    unordered_map<int, vector<int>> unmap;
    while(M--)
    {
        cin>>S>>T;
        inDegree[T]++;
        unmap[S].push_back(T);
    }
    queue<int> Q;
    for(int i = 0;i < N;++i)
    {
        if(inDegree[i] == 0)
        {
            Q.push(i);
        }
    }
    vector<int> result;
    while(!Q.empty())
    {
        auto cur = Q.front();
        result.push_back(cur);
        Q.pop();
        vector<int> cur_next = unmap[cur];
        if(!cur_next.empty())
        {
            for(auto it: cur_next)
            {
                inDegree[it]-- ;
                if(inDegree[it] == 0)
                    Q.push(it);
            }
        }
    }
    if (result.size() == N) {
        for (int i = 0; i < N - 1; i++) cout << result[i] << " ";
        cout << result[N - 1];
    } else cout << -1 << endl;



    return 0;
}