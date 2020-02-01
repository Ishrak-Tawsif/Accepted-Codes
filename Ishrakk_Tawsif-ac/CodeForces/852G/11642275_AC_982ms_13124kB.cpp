#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case #%d: ",nn)
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
#define mx                      20000005
#define mod                     1000000007


int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};

string str;
int n,m;

set <string> st;
map<string,int> cnt;
int ans;

int backtrack(string s)
{
    if(st.find(s) != st.end()) return 0;
    st.insert(s);

    ans += cnt[s];

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '?')
        {
            for(int j=0; j<5; j++)
            {
                char ch = (char) ('a' + j);
                s[i] = ch;
                backtrack(s);
            }
            s.erase(s.begin()+i);
            backtrack(s);
        }
    }
}

int main()
{
    string str;
    int in,query;

    scanf("%d %d", &in,&query);

    for(int i=0; i<in; i++) cin>> str,cnt[str]++;

    while(query--)
    {
        cin>> str;
        ans = 0;
        st.clear();
        backtrack(str);

        printf("%d\n", ans);
    }
    return 0;
}