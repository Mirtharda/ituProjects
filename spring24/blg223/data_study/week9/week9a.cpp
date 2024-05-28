//VECTOR

#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int element : row) {
            cout << element << " ";
        }
        cout << "\n";
    }
}

void addRow(vector<vector<int>>& matrix, vector<int>& newRow) {
    matrix.push_back(newRow);
}

void addColumn(vector<vector<int>>& matrix, int value) {
    for(vector<int>& row : matrix) {
        row.push_back(value);
    }
}


int main() {
    std::vector<std::vector<int>>matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Initial matrix:\n";
    printMatrix(matrix);

    vector<int> newRow = {10, 11, 12};
    addRow(matrix, newRow);
    cout << "\nMatrix after adding a new row:\n";
    printMatrix(matrix);

    addColumn(matrix, 13);
    cout << "\nMatrix after adding a new column:\n";
    printMatrix(matrix);


    return 0;   
}