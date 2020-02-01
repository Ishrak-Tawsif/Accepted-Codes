#include<bits/stdc++.h>
using namespace std;


int main()
{

    long long int n;

        while(scanf("%lld", &n) == 1)
        {
            if(n<0) n*=-1;
            int temp=0,total=0;
                while(total<n || total%2 != n%2)
                {
                    temp++;
                    total += temp;
                }

                cout<< temp << endl;
        }
    return 0;    
}