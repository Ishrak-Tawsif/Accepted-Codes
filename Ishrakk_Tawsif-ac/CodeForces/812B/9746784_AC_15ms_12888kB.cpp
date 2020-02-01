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

int arr[17][107],sum[17],dp[17][105][1550],n,m,total=0,ii;


int call(int pos,int type,int cur)
{//cout<<pos<<" "<<cur<<" " <<type <<endl;
//cout<<dp[pos][type][cur]<<endl;
    //if(tot > total) return 0;
    if(pos<0) return 0;
//cout<<dp[pos][type][cur]<<endl;
    if(dp[pos][type][cur] != -1) return dp[pos][type][cur];

        int ans1=intinf,ans2=intinf,cnt=0,i,temp=0,ccnnt,ans=0,lastone;
//cout<<type<<endl;
            if(type == 0)
            {
                cnt=0;
                ccnnt=-1;
                temp=0;
                for(i=0; i<m+2; i++)
                {
                    ccnnt++;//cout << pos <<sum[pos] << " ............ " << ccnnt << endl;
                    if(arr[pos][i] == 1) {
                            ans+=i-type+cur;
                            //ans += cur;
                            cur=0;
                            type=i; ///lastone
                    }
                    //cnt += arr[pos][i];
                    //if(cnt == sum[pos]) {/*ans+=temp;*/break;}//cout<<0<<endl;
                }//cout<<pos << " " << type << " " << temp << endl;

            }
            else
            {
                cnt=0;
                ccnnt=-1;
                temp=0;
                for(int i=m+1; i>=0; i--)
                {
                    ccnnt++;
                    if(arr[pos][i] == 1) {
                        ans += type-i+cur;
                        //ans += cur;
                        cur=0;
                        type=i; ///lastone
                    }
                    //cnt += arr[pos][i];//cout<<1<<endl;
                    //if(cnt == sum[pos]) {/*ans+=temp;*/break;}
                }

            }

        ans += min(call(pos-1,0,cur+type+1),call(pos-1,m+1,cur+m+2-type));
        //if(ans == -1)cout<<pos<<" " << m << " " <<type << " " << " " << cur << endl;
       /*if(cnt == 0)
       {
           ans1 = call(pos-1,0,cur+temp+1)+temp;//cout<<pos<<" " <<temp <<" "<<type<<" "<<ans1<<" " << ans2<<endl;
           ans2 = call(pos-1,m+1,cur+m+2-temp)+temp;
       }
       else{
           ans1 = call(pos-1,0,temp+1)+temp+cur;//cout<<pos<<" " <<temp <<" "<<type<<" "<<ans1<<" " << ans2<<endl;
           ans2 = call(pos-1,m+1,m+2-temp)+temp+cur;
       }*/


    return dp[pos][type][cur] = ans;
}

int main()
{
    //int m;
        scanf("%d %d", &n,&m);

            string s;

            loop(i,0,n)
            {//cout<<i<<endl;
                cin>> s;
                    for(int j=0; j<m+2; j++)
                    {
                        int temp = s[j];
                        temp -= 48;
                        arr[i][j] = temp;//cout<<arr[i][j];
                    }//cout<<i<<"\n";
            }
//cout<<"okkkkkkkkkkkkkkkkkkkkkkkkk\n";
            loop(i,0,n){
                loop(j,0,m+2) {/*sf(arr[i][j]);*/ (j==0)? sum[i] = arr[i][j] : sum[i] = sum[i]+arr[i][j];}
                total += sum[i];
                }//cout<<total<<endl;
//for(int i=0; i<n; i++) cout<<sum[i]<<endl;
            //ii=0;
            //while(sum[ii] == 0) ii++;
            memset(dp,-1,sizeof(dp));//cout<<ii<<endl;
            cout<<call(n-1,0,0)<<endl;
            //cout<<call(ii,1)<<endl;
    return 0;
}

/*
3 4
0 0 1 0 0 0
0 0 0 0 1 0
0 0 0 0 1 0

4 3
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0

2 2
0 0 1 0
0 1 0 0

3 2
0000
0100
0100

5 93

00000000000000000000000000000000000000000000000000000000100000000000000000000000000000000001010

00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

00000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

00000000000000000000000000000010000000000000000000100000000000000000000000000000000000000000000

00000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000


2 21
00100110100010010010010
01000001111001010000000

*/