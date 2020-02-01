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


//map <string,pair<int,int>> mp;
string ss[53];
//queue <string> q;
//deque <char> dq;

int main()
{
    int n,sobai=0;
        sf(n);

            loop(i,0,n) cin>> ss[i];

                int ans=intinf;
                for(int i=0; i<n; i++)
                {
                    int len = ss[i].length(),temp=0,cnt=0,temp2=(-1*intinf);

                        for(int j=0; j<n; j++)
                        {
                            if(len!=ss[j].length()){temp=(-1*intinf);break;}

                            //string ss = s[j];
//cout<<j<<endl;
                            queue<char>q,tempq;

                                        if(ss[i] == ss[j]){ cnt++;if(cnt == n) {temp2=max(temp2,temp);sobai=1;}continue;}

                                        for(int k=0; k<ss[j].length(); k++)q.push(ss[j][k]);

                                        for(int k=0; k<ss[j].length(); k++)
                                        {
                                            char str = q.front();
                                            q.pop();
                                            q.push(str);
                                            tempq = q;

                                                int in=0,ispos=1;
                                                while(!q.empty() && in<len)
                                                {
                                                    char cur = q.front(); q.pop();//cout<<cur;
                                                    if(ss[i][in++] != cur) ispos = 0;
                                                }//cout<<ispos<<"\n ........ \n";
                                            if(ispos) {cnt++;temp+=k+1;break;}
                                            q=tempq;
                                        }//cout<<i<<" "<<temp<<endl;
                                if(cnt == n) {temp2=max(temp2,temp);sobai=1;}
                        }

                        if(temp2 != (-1*intinf))ans = min(ans,temp2);
                }
                if(sobai == 0) pf("-1\n");
                //else if(ans==intinf) pf("0\n");
                else pf("%d\n", ans);
    return 0;
}