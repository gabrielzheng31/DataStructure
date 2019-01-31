int BinarySearch(int a[], int length, int key)
{
    int low = 0, high = length -1, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(a[mid] == key)
            return mid; 
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

