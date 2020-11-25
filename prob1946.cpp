#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    vector<pair<int, int>> applicant;
    int rank1, rank2, N, tc;
    cin >> tc;
    while(tc--){
        int mx = -999999, cnt = 0;
        applicant.clear();
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> rank1 >> rank2;
            applicant.emplace_back(make_pair(rank1, rank2));
        }
        sort(applicant.begin(), applicant.end());
        for(int i = 0; i < N; i++){
            if(applicant[i].second < mx) ++cnt;
            else mx = applicant[i].second;
        }
        cout << tc - cnt << "\n";
    }
}