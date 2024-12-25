#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime> 
using namespace std;
void findCombinations(const vector<pair<int, int>>& pairs, size_t index, unordered_set<int>& result) {
    if (index >= pairs.size()) {
        return;
    }

    result.insert(pairs[index].first);
    result.insert(pairs[index].second);
    
    findCombinations(pairs, index + 1, result);

    findCombinations(pairs, index + 1, result);
}

int main() {
    vector<pair<int, int>> pairs;
    ifstream input("C:\\Users\\oleg-\\lr41.txt"); //5 0.19, 10 0.27, 20 0.371
    if (!input) {
        cerr << "Н" << endl;
        return 1;
    }

    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        int first, second;

        ss >> first;
        ss.ignore(1, '\t'); 
        ss >> second;

        pairs.emplace_back(first, second);
    }
    input.close();
    
    cout << "pairs:" << endl;
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    

    unordered_set<int> resultSet;
    findCombinations(pairs, 0, resultSet);
    vector<int> vec(resultSet.begin(), resultSet.end());
    
    cout << "[";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "]" << endl;
    cout << "runtime = " << clock()/1000.0 << endl;
    return 0;
}