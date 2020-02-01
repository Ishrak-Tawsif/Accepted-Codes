#include<bits/stdc++.h>
using namespace std;


int main(){

    int testcase,n;

        cin>> testcase;

            while(testcase--){
                cin>> n;

                    double ans=0;

                        for(int i=1; i<=n; i++) ans+=log10(i);
                        ans = floor(ans)+1;
                        printf("%.0lf\n",ans);
            }
return 0;
}