//SETS

#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int countVowels(string& input) {
    set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int vowelCount = 0;
    for(char ch : input) {
        if(vowels.find(ch) != vowels.end()) {
            vowelCount++;
        }
    }
    return vowelCount;
}

void printSet(const set<int>& s) {
    for(int num : s) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    string text = "Hello wrold!";
    cout << "The number of vowels in \"" << text 
        << "\" is " << countVowels(text) << "." << endl;



    cout << "--------------Message 1------------\n";
    set<int> setA = {1, 2, 3, 4, 5};
    set<int> setB = {4, 5, 6, 7, 8};

    set<int> UnionSet;
    set_union(setA.begin(), setA.end(), 
                setB.begin(), setB.end(),
                inserter(UnionSet, UnionSet.begin()));
    cout << "Union of setA and setB: ";
    printSet(UnionSet);

    set<int> intersectionSet;
    set_intersection(setA.begin(), setA.end(),
                        setB.begin(), setB.end(),
                        inserter(intersectionSet, intersectionSet.begin()));
    cout << "Intersection of setA and setB: ";
    printSet(intersectionSet);

    set<int> differenceSet;
    set_difference(setA.begin(), setA.end(), 
                        setB.begin(), setB.end(), 
                        inserter(differenceSet, differenceSet.begin()));
    cout << "Difference of setA - setB: ";
    printSet(differenceSet);

    return 0;
}