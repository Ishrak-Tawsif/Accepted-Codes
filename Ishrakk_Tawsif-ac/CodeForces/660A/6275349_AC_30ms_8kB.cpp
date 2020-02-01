#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

    if(b == 0) return a;
    else gcd(b,a%b);
}

int main(){

    long numbers[1001];
    vector<long int>v;
    int n,count;

        while(scanf("%d", &n) != EOF){
            count=0;

            for(int i=0; i<n; i++)
                scanf("%ld", &numbers[i]);

                    for(int i=0; i<n-1; i++){

                        v.push_back(numbers[i]);

                          if(gcd(numbers[i],numbers[i+1])>1){
                                v.push_back(1);
                                count++;
                          }

                    }

                    v.push_back(numbers[n-1]);

                        printf("%d\n", count);
                        for(int i=0; i<v.size(); i++){
                            printf("%ld", v[i]);
                            if(i != v.size()-1) cout << " ";
                        }
                        printf("\n");
        }
return 0;
}

