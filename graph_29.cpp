#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
int a1,a2,b1,b2;
int moves[1001][1001];
int dir[8][2]={-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2};
struct  Knight
{
    int x,y;
    int g,h,f;
    bool operator < (Knight &k)
    {
        return f > k.f;
    }
};
int distance(int x,int y)
{
    return (b1 - x)*(b1 - x) + (b2-y)*(b2-y);
}
priority_queue<Knight> Pri_Q;
void Astar(Knight& k)
{
    Pri_Q.push(k);
    Knight cur,next;
    while(!Pri_Q.empty())
    {
        cur = Pri_Q.top();
        Pri_Q.pop();
        if(cur.x == b1 && cur.y == b2)
            break;
        for(int i = 0; i < 8; ++i)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if(next.x<1||next.y<1||next.x>1000||next.y>1000)
            {
                continue;
            }
            if(!moves[next.x][next.y])
            {
                moves[next.x][next.y] = moves[cur.x][cur.y]+1;
                next.g = cur.g+5;
                next.h = distance(next.x,next.y);
                next.f = next.g+next.h;
                Pri_Q.push(next);
            }
        }
    }

}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
    cin>>a1>>a2>>b1>>b2;
    Knight start;
    start.x = a1;
    start.y = a2;
    start.h = distance(a1,a2);
    start.g = 0;
    start.f = start.h + start.g;
    Astar(start);
    cout<<moves[b1][b2]<<endl;
    }
    return 0;
}