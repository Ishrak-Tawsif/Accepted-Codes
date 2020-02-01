#include<bits/stdc++.h>
using namespace std;
int main(){

    int day,bowl,plate,sum=0,temp;

        scanf("%d", &day);
        scanf("%d", &bowl);
        scanf("%d", &plate);

        int ans=0;
        int dish[day+3];
        for(int i=1;i<=day;i++)
        {
            scanf("%d",&dish[i]);
        }
        for(int i=1;i<=day;i++)
        {
            if(dish[i]==1)
            {
                if(bowl>0)
                {
                    bowl--;
                }
                else if(bowl==0)
                {
                    ans++;
                }
            }
            else if(dish[i]==2)
            {
                if(plate>0)
                {
                    plate--;
                }
                else if(bowl>0)
                {
                    bowl--;
                }
                else
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);

return 0;
}
