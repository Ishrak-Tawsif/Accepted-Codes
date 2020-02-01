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
#define ll                      unsigned long long int
#define mx                      1000005
#define mod                     1000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int vis[11][11];


ll ncr[53][53];
string ss1,ss2;
int k;

void find_var(string str)
{
    int len = str.length(),fl=0,temp;
    ss1 = "";
    ss2 = "";

    for(int i=1; ; i++)
    {
        if(str[i] == ')') {temp=i;break;}
        if(fl != 1)
        {
            if(str[i] == '+'){fl = 1;}
            else ss1 += str[i];
        }
        else ss2 += str[i];
    }
    int mul=1;
    k=0;
    for(int i=temp+1; i<len; i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            int tt = str[i];
            tt-=48;//cout<<tt<<endl;
            k = (k*mul) + (tt);
            mul *= 10;
        }
    }
}

void ncr_pre_gen()
{
    for(int i=0; i<53; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]);
        }
    }
}

int main()
{//WRITE("in.txt");
    ncr_pre_gen();

        int tc;

        sf(tc);
        string str;

            loop(tt,1,tc+1)
            {
                cin>> str;
                find_var(str);
                //int k=str[str.length()-1];
                //k-=48;
                //cout<<ss1 << " " << ss2 << " " << k << endl;
                int kk=k-1;

                pf("Case %d: ",tt);

                    if(k!=1)cout<<ss1<<"^"<<k;
                    else cout<<ss1;

                    for(int i=1; i<k; i++)
                    {
                        ll sohog = ncr[k][i];

                            //if(i==1 && kk!=1)cout<<"+"<<sohog<<ss1<<"^"<<kk<<"*"<<ss2;
                            //else cout<<"+"<<sohog<<ss1<<"^"<<kk<<"*"<<ss2<<"^"<<i;
                            cout<<"+"<<sohog<<"*"<<ss1;
                            if(kk!=1)cout<<"^"<<kk--;
                            cout<<"*"<<ss2;
                            if(i!=1) cout<<"^"<<i;
                    }
                    if(k!=1)cout<<"+"<<ss2<<"^"<<k<<endl;
                    else cout<<"+"<<ss2<<endl;
            }

    return 0;
}