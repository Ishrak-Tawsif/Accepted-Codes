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
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};


//multiset <pair<char,int> > s;

struct ST
{
    char ch;
    int ind;

        bool operator <(const ST &x)const
        {
            if(ch == x.ch) return ind < x.ind;
            return ch > x.ch;
        }
};
vector <ST> vv;
int main()
{
    string str,ans="";
    ST get;

    cin>> str;

    for(int i=str.length()-1; i>=0; i--)
    {
        get.ch = (char) str[i];
        get.ind = i;
        vv.pb(get);
    }
//out("ok");
    sort(vv.begin(),vv.end());

    char temp;
    int in=-1;

    for(int i=0; i<vv.size(); i++)
    {
        char cur = vv[i].ch;
        int index = vv[i].ind;//cout << cur << " " << index << endl;
        if(index<in) continue;

            while(str[++in] != cur && in<str.length());
            if(in>=str.length()) break;

            ans += cur; //cout << ans << endl;
    }

    //cout<<s.size()<<" "<<in<<endl;
    cout<<ans<<endl;
    return 0;
}