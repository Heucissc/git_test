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
    int N;
    cin>>N;
    int tmp1, tmp2;
    for(int i = 0; i < N;++i)
    {
        cin>>tmp1>>tmp2;
        if(haveSame_fn(tmp1,tmp2))
        {
            cout<<tmp1<<" "<<tmp2<<endl;
        }
        union_fn(tmp1,tmp2);
    }

 
   
    return 0;
}