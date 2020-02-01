#include<bits/stdc++.h>
using namespace std;

#define mx 1000005
#define ll long long int
ll m=1000003;

ll arr[1000005];

void pre_gen(){

    arr[0]=arr[1]=1;
    for(int i=2; i<=1000000; i++){
        arr[i] = (ll) ((arr[i-1]%m)*i)%m;
    }
}

ll bigmod(ll base, ll pow, ll m){

    if(pow == 0) return 1;
    else if(pow%2) return (((base%m)*((bigmod(base,pow-1,m))%m))%m);
    else{
        ll ret = (bigmod(base,pow/2,m))%m;
        return (((ret%m)*(ret%m))%m);
    }
}

int main(){
    pre_gen();
    int n,k,testcase;
    ll ans;
//cout << arr[1000000] << endl;
        scanf("%d", &testcase);

            for(int tt=1; tt<=testcase; tt++){
                scanf("%d %d", &n, &k);
                    ans=((arr[n]%m)*((bigmod(arr[k],m-2,m))%m)*(bigmod(arr[(n-k)],m-2,m)%m))%m;
                        printf("Case %d: %lld\n", tt,ans);
            }
return 0;
}