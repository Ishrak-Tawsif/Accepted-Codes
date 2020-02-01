#include<bits/stdc++.h>
using namespace std;

pair<int,int>vv[10005];

int main()
{
    int gas,len,st,en;

    while(cin>>len>> gas)
    {
        if(!len && !gas) break;
        for(int i=0; i<gas; i++)
        {
            scanf("%d %d", &st,&en);
            vv[i] = (make_pair(st-en,st+en));
            //cout<<st-en<<" "<<st+en<<endl;
        }
        sort(vv,vv+gas);
        int s = 0,cnt=0,i=0;

        while(s<len)
        {
            int cur = s;

            while(i<gas && vv[i].first<=s)
            {
                cur = max(cur,vv[i++].second);
                //i++;
            }//cout<<s<<" .. "<<cur<<endl;
            if(s == cur) break;
            s = cur;
            cnt++;
        }//cout<<s<<endl;
        if(s<len) printf("-1\n");
        else printf("%d\n", gas-cnt);
    }
    return 0;
}