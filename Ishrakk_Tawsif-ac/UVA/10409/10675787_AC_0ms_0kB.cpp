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

int t=1,b=6,n=2,s=5,w=3,e=4;
string str;

void north()
{//out("n");
    int temp = b;
    b = n;
    n = t;
    t = s;
    s = temp;
}

void south()
{//out("s");
    int temp = b;
    b = s;
    s = t;
    t = n;
    n = temp;
}

void east()
{//out("e");
    int temp = b;
    b = e;
    e = t;
    t = w;
    w = temp;
}

void west()
{//out("w");
    int temp = b;
    b = w;
    w = t;
    t = e;
    e = temp;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int tc;

    while(sf(tc) && tc)
    {
        t=1,b=6,n=2,s=5,w=3,e=4;
        while(tc--)
        {
            cin>> str;

            if(str == "north") north();
            else if(str == "south") south();
            else if(str == "east") east();
            else west();//cout<<t <<" " << b << " " << n << " " << s << " " << e << " " << w << endl;
        }
        pf("%d\n", t);
    }

    return 0;
}