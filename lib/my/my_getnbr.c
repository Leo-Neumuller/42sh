/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** return a number from a string
*/
#include "my.h"

static int concat_number(int a, int arr[], int negative)
{
    int final_int = 0;

    for (int e = 0; e < a; e++) {
        for (int s = 1; s < (a - e); s++) {
            arr[e] *= 10;
        }
        final_int += arr[e];
    }
    if (negative == 1 && final_int > 1) {
        final_int = final_int - (final_int * 2);
    }
    if (a > 10) {
        return 0;
    }
    return final_int;
}

static void check_str(char const *str, int *arr, int i, int *a)
{
    if (str[i] >= '0' && str[i] <= '9' && *a <= 10) {
        arr[*a] = (str[i] - 48);
        *a = *a + 1;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int a = 0;
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int negative = 2;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9' && negative == 2) {
            if (str[i - 1] == '-') {
                negative = 1;
            } else {
                negative = 0;
            }
        }
        check_str(str, arr, i, &a);
        if (arr[0] != 0 && !(str[i] >= '0' && str[i] <= '9')) {
            break;
        }
        i++;
    }
    return concat_number(a, arr, negative);
}
