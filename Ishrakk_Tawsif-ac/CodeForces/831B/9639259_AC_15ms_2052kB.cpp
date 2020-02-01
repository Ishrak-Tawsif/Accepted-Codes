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


int main()
{
    string s1,s2,s3,ans="";

        cin>> s1>> s2>> s3;

            int len= s3.length();
            map<char,char> mp;
            for(int i=0; i<s1.length(); i++) mp[s1[i]] = s2[i];

                for(int i=0; i<len; i++)
                {
                    char ch = s3[i];

                        if(isalpha(ch))
                        {
                            if(ch>='A' && ch<='Z')
                            {
                                ch = tolower(ch);
                                ch = mp[ch];
                                ch = toupper(ch);
                                ans += ch;
                            }
                            else
                            {
                                ch = mp[ch];
                                ans += ch;
                            }

                        }
                        else ans += ch;
                }
                cout<<ans<<endl;
    return 0;
}