#include <stdio.h>

#define mx 200005

/*int comp(char a[],char b[],int sz){
   for(int i=0; i<sz; i++){
        if(a[i] != b[i]) return 0;
   }
   return 1;
}

int call(char a[],char b[],int sz){
//printf("sz: %d\n",sz);
    if(comp(a,b,sz)) return 1;
    if(sz%2) return 0;

    int cursz = sz / 2;
    char a1[cursz],a2[cursz],b1[cursz],b2[cursz];

    for(int i=0,j=0; i<sz; i++){
        if(i<cursz) a1[i] = a[i];
        else a2[j++] = a[i];
    }

    for(int i=0,j=0; i<sz; i++){
        if(i<cursz) b1[i] = b[i];
        else b2[j++] = b[i];
    }

    //for(int i=0; i<cursz; i++) printf("%c", a1[i]); printf("\n");
    //for(int i=0; i<cursz; i++) printf("%c", a2[i]); printf("\n");
    //for(int i=0; i<cursz; i++) printf("%c", b1[i]); printf("\n");
    //for(int i=0; i<cursz; i++) printf("%c", b2[i]); printf("\n");

    if((call(a1,b1,cursz)&&call(a2,b2,cursz)) || (call(a1,b2,cursz)&&call(a2,b1,cursz))) return 1;

    return 0;
}*/

char a[mx],b[mx];

int comp(int sta,int ena,int stb,int enb){
    for(int i=sta,j=stb; i<=ena; i++,j++) if(a[i] != b[j]) return 0;
    return 1;
}

int call(int sta,int ena,int stb,int enb,int sz){
    if(comp(sta,ena,stb,enb)) return 1;
    if(sz%2) return 0;

    int cursz = sz / 2,na = (sta+cursz)-1,nb = (stb + cursz)-1;
    /// for a -> 1. sta to (sta + cursz)-1, 2. (sta+cursz),ena
    if((call(sta,na,stb,nb,cursz) && call(na+1,ena,nb+1,enb,cursz))
       || (call(sta,na,nb+1,enb,cursz) && call(na+1,ena,stb,nb,cursz))) return 1;
    return 0;
}

int main(){

    //char a[mx],b[mx];
    int sz = 0;

    scanf("%s %s", &a,&b);

    for(int i=0; a[i]!='\0'; i++) sz ++;

    call(0,sz-1,0,sz-1,sz)? printf("YES\n") : printf("NO\n");

    return 0;

}