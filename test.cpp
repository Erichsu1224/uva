#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100000+5

struct Item
{
    Item(){
        parent = -1;
        height = 0;
    }
    int parent;
    int height;
    vector<int> child;
};

Item tree[maxn];
int total = 0;

int dfs(int node)
{
    if(tree[node].child.size() != 0)
    {
        for(int i = 0; i < tree[node].child.size(); i++)
            tree[node].height = max(tree[node].height, dfs(tree[node].child[i]));
    }

    total += tree[node].height;
    return tree[node].height+1;
}

int main(void)
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);

    int n;
    scanf("%d", &n);


    for(int i = 1; i <= n; i++)
    {
        int child;
        scanf("%d", &child);
        for(int k = 0; k < child; k++)
        {
            int tmp;
            scanf("%d", &tmp);
            tree[i].child.push_back(tmp);
            tree[tmp].parent = i;
        }
    }

    int root;

    for(int i = 1; tree[i].parent != -1; i = tree[i].parent)
    {
        root = i;
    }
    root = tree[root].parent;
    
    tree[root].height = dfs(root);

    printf("%d\n%d\n", root, total);


    return 0;
}