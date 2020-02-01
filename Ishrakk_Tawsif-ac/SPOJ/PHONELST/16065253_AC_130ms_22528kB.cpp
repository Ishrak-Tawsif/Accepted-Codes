#include<iostream>
#include<bits/stdc++.h>
#include<malloc.h>
using namespace std;
#define WRITE(f)                freopen(f,"w",stdout)

string str;

struct node
{
    bool endpoint;
    int cnt;
    node *next[11];

    node()
    {
        endpoint = 0;
        cnt = 0;
        for(int i=0; i<11; i++) next[i] = NULL;
    }
}*trie;

int Insert(string str)
{
    node *cur = trie;
    int len = str.length();

    for(int i=0; i<len; i++)
    {
        int now = str[i] - '0';//cout<<now<<endl;
        if(cur->next[now] == NULL) cur->next[now] = new node();
        cur = cur->next[now];
        cur->cnt++;
        if(cur->endpoint && cur->cnt>1) return 0;
    }
    if(cur->cnt>1) return 0;
    cur->endpoint = 1;
    return 1;
}

void del(node *cur)
{
    for(int i=0; i<11; i++) if(cur->next[i] != NULL) del(cur->next[i]);
    delete(cur);
}

int main()
{
    int tc,n;

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d",&n);

        trie = new node();

        int fl = 1;
        for(int i=1; i<=n; i++)
        {
            cin>> str;
            fl &= Insert(str);
            //if(!fl) cout<<i<<endl;
        }
        fl? printf("YES\n") : printf("NO\n");
        del(trie);
    }

    return 0;
}