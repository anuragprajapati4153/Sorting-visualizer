#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

// Generate random array
vector<int> generateArray(int size, int maxValue)
{
    vector<int> array(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % maxValue + 1;
    }
    return array;
}

// Print array using star********
void printArray(const vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

// Perform bubble sort
void bubbleSort(vector<int> &array)
{
    int count = 0;
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size() - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                printArray(array);
                this_thread::sleep_for(chrono::milliseconds(1000));
                count++;
            }
        }
        if (count == 0)
            return;
    }
    // print sorted array
    cout << "Sorted Array>>>>>>>>>" << endl;
    printArray(array);
}

// Insertion sort
void insertionSort(vector<int> &array)
{
    int max;
    for (int i = array.size() - 1; i >= 0; i--)
    {
        max = i;
        for (int j = 0; j <= i; j++)
        {
            if (array[j] > array[max])
            {
                max = j;
            }
        }
        swap(array[i], array[max]);
        printArray(array);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    // print sorted array
    cout << "Sorted Array>>>>>>>>>" << endl;
    printArray(array);
}
// selection sort
void selectionSort(vector<int> &array)
{
    for (int i = 1; i < array.size(); i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (array[j] > array[j - 1])
            {
                swap(array[j], array[j - 1]);
                printArray(array);
                this_thread::sleep_for(chrono::milliseconds(1000));
            }
            else
            {
                break;
            }
        }
    }
    // print sorted array
    cout << "Sorted Array>>>>>>>>>" << endl;
    printArray(array);
}

int main()
{
    srand(time(0));
    vector<int> array = generateArray(10, 10);
    bool flag = true;
    int n;
    while (flag)
    {

        cout << "Which sorting algorithm You want to visualize>>>>>\n Press correspoding number>>>" << endl;
        cout << "Bubble sort>>>> 1" << endl;
        cout << "Insertion sort>>> 2" << endl;
        cout << "Selection sort>>> 3" << endl;
        cout << "Exit>>> 0" << endl;
        cin >> n;
        if (n < 3 && n >= 0)
        {
            // print unsorted Array
            cout << "Unsorted Array>>>>>>>>>" << endl;
            printArray(array);
        }

        switch (n)
        {
        case 1:
            bubbleSort(array);
            break;
        case 2:
            insertionSort(array);
            break;
        case 3:
            selectionSort(array);
            break;
        case 0:
            flag = false;
            break;
        default:
            cout << "\n!!!! Invalied input !!!!\n\n"
                 << endl;
        }
    }

    return 0;
}