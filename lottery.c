#include <stdio.h>
#include<math.h>
/* TODO:
 * count number of '1' bit in an integer
 * @param x : integer to be counted
 * @return number of '1' in x
 */

int getOneNum(int x) {
    int count=0;
    int A[32]={0};
    int n=0;
    while((x/2)!=0){
        A[n]=x%2;
        x/=2;
        n++;
    }
    A[n]=1;
    for(int i=0;i<32;i++){
        if(A[i]==1){
            count++;
        }
    }
    //printf("%d\n",count);
    /*if(x==1){
        count++;
        return 0;
    }
    if(x%2==1){
        count++;
    }
    getOneNum(x/2);*/
    return count;
}
/* TODO:
 * cost to buy numbers in B
 * @param B : bit vector of bought numbers
 * @return (number of ones in B)^2
 */
int cost(int B) {
    int sum;
    sum=pow(getOneNum(B),2);
    return sum;
}
/* TODO:
 * calulate money win from ordinary prize
 * @param B : bit vector of bought numbers
 * @param O : bit vector of ordinary set
 * @return money win from ordinary prize
 */
int ordinary(int B, int O) {
    int win=0;
    int P[32]={0};
    int Q[32]={0};
    int n=0;
    while((B/2)!=0){
        P[n]=B%2;
        B/=2;
        n++;
    }
    P[n]=1;
    /*for(int i=31;i>=0;i--){
        printf("%d",P[i]);
    }
    printf("\n");*/
    n=0;
    while((O/2)!=0){
        Q[n]=O%2;
        O/=2;
        n++;
    }
    Q[n]=1;
    for(int i=0;i<32;i++){
        if(P[i]==Q[i] && P[i]==1){
            win++;
        }
    }
    //printf("%d\n",win);
    /*for(int i=31;i>=0;i--){
        printf("%d",Q[i]);
    }
    printf("\n");*/
    return pow(win,3);
}
/* TODO:
 * calulate money win from special prize
 * @param B : bit vector of bought numbers
 * @param S : bit vector of special set
 * @param sp : money for special prize
 * @return money win from special prize
 */
int special(int B, int S, int sp) {
    /*int win=0;
    int P[32]={0};
    int Q[32]={0};
    int n=0;
    int B1=B;
    while((B/2)!=0){
        P[n]=B%2;
        B/=2;
        n++;
    }
    P[n]=1;*/
    /*for(int i=31;i>=0;i--){
        printf("%d",P[i]);
    }
    printf("\n");*/
    /*n=0;
    while((S/2)!=0){
        Q[n]=S%2;
        S/=2;
        n++;
    }
    Q[n]=1;
    for(int i=0;i<32;i++){
        if(P[i]==Q[i] && P[i]==1){
            win++;
        }
    }
    /*for(int i=31;i>=0;i--){
        printf("%d",Q[i]);
    }
    printf("\n");*/
   // printf("%d\n",getOneNum(B1));*/
    /*if(win==getOneNum(B1)){
        return sp;
    }else{
        return 0;
    }*/
    if(B==S){
        return sp;
    }else{
        return 0;
    }
}
int main() {
    int D, B, O, S, sp;
    scanf("%d", &D);
    while(D--) {
        scanf("%d %d %d %d",&B, &O, &S, &sp);
        //printf("%d\n",B);
        //printf("%d %d %d %d\n",getOneNum(B),cost(B),ordinary(B,O),special(B,S,sp));
        int sum=ordinary(B,O)+special(B,S,sp)-cost(B);
        printf("%d\n",sum);
        // TODO
        // calculate money win in a day and output
    }
    //printf("%d",getOneNum(B));
    //ordinary(10,11);
    return 0;
}

