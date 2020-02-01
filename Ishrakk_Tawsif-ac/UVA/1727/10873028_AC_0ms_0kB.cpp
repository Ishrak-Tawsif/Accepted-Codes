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

string temp [] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
int num[] = {31,28,31,30,31, 30, 31, 31, 30,31, 30,31};
string temp2[] = {"SAT","SUN","MON","TUE","WED","THU","FRI"};

int main()
{
    int tc,n,ans,curd,curm;
    string mon,day;

    sf(tc);

    //cin.ignore();
    for(int tt=1; tt<=tc; tt++)
    {
        cin>> mon>> day;//cout<<"...\n";
        for(int i=0; i<12; i++) if(mon == temp[i]) {curm = i; break;}
        for(int i=0; i<7; i++) if(day == temp2[i]) {curd = i; break;}

        ans=0;//cout<<curm<<" " << curd << " " << num[curm] <<endl;
        for(int i=0; i<num[curm]; i++)
        {
            if(curd == 0 || curd == 6) ans++;
            if(curd == 6) curd = 0;
            else curd++;
        }

        pf("%d\n",ans);
    }
    return 0;
}