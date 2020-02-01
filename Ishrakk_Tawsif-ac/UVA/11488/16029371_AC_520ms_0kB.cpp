#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

char ch[50005][203];
int node[203][2];//cnt[100005];
int root,curnode;
int res;
map <int,int> cnt;

int fl;

void init()
{
    root = 0;
    curnode = 0;
    for(int i=0; i<2; i++) node[root][i] = -1;
}

void insert(int id)
{
    int len = 0;

    for(int i=0; i<203; i++)
    {
        if(ch[id][i] == '\0') break;
        len++;
    }


    int now = root;
    int isok = 1,curfl=1;
//cout<<" len "<<len<<endl;
    for(int i=0; i<len; i++)
    {
        int cur = ch[id][i] - '0';//cout<<cur<<endl;

        if(node[now][cur] == -1)
        {
            node[now][cur] = ++curnode;
            for(int j=0; j<2; j++)
            {
                node[curnode][j] = -1;
            }
        }
        now = node[now][cur];//cout<<cur<<" "<<now<<endl;
        cnt[now] ++;
    }
    //isword[now] = 1;
}

void dfs(int cur,int tot)
{

    res = max(res,tot * cnt[cur]);//cout<<tot<<" "<<cnt[cur]<<endl;

    int now = node[cur][0];
    if(now != -1) dfs(now,tot+1);
    now = node[cur][1];
    if(now != -1) dfs(now,tot+1);
}

int main()
{//freopen("o.txt","w",stdout);
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        cnt.clear();

        fl = 1;

        init();

        for(int i=0; i<n; i++)
        {
            scanf("%s", &ch[i]);
            insert(i);
        }

        int len = 0;
        fl = 1;
        res = 0;

        int now = node[0][0];
        if(now != -1)dfs(now,1);
        now = node[0][1];
        if(now != -1) dfs(now,1);

        printf("%d\n", res);

//        for(int i=0; i<n; i++)
//        {
//            len = 0;
//            for(int j=0; j<13; j++)
//            {
//                if(ch[i][j] == '\0') break;
//                len ++;
//            }
//            int cc = ch[i][0] - '0';
//            int cur = node[0][cc];
//            dfs(0,0,0,len,i);
//            if(!fl) break;
//        }
//        (!fl)? printf("NO\n") : printf("YES\n");
    }
    return 0;
}