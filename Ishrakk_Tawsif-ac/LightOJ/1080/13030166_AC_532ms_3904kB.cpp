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
#define mx                      100005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

string str;
bool prop[4*mx];
int sum[4*mx];

void pushdown(int node)
{
    int lf = (node<<1);
    int rt = lf | 1;

    prop[node] = 0;
    prop[lf] ^= 1;
    prop[rt] ^= 1;
    sum[lf] ^= 1;
    sum[rt] ^= 1;
}

struct lazy
{

    void build(int node,int i,int j)
    {
        sum[node] = 0;
        prop[node] = 0;

        if(i == j) return;

        int mid = (i+j) >> 1;

        build(2*node,i,mid);
        build((2*node)+1,mid+1,j);
    }

    void update(int node,int bg,int en,int i,int j)
    {//out("here");
        if(en<i || bg>j) return;
        if(i<=bg && j>=en)
        {
            sum[node] ^= 1;//if(node == 1)if(node == 1)cout<<sum[node]<<" upr eita "<<endl;
            prop[node] ^= 1;
            return;
        }

        if(prop[node]) pushdown(node);

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg+en)>> 1;

        update(lf,bg,mid,i,j);
        update(rt,mid+1,en,i,j);

        sum[node] = (sum[lf] ^ sum[rt]);//if(node == 1)cout<<sum[node]<<" eita "<<sum[lf]<<" "<<sum[rt]<<endl;
    }
    int query(int node,int bg,int en,int i,int j)
    {
        if(en<i || bg>j) return 0;
        if(i<=bg && j>=en)
        {
            //if(sum[node] == 2)cout<<node<<" ..... "<<sum[node]<<"///\n";
            return sum[node];
        }

        if(prop[node]) pushdown(node);

        int lf = (node<<1);
        int rt = lf | 1;
        int mid = (bg + en)>> 1;

        int l = query(lf,bg,mid,i,j);
        int r = query(rt,mid+1,en,i,j);
//cout<<l<<" "<<r<<endl;
//        if(l != -1 && r != -1)return  l ^ r;//if(node == 1) cout<<"dokar "<<sum[node]<<endl;;
//        else if(l!=-1) return  l;
//        else if(r!=-1) return  r;
        return l^r;
    }
};

int main()
{//WRITE("in.txt");
    int tc,n,q,u,v;
    char c;
    lazy get;

    sf(tc);
    for(int tt=1; tt<=tc; tt++)
    {
        cin>> str;//out(str);
        n = str.length();

        get.build(1,1,n);

        sf(q);
        getchar();

        casepf(tt);

        while(q--)
        {
            scanf("%c", &c);//cout<<q<<" "<<c<<" ...... \n";
            if(c == 'I')
            {//out("ok");
                scanf("%d %d", &u,&v);
                get.update(1,1,n,u,v);
            }
            else
            {//cout<<"sum "<<sum[1]<<endl;
                scanf("%d", &u);
                int val = get.query(1,1,n,u,u);//cout<<val<<"...."<<endl;
                if(val & 1)
                {
                    if(str[u-1] == '0') pf("1\n");
                    else pf("0\n");
                }
                else pf("%c\n", str[u-1]);
            }
            getchar();
        }
    }
    return 0;
}