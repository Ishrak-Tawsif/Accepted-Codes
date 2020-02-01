#include<bits/stdc++.h>
using namespace std;
int main(){

    int testcase,num;
    double ans;
        while(scanf("%d", &testcase)==1){

            while(testcase --){
                scanf("%d", &num);

                    ans=0;
                    for(int i=1; i<=num; i++){
                        ans += log10(i);
                    }
                    ans = floor(ans)+1;
                    printf("%.0lf\n", ans);
            }
        }
return 0;
}
