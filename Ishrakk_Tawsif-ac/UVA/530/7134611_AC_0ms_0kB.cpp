#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
        while (scanf("%d %d", &n, &m) == 2){

            if(n == 0 && m == 0) break;
            double ans=1;
            if(n == m) printf("1\n");
            else{
                int max_ = max(n-m,m);
                int min_ = min(n-m,m);
                for(int i= max_+1, j=2; i<=n; i++,j++){
                if(j<=min_) {ans *= (double) i; ans /= (double)j;}
                else ans *= (double) i;
                }
                printf("%.0lf\n", ans);
            }
        }
return 0;
}