#include <assert.h>
#include "int2str.h"
#include "stdio.h"
#include <string.h>

char * int2str(int number) {
    if (number == 0) return "0";
    else if (number == -2147483648) return "-2147483648"; 
    else if (number == 2147483647) return "2147483647";
    else {
        char str [12];
        int i = 0;
        int sign = (number >= 0 ? 1 : -1);
        number *= sign;
        while (number > 0){
            str[i++] = number % 10 + '0';
            number /= 10;
        }
        if (sign < 0) str[i++] = '-';
        str[i] = '\0';
        for (int j = 0, k = i - 1; j < k; j++, k--){
            char c = str[j];
            str[j] = str[k];
            str[k] = c;
        }
        char * const res = (char *)malloc(i*sizeof(char *));
        for (int m = 0; m <= i; m++){
            res[m] = str[m];
        }
        return res;
    }
}