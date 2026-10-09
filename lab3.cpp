#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorter
{
public:

   

    void mergeSort(int arr[], int l, int r)
    {
        if (l >= r)
            return;

        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }



    void quickSort(int arr[], int low, int high)
    {
        if (low >= high)
            return;

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }


    
    void quickSortM3(int arr[], int low, int high)
    {
        if (low >= high)
            return;

        int p = partitionM3(arr, low, high);

        quickSortM3(arr, low, p - 1);
        quickSortM3(arr, p + 1, high);
    }


private:

   

    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];

        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }

        while (i < n1)
            arr[k++] = L[i++];

        while (j < n2)
            arr[k++] = R[j++];
    }


   

    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];

        int i = low;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                swap(arr[i], arr[j]);
                i++;
            }
        }

        swap(arr[i], arr[high]);

        return i;
    }


   

    int medianOfThree(int arr[], int low, int high)
    {
        int mid = (low + high) / 2;

        if (arr[low] > arr[mid])
            swap(arr[low], arr[mid]);

        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);

        if (arr[mid] > arr[high])
            swap(arr[mid], arr[high]);

        
        swap(arr[mid], arr[high]);

        return high;
    }


    
    int partitionM3(int arr[], int low, int high)
    {
        medianOfThree(arr, low, high);

        return partition(arr, low, high);
    }
};


int main()
{
    Sorter s;

    int tmp[8];

    int a[] = {64,25,12,22,11,90,45,34};
    int n = 8;

  
    copy(a, a + n, tmp);

    s.mergeSort(tmp, 0, n - 1);

    cout << "MS: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    copy(a, a + n, tmp);

    s.quickSort(tmp, 0, n - 1);

    cout << "QS: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    
    int sorted[] = {1,2,3,4,5,6,7,8};

    copy(sorted, sorted + n, tmp);

    s.quickSort(tmp, 0, n - 1);

    cout << "QS sorted: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;


    copy(sorted, sorted + n, tmp);

    s.quickSortM3(tmp, 0, n - 1);

    cout << "QSM3 sorted: ";

    for (int x : tmp)
        cout << x << " ";

    cout << endl;

    return 0;
}
