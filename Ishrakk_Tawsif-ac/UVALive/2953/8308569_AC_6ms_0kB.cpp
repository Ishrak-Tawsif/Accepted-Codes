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

///hints

/*
since fact(n) > fact(0)+fact(1)+...+fact(n-1) (this is true for each n > 2) you can
iterate from the greatest factorial(20!) to the smallest one, if fact[i] is less than
or equal to N you must take it, decrease N by fact[i] and proceed with the next
factorial. At the end, if N is 0 you found the solution, otherwise it is impossible
to obtain N adding factorials.
*/


ll fact[21];
stack<int>ans;

void pre_gen()
{
    fact[0]=fact[1]=1;
    for(ll i=2; i<=20; i++)
    {
        fact[i]=fact[i-1]*i;
    }
}

bool solve(ll n)
{
    ll temp=n;

        int i=20;

            while(i--)
            {
                if(temp>=fact[i])
                {
                    temp-=fact[i];//cout<<i<<" "<<fact[i]<<" ";
                    //ans.push(i);
                }
                if(temp==0) break;
            }//cout<<ans.size()<<endl;
            if(temp==0) return 1;
            else return 0;
}

int main()
{
    int tc;
    ll n;

    pre_gen();

        //sf(tc);

            //loop1(tt,tc)
            while(1){
                scanf("%lld", &n);
                if(n<0) break;
                //pf("Case %d: ",tt);
                //while(!ans.empty()) ans.pop();

                
                if(solve(n) && n!=0)
                {
                    /*pf("%d!",ans.top());
                    ans.pop();
                    while(!ans.empty())
                    {
                        pf("+%d!",ans.top());
                        ans.pop();
                    }//cout<<ans.size()<<endl;*/
                    pf("YES\n");
                }
                else pf("NO\n");
            }
    return 0;
}