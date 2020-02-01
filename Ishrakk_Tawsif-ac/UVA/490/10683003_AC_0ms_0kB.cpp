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

int track[153];
string str[103];

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    //cout<<calc(150)<<".."<<endl; system("pause");

    int ind = -1,cnt=-1;

    while(getline(cin,str[++ind]));
//for(int i=0; i<=ind; i++) cout<<str[i]<<endl;
//cout<<ind << " " << str[0].length() << " " << str[1].length() << endl;
//cout<<str[1][9]<<str[0][9]<<endl;
    int in = -1;

    while(1)
    {
        ++in;
        for(int i=ind-1; i>=0; i--)
        {
            if(in<str[i].length())cout<<str[i][in];
            else {
                //cout<<" ";
                if(!track[i]) cnt++,track[i]=1;
                if(cnt != (ind-1)) cout<<" ";
            }
        }
        if(cnt == (ind-1)) {break;}
        pf("\n");
    }

    return 0;
}