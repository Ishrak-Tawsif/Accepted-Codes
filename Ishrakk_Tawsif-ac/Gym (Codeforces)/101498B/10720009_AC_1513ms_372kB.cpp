#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
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


string str1,str2;
int cnt1[27],cnt2[27];

int main()
{
    int tc,ans;

    sf(tc);

    loop(tt,0,tc)
    {
        ans=0;
        cin>> str1>> str2;
        loop(i,0,26) cnt1[i]=0,cnt2[i]=0;
        //for(int i=0; i<str1.length(); i++) cnt1[str1[i]-'a']++;
        for(int i=0; i<str2.length(); i++) cnt2[str2[i]-'a']++;

        for(int i=0; i<str1.length(); i++)
        {
            int ind = str1[i]-'a';
            if(cnt2[ind]) ans++,cnt2[ind]--;
            else {break;}
        }

        cout<<ans<<endl;
    }
    return 0;
}