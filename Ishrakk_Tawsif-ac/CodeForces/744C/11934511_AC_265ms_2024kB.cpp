#include<bits/stdc++.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

/*#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
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
#define inf                     2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      5000005
#define mod                     1000000007

template <typename T> inline T BigMod(T A,T B){T ret = 1;while(B){if(B & 1) ret = (ret * A)%mod;A = (A * A)%mod;B = B >> 1;}return ret;}
template <typename T> inline T InvMod (T A,T M = mod){return BigMod(A,M-2);}

string tostring(ll res){string curstr="";while(res!=0){ll temp=(res%10);curstr+=((char)temp+'0');res/=10;}reverse(curstr.begin(),curstr.end());return curstr;}
ll toint(string ss){ll inss = 0;for(int i=0;i<ss.size();i++){inss=(inss * 10)+((int)(ss[i]-'0'));}return inss;}


/* ...........................................................................................................*/

int order[16],temp[16],ans,n,red[16],blu[16];
char card[16];

double rand_real(){
    return (double)rand() / RAND_MAX;
}

int solve()
{
    int totcost = n,redcard = 0,blucard = 0,rd=0,bl=0;

    for(int j=0; j<n; j++)
    {
        int i= order[j];//cout<<i<<endl;
        int reqred = max(red[i]-redcard,0);
        int reqblu = max(blu[i]-blucard,0);

        int reqcard=0;
        //if(reqred>0 || reqblu>0)
        //{
            reqcard = max(max(reqred-rd,0),max(reqblu-bl,0));
        //}

        rd += reqcard;
        bl += reqcard;//out(reqcard);

        rd -= reqred;//cout<<reqred<<" "<<reqblu<<" "<<redcard<<" "<<blucard<<endl;
        bl -= reqblu;

        totcost += reqcard;

        if(card[i] == 'R') redcard++;
        else blucard++;

    }//out(totcost);system("pause");
    return totcost;
}

int main()
{
    int t, i, j, k, x, lim, res, cur, next;
    char str[17];
    while (scanf("%d", &n) != EOF){
        for (i = 0; i < n; i++){
            scanf("%s %d %d", str, &red[i], &blu[i]);
            card[i] = str[0];
        }
        for (i = 0; i < n; i++) order[i] = i;


        double temperature = 6666667;
        cur = res = solve(), lim = 666667;

        for (t = 0; t < lim; t++){
            for (i = 0; i < n; i++) temp[i] = order[i];

                int fs = rand() % n, sn = rand() % n,x;
                x = order[fs], order[fs] = order[sn], order[sn] = x;

            next = solve();
            if (next < res) res = next;

            if (next < cur) cur = next;
            else{
                double curtemp = exp((double)-(next - cur) / temperature);
                if (rand_real() <= curtemp) cur = next;
                else{
                    for (i = 0; i < n; i++) order[i] = temp[i];
                }
            }

            if (temperature > 1e-20) temperature *= 0.97;
        }

        printf("%d\n", res);
    }

    return 0;
}