#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

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
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

map<string,int> mpp;

int main()
{
    string str;
    int n;

    sf(n);
    cin.ignore();
    for(int i=1; i<=n; i++)
    {//out("ok");
        //cin.ignore();

        getline(cin,str);//out(str);
        stringstream ss(str);

        int f1=0,f2=0;
        if ( str[0]=='m' && str[1]=='i' && str[2]=='a' && str[3]=='o' && str[4]=='.' )
        {
            f1 = 1;
        }
        int len = str.size();
        len--;

        if ( str[len]=='.'&&str[len-1]=='a'&&str[len-2]=='l'&&str[len-3]=='a'&&str[len-4]=='l' )
        {
            f2 = 1;
        }

        if (f1 == f2) cout << "OMG>.< I don't know!\n";
        else if (f1) cout << "Rainbow's\n";
        else cout << "Freda's\n";
    }
    return 0;
}