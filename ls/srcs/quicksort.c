#include <stdio.h>

void    ft_swap(void *a, void *b)
{
    void *tmp;

    tmp = a;
    a = b;
    b = tmp;
}

int                ft_partitiontwo(char **tab, int left, int right, int f(), char *path)
{
    int pivot;
    int    val_p;

    pivot = left;
    val_p = (*tab)[left];
    while (left < right)
    {
        while ((*tab)[left] <= val_p && left < right)
            left++;
        while ((*tab)[right] > val_p)
            right--;
 printf("tab[left] : [%s]\ntab[right] : [%s]\n", tab[left], tab[right]);       
        if ((f((*tab) + pivot, (*tab) + right, path)) == -1)//condition de swap
            ft_swap((*tab) + left, (*tab) + right);
        // else
        //     printf("tab[left] : [%s]\ntab[right] : [%s]\n", tab[left], tab[right]);
    }
 printf("tab[left] : [%s]\ntab[right] : [%s]\n", tab[left], tab[right]);   
    if ((f((*tab) + pivot, (*tab) + right, path)) == -1)
        ft_swap((*tab) + pivot, (*tab) + right);//swap;
    return (right);
}

void            ft_quicksort(char **tab, int start, int end, int (*f)(void *a ,void *b, char *path), char *path)
{
    int    pivot;

    if (start >= end)
        return ;
    pivot = ft_partitiontwo(tab, start, end, f, path);
    ft_quicksort(tab, start, pivot - 1, f, path);
    ft_quicksort(tab, pivot + 1, end, f, path);
}