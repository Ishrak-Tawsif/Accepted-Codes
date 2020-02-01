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
#define mx                      5005
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int n;

struct S
{
    int h,w;

        bool operator <(const S & x)const
        {
            if(w == x.w)  return h<x.h;
            else return w>x.w;
            //return s<x.s || f<x.f;
        }
};

vector <S> vv;
vector <int> LDS;

int dp[10005];

/*int call(int i)
{
    if(i>=n) return 0;
    if(dp[i]!= -1) return dp[i];

        int ans=1,ans2=0;
        for(int k=i+1; k<n; k++)
            if(vv[k].f>=vv[i].f && vv[k].s>=vv[i].s) {
                ans = max(ans,call(k)+1);
                //cout<<ans<<" " <<i << " " << k << endl;
            }
        //else ans2 = call(i,j+1);
        //cout<<ans<<endl;
    return dp[i] =ans;
}*/

int b_search(int s,int e,int sv)
{
    int mid;
//out(s);out("....");out(e);
        while(s<e)
        {//cout<<s<<" "<<e<<endl;system("pause");
            mid = (s+e)/2;
            if(LDS[mid]<=sv) s=mid+1;
            else e = mid;
        }
    return s;
}

int main()
{
    int tc;
    sf(tc);
    S get;

        loop(tt,1,tc+1)
        {
            sf(n);
            vv.clear();
            LDS.clear();
            loop(i,1,n+1)
            {
                scanf("%d %d", &get.w,&get.h);
                vv.pb(get);
            }

                sort(vv.begin(),vv.end());

                LDS.pb(vv[0].h);
                for(int i=1; i<n; i++)
                {//out(i);
                    int pos = b_search(0,LDS.size()-1,vv[i].h);//cout<<pos<<" .. "<<endl;
                    if(LDS[pos]>vv[i].h) LDS[pos]=vv[i].h;
                    else LDS.pb(vv[i].h);//cout<<i<<endl;
                }
                //for(int i=0; i<vv.size(); i++) cout<<vv[i].w << " " << vv[i].h << endl;
                pf("%d\n",LDS.size());//cout<<".."<<endl;
        }
    return 0;
}