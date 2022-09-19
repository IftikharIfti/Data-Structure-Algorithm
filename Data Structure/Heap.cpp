#include <bits/stdc++.h>
using namespace std;
#define MAX 10

void build_min_heap(int arr[]);
void heapify(int arr[]);
void heap_sort(int arr[], int temp);
int Heap_Minimum();
int Heap_extract_min();
void Min_heap_insert(int x);
void Heap_decrease_key(int position, int amount);
void Heap_increase_key(int key, int amount);

int arr[MAX];
int heap_size = 0;
int main()
{
    int i = 1, x;
    cin >> x;
    ///////////////
    while (x != -1 || heap_size == MAX)
    {
        arr[i++] = x;
        cin >> x;
        heap_size++;
    }
    int s = heap_size;

    for (int i = 1; i <= heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Min Heap: " << endl;
    build_min_heap(arr);

    for (int i = 1; i <= s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << " Heap sort: " << endl;
    heap_sort(arr, s);
    heap_size = s;

    for (int i = 1; i <= s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "After using Heap Minimum" << endl;
    cout << Heap_Minimum() << endl;
    cout << "After extracting minimum from heap" << endl;
    cout << Heap_extract_min() << endl;
    cout << "After inserting in the min heap" << endl;
    int k;
    cin >> k;
    Min_heap_insert(k);
   
    for (int i = 1; i <= heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout << "After decreasing a key from the heap in " << endl;
    int pos;
    cin >> pos;
    cout << pos;
    cout << " th postion" << endl;
    cin >> k;
    Heap_decrease_key(pos, k);

    for (int i = 1; i <= heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "After increasing a key from the heap in " << endl;

    cin >> pos;
    cout << pos;
    cout << " th postion" << endl;
    cin >> k;
    Heap_decrease_key(pos, k);

    for (int i = 1; i <= heap_size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
void heapify(int arr[], int i, int size)
{
    int l, r;
    l = i * 2;
    r = i * 2 + 1;

    int smallest;
    if (arr[l] < arr[i] && l <= size)
    {
        smallest = l;
    }
    else
        smallest = i;

    if (arr[smallest] > arr[r] && r <= size)
    {
        smallest = r;
    }

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest, size);
    }
}

void build_min_heap(int arr[])
{
    for (int i = heap_size / 2; i >= 1; --i)
    {
        heapify(arr, i, heap_size);
    }
}
void heap_sort(int arr[], int s)
{
    build_min_heap(arr);

    for (int i = s; i >= 2; --i)
    {
        swap(arr[i], arr[1]);
        heap_size--;

        heapify(arr, 1, heap_size);
    }
}
int Heap_Minimum()
{
    return arr[heap_size];
}
int Heap_extract_min()
{
    int n = arr[1];
    swap(arr[1], arr[heap_size]);
    heap_size--;
    heapify(arr, 1, heap_size);
    return n;
}
void Min_heap_insert(int x)
{
    heap_size++;
    arr[heap_size] = x;
    int i = heap_size;
    while (arr[i] < arr[i / 2] && i > 1)
    {
        swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

void Heap_decrease_key(int position, int amount)
{
    arr[position] += amount;
    build_min_heap(arr);
}
void Heap_increase_key(int key, int amount)
{
    arr[key] -= amount;
    build_min_heap(arr);
}
