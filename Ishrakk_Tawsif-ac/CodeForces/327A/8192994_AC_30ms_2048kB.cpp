#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(till) for(int i=0; i<till; i++)
#define pb push_back
#define mx 10000025
#define ll long long int
#define mp make_pair
#define mod 1000005

/*
creating iterator to iterate a map ...
typedef std::map<string,int>::iterator it_type;
for(it_type iterator = fruits.begin(); iterator != fruits.end(); iterator++)
*/

int main()
{
    int n,max_=INT_MIN,cnt=0,temp;
        sf(n);
            int arr[n+1],ans[n+1];
            memset(ans,0,sizeof(ans));
            //memset(ans2.0,sizeof(ans2));

                for(int i=1; i<=n; i++) {
                    sf(arr[i]);
                    if(i==1){
                        if(arr[i]==1) ans[i]++;
                        else ans[i]=0;
                    }
                    else{
                        if(arr[i]==1) ans[i]=ans[i-1]+1;
                        else ans[i]=ans[i-1];
                    }
                }
                    for(int i=1; i<=n; i++)
                    {
                        for(int j=i; j<=n; j++){
                            int one=ans[j]-ans[i-1];//cout<<i<<" "<<j<<" "<<(j-i)+1<<endl;
                            int zero=((j-i)+1)-one;
                                //if(zero>0)
                                    zero += (ans[n]-one);//cout<<zero<<endl;
                                //else zero=ans[n]-one;
                                    if(max_<zero){
                                        max_=zero;//cout<<one<<" "<<(j-i)+1<<endl;
                                        //temp=ans[n-1]-one;
                                    }
                        }
                    }
                    //cout<<temp<<" "<<max_<<endl;
                    pf("%d\n",max_);
    return 0;
}