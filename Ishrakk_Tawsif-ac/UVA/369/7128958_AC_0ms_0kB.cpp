#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
        while (scanf("%d %d", &n, &m) == 2 && n && m){
            double ans=1;
            for(int i=(n-m)+1, j=2; i<=n; i++,j++){
                if(j<=m) {ans *= (double) i; ans /= (double)j;}
                else ans *= (double) i;
            }printf("%d things taken %d at a time is %.0lf exactly.\n",n,m,ans);
        }
return 0;
}