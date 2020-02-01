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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())
#define mx                      100005
#define mod                     1000000007


int dx[8] = {1,-1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

unordered_map <string,int> cnt;

/*struct ST
{
    string s;
    int n;

        bool operator <(const ST &x)const
            return n>x.n;
};*/

int main()
{
    int po,en,fl;
    string temp;
    queue <string> pol,ene,com;

        scanf("%d %d", &po,&en);

            for(int i=0; i<po; i++)
            {
                cin>> temp;
                cnt[temp]++;
                pol.push(temp);
            }

            for(int i=0; i<en; i++)
            {
                cin>> temp;
                cnt[temp]++;
                if(cnt[temp] > 1)com.push(temp);
                else ene.push(temp);
            }

            int iswin,lastturn; ///lastturn 0 means polan
            (com.size()%2 == 1)? fl=1 : fl=0;
            (fl==0)? lastturn=1 : lastturn=0;
            //if(com.size() == 0) lastturn=1;
//cout<<lastturn<<endl;
            while(1)
            {
                if(lastturn == 0)
                {
                    if(ene.empty()){fl=1; break;}
                    else ene.pop(),lastturn=1;
                }
                else
                {
                    if(pol.empty()){fl=0;break;}
                    else
                    {//out("ok");
                        while(!pol.empty() && cnt[pol.front()] > 1 ) {pol.pop();}
                        if(pol.empty()) {fl=0;break;}
                        else pol.pop(),lastturn=0;
                    }
                }
            }
            (fl==1)? pf("YES\n") : pf("NO\n");
    return 0;
}