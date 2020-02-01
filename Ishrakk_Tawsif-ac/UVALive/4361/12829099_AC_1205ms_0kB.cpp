#include<bits/stdc++.h>
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
#define mx                      11
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}

/* ...........................................................................................................*/

string str, des = "3123456789";;
int mxmv;
unordered_map <string,int> vis;

bool check(string now)
{
    int fl = 0,len=str.length();
    for(int i=0; i<len; i++) if(str[i]>'0') fl = 1;

    return fl;
}

string change(string cur,int tp,int kon)
{//out(tp);
    if(tp == 1)
    {//out("ok1");
        if(kon == 1)
        {
            char ch = cur[2];
            cur[2] = cur[1];
            cur[1] = cur[4];
            cur[4] = cur[5];
            cur[5] = ch;
        }
        else
        {
            char ch = cur[2];
            cur[2] = cur[5];
            cur[5] = cur[4];
            cur[4] = cur[1];
            cur[1] = ch;
        }
    }
    else if(tp == 2)
    {//out("ok2");
        if(kon == 1)
        {
            char ch = cur[3];
            cur[3] = cur[2];
            cur[2] = cur[5];
            cur[5] = cur[6];
            cur[6] = ch;
        }
        else
        {
            char ch = cur[2];
            cur[2] = cur[3];
            cur[3] = cur[6];
            cur[6] = cur[5];
            cur[5] = ch;
        }
    }
    else if(tp == 3)
    {//out("ok3");
        if(kon == 1)
        {
            char ch = cur[5];
            cur[5] = cur[4];
            cur[4] = cur[7];
            cur[7] = cur[8];
            cur[8] = ch;
        }
        else
        {
            char ch = cur[4];
            cur[4] = cur[5];
            cur[5] = cur[8];
            cur[8] = cur[7];
            cur[7] = ch;
        }
    }
    else
    {//out("ok4");
        if(kon == 1)
        {
            char ch = cur[6];
            cur[6] = cur[5];
            cur[5] = cur[8];
            cur[8] = cur[9];
            cur[9] = ch;
        }
        else
        {
            char ch = cur[6];
            cur[6] = cur[9];
            cur[9] = cur[8];
            cur[8] = cur[5];
            cur[5] = ch;
        }
    }//out(cur);
    return cur;
}

int dikjstra()
{
    vis.clear();
    set <pair<int,string> > st;
    st.insert(mp(0,str));
    vis[str] = 1;

    while(!st.empty())
    {
        pair <int,string> temp = *st.begin();
        st.erase(st.begin());

        string now = temp.second;
        int cst = temp.first;//cout<<now<<" "<<des<<endl;
        //if(now[1] == '1')cout<<now<<" "<<cst<<endl;
        if(now == des && cst<=mxmv) return cst;
        if(cst>mxmv) return -1;
        for(int tp = 1; tp<=4; tp++)
        {
            for(int i=1; i<=2; i++)
            {
                now = temp.second;
                int kk;
                //if(i%2 == 0) kk = 2; else kk = 1;
                now = change(now,tp,i);

                if((cst+1)>mxmv) {continue;}
                if(!vis[now])vis[now]=1,st.insert(mp(cst+1,now));
            }
        }
    }
    return -1;
}

int main()
{
    int tt = 0;
    while(cin>> str && str != "0000000000")
    {
        //if(!check(str)) break;
        des[0] = str[0];//out(des);system("pause");
        mxmv = str[0] - '0';

        pf("%d. %d\n",++tt,dikjstra());
    }
    return 0;
}