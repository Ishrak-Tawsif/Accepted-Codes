#include<bits/stdc++.h>
using namespace std;


struct d{

    int num,divisor;

    bool operator < (const d & x) const{
        if(divisor == x.divisor) return num>x.num;
        return divisor<x.divisor;
    }
};


vector <d> order;

int count_div(int n){

    int count=0;
        if(n == 1) return 1;
        else{
            for(int i=1; i <= n; i++){

                if(n%i == 0) count ++;
            }
            return count;
        }

}

void pre_genarator(){



    for(int i=1; i<=1000; i++){

        d get;

        get.num=i;
        get.divisor=count_div(i);
        //cout << get.divisor << endl;
        order.push_back(get);
    }
}


int main(){
    pre_genarator();

    sort(order.begin(),order.end());

        int a,testcase;

            //for(int i=562; i<590; i++) cout << i << " " << order[i].num << " " << order[i].divisor << endl;
            scanf("%d", &testcase);
            for(int t=1; t<=testcase; t++){
                scanf("%d", &a);
                printf("Case %d: %d\n", t, order[a-1].num);
            }

return 0;
}
