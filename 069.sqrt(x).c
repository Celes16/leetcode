#include <stdio.h>

//other resolutions have declare long than int because using long you can avoid overflow 32 bits. the storage is bigger in long (64bits), but in this problem you have:
//0 <= x <= 231 - 1 (32 bits)
int mySqrt (int x) {
    if ( x== 0 || x == 1) {
    return x; 
    }
    int left = 1, right = x, result = 0;

    while (left <= right){
        int mid = left + (right - left) / 2;

        //evitar overflow ao verificar mid* mid <= x

        if (mid <= x / mid) { // se mid² <= x
            result = mid;
            left = mid + 1; 
        } else{
            right = mid -1;
        }
    }
    return result;
}

int main () {
    int x;
    printf (" digite um numero não negativo:");
    scanf ("%d", &x);

    if(x < 0) {
        printf("numero negativo, não é possivel calcular \n");
        return 1;
    }

    printf("a raiz quadrada inteira de %d é: %d\n", x, mySqrt(x));
    return 0;
}