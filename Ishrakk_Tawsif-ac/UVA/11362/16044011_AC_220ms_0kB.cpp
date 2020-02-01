#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;


struct node
{
    node *next[27];
    int endmark;

    node()
    {
        endmark = 0;
        for(int i=0; i<27; i++) next[i] = NULL;
    }
} * trie;

void Insert(string str)
{
    node *cur = trie;
    int len = str.length();

    for(int i=0; i<len; i++)
    {
        int now = str[i] - '0';//cout<<now<<endl;
        if(cur->next[now] == NULL) cur-> next[now] = new node();
        cur = cur->next[now];//cout<<"here\n";
    }
    cur->endmark = 1;
}

void del(node *cur)
{
    for(int i=0; i<27; i++)
    {
        if(cur-> next[i] != NULL) del(cur->next[i]);
    }
    delete(cur);
}

int check(string str)
{
    node *cur = trie;
    int len = str.length();

    for(int i=0; i<len; i++)
    {
        int now = str[i] - '0';
        if(cur->next[now] != NULL) cur = cur-> next[now];
        if(cur->endmark == 1 && i!=(len-1)) return 0;
    }
    return 1;
}

int main()
{
    int tc,n;
    string str[10005];

    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++)
    {
        scanf("%d", &n);

        trie = new node();

        for(int i=0; i<n; i++)
        {
            cin>> str[i];
            Insert(str[i]);
        }//cout<<"ok\n";

        int fl = 1;
        for(int i=0; i<n; i++)
        {
            fl &= check(str[i]);
        }

        //printf("Case %d: ", tt);
        fl? printf("YES\n") : printf("NO\n");

        del(trie);
    }

    return 0;
}