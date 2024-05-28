#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    Book* next;
    Book* prev;

    Book(std::string title, std::string author, std::string publisher){
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        next = NULL;
        prev = NULL;
    }
};

class Library {
private:
    Book* head;

public:
    Library() : head(nullptr) {}

void addBook(std::string title, std::string author, std::string publisher) {
    Book* newBook = new Book(title, author, publisher);
    if (head == nullptr) {
        head = newBook;
    } else {
        Book* temp = head;
        Book* prev = nullptr;
        while (temp != nullptr && temp->title < title) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            newBook->next = head;
            head->prev = newBook;
            head = newBook;
        } else {
            prev->next = newBook;
            newBook->prev = prev;
            newBook->next = temp;
            if (temp != nullptr) {
                temp->prev = newBook;
            }
        }
    }
}

    void displayBooks() {
        Book* temp = head;
        while (temp != nullptr) {
            std::cout << "Title: " << temp->title << ", Author: " << temp->author << ", Publisher: " << temp->publisher << std::endl;
            temp = temp->next;
        }
    }
    void deleteBook(std::string title) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                if (temp == head) {
                    head = temp->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = temp->prev;
                    }
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Book not found!" << std::endl;
    }

    void searchBook(std::string title) {
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->title == title) {
                std::cout << "Book found! Title: " << temp->title << ", Author: " << temp->author << ", Publisher: " << temp->publisher << std::endl;
                return;
            }
            temp = temp->next;
        }
        std::cout << "Book not found!" << std::endl;
    }
};

int main() {
    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "Scribner");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.");
    library.addBook("1984", "George Orwell", "Secker & Warburg");
    library.addBook("Pride and Prejudice", "Jane Austen", "T. Egerton");

    std::cout << "Books in the library:" << std::endl;
    library.displayBooks();

    std::cout << "\nSearching for the book '1984':" << std::endl;
    library.searchBook("1984");

    std::cout << "\nDeleting the book 'To Kill a Mockingbird':" << std::endl;
    library.deleteBook("To Kill a Mockingbird");

    std::cout << "\nBooks in the library after deletion:" << std::endl;
    library.displayBooks();
    library.searchBook("To Kill a Mockingbird");
    return 0;
}
