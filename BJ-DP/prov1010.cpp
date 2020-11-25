#include <cstdio>

int main(){
    int t, n, m, i, tmp; long long ans = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        tmp = m - n;
        if(n > tmp){
            for(i = n; i < m; i++){
                ans *= i;
                while(1){
                    if(!(ans % tmp)) ans /= tmp--;
                    else break;
                }
            }
        }
        else{
            for(i = tmp; i < m; i++){
                ans *= i;
                while(1){
                    if(!(ans % n)) ans /= n--;
                    else break;
                }
            }
        }
        printf("%lld", ans);
    }
}