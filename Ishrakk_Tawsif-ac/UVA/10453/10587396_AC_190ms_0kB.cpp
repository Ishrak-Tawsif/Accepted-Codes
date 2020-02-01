#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

int dirr[] = {-1,-1,0,0,1,1};
int dirc[] = {0,1,-1,1,-1,0};

int n,k,ispos=0,dp[1003][1003];
string str;

int call(int i,int j)
{
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(str[i] == str[j]) return dp[i][j] = call(i+1,j-1);

    int ans1 = intinf,ans2=intinf;

    ans1 = 1+call(i+1,j);
    ans2 = 1+call(i,j-1);

    return dp[i][j] = min(ans1,ans2);
}
string temp = "";
void printsolu(int i,int j)
{
    if(i>j) return;
    if(i==j) {pf("%c", str[i]); /*temp += str[i];*/ return;}

    if(str[i] == str[j])
    {
        pf("%c", str[i]);
        //temp += str[i];
        printsolu(i+1,j-1);
        pf("%c", str[j]);
        //temp += str[j];
    }
    else if(call(i+1,j)<call(i,j-1))
    {
        pf("%c", str[i]);
        //temp += str[i];
        printsolu(i+1,j);
        pf("%c", str[i]);
        //temp += str[i];
    }
    else
    {
        pf("%c", str[j]);
        //temp += str[j];
        printsolu(i,j-1);
        pf("%c", str[j]);
        //temp += str[j];
    }
}

void check()
{
    int fl=1;

    int i=0,j=temp.length()-1;

    while(i<j)
    {
        if(temp[i] != temp[j]) {for(int k=0; ;k++){cout<<temp[i]<<" problem "<<temp[j]<<endl;system("pause");}}
        i++,j--;
    }
}

int main()
{//WRITE("in.txt");
    int tc,tt=0;

    //sf(tc);

    while(cin>> str)
    {
        //cin>> str;
        mem(dp,-1);
        for(int i = 0; i < str.length()-1; i++) {
            dp[i][i] = 1;
        }
        //casepf(++tt);
        pf("%d ", call(0,str.length()-1));temp = "";
        printsolu(0,str.length()-1); pf("\n");//cout<<temp<<"///"<<endl;
        //check();
    }

    return 0;
}