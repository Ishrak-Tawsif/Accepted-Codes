#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d:\n",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<till; var++)
#define pb                      push_back
#define mem(a,b)                memset(a,b,sizeof(a))
#define mp                      make_pair
#define ll                      long long int
#define inf                     2e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

ll track[2000005],ar[2005],ar2[2005],n;

string str[11];

int main()
{//WRITE("in.txt");

    str[0] = "O-|-OOOO";
    str[1] = "O-|O-OOO";
    str[2] = "O-|OO-OO";
    str[3] = "O-|OOO-O";
    str[4] = "O-|OOOO-";
    str[5] = "-O|-OOOO";
    str[6] = "-O|O-OOO";
    str[7] = "-O|OO-OO";
    str[8] = "-O|OOO-O";
    str[9] = "-O|OOOO-";

    string temp;

    while(cin>> temp)
    {
        int len = temp.size();

        for(int i=len-1; i>=0; i--)
        {
            int ind = (int)  temp[i]-'0';//cout<<ind<<endl;
            cout<<str[ind]<<endl;
        }
    }

    return 0;
}