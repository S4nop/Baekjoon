#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    string num;
    while(true){
        cin >> num;
        if(num == "0") break;
        int i, len = num.length();
        for(i = 0; i < len / 2 + 1; i++){
            if(num.c_str()[i] != num.c_str()[len - i - 1])
                break;
        }
        cout << (i < len / 2 ? "no\n" : "yes\n");
    }

}