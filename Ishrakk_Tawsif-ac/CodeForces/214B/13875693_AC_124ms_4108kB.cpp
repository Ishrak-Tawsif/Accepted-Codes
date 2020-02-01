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
#define casepf(nn)              printf ("Case %d: ",nn)
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
#define Unique_(a)              sort(all(a));a.erase(unique(all(a)),a.end())
#define mx                      47000+5
#define mod                     1000000007
#define left(n)                 (n<<1)
#define right(n)                ((n<<1) + 1)
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI                      acos(-1)
#define ull                     unsigned long long
template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}
//template <class T> inline T bigMod(T p,T e,T M){ ll ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int main()
{
    //int n,res;

    //sf(n);

//    for(int i=0; ; i++)
//    {
//        int now = pow(2,i);
//        if(now>n) {res = i;break;}
//    }
//    out(res);

//    set <int> st;
//    for(int i=1; i<=n; i++)
//    {
//        st.insert(i);
//    }
//
//    int cnt = 0,maxi = -2e9;
//    bool fl = 0;
//    vector <int> vv;
//    for(int i=2; i<=n; i++)
//    {
//        auto cur = st.lower_bound(i);
//        if(*cur != i) continue;
//
//        cnt = 0;
//        vv.clear();
//        vv.pb(i);
//        st.erase(i);
//        for(auto x : st)
//        {
//            fl = 1;//out(x);
//            for(int j=0; j<vv.size(); j++)
//            {//cout<<x<<" "<<vv[j]<<endl;
//                if(x%vv[j] != 0) {fl = 0; break;}
//            }
//            if(fl) {vv.pb(x);st.erase(x);}
//        }//out(vv.size());
////        if(vv.size()>=3)
////        {
////            for(int j=0; j<vv.size(); j++) cout<<" "<<vv[j]; cout<<endl;
////        }
//        if((int)(vv.size()+1)>maxi) maxi = vv.size()+1;
//    }
//    out(maxi);

    int n,fl = 0,sum=0,ar[100005];
    sf(n);
    for(int i=0; i<n; i++) {sf(ar[i]); if(!ar[i]) fl++; sum += ar[i];}

    if(!fl){pf("-1\n"); return 0;}
    if(fl == n){pf("0\n"); return 0;}
    sort(ar,ar+n);

    if(sum%3 == 0) {for(int i=n-1; i>=0; i--) cout<<ar[i]; pf("\n");}
    else
    {
        sum = sum%3;
        int cnt1 = 0,last,last2;

        if(sum == 2)
        {
            int fl = 0;
            for(int i=0; i<n; i++)
            {//out(i);
                if(ar[i]%3 == 2)
                {//out("i");
                    ar[i] = -1;//out(i);
                    fl = 1;
                    break;
                }
                else if(ar[i]%3 == 1)
                {
                    cnt1++;
                    if(cnt1 == 1)last = i;
                    if(cnt1 == 2) {last2 = i;}
                }
            }

            if(!fl) ar[last] = ar[last2] = -1;

            int zero = 0,tot = 0;

            for(int i=n-1; i>=0; i--)
            {
                if(ar[i] != -1) tot++;
                if(!ar[i])zero ++;
            }
//cout<<tot<<" "<<zero<<endl;
            if(tot == zero)
            {
                pf("0\n"); return 0;
            }

            for(int i=n-1; i>=0; i--)
            {
                if(ar[i] != -1) pf("%d", ar[i]);
            }pf("\n");
        }
        else
        {
            int last = -1,fl = 0,cnt1=0,last2;
            for(int i=0; i<n; i++)
            {
                if(ar[i]%3 == 1)
                {
                    ar[i] = -1;
                    fl = 1;
                    break;
                }
                else if(ar[i]%3 == 2)
                {
                    cnt1++;
                    if(cnt1 == 1) last = i;
                    if(cnt1 == 2) last2 = i;
                    //break;
                }
            }
            if(!fl) ar[last] = ar[last2] = -1;

            int zero = 0,tot = 0;

            for(int i=n-1; i>=0; i--)
            {
                if(ar[i] != -1) tot++;
                if(!ar[i])zero ++;
            }

            if(tot == zero)
            {
                pf("0\n"); return 0;
            }

            for(int i=n-1; i>=0; i--)
            {
                if(ar[i] != -1) pf("%d", ar[i]);
            }pf("\n");
        }
    }
    return 0;
}