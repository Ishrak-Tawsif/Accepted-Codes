#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

int res;
string str[50005];

struct node
{
    int endmark,koyta;
    node *next[5];

    node()
    {
        endmark = 0;
        koyta = 0;
        for(int i=0; i<2; i++) next[i] = NULL;
    }
} *trie;

int getid(char ch)
{
    if(ch == '0') return 0;
    return 1;
}

void Insert(string str)
{
    node *cur = trie;
    int len = str.length();

    for(int i=0; i<len; i++)
    {//cout<<i<<endl;
        int now = getid(str[i]);//cout<<now<<endl;
        if(cur-> next[now] == NULL) cur-> next[now] = new node();//cout<<i<<endl;
        cur = cur->next[now];
        cur->koyta ++;
    }
    cur->endmark = 1;
}

void del(node *cur)
{
    for(int i=0; i<=1; i++) if(cur-> next[i] != NULL) del(cur-> next[i]);
    delete(cur);
}

void dfs(node *cur,int dis)
{
    res = max(res,cur->koyta*dis);

    for(int i=0; i<=1; i++) if(cur->next[i] != NULL) dfs(cur->next[i],dis+1);
}

int main()
{
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);
        trie = new node();
        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            Insert(str[i]);
        }
        res = 0;
        dfs(trie,0);
        printf("%d\n", res);
        del(trie);
    }

    return 0;
}