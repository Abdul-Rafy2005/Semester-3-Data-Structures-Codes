
#include <iostream>
using namespace std;       //     this is starting from index 1 and below code start from index 0
 
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int n)
{
    // Start from the last parent node in the range [1, n-1]
    for (int i = (n / 2); i >= 1; i--)
    {
        int j = 2 * i;  // Left child for current i (adjusted for 1-based indexing)
 
        while (j <= n - 1)
        {
            // Compare left and right children of current i
            if (j < n - 1 && A[j] < A[j + 1]) j = j + 1;

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i;
            }
            else break;
        }
    }
}

int Delete(int A[], int n)
{
    int x = A[1];  // Max element (root of the heap)
    A[1] = A[n - 1];  // Move the last element to the root
 
    int i = 1;
    int j = 2 * i;
 
    while (j < n - 1)
    {
        // Compare left and right children
        if (j < n - 2 && A[j] < A[j + 1]) {
            j = j + 1;
        }
 
        // Compare parent and largest child
        if (A[i] < A[j]) {
            swap(A, i, j);
            i = j;
            j = 2 * i;
        } else {
            break;
        }
    }

    return x;
}
 
template <class T>
void Print(T& vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 1; i < n; i++)  // Start from index 1
    {
        cout << vec[i] << flush;
        if (i < n - 1)   cout << ", " << flush;
    }
    cout << "]" << endl;
}

int main()
{
    int A[] = {0, 5, 10, 30, 20, 35, 40,45};  // 0th index ignored
    Print(A, sizeof(A) / sizeof(A[0]), "A");
 
    Heapify(A, sizeof(A) / sizeof(A[0]));
    Print(A, sizeof(A) / sizeof(A[0]), "Heapified A");
    cout << endl;
 
    // int B[] = {0, 5, 10, 30, 20};  // 0th index ignored
    // Print(B, sizeof(B) / sizeof(B[0]), "B");
 
    // Heapify(B, sizeof(B) / sizeof(B[0]));
    // Print(B, sizeof(B) / sizeof(B[0]), "Heapified B");
 
    return 0;
}

