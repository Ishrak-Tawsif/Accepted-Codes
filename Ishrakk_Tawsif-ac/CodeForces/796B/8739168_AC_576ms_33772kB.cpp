#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 100005
#define ll long long int
#define mp make_pair
#define mod 100000007

int dir_r_8[]={-1,-1,-1,0,0,1,1,1};
int dir_c_8[]={-1,0,1,-1,1,-1,0,1};
int dir_r_4[]={-1,1,0,0};
int dir_c_4[]={0,0,-1,1};

unordered_map <int,int>track;
int arr[1000005];

int main()
{
    int n,m,k,temp,u;

        while(scanf("%d %d %d", &n,&m,&k) == 3)
        {

            //track.clear();

            loop(i,m)
            {
                sf(temp);
                track[temp]=1;
            }

            int ans=1,fl=0;
            arr[1]=1;

            if(track[1] == 1) {fl=1; ans=1;}

            loop(i,k)
            {
                sf(temp); sf(u);

                if(arr[temp]==1 || arr[u]==1){

                    if(arr[temp]==1) {arr[temp]=0; arr[u]=1;}
                    else if(arr[u]==1) {arr[u]=0; arr[temp]=1;}
//cout <<u << " "<<track[u]<<" " <<fl << " " << arr[u] << endl;
                    if(track[temp] == 1 && fl==0 && arr[temp]==1) {ans=temp; fl=1;}
                    else if(track[u] == 1 && fl==0 && arr[u]==1){ans=u; fl=1;}
                    else if(fl==0 && arr[temp]==1) ans = temp;
                    else if(fl==0 && arr[u]==1) ans = u;
                }
            }
            pf("%d\n",ans);
        }
}