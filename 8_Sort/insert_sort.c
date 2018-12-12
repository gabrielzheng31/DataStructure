void InsertSort(int a[] ,int n)
{
    int i, j;
    for(i = 2; i < n; i++)
    {
        if(a[i] < a[i-1])
           a[0] = a[i];
        for(j = i - 1; a[j] > a[0]; j--)
           a[j+1] = a[j];
        a[j+1] = a[0]; 
    }
}

void BinaryInsertSort(int a[], int n)
{
    int i, j, low, high, mid;
    for(i=2; i <= n; i++)
    {
        a[0] = a[i];
        low = 1;
        high = i - 1;
        while(low <= high) 
        {
            mid=(low+high)/2;
            if(a[0] == a[mid])
                break;
            else if(a[0] < a[mid])
                high = mid -1;
            else
                low = mid + 1; 
        }
        for(j = i - 1; j >= low; j--)
            a[j+1] = a[j];
        a[low] = a[0];
    }
}

void ShellSort(int a[], int n)
{
    
}
