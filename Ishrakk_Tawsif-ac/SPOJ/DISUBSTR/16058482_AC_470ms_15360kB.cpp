#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include<bits/stdc++.h>
#define fast                    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

unordered_map <int,long long int> cnt;
long long int res;

struct node
{
    int endmark;
    node *next[63];

    node()
    {
        endmark = 0;
        for(int i=0; i<53; i++) next[i] = NULL;
    }
} *trie;

int getid(char ch)
{
        int id;
        if(ch>='a' && ch<='z') id = ch - 'a';
        else  id = ch - 'A' + 26;
        return id;
      //return (int)ch;
}

void Insert(node *cur,string str)
{
    int len = str.length();

    for(int i=0; i<len; i++)
    {
        int now = getid(str[i]);
        if(cur->next[now] == NULL)
        {
            cur ->next[now] = new node();
            res++;
        }
        cur = cur-> next[now];
    }
}

void del(node *cur)
{
    for(int i=0; i<53; i++) if(cur->next[i] != NULL) del(cur->next[i]);
    delete(cur);
}

//string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{//for(int i=0; i<alpha.length(); i++) cout<<alpha[i]<<" "<<getid(alpha[i])<<endl;

    fast;

    int tc;
    string str;

    cin>> tc;

    for(int tt=1; tt<=tc; tt++)
    {
        str.clear();
        cin>> str;

        trie = new node();

        res = 0;

        for(int i=0; i<str.length(); i++)
        {
            string temp = str.substr(i);//cout<<temp<<endl;
            Insert(trie,temp);
        }
        //dfs(trie,0);

        //for(int i=1; i<=str.length(); i++) if(cnt[i]) res += cnt[i],cnt[i] = 0;
        //cnt.clear();

        cout<<res<<endl;

        del(trie);
    }
    return 0;
}