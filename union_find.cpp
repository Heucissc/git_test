#include <iostream>

using namespace std;
#define MAXSIZE 20001
int father[MAXSIZE] = {};
void init_fn()
{
    for(int i = 0; i < MAXSIZE;++i)
    {
        father[i] = i;
    }
}
int find_fn(int x)
{
    if(father[x] == x) 
        return x;
    else{
        father[x] = find_fn(father[x]);
        return father[x];
    }
}
void union_fn(int x,int y)
{
    int father_x = find_fn(x);
    int father_y = find_fn(y);
    if(father_x != father_y)
    {
        father[father_x] = father_y;
    }
}

int main()
{
    int N,M;
    cin>>N>>M;

    return 0;
}