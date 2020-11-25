#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main(){
    ios_base::sync_with_stdio(0);
    int sum = 0, tmp;
    for(int =i = 0; i < 9; i++){
        cin >> tmp;
        arr.push_back(tmp);
        sum += tmp; 
    }
    
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            if(sum - arr[i] - arr[j] == 100){
                cout << arr[i] << " " << arr[j] << endl;
                arr.erase(arr.begin() + i - 1);
                arr.erase(arr.begin() + j - 2);
                sort(arr.begin(), arr.end());
                for(auto v : arr)
                    cout << v << "\n";
                exit(0);
            }
        }
    }
    
}