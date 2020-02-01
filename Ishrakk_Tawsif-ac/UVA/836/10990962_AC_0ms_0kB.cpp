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
#define inf                     1e9
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

int ar[103][103],rr,cc;

void do_sum()
{
    for(int i=1; i<=rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            ar[i][j] += ar[i-1][j];
            ar[i][j] += ar[i][j-1];
            ar[i][j] -= ar[i-1][j-1];
        }
    }

    /*for(int i=1; i<rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            cout<<" "<<ar[i][j];
        }cout<<endl;
    }*/
}

int call()
{
    int ans = -inf,fl=0;

    for(int i=1; i<=rr; i++)
    {
        for(int j=1; j<=cc; j++)
        {
            for(int tempi = i; tempi<=rr; tempi ++)
            {
                for(int tempj=j; tempj<=cc; tempj++)
                {
                    int val = ar[tempi][tempj];//11cout<<val<<" ...... ";
                    val -= ar[tempi][j-1];
                    val -= ar[i-1][tempj];
                    val += ar[i-1][j-1];//cout<<val<<endl;
                    int area = ((abs(tempi-i))+1) * (abs(tempj-j)+1);


                    if(val == area)ans = max(ans,val); ///we will only update answer when all element in
                                                       ///in the are are 1.
                }
            }
        }
    }
    return ans;
}

int main()
{//WRITE("in.txt");
    int tc;

    sf(tc);

    string str;
    getline(cin,str);
    getline(cin,str);
    for(int tt=1; tt<=tc; tt++)
    {
        rr = 0;
        mem(ar,0);
        //cin.ignore();

        while(getline(cin,str) && str != "")
        {
            cc = str.size();
            rr++;

            for(int i=0; i<cc; i++)
            {
                int temp = (int) str[i] - '0';//cout<<temp<<endl;
                ar[rr][i+1] = temp;
            }
            //rr++;
        }
        do_sum();
        int res = call();

        if(res == -inf) res = 0;
        tt==tc? pf("%d\n", res) : pf("%d\n\n", res);
    }

    return 0;
}