#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100009
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

vector <int> prime;
bitset <mx> isprime;
int arr[mx+20],cnt=0,track[mx+20],yo,ans[mx];

void sieve()
{
    isprime[2]=1;
    prime.pb(2);
    arr[2]=++cnt;

        for(int i=3; i*i<mx; i+=2)
        {
            if(!isprime[i]) for(int j=i*i; j<mx; j+=i)  isprime[j]=1;
        }
        for(int i=3; i<mx; i+=2) {if(!isprime[i]) {prime.pb(i); arr[i]=++cnt;}}
}

int main()
{
    sieve();
    //cout<<prime.size() << endl;

        int n,koyta=0,col=1;
        yo=0;
            sf(n);

                ans[2]=1;
                for(int i=3; i<=n+1; i++)
                {
                    if(!isprime[i] && i%2!=0) ans[i]=1;
                    else ans[i]=2;
                }

                if(n!=1 && n!=2)cout<<2<<endl; else cout<<1<<endl;
                for(int i=2; i<=n; i++) cout << ans[i] << " ";
                cout<<ans[n+1]<<endl;

    return 0;
}