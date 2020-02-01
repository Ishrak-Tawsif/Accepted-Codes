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

ll n,totpil,mypos;

bool solve(ll mypil)
{
    ll right = n-mypos;
    ll left = mypos-1;
    ll totneed=mypil;
//cout<< " left " << left << " right " << right << endl;
    if(right == (mypil-1)) totneed += (mypil*(mypil-1))>>1;
    else if(right>(mypil-1))
    {
        totneed += (mypil*(mypil-1))>>1;
        totneed += (right-(mypil-1)>0)? (right-(mypil-1)) : 0;
    }
    else if(right != 0)
    {//cout<<" 1 " << totneed << endl;
        ll start = mypil -right ;
        ll endd  = mypil-1;//cout<<start <<  " " << endd << endl;
        start--;//cout<<start << " ???? " << endd << endl;
        ll temp;
        temp = ((endd*(endd+1))/2);//cout<<temp<<endl;
        temp = temp-(((start)*(start+1)/2));//cout<<(((start)*(start+1))/2)<<endl;
        if(temp!=-1)totneed += temp;//cout<<"temp ...... "<<temp<<endl;
    }
//cout<<" 2 " << totneed << endl;
    if(left == (mypil-1)) totneed += (mypil*(mypil-1))>>1;
    else if(left>(mypil-1))
    {
        totneed += ((mypil*(mypil-1))>>1);//cout<<((mypil*(mypil-1))>>1)<<"...\n";
        totneed += (left-(mypil-1)>0)? (left-(mypil-1)) : 0;//cout<<left-mypil<<"////\n";
    }
    else if(left != 0)
    {
        ll start = mypil - left;
        ll endd  = mypil-1;
        start--;
        ll temp;//cout<<start << " //// " << endd << endl;
        temp = ((endd*(endd+1))/2);//cout<< temp<<endl;
        temp = temp-(((start)*(start+1)/2));
        if(temp != -1)totneed += temp;//cout<<" temp " << temp << endl;
    }
//cout<<mypil << "  .............. " << totneed << endl;
//cout<<totneed-mypil<<endl;
    return (totneed<=totpil);
}

ll bsearch(ll s,ll e)
{
    ll mid,ans=-1;

        while(s<=e)
        {
            mid = (s+e)>>1;
            if(solve(mid))
            {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
    return ans;
}

int main()
{
    //cout<<(10>>1)<<endl;
    /*ll ans=0,ans1=0;
    ll x = 10000115,y=10000034;cout<<1000000000-((((y-1+y-80)*80)/2)+(((y-1+y-19)*19)/2))<<endl;
cout<<((x*(x+1))/(ll)2)-((y*(y+1))/(ll)2)<<endl;
    for(ll i=10000033; i>10000014; i--) ans += i;cout<<ans<<endl;
    for(ll i=10000033; i>9999953; i--) ans1 += i;cout<<ans1<<endl;
    cout<<1000000000-(ans+10000033+ans1)<<endl;*/


    scanf("%lld %lld %lld", &n,&totpil,&mypos);
    //cout<<solve(10000034);
    pf("%lld\n",bsearch(1,totpil));

    return 0;
}