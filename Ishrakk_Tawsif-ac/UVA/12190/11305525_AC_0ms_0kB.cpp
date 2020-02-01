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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      1000005
#define mod                     1000000007

ll b,curres;

ll solve(ll temp)
{
   ll ans = 0;

   ans += min(max((ll)0,temp/2),(ll)100),temp-=2*100;
   ans += min(max((ll)0,temp/3),(ll)9900), temp-=3*9900;
   ans += min(max((ll)0,temp/5),(ll)990000), temp -= 5*990000;
   ans += max((ll)0,temp/7);

   return ans;
}

ll check(ll temp)
{///unit to taka
    ll ans = 0;

    ans += min(max((ll)0,(ll)temp*2),(ll)200),temp -= 100;
    ans += min(max((ll)0,(ll)temp*3),(ll)3*9900),temp-=9900;
    ans += min(max((ll)0,(ll)temp*5),(ll)5*990000), temp-=990000;
    ans += max((ll)0,(ll)temp*7);

    return ans;
}

ll bsearch(ll st,ll en)
{
    ll mid,ans=0;

    while(st<=en)
    {
        mid = ((st+en)/2);//cout<<mid<<" /// "<<check(mid)<<endl;
        ll curval = check(curres-mid)-check(mid);//cout<<curval<<endl;

        //if(curval<0) curval *= -1;

        if(curval == b) {ans=mid;break;}
        else if(curval>b)
        {
            //ans = mid;
            st = mid+1;
        }
        else en = mid - 1;
    }
    return ans;
}

int main()
{//WRITE("in.txt");
    ll a;
int tt=0;
    while(scanf("%lld %lld", &a,&b) && a && b)
    {

        curres = solve(a);
//out(curres);///
        ll ans = bsearch(1,curres);
        ll temp = curres-ans;
        temp=(temp<ans)? temp : ans;
//cout<<temp<<endl;
        ll ans1 = check(temp);
//casepf(++tt);
        pf("%lld\n", ans1);//if(tt==177) system("pause");
    }
    return 0;
}