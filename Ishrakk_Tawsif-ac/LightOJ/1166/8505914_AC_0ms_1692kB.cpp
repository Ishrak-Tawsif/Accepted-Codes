#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 2503
#define ll long long int
#define mp make_pair
#define mod 100000007

//int row,col,r,c,cost[21][21],dis[21][21],vis[21][21],dp[21][1<<21],len;
string grid[21];
vector <pair<int,int> >vv,cc;

int dir_r[]={-1,-1,-1,0,0,1,1,1};
int dir_c[]={-1,0,1,-1,1,-1,0,1};

/*int time_needed()
{
    double end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<cpu_time_used<<endl;
}*/

/*struct order
{
    int s,e;

        bool operator < (const order &x) const
        {
            //if(s == x.s) return e<x.e;
            //else
                return e<x.e;
        }
};*/

int arr[1005],k,n;

bool ispossible(int max_min)
{
    int day=k,dis=n,camp=0,cur=0;

        while(1)
        {
            if(camp>n) break;
            cur=0;
                while(camp<=n && cur+arr[camp]<=max_min)
                {
                    //if(day == dis) return true;
                    cur+=arr[camp];
                    camp++;
                    dis--;
                }
            day--;
        }//cout<<day<<" "<<dis<<" "<<camp<<endl;
    if(day >= 0 && camp>n) return true;
    return false;
}

int binary_search(int low,int high)
{
    int mid=(low+high)/2,ans=0;

        while(low<=high)
        {
            mid=(low+high)/2;
            //cout << mid << " .. " << endl;
            if(ispossible(mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;//cout<<low<<" "<<high<<endl;
        }
    return ans;
}

void print_answer(int ans)
{
   int day=k,dis=n,camp=0,cur=0;

        while(1)
        {
            if(camp>n) break;
            cur=0;

                while(camp<=n && cur+arr[camp]<=ans)
                {
                    if(day == dis)
                    {
                        pf("%d\n", cur+arr[camp++]);
                        while(camp<=n)
                        {
                            pf("%d\n",arr[camp++]);
                        }
                        return;
                    }
                    cur+=arr[camp];
                    camp++;
                    dis--;
                }
            day--;
            pf("%d\n", cur);
        }
}

int main()
{
    int tc,max_,sum,arr2[103],cnt,arr3[103];

        sf(tc);

            loop1(tt,tc)
            {
                sf(n);
                cnt=0;

                    loop1(i,n) {sf(arr[i]); arr2[arr[i]]=i;}
                    //for(int i=1; i<=n; i++) cout<<arr2[i]<<endl;
                        for(int i=1; i<=n; i++)
                        {
                            if(arr[i]!= i)
                            {
                                cnt++;
                               
                                swap(arr[i],arr[arr2[i]]);
                                swap(arr2[arr[i]],arr2[arr[arr2[i]]]);

                            }
                        }
                        
                       
                        pf("Case %d: %d\n",tt,cnt);
            }
    return 0;
}