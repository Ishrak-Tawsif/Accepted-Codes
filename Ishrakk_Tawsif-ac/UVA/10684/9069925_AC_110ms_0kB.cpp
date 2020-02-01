#include<bits/stdc++.h>
using namespace std;

#define sf(nn) scanf ("%d", &nn)
#define pf printf
#define loop(var,till) for(int var=0; var<till; var++)
#define loop1(var,till) for(int var=1; var<=till; var++)
#define pb push_back
#define mx 1003
#define ll long long int
#define mp make_pair
#define mod 1000000


int main()
{
    ll temp,n;

        while(cin>> n)
        {
            if(n == 0) break;

                ll sum=0,max_=LONG_MIN;
                loop(i,n)
                {

                    cin>> temp;
                    sum += temp;

                        if(sum>max_) max_ = sum;
                        if(sum<0) sum = 0;
                }
                if(sum>0) cout << "The maximum winning streak is " <<max_<<"."<<endl;
                else cout<< "Losing streak."  << endl;
        }
    return 0;
}