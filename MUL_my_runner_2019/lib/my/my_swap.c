/*
** EPITECH PROJECT, 2019
** MY_SWAP
** File description:
** swaps the value of two integers
*/

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}