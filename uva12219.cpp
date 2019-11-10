#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 50000+5

//structure
struct Node
{
    int l, r;
    string s;
    Node(int l = 0, int r = 0, string s = ""):l(l), r(r), s(s){}

    bool operator< (const Node& rs) const
    {
        if(s != rs.s)
            return s < rs.s;
        if(l != rs.l)
            return l < rs.l;
        return r < rs.r;
    }
};
//declaration
int T, k, cnt;
bool visit[maxn];
string str;
Node tree[maxn];
map<Node, int> mp;
//functions
int dfs(void)
{

    int id = k++;
    //init
    tree[id].l = 0;
    tree[id].r = 0;
    tree[id].s = "";


    while(isalpha(str[cnt]))
    {
        // tree[id].hash = tree[id].hash*26+str[cnt]-'a'+1;

        tree[id].s.PB(str[cnt]);
        cnt++;
    }

    if(str[cnt] == '(')
    {
        cnt++;
        tree[id].l = dfs();
        cnt++;
        tree[id].r = dfs();
        cnt++;
    }

    // cout << id << ' ' << tree[id].l << ' ' << tree[id].r << ' ' << tree[id].s << endl;

    if(mp.count(tree[id]))
    {
        // cout << "in " << id << ' ' << tree[id].s << endl;
        k--;
        return mp[tree[id]];
    }

    return mp[tree[id]]=id;
}

void print(int id)
{
    if(visit[id])
    {
        printf("%d", id+1);
        return;
    }
        
    visit[id] = true;
    cout << tree[id].s;

    if(tree[id].l)
    {
        printf("(");
        print(tree[id].l);
        printf(",");
        print(tree[id].r);
        printf(")");
    }
}


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--)
    {
        cin >> str;
        mp.clear();
        cnt = 0;
        k = 0;
        dfs();   

        // for(int i = 0; i < k; i++)
        // {
        //     cout << tree[i].l << ' ' << tree[i].r << ' ' << tree[i].s << endl;
        // }

        MSET(visit, false);

        print(0);
        puts("");
    }

	return 0;
}