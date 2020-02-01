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
#define intinf                  7e18
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

vector <int> lc,nin;

string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int tc,n,s,d,ans;
    string str;
    char ch1,ch2;

    sf(tc);

    cin.ignore();
    for(int tt=1; tt<=tc; tt++)
    {
        cin>> str;
        sf(n);
//cout<<str<<endl;
        string cur = temp;//cout<<cur<<endl;
        cin.ignore();
        for(int i=0; i<n; i++)
        {
            cin>> ch1>> ch2;//cout<<ch1<<" " << ch2 << " " << i <<endl;
            for(int j=0; j<cur.size(); j++)
            {
                if(cur[j] == ch2) cur[j] = ch1;
            }
        }//cout<<cur<<endl;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]>='A' && str[i]<='Z'){int pos = str[i] - 'A';cout<< cur[pos] ;}
            else cout<<str[i];
        }
        pf("\n");
    }

    return 0;
}