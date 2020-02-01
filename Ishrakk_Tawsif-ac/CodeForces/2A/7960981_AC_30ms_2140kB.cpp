 #include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000000005
#define ll long long int
#define mp make_pair
#define mod 10000007

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

/*int knapsack(int i,int w)
{
    if(i<0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];

        if(w-wei[i]>=0)dp[i][w] = max(ks(i-1,w),ks(i-1,w-wei[i])+val[i]);
        else dp[i][w]=ks(i-1,w);
        //cout << i << " " << w << " " << dp[i][w]<<endl;
    return dp[i][w];
}*/

//vector <int> graph[mx];
//vector <int> graph2[mx];

//bitset<mx>isprime;
//vector<int>prime;

/*void sieve()
{

    isprime[0]=isprime[1]=1;
    prime.pb(2);

            for(int i=3; i*i<mx; i+=2)
            {
                if(!isprime[i]) for(int j=i*i; j<mx; j+=i) isprime[j]=1;
            }
            for(int i=3; i<mx; i+=2) if(!isprime[i]) prime.pb(i);
}*/
/*int arr[101][101],dp[101][101],n,m;

int call(int i, int j)
{
    if(i<=0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

        int ans;

            ans=arr[i][j] + min(call(i-1,j),min(call(i-1,j-1),call(i-1,j+1)));
            //cout<<ans<<endl;
    return dp[i][j]=ans;
}*/

struct d
{
    int h,w,nn;

        bool operator <(const d &x) const{
            if(w==x.w) return h<x.h;
            return w<x.w;
        }
};

vector <d> vv;

map<string,int>mmp;
map<string,int>track;

int main()
{
    /*d get;
    int n,eh,ew;
    vector<int>ans;
        while(scanf("%d %d %d", &n,&eh,&ew) == 3){
            for(int i=0; i<n; i++) {cin>> get.h>> get.w; get.nn=i+1; vv.pb(get);}
            sort(vv.begin(),vv.end());
        //for(int i=0; i<vv.size(); i++) cout<<vv[i].h<<" "<<vv[i].w << endl;
            int cnt=0;
            ans.clear();
                int cur1=eh,cur2=ew,fl=0;
                int j=0;
                for(j=0; j<n; j++){
                    if(vv[j].h>cur1 && vv[j].w>cur2){
                        cnt++;
                        cur1=vv[j].h;
                        cur2=vv[j].w;
                        ans.pb(vv[j].nn);
                        break;
                    }
                }//cout<<j<<endl;
                for(int i=j+1; i<n; i++){
                    if(vv[i].h>cur1 && vv[i].w>cur2){
                        cnt++;
                        cur1=vv[i].h;
                        cur2=vv[i].w;
                        ans.pb(vv[i].nn);
                    }
                    //else break;
                }
                if(cnt==0)pf("%d\n", cnt);
                else{
                    pf("%d\n", cnt);
                    cout<<ans[0];
                    for(int i=1; i<ans.size(); i++) cout<<" " << ans[i];
                    cout<<endl;
                }
        }*/
        //for(int i=0; i<vv.size(); i++) cout<<vv[i].h<<" "<<vv[i].w << endl;
            string s;
            int n,temp;

            cin>> n;
            string str[n+1];
            int nn[n+1];
                loop(n)
                {
                    cin>> str[i]>> nn[i];
                    mmp[str[i]]+=nn[i];
                }
            int max_=INT_MIN;
            for(int i=0; i<n; i++){
                if(mmp[str[i]]>max_) max_=mmp[str[i]];
            }
            for(int i=0; i<n; i++)
            {
                track[str[i]]+=nn[i];
                    if(track[str[i]]>=max_ && mmp[str[i]]>=max_)
                    {
                        cout<<str[i]<<endl;
                        break;
                    }
            }

    return 0;
}