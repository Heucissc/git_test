#include <iostream>

using namespace std;
int father[105];
void init_fn()
{
    for(int i = 1; i < 105;++i)
    {
        father[i] = i;
    }
}
int find_fn(int x)
{
    return father[x] == x ? x : father[x] = find_fn(father[x]);
}
void union_fn(int x,int y)
{
    int fa_x = find_fn(x);
    int fa_y = find_fn(y);
    if(fa_x == fa_y) return;
    father[fa_x] = fa_y;
}
bool haveSame_fn(int x,int y)
{
    int fa_x = find_fn(x);
    int fa_y = find_fn(y);
    if(fa_x == fa_y) return true;
        return false;
}
int main()
{
    init_fn();
    int N,M;
    cin>>N>>M;
    int tmp1, tmp2;
    while(M--)
    {
        cin>>tmp1>>tmp2;
        union_fn(tmp1, tmp2);
    }
    int src,dst;
    cin>>src>>dst;
    cout<<haveSame_fn(src,dst)<<endl;
   
    return 0;
}