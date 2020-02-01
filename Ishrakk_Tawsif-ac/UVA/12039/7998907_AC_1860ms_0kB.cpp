 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000025
#define ll long long int
#define mp make_pair
#define mod 1000005

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

//ll val[1001],coin [1001],dp[1001][1001],n;

//knapsack
/*int ks(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

//vector <int> graph[4005];
//int vis[4005],dis[4005];
//vector <int> graph2[mx];

bitset<mx>isprime;
int prime[mx],in;
ll cnt[mx];

void sieve()
{

    isprime[0]=isprime[1]=1;
    prime[0]=2;

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            //cnt[2]=1;
            in=0;
            for(int i=3; i<mx; i+=2){
                    if(!isprime[i] && (i%2)!=0) prime[++in]=i;
                    //else cnt[i]=cnt[i-1];
            }
}
//int arr[101][101],dp[101][101],n,m;

/*struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};*/

/*ll ipow(ll base,ll pow)
{
    ll res=base;

        while(pow--) res*=base;
    return res;
}*/

ll solve(int h)
{
    int pos_h = (int)(upper_bound(prime+1, prime+in, h) - (prime+1));//cout<<pos_h<<endl;
    //int pos_l = (int)(lower_bound(prime+1, prime+in, h) - (prime+1));cout<<prime[pos_l]<<endl;

    //cout<<pos_l << " " << pos_h << "\n " << prime[pos_l] << " " << prime[pos_h-1] << endl;
    //cout<<pos_h-pos_l<<endl;
        ll cnntt=0;
        for(int i=1; i<=in && prime[i]<h; i++){
            while (pos_h > 0 && prime[i] + prime[pos_h] > h)
                pos_h--;
            if (pos_h >= i)
                cnntt--;
            cnntt += pos_h;
        }
return cnntt/2;
}

/*int fl=0;

int dfs(int s,int cur)
{
    if(!vis[s]){
        vis[s]=1;
        for(int i=0; i<graph[s].size(); i++){
        if(dis[s] == 2 && graph[s][i] == cur){fl=1;return 0;}
        if(!vis[graph[s][i]]){
            dis[graph[s][i]]=dis[s]+1;
            dfs(graph[s][i],cur);
        }
        }
    }
}*/

int main()
{
   sieve();
   int h,l;//cout<<in<<endl;

        while(cin>>l >>h && h+l)
        {
            h=(h/2) * 2;
            l=(l-1)/2 * 2;//cout<<l<<endl;
            cout<<solve(h)-solve(l)<<endl;
        }

   return 0;
}