#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      unsigned long long int
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{
    string s1,s2,ans="";
    int len,fl=1;;

        cin>> s1>> s2;
        len = s1.length();

            for(int i=0; i<len; i++)
            {
                if(s1[i]<s2[i]){fl=0; break;}
                if(s1[i] != s2[i]) ans += s2[i];
                else
                {
                    /*if(s1[i] != 'z')*/ ans += 'z';
                    //else{fl=0; break;}
                }
            }

            if(fl==1)cout<<ans<<endl;
            else cout<<"-1\n";
    return 0;
}