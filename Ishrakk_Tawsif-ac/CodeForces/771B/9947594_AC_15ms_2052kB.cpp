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


string str[53];

int main()
{
    vector<string>vv,q;

        for(int i=65; i<=90; i++)
        {
            char ch = i;
            string temp = "";
            temp += ch;
            vv.pb(temp);//cout<<temp<<endl;
        }

         for(int i=65,j=97; i<=90; i++,j++)
        {
            char ch = i;
            char ch2 = j;
            string temp = "";
            temp += ch;
            temp += ch2;
            vv.pb(temp);//cout<<temp<<endl;
        }//cout<<q.size()<<endl;

        int n,k;

            scanf("%d %d", &n,&k);

                loop(i,0,(n-k)+1)cin>> str[i];

                    loop(i,0,(n-k)+1)
                    {
                        if(str[i] == "NO")
                        {//cout<<i<<endl;
                            int in = (i+k)-1;
                            vv[in]=vv[i];
                        }

                    }
           cout<<vv[0];
           for(int i=1; i<n; i++) cout<<" "<<vv[i];
           cout<<"\n";
}