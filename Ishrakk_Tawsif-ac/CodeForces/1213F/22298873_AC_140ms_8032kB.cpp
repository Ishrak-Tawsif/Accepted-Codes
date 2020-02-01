#include<bits/stdc++.h>
using namespace std;

struct node{
	int st, en, val,start_kar;

	bool operator <(const node & x) const{
        if(x.st == st) return en<x.en;
        else return st<x.st;
	}
};
node ar[200005],finalar[200005];
int a[200005],b[200005];
char ch[] = "abcdefghijklmnopqrstuvwxyz";
char res[200005];

int main()
{
	int n, k;

	scanf("%d %d", &n,&k);

	int val;
	node get;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		a[i] = val;
		get.val = val;
		get.st = i;
		//get.start_kar = 1;
		ar[val] = get;
	}

    for(int i=1; i<=n; i++){
        scanf("%d", &val);
        b[i] = val;
        get.val = val;
        if(i<ar[val].st){
            get.en = ar[val].st;
            get.st = i;
            //get.start_kar = 2;
        }
        else get = ar[val],get.en = i;
        ar[val] = get;
        //cout<<val<<" ok "<<ar[val].st<<" "<<ar[val].en<<endl;
    }
    sort(ar,ar+n+1);

//    for(int i=1; i<=n; i++){
//        cout<<ar[i].st<<" "<<ar[i].en<<endl;
//    }

    int curst = ar[1].st,curen = ar[1].en,ind = 1;
    for(int i=2; i<=n; i++){
        if(curen<ar[i].st){
            get.st = curst;
            get.en = curen;
            finalar[ind++] = get;
            curst = ar[i].st;
            curen = ar[i].en;
        }
        else {
            if(curen<ar[i].en) curen = ar[i].en;
        }//cout<<curst<<" ... "<<curen<<endl;
    }
    finalar[ind].st = curst;
    finalar[ind++].en = curen;

    int pos = 0,ps = 0;
    set <int> st;
    sort(finalar,finalar+ind);
    for(int i=1; i<ind; i++){
        curst = finalar[i].st;
        curen = finalar[i].en;//cout<<curst<<" ... "<<curen<<endl;
//        for(int j=curst; j<=curen; j++) {st.insert(a[j]);}
//        while(!st.empty()){
//            int now = *st.begin(); st.erase(st.begin());
//            res[now] = ch[pos];
//        }
//        pos ++;
        for(int i=curst; i<=curen; i++)
        {
            res[a[i]] = ch[pos];
        }
        pos = min(pos+1,25);
        ps++;
    }
//printf("pos: %d\n", pos);
///
    if(ind>=(k+1)){
        printf("YES\n");
        for(int i=1; i<=n; i++) cout<<res[i];
        printf("\n");
    }
    else{
        printf("NO\n");
    }
	return 0;
}	  			     			  	  	  		 	