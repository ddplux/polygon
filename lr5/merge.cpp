#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime> 
using namespace std;
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr;
    ifstream input;
    input.open("C:\\Users\\oleg-\\lr52345.txt");
    if (!input) { 
        cout << "Не";
        return 1; 
    }
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        string number;
        while (getline(ss, number, '\t')) {
            arr.push_back(stoi(number));
        }
    }
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "Отсортированный массив: ";
    for (int el : arr) {
        cout << el << " ";
    }
    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы
    return 0;
}