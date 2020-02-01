#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
      ll n;
      int tc;
      cin>> tc;
           while(tc--)
           {
                 cin>>n;

                 if(n%2 == 0) cout<<__gcd(n,(n/2))<<endl;
                 else cout<<__gcd((n-1),(n-1)/2)<<endl;
           }
      return 0;
}