#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 1000005
#define ll long long int

vector <int> graph[mx];
vector <int> topsort;
int vis[mx],n,domino;

int arr[105],sum[105];


int main()
{
    int n,i,arr[1001],in,m,l,r,u,d;
    string str[53];

        while(sf(n) == 1)
        {
            sf(m);
            l=53,r=-1,u=53,d=-1;
                loop(n)
                {
                    cin>> str[i];
                    for(int j=0; j<m; j++){
                        if(str[i][j] == '*'){
                            if(j<l) l=j;
                            if(j>r) r=j;
                            if(i<u) u=i;
                            if(i>d) d=i;
                        }
                    }
                }//cout<<r<<" "<<l << " " <<u << " " << d << endl;

                for(int i=u; i<=d; i++)
                {
                    for(int j=l; j<=r; j++) cout<<str[i][j];
                    pf("\n");
                }
        }
   return 0;
}