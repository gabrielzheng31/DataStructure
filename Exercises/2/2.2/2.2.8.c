#include <stdio.h>
#include <stdlib.h>

void Reverse(int a[], int size, int left_subscript, int right_subscript);
void Reverse(int a[], int size, int left_subscript, int right_subscript)
{
   if(left_subscript<0 || right_subscript>=size 
           || left_subscript >= right_subscript) 
        exit(EXIT_FAILURE);
   int mid = (left_subscript + right_subscript) / 2;
   for(int i = 0; i <= mid; i++)
   {
        int temp = a[left_subscript + i];
        a[left_subscript + i] = a[right_subscript - i];
        a[right_subscript -i ] = temp;
   }
}

void ExChange(int a[], int m, int n)
{
    Reverse(a[], m+n, 0, m+n-1);
    Reverse(a[], m+n, 0, m);
    Reverse(a[], m+n, m, m+n-1);
}
