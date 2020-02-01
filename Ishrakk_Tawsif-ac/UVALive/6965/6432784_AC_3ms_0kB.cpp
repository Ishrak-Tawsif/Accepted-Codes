#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,half,i,ans;

        while(scanf("%d", &n) == 1 && n!=-1){

            int num[n+3];

                for(i=0; i<n; i++) scanf("%d", &num[i]);
                    sort(num, num+i);

                        if(n%2 == 0){
                            half = n/2;
                            ans = (num[half-1]+num[half])/2;
                        }
                        else ans = num[(n/2)];

                        printf("%d\n",ans);
        }
   return 0;
}
