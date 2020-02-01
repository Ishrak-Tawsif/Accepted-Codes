#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1000005
#define ll long long int
#define mp make_pair
#define mod 100000007


int main()
{
    string str;
    int tc,arr[123],grid[37],in=0;
    //cout<<(int)'z'<<endl;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){ grid[++in]=i+j;}
    }sort(grid,grid+37);
    /*for(int i=0; i<36; i++){
        cout<<grid[i]<<" ";
        //cout<<endl;
    }*/
        sf(tc);
        cin.ignore();
            loop1(tt,tc)
            {
                //cout<<tt<<endl;
                getline(cin,str);
                int len=str.length();
                memset(arr,0,sizeof(arr));

                    loop(i,len){
                        int temp=(int)str[i];
                        if(temp!=32)arr[temp]++;//cout<<str[i]<<" "<<temp<<" "<<arr[temp]<<endl;
                    }
                    sort(arr,arr+123);
                    int ans=0;
                    in=0;
                    for(int i=0,k=122; i<len; i++,k--) {
                        ans += arr[k]*grid[i];
                        //cout<<arr[k]<<" "<<grid[i]<<" "<<ans<<endl;
                    }

                    cout<<ans<<endl;
            }
    return 0;
}