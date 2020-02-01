#include<bits/stdc++.h>
using namespace std;


int main(){

    long long int n,sum=0,cnt=0;
    int testcase;

      scanf("%d", &testcase);
      for(int t=1; t<=testcase; t++){

        cin>> n;
        sum=0;

        for(long long int i=1; i<=n; ){
                long long int x = n/i;
                long long int y = n/x-i;
                //sum += x*y;
                if(y!=0){sum += x*y; i += y;}
                else{sum+=x; i++;}
                //cout << y << endl;
        }

        printf("Case %d: %lld\n", t, sum);
      }

    return 0;
}
