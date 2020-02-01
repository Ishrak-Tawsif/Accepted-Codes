#include <iostream>
#include <stdio.h>

using namespace std;

char ch[100005][13];
int node[100005][13];
int root,curnode;
int isword[100005];

int fl;

void init()
{
    root = 0;
    curnode = 0;
    for(int i=0; i<13; i++) node[root][i] = -1;
}

void insert(int id)
{
    int len = 0;

    for(int i=0; i<11; i++)
    {
        if(ch[id][i] == '\0') break;
        len++;
    }


    int now = root;
    int isok = 1,curfl=1;

    for(int i=0; i<len; i++)
    {
        int cur = ch[id][i] - '0';

        if(node[now][cur] == -1)
        {
            node[now][cur] = ++curnode;
            for(int j=0; j<12; j++)
            {
                node[curnode][j] = -1;
            }
        }
        now = node[now][cur];
    }
    isword[now] = 1;
}

void dfs(int root,int cur,int tot,int len,int id)
{
    if(cur>=len)
    {
        for(int i=0; i<12; i++)
        {
            if(node[root][i] != -1) fl = 0;
        }
        return;
    }

    char c = ch[id][cur];
    int now = c - '0';


    int nxt = node[root][now];
    if(nxt == -1) return;
    dfs(nxt,cur+1,tot+1,len,id);
}

int main()
{//freopen("o.txt","w",stdout);
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        fl = 1;

        init();

        for(int i=0; i<n; i++)
        {
            scanf("%s", &ch[i]);
            insert(i);
        }

        int len = 0;
        fl = 1;
        for(int i=0; i<n; i++)
        {
            len = 0;
            for(int j=0; j<13; j++)
            {
                if(ch[i][j] == '\0') break;
                len ++;
            }
            int cc = ch[i][0] - '0';
            int cur = node[0][cc];
            dfs(0,0,0,len,i);
            if(!fl) break;
        }
        (!fl)? printf("NO\n") : printf("YES\n");
    }
    return 0;
}