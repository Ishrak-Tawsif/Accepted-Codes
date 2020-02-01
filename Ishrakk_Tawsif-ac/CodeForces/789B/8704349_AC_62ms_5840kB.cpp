#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 103
#define ll long long int
#define mp make_pair
#define mod 100000007

unordered_map<ll,int>track;

int main()
{
    ll b,q,l,m;

        while(scanf("%lld %lld %lld %lld", &b,&q,&l,&m) == 4)
        {
            ll temp;

            track.clear();
                loop(i,m)
                {
                    scanf("%lld", &temp);
                    track[temp]=1;
                }

            int cnt=0;

            if(abs(b)>l) pf("0\n");
            else if(b==0)
            {
                if(track[b]==1) pf("0\n");
                else pf("inf\n");
            }
            else if(q == 1)
            {
                if(track[b] == 1) pf("0\n");
                else pf("inf\n");
            }
            else if(q==-1)
            {
                if(track[b]==1 && track[(b*-1)]==1) pf("0\n");
                else pf("inf\n");
            }
            else if(q==0)
            {
                if(track[0]==0)pf("inf\n");
                else if(track[b] == 0) pf("1\n");
                else pf("0\n");
            }

            /*if(q==1 && track[b]==1) pf("0\n",cnt);
            else if(q==-1 && track[b]==1) pf("0\n",cnt);
            else if(q==1 && track[b]==0) pf("inf\n",cnt);
            else if(q==-1 && track[b]==0) pf("inf\n",cnt);
            else if(q==0 && abs(b)<=l)
            {
                cnt=0;
                if(track[0]==0) pf("inf\n");
                else if(track[0]==1 && track[b]==1) pf("0\n");
                else if(track[0]==1 && track[b]==0) pf("1\n");
            }
            else if(b==0)
            {
                if(track[0]==1) pf("0\n");
                else pf("inf\n");
            }
            //else if(q==0 && track[0]==0) pf("inf\n",cnt);*/
            else
            {
                for(ll i=b; abs(i)<=l; i*=q)
                {
                    if(track[i]==0) cnt++;//cout<<i<<endl;
                }
                pf("%d\n",cnt);
            }
        }
    return 0;
}


/*

-1000000000 -1000000000 1 1
232512888

3 3 104 17
9 -73896485 -290898562 5254410 409659728 -916522518 -435516126 94354167 262981034 -375897180 -80186684 -173062070 -288705544 -699097793 -11447747 320434295 503414250

11 0 228 5
-1 0 1 5 -11245

*/