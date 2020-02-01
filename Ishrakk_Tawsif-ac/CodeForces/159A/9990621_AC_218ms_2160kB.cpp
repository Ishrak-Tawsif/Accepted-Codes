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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};


string sr,ds;
//int time;
vector <pair<string,string> > vv;
set <pair<string,string> > frnd;
vector<int>vtime;

int main()
{
    int n,d,time;

        scanf("%d %d",&n,&d);
            loop(i,0,n)
            {
                cin>> sr>> ds>> time;
                vv.pb(mp(sr,ds));
                vtime.pb(time);
            }

            string sfr1,dfr1,sfr2,dfr2;
            int tm1,tm2;

            for(int i=0; i<n; i++)
            {
                sfr1 = vv[i].first;
                dfr1 = vv[i].second;
                tm1=vtime[i];
                    for(int j=i+1; j<n; j++)
                    {
                        sfr2 = vv[j].first;
                        dfr2 = vv[j].second;
                        tm2 = vtime[j];

                            if(tm2>tm1)
                            {
                                if(tm2-tm1<=d && sfr1 == dfr2 && sfr2 == dfr1)
                                {
                                    pair<string,string> temp1=mp(sfr1,dfr1);
                                    pair<string,string> temp2=mp(dfr1,sfr1);

                                    if(frnd.find(temp1) == frnd.end() && frnd.find(temp2) == frnd.end())
                                    {
                                        frnd.insert(temp1);
                                    }
                                }
                            }
                    }
            }
            cout<<frnd.size()<<endl;
            set <pair<string,string> >::iterator it;

            for(it=frnd.begin(); it!=frnd.end(); it++)
            {
                cout<<it->first<<" "<<it->second<<endl;
            }

    return 0;
}