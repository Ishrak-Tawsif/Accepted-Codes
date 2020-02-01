#include <bits/stdc++.h>
using namespace std;

struct st{
    string curstr;

    bool operator <(const st & x){
        if(curstr.length() == x.curstr.length()) return curstr < x.curstr;
        else return curstr.length()<x.curstr.length();
    }
};

st ch[50005];

struct node{
    int endmark;
    node *next[26];

    node(){
        endmark = 0;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

int getVal(char ch){
    int now = (ch-'a');
    return now;
}

int check(node *root,int ind,int pos){//cout<<ind<<" "<<pos<<endl;
    node *cur = root;
    for(int i=pos; i<ch[ind].curstr.length(); i++){
        int now = getVal(ch[ind].curstr[i]);//cout<<"check: "<<ind<<" "<<ch[ind].curstr[i]<<endl;
        if(cur->next[now] != NULL) cur = cur->next[now];
        else return 0;
    }
    if(cur->endmark) return 1;
}

int _insert(node *root,int ind){
    node *cur = root;
    int fl = 0;
    for(int i=0; i<ch[ind].curstr.length(); i++){
        int now = getVal(ch[ind].curstr[i]);//cout<<ind<<" "<<"now "<<now<<endl;
        if(cur->next[now] == NULL){//cout<<ind<<" "<<ch[ind].curstr[i]<<" NULL\n";
            cur->next[now] = new node();
        }
        cur = cur->next[now];
        if(cur->endmark){
            fl |= check(root,ind,i+1);
        }
    }
    cur->endmark = 1;//cout<<"fl: "<<fl<<endl;
    return fl;
}

int main(){
    int n = 0;
    string str;
    node *root = new node();
    while(cin>> str){
        ch[n++].curstr = str;
    }
    sort(ch, ch+n);//for(int i=0; i<n; i++) cout<<"   "<<ch[i].curstr<<endl;

    vector <string> vv;
    for(int i=0; i<n; i++){
        if(_insert(root,i)) vv.push_back(ch[i].curstr);
    }

    sort(vv.begin(),vv.end());

    for(int i=0; i<vv.size(); i++) cout<<vv[i]<<endl;

    return 0;

}

/*

a
ahat
hat
hatword
hziee
word
*/