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
#define intinf                  1e9
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

string str;

int check(int ind,int len)
{
    int ar[3];
    mem(ar,0);//cout<<ind<<".....\n";
    if(ind+2>=len) return 0;
    for(int i=0; i<=2; i++)
    {   //cout<<str[i]<<endl;
        if(str[ind+i] == 'R') ar[0] = 1;
        else if(str[ind+i] == 'B') ar[1] = 1;
        else if(str[ind+i] == 'L') ar[2] = 1;
    }//cout<<ar[0]<<" " << ar[1] << " " << ar[2] <<endl;
    if(ar[0] == 1 && ar[1] == 1 && ar[2] == 1) return 1;
    else return 0;
}

int main()
{
    //string str;

    cin>> str;
    int len = str.length();

    for(int i=0; i<len; )
    {
        if(check(i,len)) cout<< 'C', i+=3;
        else if(str[i] == 'R') cout << 'S',i++;
        else if(str[i] == 'B') cout << 'K',i++;
        else if(str[i] == 'L') cout << 'H',i++;
    }
    return 0;
}