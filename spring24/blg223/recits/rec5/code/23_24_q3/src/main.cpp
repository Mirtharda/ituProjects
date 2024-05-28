#include <iostream>

struct Food {
    std::string meal; 
    Food* next; 
};

struct RecipeList {
    Food* head;
    RecipeList() : head(nullptr) {}

    void addFood(std::string meal) {
        Food* newFood = new Food(); 
        newFood->meal = meal;

        if (head == nullptr) {
            head = newFood; 
            newFood->next = head; 
        } else {
            Food* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newFood; 
            newFood->next = head; 
        }
    }

    void traverseList() {
        if (head == nullptr) {
            std::cout << "Empty List" << std::endl;
            return;
        }

        Food* temp = head;
        do {
            std::cout << temp->meal << " ";
            temp = temp->next;
        } while (temp != head); 
        std::cout << std::endl;
    }

    void deleteFood(std::string meal) {
        if (head == nullptr) {
            std::cout << "Empty List" << std::endl;
            return;
        }

        Food* temp = head;
        Food* prev = nullptr;

        do {
            if (temp->meal == meal) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp == head && temp->next == head) { 
            delete temp;
            head = nullptr;
            return;
        }

        if (temp == head) { 
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            prev->next = head->next;
            delete head;
            head = prev->next;
        } else { 
            prev->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    RecipeList recipeBook; 

    recipeBook.addFood("Pizza");
    recipeBook.addFood("Pasta");
    recipeBook.addFood("Cake");

    std::cout << "Recipes:" << std::endl;
    recipeBook.traverseList();

    recipeBook.deleteFood("Pasta");

    std::cout << "Updated Recipes:" << std::endl;
    recipeBook.traverseList();
    recipeBook.addFood("Fish");
    std::cout << "Updated Recipes:" << std::endl;
    recipeBook.traverseList();

    return 0;
}
