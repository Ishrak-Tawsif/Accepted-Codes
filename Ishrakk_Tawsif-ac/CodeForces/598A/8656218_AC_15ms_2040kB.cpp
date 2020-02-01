#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 5005
#define ll long long int
#define mp make_pair
#define mod 100000007


bitset <mx> isprime;
vector <int> prime;

ll ipow(ll base, ll pow)
{
    ll res=1;

        while(pow--) res *= base;//cout<<base<<" "<<res<<endl;
    return res;
}

int main()
{
    /*int n;

        while(scanf("%d", &n) == 1)
        {
            int ans=0;
            for(int i=1; i<=n; i++)
            {
                ans += (((n-i)+1)+(i-1)*(n-i)); //cout<<ans<<endl;
            }
            pf("%d\n",ans);
        }*/
        ll nn,tc;
            ll pow_2[33];
            for(int i=0; i<=30; i++) pow_2[i]=ipow(2,i);
            cin>> tc;
            while(tc--)
            {
                cin>>nn;

                ll in=0,ttt=nn,temp=1;
                nn = (nn*(nn+1))/2; //cout<<nn<<endl;
                for(int i=0; temp<=ttt; i++)
                {
                    nn -= (temp*2);
                    temp = pow_2[++in];
                }
                cout<<nn<<endl;
            }
    return 0;
}