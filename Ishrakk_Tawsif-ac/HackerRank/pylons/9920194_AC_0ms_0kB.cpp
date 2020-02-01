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
#define mod                     100000007


int dr8[]={-1,-1,0,1,1,1,0,-1};
int dc8[]={0,1,1,1,0,-1,-1,-1};
vector <int> vv;



int main()
{
    int n,k,arr[100005],in=0,temp,cur=-1;


        sf(n);
        sf(k);

            for(int i=0; i<n; i++)
            {
                sf(temp);
                if(temp==1) cur=i;
                arr[i] = cur;
            }
//out("ok");
            //int pos = upper_bound(vv.begin(),vv.end(),2)-vv.begin();

            int cnt=0,fl=1;
            for(int i=0; i<n; )
            {
                //int pos = bs(0,vv.size()-1,min((i+(k-1)),n-1));//cout<<i+(k-1) << " "<<pos<<endl;
                //cout<<(min((i+(k-1)),n-1))<<" "<<pos<< " " <<i<<endl;
                int pos = arr[min((i+(k-1)),n-1)];//cout<<pos+k<<" " <<i<<endl;
                if(pos!=-1 && pos+k>i)
                {
                    cnt++;
                    i = pos+k;//cout<<vv[pos]<<" " <<i<<endl;
                }
                else{fl=0;break;}
            }

            //cout<<pos<<endl;
            (fl == 0)? pf("-1") : pf("%d\n",cnt);//}
    return 0;
}

/*
10 3
1 0 0 1 0 1 0 0 1 1 1

*/