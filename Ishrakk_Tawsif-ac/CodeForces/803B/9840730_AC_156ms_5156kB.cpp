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
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int arr[200005],low[200005];
vector <int>vv;

int main()
{
    int n,cur_low=-1;
    sf(n);
        vv.pb(-1);
        loop(i,0,n)
        {
            sf(arr[i]);
            if(arr[i]==0) {vv.pb(i+1);cur_low=i;}
            low[i]=cur_low;
        }
        vv.pb(intinf);
        sort(vv.begin(),vv.end());
        loop(i,0,n)
        {
            if(i!=0) cout<<" ";
            int up= std::upper_bound (vv.begin(), vv.end(), i+1)-vv.begin();
//cout<<"\n"<<low[i] << " " << vv[up] << endl;
            if(arr[i] == 0) cout<<"0";
            else if(low[i]!=-1 && up<vv.size()-1)
            {
                int temp = abs(vv[up]-(i+1));
                int ttmp = abs(low[i]-i);
                cout<<min(temp,ttmp);
            }
            else if(low[i]==-1)cout<<abs(vv[up]-(i+1));
            else if(vv[up] == intinf) cout<<abs(low[i]-i);

        }
        cout<<"\n";
    return 0;
}