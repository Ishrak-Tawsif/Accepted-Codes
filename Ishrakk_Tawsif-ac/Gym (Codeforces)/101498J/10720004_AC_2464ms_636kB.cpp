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

int ar[100005];

int main()
{
    int tc,a,b;

    sf(tc);
    string str;
    cin.ignore();
    while(tc--)
    {
        getline(cin,str);
        //cout<<str.length()<<endl;
        int fl=0;
        for(int i=0; i<str.length(); i++)
        {
            int flag = 1;

                for(int j=i; j<str.length(); j+=i)
                {//if(i==18)cout<<j<<" "<<str[j]<<endl;
                    if(str[j] != ' ') {flag = 0;/*cout<<str[j]<<"....\n";*/ break;}
                    else j++;
                    if(str.length() == j) break;//if(i==19)cout<<"... "<<j<<endl;;
                    if(j+i>str.length()){flag=0;break;}
                }
            if(flag){fl=1;/*cout<<i<<endl;*/break;}
        }
        (fl)? pf("YES\n") : pf("NO\n");
    }
    return 0;
}