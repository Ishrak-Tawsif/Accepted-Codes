#include <stdio.h>

#define base 100001
#define mod 1000000007
#define ll long long int

char ch[100005];
int sz;

ll HP[100005],HS[100005],pow[100005];

void init(){
    pow[0] = 1;
    for(int i=1; i<100005; i++) {
        pow[i] = (pow[i-1]%mod * base%mod) % mod;
        pow[i] %= mod;
    }
}

int getVal(char ch){
    if(ch>='a' && ch<='z') return ((ch-'a')+1);
    else return ((ch-'A') + 27);
}

void computeHashPre(){
    HP[0] = getVal(ch[0]);
    for(int i=1; i<=sz; i++){
        HP[i] = ((HP[i-1] * base)%mod + getVal(ch[i])) % mod;
    }
}

void computeHashSuf(){
    HS[sz] = getVal(ch[sz]);
    for(int i=sz-1; i>=0; i--){
        HS[i] = ((HS[i+1] * base)%mod + getVal(ch[i])) % mod;
    }
}

ll getValPre(int l,int r){
    if(!l) return HP[r];

    ll res = (HP[r] - ((HP[l-1] * pow[r-l+1])%mod)) % mod;
    res = (res + mod) % mod;

    return res%mod;
}

ll getValSuf(int l,int r){
    if(r == sz) return HS[l];

    ll res  = HS[l] - ((HS[r+1] * pow[r-l+1])%mod);
    res = (res + mod) % mod;

    return res%mod;
}

int main(){

    init();
    while(scanf("%s", &ch) && ch[0] != '\0'){

        sz = 0;
        for(int i=0; ch[i] != '\0'; i++) sz++;
        sz--;
        int last = 0;
        computeHashPre();
        computeHashSuf();
        for(int i=0; i<=sz; i++){//printf("%d\n", i);
            ll pre = getValPre(i,sz)%mod;
            ll suf = getValSuf(i,sz)%mod;//printf("%lld %lld last: %d\n", pre,suf,last);
            if(pre == suf){
                last = i;
                break;
            }
        }
        printf("%s", ch);
        for(int i=last-1; i>=0; i--) printf("%c", ch[i]);
        printf("\n");
        ch[0] = '\0';
    }

    return 0;
}