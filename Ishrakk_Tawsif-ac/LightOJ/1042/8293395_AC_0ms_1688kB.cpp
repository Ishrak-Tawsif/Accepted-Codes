#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

int pow_[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,
65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,
33554432,67108864,134217728,268435456,536870912,1073741824};

int main()
{
    /*freopen("test.txt","w",stdout);
    for(int i=1; i<=30;i++)
    {
        int base=2,res=1,pow=i;

            while(pow--) res *= base;
            cout<<res<<",";
    }*/

    int n,tc;
        sf(tc);
            loop1(tt,tc)
            {
                sf(n);
                    ll ans=0;
                    vector<int>v;
                        int temp=n;

                            while(temp!=0)
                            {
                                v.pb(temp%2);
                                temp/=2;
                            }
                            
                            v.pb(0);
                            reverse(v.begin(),v.end());
                            ///we need to call next_permutation once cause
                            /*
                            Next_permutation transforms the range of elements [first, last) 
                            into the lexicographically next greater permutation of the elements.
                            */
                            next_permutation(v.begin(),v.end());


                            for(int i=v.size()-1,j=0; i>=0; i--,j++)
                            {
                                ans += (ll) v[i]*pow_[j];
                            }
                            pf("Case %d: %lld\n",tt,ans);
            }
    return 0;
}