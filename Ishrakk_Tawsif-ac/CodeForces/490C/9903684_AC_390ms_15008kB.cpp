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
#define intinf                  2e9
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())

int dirR[] = {0,0,-1,1,-1,-1,1,1};
int dirC[] = {-1,1,0,0,-1,1,-1,1};

vector <int> aa,bb;
string s;
int bbb[1000005];

int main()
{
    ll a,b;

    cin>> s;
    scanf("%lld %lld", &a,&b);
//cout<<"gwrweg"<<endl;
        ll rem = 0,mul=1;
            for(int i=0; i<s.length(); i++)
            {
                ll num = (ll) s[i];
                num -= 48;
                //if()
                num = (rem*10) + num;
                rem = num%a;
                if(rem == 0) aa.pb(i);
            }
//cout<<"grg"<<endl;
            rem=0;
            for(int i=s.length()-1; i>=0; i--)
            {
                ll num = (ll) s[i];
                num -= 48;//cout<<num<<endl;
                //if(num==0)continue;
                num = (rem + ((num*(mul)%b)%b))%b;//cout<<i<<" "<<num<<" "<<rem<<endl;system("pause");
                rem = num%b;
                if(rem == 0) {
                    bb.pb(i);
                    bbb[i] = 1;//cout<<i<<".........\n";
                }
                mul = ((mul%b) * 10)%b;
            }
//cout<<"gfwrfgrwg"<<endl;
            int fl=0,st;
            for(int i=0; i<aa.size(); i++)
            {//cout<<aa[i]<<".."<<endl;
                if(bbb[aa[i]+1] == 1 && s[aa[i]+1] != '0') {fl=1;st=aa[i];/*cout<<st<<"..."<<endl;*/break;}
            }

            if(fl == 1)
            {
                pf("YES\n");//cout<<st<<"/////////\n";
                for(int i=0; i<=st; i++) cout<<s[i]; cout<<endl;
                for(int i=st+1; i<s.length(); i++) cout<<s[i]; cout<<endl;
            }
            else pf("NO\n");

    return 0;
}