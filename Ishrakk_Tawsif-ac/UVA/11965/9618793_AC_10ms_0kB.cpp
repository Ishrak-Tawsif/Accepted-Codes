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
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

ll cake[1003],drink[1003];
string str;
string ans[53];

int main()
{
    int tc,n;

        sf(tc);

            loop(tt,1,tc+1)
            {
                sf(n);

                    cin.ignore();
                    loop(i,0,n)
                    {
                        getline(cin,str);
                        int len = str.length(),j=0;//cout<<str<<" " << len << endl;
                        ans[i]="";

                            if(str[0] == ' ') ans[i] += ' ';

                            while(str[j] == ' ' && j<len) j++;

                            for(j=j; j<len; j++)
                            {
                                /*if(str[j] == ' ')
                                {
                                    while(str[j] == ' ' && j<len) j++;
                                    ans[i] += ' ';
                                    j--;
                                }*/
                                if(str[j] != ' ') ans[i] += str[j];
                                else
                                {
                                    while(str[j] == ' ' && j<len) j++;
                                    ans[i] += ' ';
                                    j--;
                                }
                            }

                            //cout<<endl;
                    }
                    pf("Case %d:\n", tt);
                    for(int i=0; i<n; i++) cout<<ans[i]<<endl;

                    if(tt<tc) puts("");
            }

    return 0;
}