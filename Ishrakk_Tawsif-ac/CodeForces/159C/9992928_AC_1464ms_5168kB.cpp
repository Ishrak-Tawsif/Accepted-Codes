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

int mark[200005],cnt[27];
vector <int> ind[31];

int main()
{
    int k,n,tm,u,v;
    string str,tot="";
    char ch;

        sf(k);
        cin>> str;

            for(int i=0; i<k; i++) tot += str;
//cout<<tot<<endl;system("pause");
            for(int i=0; i<tot.size(); i++)
            {
                int temp = tot[i];
                temp -= 97;
                ind[temp].pb(i+1);
            }

            sf(n);
            loop(i,0,n)
            {
                cin>>u>> ch;
                int temp = ch;
                temp -= 97;
                mark[ind[temp][u-1]]=1;
                ind[temp].erase(ind[temp].begin()+(u-1));
            }
            for(int i=0; i<tot.length(); i++)
            {
                if(!mark[i+1])cout<<tot[i];
            }
            cout<<endl;

    return 0;
}