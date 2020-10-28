#include <bits/stdc++.h>
using namespace std;

#define maxn 1005

vector<int> r;
vector<int> c;

int Matching(vector<vector<int>> W) {
    int N = W.size();
    vector<int> fl(N, -1), fr(N, -1), hr(N), hl(N);
    for (int i = 0; i < N; ++i) {
        hl[i] = *max_element(W[i].begin(), W[i].end());
    }
    constexpr int kInf = 1'000'000'000;
    auto Bfs = [&](int s) {
        vector<int> slk(N, kInf), pre(N);
        vector<bool> vl(N, false), vr(N, false);
        queue<int> que;
        que.push(s);
        vr[s] = true;
        auto Check = [&](int x) -> bool {
            if (vl[x] = true, fl[x] != -1) {
                que.push(fl[x]);
                return vr[fl[x]] = true;
            }
            while (x != -1) swap(x, fr[fl[x] = pre[x]]);
            return false;
        };
        while (true) {
            while (!que.empty()) {
                int y = que.front();
                que.pop();
                for (int x = 0, d = 0; x < N; ++x) {
                    if (!vl[x] && slk[x] >= (d = hl[x] + hr[y] - W[x][y])) {
                        if (pre[x] = y, d) slk[x] = d;
                        else if (!Check(x)) return;
                    }
                }
            }
            int d = kInf;
            for (int x = 0; x < N; ++x) {
                if (!vl[x] && d > slk[x]) d = slk[x];
            }
            for (int x = 0; x < N; ++x) {
                if (vl[x]) hl[x] += d;
                else slk[x] -= d;
                if (vr[x]) hr[x] -= d;
            }
            for (int x = 0; x < N; ++x) {
                if (!vl[x] && !slk[x] && !Check(x)) return;
            }
        }
    };

    for (int i = 0; i < N; ++i) Bfs(i);
    int res = 0;
    for (int i = 0; i < N; ++i){
        if(!hl[i])
            r.emplace_back(i);
        if(hr[i])
            c.emplace_back(i);
        
        res += W[i][fl[i]];
    }
    return res;
}

int main() {
    int n, m, q;
    int x, y;
    while (cin >> n >> m >> q) {
        if (n == 0 && m == 0 && q == 0) 
            break;
        vector<vector<int>> W(n, vector<int>(m));
        r.clear();
        c.clear();
        ji  


        for (int i = 0; i < q; ++i) {
            cin >> x >> y;   
            W[x-1][y-1] = 1;
        }
        cout << Matching(W); 
        
        for(auto i : r)
            cout << " r" << i;
        for(auto i : c)
            cout << " c" << i;
        cout << '\n';
    }
}

// int main(void){
//     int n, m, q;
//     int x, y;

//     while(cin >> n >> m >> q){
//         if(n == 0 && m == 0 && q == 0)
//             break;

//         KM<int> km;
//         km.init(n, m);

//         for(int i = 0; i < q; i++){
//             cin >> x >> y;
//             km.w[x][y] = 1;
//         }

//         km.hungarian();

//         for(int i = 1; i <= m; i++){
//             cout << km.Left[i] << '\n';
//         }
//     }
// }