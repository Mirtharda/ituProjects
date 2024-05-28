#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, int> studentScores = {
        {123, 85},  
        {456, 92},  
        {789, 75}, 
        {101, 88}   
    };

    int studentID = 456;
    std::map<int, int>::iterator it;
    for (it = studentScores.begin(); it != studentScores.end(); ++it) {
        if (it->first == studentID) {
            std::cout << "Student " << it->first << " Grade: " << it->second << std::endl;
            break;
        }
    }

    int minScore = std::numeric_limits<int>::max(); 
    int minScoreStudentID = -1; 
    for (it = studentScores.begin(); it != studentScores.end(); ++it) {
        if (it->second < minScore) {
            minScore = it->second;
            minScoreStudentID = it->first;
        }
    }

    std::cout << "Student with lowest grade: " << minScoreStudentID << " (Grade: " << minScore << ")" << std::endl;

    return 0;
}
