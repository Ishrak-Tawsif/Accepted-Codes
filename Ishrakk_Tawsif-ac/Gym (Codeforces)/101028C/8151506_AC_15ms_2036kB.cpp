#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tc,len;

        scanf("%d", &tc);

            while(tc--)
            {
                scanf("%d", &len);
                char str1[len+1],str2[len+1];
                cin>>str1>>str2;

                    int fl=1,ans=1;

                        for(int i=0; i<len; i++)
                        {
                            if(str1[i]=='1' && str2[i]=='1')
                                ans = (ans*2)%1000000007;
                            else if(str1[i]=='1'&&str2[i]=='0')
                            {
                                fl=0;
                                break;
                            }
                        }
                        if(fl==1) cout<<ans<<endl;
                        else cout<<"IMPOSSIBLE"<<endl;
            }
    return 0;
}