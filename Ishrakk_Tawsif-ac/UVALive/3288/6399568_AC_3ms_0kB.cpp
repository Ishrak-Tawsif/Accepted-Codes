#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b){

    if(a == 0) return b;
    else return gcd(b%a,a);
}

/*long long int LCM(long long int c, long long int d){

    return abs(c*d)/gcd(c,d);
}*/

int main(){

    int s,n,arr[11];
    long long int temp,ans,sum,lcm;

        while(scanf("%d", &s) == 1){
            for(int t=1; t<=s; t++){
            scanf("%d", &n);

                lcm=1;
                sum=0;
                for(int i=0; i<n; i++){
                    scanf("%d", &arr[i]);
                    lcm *= arr[i];
                }

                    //cout<<lcm<<endl;
                    for(int i=0; i<n; i++) {sum += lcm/arr[i];}

                    lcm=n*lcm;
                    temp = (lcm/(gcd(lcm,sum)));
                    ans = (sum/(gcd(lcm,sum)));

                    printf("Case %d: %lld/%lld\n",t,temp,ans);
            }
        }
}
