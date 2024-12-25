#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime> 
using namespace std;
void bubbleSort(vector<int> &arr) 
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() 
{
    vector<int> arr;
    ifstream input;
    input.open("C:\\Users\\oleg-\\lr52345.txt");
    if (!input) 
    { 
        cout << "Не";
        return 1; 
    }

    string line;
    while (getline(input, line)) 
    {
        stringstream ss(line);
        string number;
        while (getline(ss, number, '\t')) 
        {
            arr.push_back(stoi(number));
        }
    }

    bubbleSort(arr);
    for (int el : arr) 
    {
        cout << el << " ";
    }

    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы

    return 0;
}



