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

int main()
{
    int n,m,cnt[31];
    char c;
    string arr[101];

        while(scanf("%d %d %c", &n,&m,&c) == 3)
        {
            loop(n) cin>>arr[i];

                memset(cnt,0,sizeof(cnt));
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        if(arr[i][j]==c){
                        int t1=i-1,t2=i+1;

                            if(t1>=0 && t1<n)cnt[arr[t1][j]-'A']++;//cout<<arr[t1][j]; }
                            if(t2>=0 && t2<n)cnt[arr[t2][j]-'A']++;
//cout<< " " << arr[t2][j] << endl;}
                        t1=j-1,t2=j+1; //cout<<i<<" "<<t1<<" " << t2<<endl;
                            if(t1>=0 && t1<m) cnt[arr[i][t1]-'A']++;//cout<<arr[t1][j]; }
                            if(t2>=0 && t2<m) cnt[arr[i][t2]-'A']++;
//cout<< " " << arr[t2][j] << endl;}
                    }
                    }
                }
                
                int temp=c-'A',cnnt=0;
                for(int i=0; i<26; i++){

                    if(cnt[i]!=0 && i!=temp) cnnt++;
                }
                cout<<cnnt<<endl;
        }
    return 0;
}