#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct node
{
    ll val;
    node *next;
    node *pre;

    node(ll v)
    {
        val = v;
        next = NULL;
        pre = NULL;
    }
};

node *root = NULL;
node *tail = root;
//int sz;

struct myqueue
{
    int sz = 0;
    void pushfront(ll val)
    {
        sz ++;//cout<<sz<<endl;
        node *newnode = new node(val);
        if(root == NULL)
        {//cout<<"root == tail\n";
            root = newnode;
            tail = root;
            return;
        }
//cout<<"root != tail\n";
        newnode->next = root;
        root->pre = newnode; ///newly added
        /*if(tail->pre == NULL)
        {
            tail->pre = newnode;//cout<<"tail-Pre == NULL\n";
        }*/
        root = newnode;
    }

    void popfront()
    {
        sz--;
        root = root->next;
        if(root == NULL) tail = NULL;
        else root->pre = NULL;
    }

    void popback()
    {
        sz--;
        tail = tail->pre;
        if(tail == NULL) root = NULL;
        else tail->next = NULL;
    }

    int getsize()
    {
        return sz;
    }

    ll getfront()
    {
        return root->val;
    }

    ll getback()
    {
        return tail->val;
    }

    bool isempty()
    {
        return (sz == 0);
    }
};

myqueue q;
map <ll,ll> vis;

int main()
{
    int n,k,v;

    scanf("%d %d", &n,&k);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &v);//cout<<"v: "<<v<<endl;
        if(vis[v]) continue;
        if(q.sz>=k)
        {
            int now = q.getback();//cout<<"///\n";
            vis[now] = 0;
            q.popback();//cout<<"....\n";
        }
        q.pushfront(v);//cout<<"here\n";
        vis[v] = 1;
    }

    printf("%d\n", q.sz);

    int fl = 0;
    while(!q.isempty())
    {
        int now = q.getfront();
        if(!fl) printf("%d", now), fl = 1;
        else printf(" %d", now);

        q.popfront();
    }

    return 0;

}