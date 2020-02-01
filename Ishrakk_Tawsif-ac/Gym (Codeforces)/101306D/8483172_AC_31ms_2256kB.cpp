#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
string grid[21];
vector <pair<int,int> >vv,cc;

int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};

/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

struct order
{
    int s,e;

        bool operator < (const order &x) const
        {
            //if(s == x.s) return e<x.e;
            //else
                return s>x.e;
        }
};

vector <order> ord;

char low[]={"abcdefghijklmnopqrstuvwxyz"};
char m_low[]={"PgEfTYaWGHjDAmxQqFLRpCJBow"};
char m_up[]= {"nyUKZXkbvzIdshurMilNSVOtec"};

int main()
{
    //cout<<'Z'-'A'<<endl;
    /*int arr[101];
    memset(arr,0,sizeof(arr));
    for(int i=0; i<26; i++)
    {
        arr[m_low[i]-'A']++;
        arr[m_up[i]-'A']++;
    }
     for(int i=0; i<60; i++){
        if(arr[i]==0) cout<<i<<endl;
        if(arr[i]>1) cout<<i<<endl;
     }*/


     int n;
        sf(n);
        string s;
        loop1(tt,n)
        {
            cin>> s;
                for(int i=0; i<s.length(); i++)
                {
                    if(isupper(s[i]))cout<<m_up[s[i]-'A'];
                    else cout<<m_low[s[i]-'a'];
                }
                if(tt==n)cout<<endl;
                else cout<<" ";
        }
    return 0;
}