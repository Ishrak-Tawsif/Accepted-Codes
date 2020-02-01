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



int main()
{
    string str;
    int tc;

    sf(tc);
    cin.ignore();
    while(tc--)
    {//cout<<tc<<endl;
        getline(cin,str);//cout<<str<<endl;
        int flag = 0;
        for(int i=1; i<str.size()-2; i++)
        {
            int fl=1;
            for(int j=i; j<str.size(); j+=i)
            {//if(i==20)cout<<i<<" " << j << " " << str[j] << endl;
                if(str[j] != ' '){fl=0; break;}
                else j++;
                if((j+i)>str.size()) {fl=0;break;}
            }
            if(fl){flag=1;break;}
        }
        (flag)? pf("YES\n") : pf("NO\n");
    }

    return 0;
}