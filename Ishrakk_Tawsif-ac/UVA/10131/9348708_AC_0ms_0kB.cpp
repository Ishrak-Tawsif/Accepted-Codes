#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define mx                      10000007
#define mod                     100000007
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

string str1,str2;
int dp[1003],path[1003],len1,len2,tt;

struct S
{
    int wei,in,num;

        bool operator < (const S & x) const
        {
            if(wei == x.wei) return in>x.in;
            else return wei<x.wei;
        }
};
vector <S> vv;

int call(int i)
{//cout<<i<<" ... "<<endl;
    //if(i>=tt || j>=tt) return 0;
    if(dp[i] != -1) return dp[i];

        int ans=1;
        for(int j=i+1; j<tt; j++)
        {//cout<<i<<" /////////// "<<endl;
            if(vv[i].wei<vv[j].wei && vv[i].in>vv[j].in)
            {//cout<<i<< " /// " << j << endl;
                int ans1 = call(j)+1;
                //int ans2 = call(i);

                    //ans=max(ans1,ans);
                    if(ans<ans1)
                    {//cout<<i<<" " <<j<<endl;
                        path[i] = j;
                        ans = ans1;
                    }
            }
        }

    return dp[i] = ans;
}

void path_printing(int cur)
{
    while(cur != -1)
    {
        pf("%d\n", vv[cur].num);
        cur = path[cur];
    }
}

int main()
{
    int weight,intel;
    S get;
    tt=0;

        while(scanf("%d %d",&get.wei,&get.in) == 2)
        {
            tt++;
            get.num=tt;
            vv.pb(get);
        }
        sort(vv.begin(),vv.end());

        /*for(int i=0; i<vv.size(); i++)
        {
            cout<<vv[i].wei << " " << vv[i].in << endl;
        }*/
//out(tt);
        mem(dp,-1);
        mem(path,-1);

        int max_ = intinf*-1,start,temp;

        loop(i,0,tt-1)
        {
            temp = call(i);
            if(temp>max_) {max_ = temp; start=i;}
            //system("pause");
        }
        pf("%d\n",max_);
        path_printing(start);

    return 0;
}