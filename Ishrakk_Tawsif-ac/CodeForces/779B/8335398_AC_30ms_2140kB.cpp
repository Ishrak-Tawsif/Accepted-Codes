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

#include<bits/stdc++.h>
using namespace std;

const int infinity=INT_MAX;

int main()
{
    
    string num;
    int k;

        while(cin>> num>> k)
        {
            int len=num.length(),zero=0,cnt=0;

                for(int i=len-1; i>=0; i--)
                {
                    if(zero==k) break;
                    if(num[i]=='0') zero++;
                    else cnt++;
                }
                if(zero == k) cout<<cnt<<endl;
                else cout<<len-1<<endl;
        }
    return 0;
}