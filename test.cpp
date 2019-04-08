#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
vector<deque<int> > v;//儲存7堆的牌 
deque<int> deck;//發牌 
struct sta{//儲存v與deck的狀態，判斷是否重複，表示draw 
    int n[62];
    sta(){
        memset(n, 0, sizeof(n));
    }
    bool operator<(const sta& rhs) const{//set需要operator<，決定set擺放的順序 
        return (memcmp(n, rhs.n, sizeof(sta)) < 0);//數字小的在上面 
    }
};
set<struct sta> mset;//set以binary search tree實作，儲存struct sta 
bool check(int i){//大於等於三張時 
    int s = v[i].size();
    if (!((v[i][0] + v[i][1] + v[i][s - 1]) % 10)){//first兩張，last一張 
        deck.push_back(v[i][0]);
        deck.push_back(v[i][1]);
        deck.push_back(v[i][s - 1]);
        v[i].pop_front();
        v[i].pop_front();
        v[i].pop_back();
        return true;//等於三張時，條件成立只會執行到此 
    }
    if (!((v[i][0] + v[i][s - 1] + v[i][s - 2]) % 10)){//first一張，last兩張
        deck.push_back(v[i][0]);
        deck.push_back(v[i][s - 2]);
        deck.push_back(v[i][s - 1]);
        v[i].pop_front();
        v[i].pop_back();
        v[i].pop_back();
        return true;
    }
    if (!((v[i][s - 1] + v[i][s - 2] + v[i][s - 3]) % 10)){//last三張
        deck.push_back(v[i][s - 3]);
        deck.push_back(v[i][s - 2]);
        deck.push_back(v[i][s - 1]);
        v[i].pop_back();
        v[i].pop_back();
        v[i].pop_back();
        return true;
    }
    return false;
}
void placeCard(int i, int j){//將j放到v[i] 
    bool notF = true;
    v[i].push_back(j);
    while ((v[i].size()>=3) && notF) {//牌大於等於3張，且要能夠不斷判斷 
        notF = check(i);
    }
}
sta recState(){//將v與deck的數字記錄52個數字，加上間隔數字0，有7個 
    int k = 0;
    sta s;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < v[i].size(); j++){
            s.n[k++] = v[i][j];
        }
        s.n[k++] = 0;
    }
    for (int i = 0; i < deck.size(); i++){
        s.n[k++] = deck[i];
    }
    return s;
}
int main(){

    #ifndef file
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif

    int a;
    int cnt;
    while ((cin >> a) && a){
        mset.clear();
        deck.clear();
        v.clear();
        cnt = 0;
        deck.push_back(a);
        for (int i = 0; i<51; i++){
            cin >> a;
            deck.push_back(a);
        }
        for (int i = 0; i<7; i++){//建立v[0]到v[6]，各發一張牌 
            deque<int> tmp;
            tmp.push_back(deck.front());
            deck.pop_front();
            v.push_back(tmp);
            cnt++;
        }
        bool isdraw = false;
        while (deck.size()>0 && deck.size()<52 && !isdraw){
            cout << deck.size() << ' ';
            cout << cnt << endl;
            for (int i = 0; i<7; i++){
                if (v[i].size() == 0) continue;//v[i]已經沒牌了，不加牌 
                placeCard(i, deck.front());//將deck.front()加到v[i] 
                cnt++;
                deck.pop_front();
                sta s = recState();//紀錄目前狀態 
                if (mset.count(s)>0) {//檢查是否有重複 
                    isdraw = true;//Draw
                    break;
                }
                else mset.insert(s);
                if (deck.size() == 0 || deck.size()==52) break;//Win或Loss
            }
        }
        if (deck.size() == 52) cout << "Win : " << cnt << endl;
        else if (deck.size() == 0) cout << "Loss: " << cnt << endl;
        else cout << "Draw: " << cnt << endl;
    }
}