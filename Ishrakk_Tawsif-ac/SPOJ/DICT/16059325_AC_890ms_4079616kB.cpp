#include<iostream>
#include<bits/stdc++.h>
#include<malloc.h>
using namespace std;
#define WRITE(f)                freopen(f,"w",stdout)
string ss[25005];
unordered_map <string,int> vis;

struct node
{
    bool endpoint;
    node *next[27];
    int cnt;
    int list[25005];

    node()
    {
        endpoint = 0;
        for(int i=0; i<27; i++) next[i] = NULL;
    }
} *trie;

void Insert(string str,int ind)
{
    int len = str.length();

    node *cur = trie;

    for(int i=0; i<len; i++)
    {
        int now = str[i] - 'a';
        if(cur-> next[now] == NULL) cur-> next[now] = new node();
        cur = cur-> next[now];
        if(i != len-1)
        {
            cur-> cnt++;
            cur->list[cur->cnt] = ind;
        }
    }
    cur-> endpoint = 1;
}

void printans(string str)
{
    node *cur = trie;

    for(int i=0; i<str.length(); i++)
    {
        int now = str[i] - 'a';
        if(cur->next[now] == NULL)
        {
            printf("No match.\n");
            return;
        }
        else
        {
            cur = cur->next[now];
        }
    }//cout<<" ok "<<" "<<cur->cnt<<endl;;

    if(!cur->cnt)
    {
        printf("No match.\n");
        return;
    }

    multiset <string> st;
    for(int i=1; i<=cur->cnt; i++)
    {
        st.insert(ss[cur->list[i]]);
        //cout<< ss[cur->list[i]] <<endl;
    }

    for(auto x : st)
    {
        cout<<x<<endl;
    }
}

int main()
{//WRITE("in.txt");
    int n,q;
    string str;

    trie = new node();

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        cin>> ss[i];
        if(!vis[ss[i]])Insert(ss[i],i);
        vis[ss[i]] = 1;
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        cin>> str;
        printf("Case #%d:\n", i+1);
        printans(str);
    }

    return 0;
}