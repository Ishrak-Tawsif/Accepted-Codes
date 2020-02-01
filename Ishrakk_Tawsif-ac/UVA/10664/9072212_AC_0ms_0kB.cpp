#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000

int arr[23],dp[23][2003],n,in;

int call(int pos,int wei)
{//cout<<pos<<" " <<wei<<endl;
    if(wei<0) return 0;
    if(pos>in) return 0;
    if(dp[pos][wei] != -1) return dp[pos][wei];

        int ans=0;
            for(int i=pos; i<=in; i++)
            {
                if(wei>=arr[i]) ans = max(ans,call(i+1,wei-arr[i])+arr[i]);
            }//cout<<ans<<endl;
     return dp[pos][wei] = ans;
}

int main()
{
    int temp,sum;
    string line;

        scanf("%d", &n);

        cin.ignore();

            loop(i,n)
            {

                 getline(cin,line);
                 istringstream ss(line);

                    sum=0,in=0,temp;
                    memset(arr,0,sizeof(arr));
                    
                    while( ss>> temp )
                    {
                        arr[++in]=temp;
                        sum += arr[in];
                        //in++;
                    }//cout<<"sum : " << sum << endl;
                    if(sum%2 == 1) pf("NO\n");
                    else{
                            memset(dp,-1,sizeof(dp));
                            int ans=call(1,sum/2); //cout << " ans "<< ans <<".."<<endl;

                            if(ans == (sum/2)) pf("YES\n");
                            else pf("NO\n");
                    }
            }

    return 0;
}

/*
3
2
3
4
1
2
5
10
50
3
50
*/