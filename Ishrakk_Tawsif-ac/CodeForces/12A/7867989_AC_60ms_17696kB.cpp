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
   string str[5];

            while(cin>> str[0])
            {
                cin>> str[1]>> str[2];

                    if(str[0][0] == str[2][2] && str[1][0]==str[1][2] && str[2][0]==str[0][2] && str[2][1]==str[0][1])
                        pf("YES\n");
                    else pf("NO\n");
            }
   return 0;
}