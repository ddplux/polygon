#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
using namespace std;

void countingSort(vector<int> &arr, int k) {
    // count для хранения количества вхождений
    vector<int> count(k + 1, 0);

    // количество вхождений каждого числа
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Заполняем выходной массив с учетом количества вхождений
    vector<int> output;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < count[i]; j++) {
            output.push_back(i);  
        }
    }

    arr = output;
}

int main() {
    vector<int> arr;
    ifstream input("C:\\Users\\oleg-\\lr52345.txt");
    if (!input) { 
        cout << "Не удалось открыть файл." << endl;
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

    int k = *max_element(arr.begin(), arr.end()); 

    countingSort(arr, k);

    cout << "Отсортированный массив: ";
    for (int el : arr) {
        cout << el << " ";
    }
    cout << endl;
    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы

    return 0;
}