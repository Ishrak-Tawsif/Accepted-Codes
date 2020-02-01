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

int track[153],temp[153];

int calc(int num)
{
    int ans;
    for(int i=1; ; i++)
    {//cout<<i<<" .......... "<<endl;
        mem(track,0);
        track[1] = 1;
        int cnt = 0,cur=2,last = 1,cnt2=0;
        while(1)
        {//cout<<cur<<" " << cnt <<endl;
            if(track[cur] == 0) {cnt++,cur++;}
            else cur++;//cout<<cur;//cout<<" "<<cnt<<" '''' \n";system("pause");
            if(cnt == i) track[cur-1]=1,last=cur-1,cnt=0,cnt2++;
            if(cur == (num+1)) cur = 1;
            if(cnt2 == (num-1)) break;
        }//cout<<last <<endl;
        if(last == 2) {ans=i; break;}
    }
    return ans;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<calc(150)<<".."<<endl; system("pause");
    int ans[153];
    for(int i=3; i<=150; i++)
    {
       ans[i] = calc(i);//cout<<ans<<endl;
    }

    int n;
    while(sf(n) && n)
    {
        pf("%d\n", ans[n]);
    }
    return 0;
}