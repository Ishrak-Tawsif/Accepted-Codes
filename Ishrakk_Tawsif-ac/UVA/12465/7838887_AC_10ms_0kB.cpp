#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int a,b,temp,cnt,len;

        while(scanf("%ld %ld", &a,&b) == 2 && a && b)
        {
            cnt=0;
            temp=abs(a-b);
            len=sqrt(temp);
                for(int i=1; i<=len; i++)
                {//cout<<i<<endl;
                    if(temp%i == 0) cnt+=2;
                }
            if(len*len == temp) cnt--;
            printf("%ld\n",cnt);
        }

    return 0;
}