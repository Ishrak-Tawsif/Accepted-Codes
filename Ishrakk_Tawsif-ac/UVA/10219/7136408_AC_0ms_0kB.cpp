#include<bits/stdc++.h>
using namespace std;

int main(){

    long long int n,m;
        while (scanf("%lld %lld", &n, &m) == 2){

            //if(n == 0 && m == 0) break;
            double ans=0;
            if(n == m) printf("1\n");
            else{
                int max_ = max(n-m,m);
                int min_ = min(n-m,m);
                for(int i= max_+1, j=2; i<=n; i++,j++){
                if(j<=min_) {ans += log10(i); ans -= log10(j);}
                else ans += log10(i);
                }
                //printf("%.0lf\n",(ans));
                printf("%.0lf\n", floor(ans)+1.0);

            }
        }
return 0;
}