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
//Diamond, Club, Heart, Spade
int getval(char ch)
{
    if(ch == 'D') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'H') return 3;
    return 4;
}

int getid(char ch)
{
    if(ch == 'T') return 10;
    else if(ch == 'J') return 11;
    else if(ch == 'Q') return 12;
    else if(ch == 'K') return 13;
    return 14;
}

struct st
{
    int num,val;

    bool operator <(const st & x) const
    {
        if(num == x.num) return val < x.val;
        else return num < x.num;
    }
};

struct st2
{
    int num,val;

    bool operator <(const st2 & x) const
    {
        if(num == x.num) return val > x.val;
        else return num > x.num;
    }
};

string temp = "23456789TJQKA";
string temp2 = "DCHS";
map <string,int> vis;

st convert(string str)
{
    st get;
    if(str[0]>='0' && str[0]<='9') get.num = str[0] - '0';
    else get.num = getid(str[0]);

    get.val = getval(str[1]);

    return get;
}

st2 convert2(string str)
{
    st2 get;
    if(str[0]>='0' && str[0]<='9') get.num = str[0] - '0';
    else get.num = getid(str[0]);

    get.val = getval(str[1]);

    return get;
}

int main()
{
    int tc;

    scanf("%d", &tc);

    st get;
    while(tc--)
    {
        set <st> sat;
        set <st2> sat2;
        vis.clear();

        string now;
        for(int i=1; i<=26; i++)
        {
            cin>> now;
            vis[now] = 1;
            get = convert(now);
            sat.insert(get);
        }

        st2 get2;
        for(int i=0; i<temp2.length(); i++)
        {
            for(int j=0; j<temp.length(); j++)
            {
                now = "";
                now += temp[j];
                now += temp2[i];
                if(!vis[now]) get2 = convert2(now),sat2.insert(get2);
            }
        }

        int fl,res=0;
        for(auto x : sat)
        {
            fl = 0;
            for(auto y : sat2)
            {
                if(x.num>y.num)
                {
                    fl = 1;
                    sat2.erase(y);
                    break;
                }
                else if(x.num == y.num && x.val>y.val)
                {
                    fl = 1;
                    sat2.erase(y);//cout<<y.num<<" ..."<<y.val<<endl;
                    //for(auto k : sat2) cout<<k.num<<" "<<k.val<<endl;
                    break;
                }
            }
            if(fl) res++;
        }
        printf("%d\n", res);
    }

    return 0;
}