#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,cnt,temp;

        while(scanf("%d", &n) == 1)
        {

            cnt=0;
            for(int i=1; i<=5; i++)
            {
                scanf("%d", &temp);
                    if(temp == n) cnt++;
            }
            printf("%d\n", cnt);
        }
    return 0;
}