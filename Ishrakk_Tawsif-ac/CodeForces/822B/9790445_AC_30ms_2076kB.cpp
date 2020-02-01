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
#define mx                      5005
#define mod                     100000007
#define intinf                  2100000000
#define llinf                   2e18
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)
#define Unique(a)               sort(all(a)),a.erase(unique(all(a)),a.end())


int main()
{

    queue<int>q,qq;
    int temp,len1,len2;
    string s,ss;

        scanf("%d %d", &len1,&len2);
        cin>> s>> ss;
            for(int i=0; i<len1; i++)
            {
                if(s[i] != ss[i]) q.push(i);
            }
//cout<<q.size()<<endl;
            qq=q;
            int st=1;
            for(int i=1; i<len2; i++)
            {
                queue<int>qqq;
                if(i+len1>len2) break;
                int k=0;
                for(int j=i; j<len1+i; j++)
                {//cout<<j<<" "<<k<<endl;
                    if(s[k] != ss[j]) {qqq.push(k);/*cout<<i<<" .... "<<s[k]<<" "<<ss[j]<<endl;*/}
                    k++;
                }
                if(qq.size()>qqq.size())qq=qqq;
            }
            pf("%d\n",qq.size());
            if(qq.size()!=0){pf("%d",qq.front()+1); qq.pop();}
            while(!qq.empty())
            {
                pf(" %d",qq.front()+1); qq.pop();
            }
                pf("\n");
    return 0;
}