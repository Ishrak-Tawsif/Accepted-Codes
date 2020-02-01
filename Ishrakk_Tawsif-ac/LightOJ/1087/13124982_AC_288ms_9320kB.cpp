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
    #define mx                      150002
    #define mod                     1000000007

    template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
    template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

    string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
    ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


    /* ...........................................................................................................*/

    struct ST
    {
        int b,e,sum;
    }tree[4*mx];

    int  ar[mx];

    struct Segmenttree
    {
        void build(int node,int bg,int en)
        {
            tree[node].b = bg;
            tree[node].e = en;

            if(bg == en)
            {
                    tree[node].sum = (ar[bg]>=0);
                    return;
            }

            int mid = (bg + en)/2;
            int lf = 2*node;
            int rt = lf + 1;

            build(lf,bg,mid);
            build(rt,mid+1,en);
            tree[node].sum = tree[lf].sum + tree[rt].sum;
        }

        void update(int node,int bg,int en,int pos,int val)
        {
            if(tree[node].b == tree[node].e)
            {
                tree[node].sum = val;
                return;
            }

            int mid = (bg + en)/2;
            int lf = 2*node;
            int rt = lf + 1;

            if(pos<=tree[lf].e)update(lf,bg,mid,pos,val);
            else update(rt,mid+1,en,pos,val);

            tree[node].sum = tree[lf].sum + tree[rt].sum;
        }

        int query(int node,int bg,int en,int pos)
        {
            //int now;
            if(tree[node].b == tree[node].e)
            {
                //holdpos = bg;
                //now = ar[bg];
                return tree[node].b;
            }

            int mid = (bg + en)/2;
            int lf = 2*node;
            int rt = lf + 1;

            if(pos<=tree[lf].sum) return query(lf,bg,mid,pos);
            else return query(rt,mid+1,en,pos-tree[lf].sum);
        }
    };

    int main()
    {//WRITE("loj1.txt");
        int tc,n,q,val;
        char c;
        Segmenttree get;
        sf(tc);

        for(int tt=1; tt<=tc; tt++)
        {
            scanf("%d %d", &n,&q);
            //mem(sum,0);
            mem(ar,-1);

            for(int i=1; i<=n; i++) sf(ar[i]);
            get.build(1,1,n+q);
            int ind = n;

            casepf(tt);

            for(int qq=1; qq<=q; qq++)
            {
                scanf(" %c %d", &c,&val);
                if(c == 'a')
                {
                    ++ind;
                    ar[ind] = val;
                    get.update(1,1,n+q,ind,1);
                }
                else
                {
                    //int holdpos;//out(sum[1]);
                    if(tree[1].sum < val ) pf("none\n");
                    else
                    {
                        int now = get.query(1,1,n+q,val);//cout<<"now "<<now<<endl;
                        pf("%d\n",ar[now]);
                        get.update(1,1,n+q,now,0);
                    }
                }
            }
        }
        return 0;
    }