#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define mx 100005
#define ll long long int

char dicch[mx],proceceddicch[mx];
char chh[mx];
int isend[mx]; ///should be int not bool

int getchval(char c){
    int now;
    if(c>='a' && c<='z'){
        now = c - 'a';
    }
    else {
        now = c - 'A';
        now += 26;
    }
    return now;
}

int root,nnode,node[mx][52];

void init(){
    root = 0;
    nnode = 0;

    for(int i=0; i<mx; i++) isend[i] = 0;

    for(int i = 0; i<52; i++){
        node[root][i] = -1;
    }
}

void _insert(){
    int now = root;

    for(int i=0; proceceddicch[i] != '\0'; i++){
        int cur = getchval(proceceddicch[i]);
        if(node[now][cur] == -1){
            node[now][cur] = ++nnode;
            for(int j=0; j<52; j++) node[nnode][j] = -1;
        }
        now = node[now][cur];
    }
    isend[now] ++;//cout<<"in insert: "<<now<<" "<<isend[now]<<endl;
}

void process_insert(){
    //char nowch[105];
    int cnt[105],sz = 0;
    for(int i=0; i<105; i++) cnt[i] = 0;
    for(int i=0; dicch[i] != '\0'; i++){
        if(i == 0 || dicch[i+1] == '\0') continue;
        int curval = getchval(dicch[i]); //cout<<i<<" "<<dicch[i]<<" ||| "<<curval<<endl;
        sz++;
        cnt[curval] ++;
        //cout<<dicch[i];
    }//cout<<"sz: "<<sz<<endl;
    proceceddicch[0] = dicch[0];
    proceceddicch[sz+1] = dicch[sz+1];
    proceceddicch[sz+2] = '\0';
    int ind = 1;
    for(int i=0; i<52; i++){
        if(cnt[i]){//cout<<i<<" "<<cnt[i]<<endl;
            while(cnt[i]){
                cnt[i] --;
                if(i<26)proceceddicch[ind++] = ((i + 'a'));
                else proceceddicch[ind++] = ((i-26) + 'A');
            }
        }
    }
    //_insert();
    //printf(".....\n");
    //cout<<dicch<<" "<<proceceddicch<<endl<<endl;
    //for(int i=0; i<sz; i++) printf("%c", proceceddicch[i]);
    //printf("\n......\n\n");
}

ll _search(int cur,int pos){//cout<<proceceddicch[pos]<<endl;
    if(proceceddicch[pos] == '\0')
    {
        //cout<<"\n.... "<<cur<<" "<<proceceddicch[pos]<<" "<<isend[cur]<<endl;
        return isend[cur];
    }

    int now = getchval(proceceddicch[pos]);//cout<<proceceddicch[pos];
    if(node[cur][now] != -1) return _search(node[cur][now],pos+1);
    else return 0;
}

void getinput(){

    char ch;
    int ind = 0;
    while(scanf("%c", &ch)){
        chh[ind++] = ch;
        chh[ind] = '\0'; //cout<<"chh "<<chh<<endl;
        if(ch == '\n') {break;}
    }

    //cout<<"here "<<chh<<endl;
}

int main(){
    //freopen("out_new.txt","w",stdout);
    int tc,n,m;
//char ccc; while(cin>> ccc) cout<<getchval(ccc)<<endl;
    scanf("%d", &tc);

    for(int tt=1; tt<=tc; tt++){
        init();
        printf("Case %d:\n", tt);
        scanf("%d", &n);

        for(int i=1; i<=n; i++){
            scanf("%s", &dicch); //cout<<i<<" "<<dicch<<endl;
            process_insert();
            _insert();
        }

        scanf("%d", &m);
//out<<"  hereeee ..................\n";

        if(!n && !m){
            printf("0\n");
            continue;
        }

        getchar();

        ll res = 1;
        for(int i=1; i<=m; i++){
            res = 1;

            getinput(); //cout<<i<<" "<<chh<<endl;
            //gets(chh);
            int ind = 0;
            //for(int i=0; i<105; i++) dicch[i] = '\0';
            while(chh[ind] != '\0'){
                int curind = 0,fl = 0;
                while(isalpha(chh[ind])){
                    dicch[curind++] = chh[ind++];
                    dicch[curind] = '\0';//cout<<dicch<<endl;
                    fl = 1;
                }
                //dicch[curind] = '\0';
                if(fl){
                    process_insert();
                    //cout<<dicch<<" "<<proceceddicch<<endl;
                    res *= _search(0,0); //printf("res: %lld\n", res);
                }
                ind++;
            }
            //system("pause");
            printf("%lld\n",res);
        }
    }
//system("pause");
    return 0;
    
}


/*
1
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
*/