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


ll arr[200005];
vector <ll>vv[200005];

int main()
{
    /*pair<int,int> arr[23],ano[23];
    int n,temp;
        sf(n);

            loop(i,0,n)
            {
                sf(temp);
                arr[i]=mp(temp,i);
            }

            for(int i=0; ; i++)
            {
                int in = (n-i)-1,ii=i;
                if(in<=ii) break;

                for(int i=0; i<n; i++){ano[i].first=arr[i].first;ano[i].second=arr[i].second;}
cout<<ii<<" .... "<<in<<endl;system("pause");
                for(int j=in; j>=i; j--)
                {
                    ano[j]=arr[ii];ii++;
                }
                for(int i=0; i<n; i++){arr[i].first=ano[i].first;arr[i].second=ano[i].second;}
            }
            for(int i=0; i<n; i++)cout<<arr[i].first<<" " << arr[i].second<<endl;*/

            int n;

            sf(n);

                loop(i,0,n)
                {
                    scanf("%lld",&arr[i]);//cout<<arr[i]<<endl;
                }
                if(n==2)
                {
                    cout<<arr[1]<<" " << arr[0]<<endl;
                    return 0;
                }
                    if(n%2 != 0)
                    {
                        int st=n-1;
                        for(int i=0; i<n; i++)
                        {
                            if(i%2==0){cout<<arr[st];st-=2;}
                            else cout<<arr[i];
                            if(i!=n-1)cout<<" ";
                        }
                        cout<<endl;
                    }
                    else
                    {
                        int st=n-1,half=(n/2);
                        //(half%2==0)?half = half : half++;

                            for(int i=0; i<n; i++)
                            {
                                if(vv[i].size()==0 && i<half)
                                {//cout<<"\n............."<<i<<" "<<arr[i]<<endl;
                                    if(i%2==0){cout<<arr[st];vv[st].pb(i);st-=2;}
                                    else cout<<arr[i];
                                }
                                else
                                {
                                    if(i==half)
                                    {
                                        if(half%2!=0){cout<<arr[vv[i][0]];st--;}
                                        else{cout<<arr[i];st--;}
                                    }
                                    else
                                    {
                                        if(i%2!=0)cout<<arr[vv[i][0]];
                                        else {cout<<arr[i];}
                                    }
                                }
                                if(i!=n-1)cout<<" ";
                            }
                            cout<<endl;
                    }

}