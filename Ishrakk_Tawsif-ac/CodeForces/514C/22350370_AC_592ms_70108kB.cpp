#include <bits/stdc++.h>
using namespace std;

#define mx 4000005

int node[mx][3],root,nnode,sz;
bitset <mx> isend;
char ch[mx];

void init(){
    root = 0;
    nnode = 0;
    for(int i=0; i<3; i++){
        node[root][i] = -1;
    }
}

void _insert(){//cout<<"in insert ch: "<<ch<<endl;
    int now = root;
    for(int i=0; ch[i] != '\0'; i++){
        int cur = ch[i] - 'a';//printf("%d............\n", cur);
        if(node[now][cur] == -1){
            node[now][cur] = ++nnode;
            for(int j=0; j<3; j++){
                node[nnode][j] = -1;
            }
        }
        now = node[now][cur];
    }
    isend[now] = 1;//printf("nnode: %d\n",nnode);
}

int _search(int cur,int pos,int cnt){//printf("pos: %d %d %d\n",pos,cur,cnt);
    //if(cnt>1) return 0;
    if(cnt>1) return 0;
    if(pos>=sz) {//printf("%d %d\n", cnt,isend[cur]);
        int fl = ((cnt == 1) && (isend[cur]));
        return fl;
    }

    int now = ch[pos] - 'a',res = 0;
    if(node[cur][now] != -1){//cout<<"here: "<<cur<<" "<<now<<endl;
        res = _search(node[cur][now],pos+1,cnt);
    }
    if(res) return res;
    //else if(cnt == 0){//*///cout<<pos<<" .. "<<cur->curch<<" "<<now<<endl;
        //now =
        //cout<<"vitore pos: "<<pos<<endl;
        //int res = 0;
        //if(res) return res;
        //cout<<"else\n "<<cur<<endl;;
        for(int i=0; i<3; i++) {
            if(node[cur][i] != -1){
                if(i == now) continue;
                int newcur = node[cur][i];
                if(cnt == 0)res |= _search(newcur,pos+1,cnt+1);
                if(res) return res;
                //if(res) return res;
                    /*for(int j=0; j<3; j++){
                            if(newcur->next[j] != NULL)
                            {//cout<<"calling: "<<pos<<" "<<newcur->next[j]->curch<<" "<<ch[pos+1]<<endl;;
                                return _search(ch,newcur->next[j],pos+1,cnt+1);
                            }
                    }*/
            }
        }
        //return res;
    //}
    return res;
}

int main(){

    int n,m;

    scanf("%d %d", &n,&m);
    //char ch[300005];

    init();

    //trie = new node();
    //cin.ignore();
    for(int i=0; i<n; i++){
        scanf("%s", &ch);//cout<<i<<" ?????? "<<ch<<endl;
        _insert();
    }

    //cin.ignore();
    for(int i=0; i<m; i++){
        scanf("%s", &ch);//cout<<i<<" >??????? "<<ch<<endl;

        sz = 0; for(int i=0; ch[i] != '\0'; i++) sz ++;
        //sz = strlen(sz);

        int fl = _search(root,0,0);
        //cout<<"fl "<<fl<<endl;
        fl? printf("YES\n") : printf("NO\n");
        //cin.ignore();
    }
//cout<<"out\n";
    //del(trie);

    return 0;

}