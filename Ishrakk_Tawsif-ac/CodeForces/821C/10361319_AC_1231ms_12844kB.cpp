#include<bits/stdc++.h>
using namespace std;

#define sf(nn)                  scanf ("%d", &nn)
#define sfll(nn)                scanf ("%lld", &nn)
#define pf                      printf
#define casepf(nn)              printf ("Case %d: ",nn)
#define out(nn)                 cout <<nn <<endl
#define loop(var,start,till)    for(int var=start; var<=till; var++)
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


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};

stack <int> st;
set<int>ss;
int main()
{
    int n,till,min_,cnt=0,temp,fl=0,lastadded=-1;
    string str;

        sf(n);
        till = 2*n;
        min_ = intinf;

            for(int i=0; i<till; i++)
            {
                cin>> str;

                if(str == "add")
                {
                    sf(temp);
                    if(temp<=min_ || min_ == intinf)
                    {
                        min_ = temp;
                        ss.insert(temp);
                        min_ = *ss.begin();
                        //lastadded = temp;
                        st.push(temp);
                    }
                    else
                    {
                        //cnt++;
                        fl=1;
                        ss.insert(temp);
                        min_ = *ss.begin();
                        //lastadded = temp;
                        st.push(temp);
                    }
                }
                else
                {
                    if(fl == 1 && st.top() != (*ss.begin())) {cnt++; fl=0;}
                    else if(st.top() == (*ss.begin()))
                    {
                        st.pop();
                    }
                    ss.erase(*ss.begin());
                    if(ss.empty())min_ = intinf;
                    else
                    {//cout<<*ss.begin()<<endl;
                        min_ = *ss.begin();
                    }
                }
            }
            pf("%d\n", cnt);
    return 0;
}