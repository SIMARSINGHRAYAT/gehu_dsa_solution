#include <stdio.h>  

void TOH(int n, int a, int b, int c) {  
    if (n == 1) {  
        printf("%d -> %d\n", a, c);  
        return;  
    }  
    TOH(n - 1, a, c, b);  
    printf("%d -> %d\n", a, c);  
    TOH(n - 1, b, a, c);
}  

int main() {  
    int n = 3; 
    TOH(n, 1, 2, 3);  
    return 0;  
}