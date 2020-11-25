#include <bits/stdc++.h>

using namespace std;
set<int> btn;

int main(){
    ios_base::sync_with_stdio(0);
    int N, M, tmp, len, now = 100, mx = 0, mn = 0;
    bool gotoMax = false, gotoMin = false;
    char nChar[10];
    for(int i = 0; i < 10; i++) btn.insert(i);
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> tmp;
        btn.erase(tmp);
    }


    for(int i = 0; i < len; i++){
        int n = nChar[i] - '0';
        mx *= 10;
        if(gotoMax){
            mx += *btn.end();
            continue;
        }
        auto it = btn.find(n);
        if(it == btn.end()) {
            gotoMax = true;
            if(btn.lower_bound(n) == btn.begin())
                mx += 0;
            else
                mx += *btn.lower_bound(n);
        }
        else{
            mx += n;
        }
    }
    
}