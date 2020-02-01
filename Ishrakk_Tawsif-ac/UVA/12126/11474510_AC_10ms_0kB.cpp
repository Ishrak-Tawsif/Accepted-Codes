#define ONLINE_JUDGE 1
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
#define mx                      1000+5
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

pair <ll,ll> calc(ll l,ll w)
{
    ll curl,curw;
    curl = (l*40) + (l+1)*4;
    curw = (w*8) + (w+1)*2;

    return (mp(curl,curw));
}

int main()
{//WRITE("in.txt");
    int tc;
    ll n;

    sf(tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%lld", &n);
        ll tot = (n/5) + (n%5>0);

        ll finalans = 1e18+30,finall,finalw,tempans,templ,tempw;

        for(ll i=1; i*i<=tot; i++)
        {
            //if(!(tot%i))
            //{
                ll area1 = 1e18+10,area2 = 1e18+10,var;

                if(tot%i) var = tot/i + 1;
                else var = tot/i;

                pair<ll,ll> now = calc(i,var);
                /*if(now.first>=now.second)*/ area1 = now.first * now.second;

                pair<ll,ll> now2 = calc(var,i);
                /*if(now2.first>=now2.second)*/ area2 = now2.first * now2.second;

                //if(area1 == 1e18+10 && area2 == 1e18+10) continue;

                tempans = 1e18 + 25;

                if(area1<area2)
                {
                    tempans = area1;
                    templ = max(now.first,now.second);
                    tempw = min(now.first,now.second);
                }
                else if(area1>area2)
                {
                    tempans = area2;
                    templ = max(now2.first,now2.second);
                    tempw = min(now2.first,now2.second);
                }
                else
                {
                    tempans = area1;
                    if(abs(now.first-now.second)<abs(now2.first-now2.second))
                    {
                        templ = max(now.first,now.second);
                        tempw = min(now.first,now.second);
                    }
                    else
                    {
                        templ = max(now2.first,now2.second);
                        tempw = min(now2.first,now2.second);
                    }
                }
                //pair<ll,ll> now = calc(i,tot/i);
                //tempans = now.first * now.second;

                if(finalans>tempans)
                {
                    finalans = tempans;
                    finall = max(templ,tempw);
                    finalw = min(templ,tempw);
                }
                else if(finalans == tempans)
                {
                    if(abs(finall - finalw)> abs(templ-tempw))
                    {
                        finall = templ;
                        finalw = tempw;
                    }
                }
            //}
        }
//cout << (finall-4)/44 << " " << (finalw-2)/10 << endl;
        pf("%lld X %lld = %lld\n", finall,finalw,finalans);
    }
    return 0;
}