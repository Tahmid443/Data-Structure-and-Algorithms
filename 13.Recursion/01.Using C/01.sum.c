#include <stdio.h>
int sum(int a){
    if(a == 0) return 0;
    return a+sum(a-1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d ", sum(n));
    return 0;
}