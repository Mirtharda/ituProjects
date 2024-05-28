#include <iostream>
#include <vector>
#include <string>
#include <sstream>


template <class T>
std::string to_str(const T& value) {
  std::string ret;
  std::ostringstream ss;
  ss << value;
  ret = ss.str();
  return ret;
}

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
struct List {
    Node<T>* head;

    List() : head(nullptr) {}

    void addNode(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    std::string getString(int num) {
        std::string result;
        Node<T>* current = head;
        while (current != nullptr && num > 0) {
            result += to_str(current->data);
            current = current->next;
            --num;
        }
        return result;
    }

    void deleteNodesFromBeginning(int count) {
        while (count > 0 && head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            --count;
        }
    }
};

int main() {
    List<int> intList;
    List<char> charList;
    List<std::string> stringList;

    for (int i = 1; i <= 15; ++i) {
        intList.addNode(i);
        charList.addNode('a' + i - 1); // ASCII values from 'a' to 'o'
        stringList.addNode(to_str(i%5)+to_str(i%3));
    }
    intList.printList();
    charList.printList();
    stringList.printList();

    int numbers[] = {2, 4, 1};
    std::string combinedStr;
    for(int i = 0; i < 3; i++){
        std::string intString = intList.getString(numbers[i]);
        intList.deleteNodesFromBeginning(numbers[i]);
        std::string charString = charList.getString(numbers[i]);
        charList.deleteNodesFromBeginning(numbers[i]);
        std::string strString = stringList.getString(numbers[i]);
        stringList.deleteNodesFromBeginning(numbers[i]);
        combinedStr += intString + charString + strString;
    }
    std::cout << combinedStr << std::endl;
    

    return 0;
}
