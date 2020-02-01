#include <stdio.h>
using namespace std;

struct node{
    int endmark;
    int curch;
    node *next[3];
    node(){
        endmark = 0;
        for(int i=0; i<3;i++){
            next[i] = NULL;
        }
    }
} *trie;

char ch[600005];
int sz;

void _insert(){
    node *cur = trie;

    for(int i=0; ch[i] != '\0'; i++){
        int now = ch[i] - 'a';
        if(cur->next[now] == NULL){
            cur->next[now] = new node();
        }
        cur = cur->next[now];
        cur->curch = now;
    }
    //cout<<"endmarking :"<<cur->curch<<endl;
    cur->endmark = 1;
}

int _search(node *cur,int pos,int cnt){//printf("pos: %d\n", pos);
    if(cnt>1) return 0;
    if(cur == NULL) return 0;
    if(pos>=sz) {//cout<<cnt<<" ?? "<<cur->endmark<<endl;
        int fl = ((cnt == 1) && (cur->endmark));
        return fl;
    }

    int now = ch[pos] - 'a';
    int res = 0;
    if(cur->next[now] != NULL){//printf("%d vitore\n",now);
        res = _search(cur->next[now],pos+1,cnt);
    }

    if(res) return res;

        for(int i=0; i<3; i++) {
            if(i == now) continue;
            if(cur->next[i] != NULL){

                res |= _search(cur->next[i],pos+1,cnt+1);
                if(res) return res;
            }
        }
        return res;
    //}
}

void del(node *cur){
    if(cur == NULL) return;
    for(int i=0; i<3; i++) del(cur->next[i]);
    delete(cur);
}

int main(){

    int n,m;

    scanf("%d %d", &n,&m);

    trie = new node();
    //cin.ignore();
    for(int i=0; i<n; i++){
        scanf("%s", &ch);
        _insert();
    }

    //cin.ignore();
    for(int i=0; i<m; i++){
        scanf("%s", &ch);

        sz = 0;
        for(int i=0; ch[i] != '\0'; i++) sz ++;

        int fl = _search(trie,0,0);
        fl? printf("YES\n") : printf("NO\n");
    }

    return 0;
}