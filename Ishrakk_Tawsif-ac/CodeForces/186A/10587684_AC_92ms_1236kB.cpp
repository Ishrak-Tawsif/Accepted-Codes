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
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};


int main()
{
    string s1,s2;

    cin>> s1>> s2;

    if(s1.length() != s2.length())
    {
        pf("NO\n");
        return 0;
    }

    int cnt=0;
    vector <int> vv;
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i] != s2[i]) vv.pb(i);
    }

    if(vv.size() == 2)
    {
        if(s1[vv[0]] == s2[vv[1]] && s2[vv[0]] == s1[vv[1]])
        {
            pf("YES\n");
        }
        else pf("NO\n");
    }
    else pf("NO\n");

    return 0;

}