#include<bits/stdc++.h>
using namespace std;

long long int arr[1000005];

void pre_gen(){
    arr[0] = arr[1] = 1;
    for(int i=2; i<=1000000; i++){
        arr[i] = (long long int) ((arr[i-1] * i)%1000003);
        //arr[i] %= 1000003;
    }
}

long long int  bigmod ( long long num,long long int pow,long long int m )
{
    if ( pow == 0 )return 1; // If power is 0, then a ^ 0 = 1 for any value of a, And 1 Mod m=1 for any value of m, So return 1

    if ( pow % 2 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left and right child respectively.
    {
        return ( ( num % m ) * ( bigmod ( num, pow - 1, m ) ) ) % m;
    }
    else //If power is even then split it equally and return the result...
    {
        long long ret = bigmod ( num, pow / 2, m );
        return ( (ret%m) * (ret%m) ) % m;
    }
}

int main(){
    pre_gen();

        long long int testcase,n,k;

            scanf("%lld", &testcase);

                for(int i=1; i<=testcase; i++){
                    scanf("%lld %lld", &n, &k);
                        if(n<k){printf("Case %d: 0\n",i);continue;}
                        else if(n == k && k==0){printf("Case %d: 1\n",i);continue;}
                        long long int temp = (arr[k]%1000003)*(arr[n-k]%1000003)%1000003;
                        printf("Case %d: %lld\n", i,(long long int) arr[n]*bigmod(temp,1000003-2,1000003)%1000003);
                }

return 0;
}