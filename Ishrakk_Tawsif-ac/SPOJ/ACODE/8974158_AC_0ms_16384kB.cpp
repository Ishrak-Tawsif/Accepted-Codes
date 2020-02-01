#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 10005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

string num;
ll len,dp[5000];

ll call(int pos)
{
    if(pos == len) return 1;
    if(dp[pos] != -1) return dp[pos];
    if(num[pos] == '0') return 0;

        ll p1=0,p2=0;

        p1=call(pos+1);

        if(pos<(len-1)){

            ll nn = (num[pos]-48)*10 + (num[pos+1]-48);

                if(nn<=26)
                {
                    p2 = call(pos+2);
                }
        }
     return dp[pos] = p1+p2;
}

int main()
{
    while(cin>> num)
    {
        if(num[0] == '0') break;
        len = num.length();
        memset(dp,-1,sizeof(dp));
        cout<<call(0)<<endl;
    }
    
    return 0;
}