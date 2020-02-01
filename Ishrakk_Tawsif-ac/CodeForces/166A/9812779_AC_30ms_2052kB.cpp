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
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

struct s
{
    int pr,pen;

        bool operator <(const s &x)const
        {
            if(pr == x.pr) return pen<x.pen;
            else return pr>x.pr;
        }
};

vector <s> vv;

int main()
{
    int n,k,pr,pn;

        sf(n); sf(k);
        s get;

            loop(i,0,n)
            {
                sf(get.pr);
                sf(get.pen);

                    vv.pb(get);
            }
            sort(vv.begin(),vv.end());
            int team=0;
            //for(int i=0; i<n; i++) cout<<vv[i].pr << " " << vv[i].pen << endl;
            //for(int i=0; i<n;)
            //{


                    k-=1;
                    int i=k;
                    int tpr=vv[k].pr,tpn=vv[k].pen,cnt=0;

                    while(i>0 && vv[i-1].pr == tpr && vv[i-1].pen == tpn ) {i--;}

                    int j=k-1;
                    //if(i>=0){
                        while(j+1<n && vv[j+1].pr == tpr && vv[j+1].pen == tpn) {j++;}
                    //}
                    //team++;
                    //cout<<i<<" " << j << endl;
                    pf("%d\n",j-i+1);
            //}

}