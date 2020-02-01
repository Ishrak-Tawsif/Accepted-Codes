#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dirx[8]={0,0,1,-1,1,1,-1,-1};
int diry[8]={1,-1,0,0,1,-1,1,-1};
///#pragma comment(linker,"/stack:200000000")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll             long long
#define sc1(a)         scanf("%d",&a)
#define llsc1(a)       scanf("%lld",&a)
#define sc2(a,b)       scanf("%d %d",&a,&b)
#define llsc2(a,b)     scanf("%lld %lld",&a,&b)
#define sc3(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define llsc3(a,b,c)   scanf("%lld %lld %lld",&a,&b,&c)
#define min3(a,b,c)    min(a,min(b,c))
#define max3(a,b,c)    max(a,max(b,c))
#define pf             printf
#define cpfl(s)        cout<<s<<endl
#define cpf(s)         cout<<s
#define FOR(a)         for(ll i=0;i<a;i++)
#define inf            2e9
#define pr             pair<int,int>
#define mpp            make_pair
#define pi             acos(-1)
#define sqr(a)         (a*a)
#define eps            1e-6
#define all(a)         a.begin(),a.end()
#define newline        pf("\n")
#define mem(a,b)       memset(a,b,sizeof(a))
#define srt(a,n)       sort(a,a+n)
#define pks(a)         pf("Case %d: ",a)
#define mx             50005
#define mm             1420
#define mod            1000000007
#define frd            freopen("input.txt","r",stdin)
#define fpf            freopen("in.txt","w",stdout)

string tostring(ll n){if(!n)return "0";string ans="";while(n!=0){ans+=(n%10)+'0';n/=10;}reverse(ans.begin(),ans.end());return ans;}
double toDouble(string s){double ans=0;int i=0,flag=0,cnt=0,ff=1;while(i<s.length()){if(s[i]=='-'){ff=-1;i++;continue;}if(s[i]=='.'){flag=1;i++;continue;}ans*=10;ans+=s[i]-'0';if(flag)cnt++;i++;}ans*=ff;return ans/pow(10,cnt);}
/// Template Ends
///
bitset<mx>bt;
int prime[mx],e=0;
void sieve()
    {
        bt[0]=bt[1]=1;
        prime[++e]=1;
        prime[++e]=2;
        for(int i=3;i*i<=mx;i+=2){
            if(!bt[i]){
                prime[++e]=i;
                for(int j=i*i;j<mx;j+=2*i)bt[j]=1;
            }
        }
        for(int i=223;i<mx;i+=2){
            if(!bt[i])prime[++e]=i;
        }
        //cpfl(e);
    }
int dis[mx];
void init()
    {
        for(int i=0;i<mx;i++)dis[i]=inf;
    }
void bfs(int n,int m)
    {
        init();
        queue <int> q;
        q.push(0);
        dis[0] = 0;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            for(int i=1; i<=n; i++)
            {
                int now = prime[i] + cur;

                //now += cur;
                if(now>m) continue;
                if(dis[now]>dis[cur]+1)
                {
                    dis[now] = dis[cur] + 1;
                    q.push(now);
                }
            }
        }
    }

int main()
    {
        //frd;
        //fpf;

        sieve();
        int tc,n,q;
        sc1(tc);
        while(tc--){
            sc2(n,q);
            bfs(n,q);
            pf("%d\n",dis[q]);
        }
        
        return 0;
    }