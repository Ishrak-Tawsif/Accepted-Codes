#include <bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define loop1(var,start,till)   for(int var=start; var<=till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define all(a)                  (a.begin(),a.end())
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

vector <int> vv[27];

struct ST
{
    int pos,fl,pre;
}track[200000+11];

int bsearch(int konta,int val)
{
    int st = 0,en = vv[konta].size()-1,res = -1,mid;//cout<<konta<<" ... "<<" "<<vv[konta].size()<<endl;
    if(en == -1) return -1;
    while(st<=en)
    {
        mid = (st + en)>> 1;
        if(vv[konta][mid]>val) res = vv[konta][mid],en = mid-1;
        else st = mid + 1;
    }
    return res;
}

int print(char ch,int llast)
{
    //int fl = 1;
    int now = ch - 'a';
    int cur = bsearch(now,llast);

    return cur;
}

int main()
{//READ("in.txt");
    string s,p="",temp;
    char ch;
    int q;

    cin>> s;

    int len = s.length();

    for(int i=0; i<len; i++)
    {
        int now = s[i] - 'a';
        vv[now].pb(i);
    }

    sf(q);

    int cur = -1,curfl;
    while(q--)
    {
        cin>> temp;
//cout<<temp<<endl;
        if(temp == "push")
        {
            scanf(" %c",&ch);
            p += ch;
            if(cur != -1)
            {
                int now = print(ch,track[cur].pre);//cout<<track[cur].fl<<" "<<now<<endl;
                curfl = track[cur].fl & (now != -1);
                track[cur+1].fl = curfl;
                track[cur+1].pre = now;
                //track[cur+1].pos
            }
            else
            {
                int now = print(ch,-1);
                curfl = (now != -1);
                track[cur+1].fl = curfl;
                track[cur+1].pre = now;
            }
            ++cur;
        }
        else
        {
            //p.erase(p.begin()+p.size()-1);
            if(cur != -1 && cur != 0)
            {
                --cur;
                curfl = track[cur].fl;
            }
            else if(cur == 0) curfl = 1,--cur;
            else if(cur == -1) curfl = 1;
        }

        if(curfl) pf("YES\n");
        else pf("NO\n");//cout<<p<<" "<<cur<<" "<<track[cur+1].fl<<endl;
    }

    return 0;
}