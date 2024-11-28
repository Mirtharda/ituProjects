#include "methods.h"
/**
 * SELİN YILMAZ
 * 150210100
 */

std::vector<Item> countingSort(std::vector<Item>& items, const std::string& attribute, bool ascending)
{   //C[0:k] k<-items'daki en büyük değer
    //getMax kullanılacak
    //attribute is age, type, or rarity

    int k = getMax(items, attribute);
    std::vector<int> C(k + 1, 0);
    std::vector<Item> B(items.size());

    
    if(attribute == "age") {
        /*for(int i = 0; i < k; i++) {
            C[i].age = 0;
        }*/
        if(ascending == true) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].age] = C[items[j].age] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = 1; i <= k; i++) {
                C[i] = C[i] + C[i - 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].age] - 1] = items[j];          //-1 is essential, otherwise B nin sınırını aşıyor
                C[items[j].age] = C[items[j].age] - 1;
            }
        } else if(ascending == false) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].age] = C[items[j].age] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = k - 1; i >= 0; i--) {
                C[i] = C[i] + C[i + 1];
            //C[i] now contains the number of elements greater than or equal to i.
            //this ensures larger numbers are placed first
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].age] - 1] = items[j];
                C[items[j].age] = C[items[j].age] - 1;
            }
        } else {
            std::cerr << "ERROR: Invalid parameter.\n";
            return {};
        }
    } else if(attribute == "type") {
        if(ascending == true) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].type] = C[items[j].type] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = 1; i <= k; i++) {
                C[i] = C[i] + C[i - 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].type] - 1] = items[j];
                C[items[j].type] = C[items[j].type] - 1;
            }
        } else if(ascending == false) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].type] = C[items[j].type] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = k - 1; i >= 0; i--) {
                C[i] = C[i] + C[i + 1];
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].type] - 1] = items[j];
                C[items[j].type] = C[items[j].type] - 1;
            }            
        } else {
            std::cerr << "ERROR: Invalid parameter.\n";
            return {};
        }
    } else if(attribute == "origin") {
        if(ascending == true) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].origin] = C[items[j].origin] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = 1; i <= k; i++) {
                C[i] = C[i] + C[i - 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].origin] - 1] = items[j];
                C[items[j].origin] = C[items[j].origin] - 1;
            }
        } else if(ascending == false) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].origin] = C[items[j].origin] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = k - 1; i >= 0; i--) {
                C[i] = C[i] + C[i + 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].origin] - 1] = items[j];
                C[items[j].origin] = C[items[j].origin] - 1;
            }
        } else {
            std::cerr << "ERROR: Invalid parameter.\n";
            return {};
        }
    } else if(attribute == "rarityScore") {
        if(ascending == true) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].rarityScore] = C[items[j].rarityScore] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = 1; i <= k; i++) {
                C[i] = C[i] + C[i - 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].rarityScore] - 1] = items[j];
                C[items[j].rarityScore] = C[items[j].rarityScore] - 1;
            }
        } else if(ascending == false) {
            for(int j = 0; j < items.size(); j++) {
                C[items[j].rarityScore] = C[items[j].rarityScore] + 1;
                //C[i] now contains the number of elements equal to i.
            }
            for(int i = k - 1; i >= 0; i--) {
                C[i] = C[i] + C[i + 1];
                //C[i] now contains the number of elements less than or equal to i.
            }
            //copy A to B, starting from the end of A
            for(int j = items.size() - 1; j >= 0; j--) {
                B[C[items[j].rarityScore] - 1] = items[j];
                C[items[j].rarityScore] = C[items[j].rarityScore] - 1;
            }
        } else {
            std::cerr << "ERROR: Invalid parameter.\n";
            return {};
        }
    } else {
        std::cerr << "ERROR: Invalid parameter.\n";
        return {};
    }
    return B;
}

// Function to heapify a subtree rooted with node i in the array of items
//n = number of nodes
//rarity ye göre bakılmalı
void heapify(std::vector<Item>& items, int n, int i, bool descending)
{
    //MAX-HEAPIFY
    if(descending == false) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && items[left].rarityScore > items[i].rarityScore) { 
            largest = left; 
        } else { 
            largest = i;
        }

        if(right < n && items[right].rarityScore > items[largest].rarityScore) { 
            largest = right; 
        }

        if(largest != i) {
            //exchange items[i] with items[largest]

            //can be shadow copy, CAREFULL!!
            Item temp = items[i];
            items[i] = items[largest];
            items[largest] = temp;

            heapify(items, n, largest, false);
        }
    } else if(descending == true){
        //min-heapify
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && items[left].rarityScore < items[i].rarityScore) {
            smallest = left;
        } else {
            smallest = i;
        }

        if(right < n && items[right].rarityScore < items[smallest].rarityScore) {
            smallest = right;
        }

        if(smallest != i) {
            Item temp = items[i];
            items[i] = items[smallest];
            items[smallest] = temp;

            heapify(items, n, smallest, true);
        }
    } else {
        std::cerr << "ERROR: Invalid ordering way.\n";
        return;
    }
}

// Function to perform heap sort on rarityScore scores of items
std::vector<Item> heapSortByRarity(std::vector<Item>& items, bool descending)
{
    if(items.empty()) {
        return {};
    }
     
    int n = items.size();

    if(descending == false) {
        //MAX-HEAPIFY
        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(items, n, i, false);
        }

        for(int i = n - 1; i >= 1; i--) {
            Item temp = items[0];
            items[0] = items[i];
            items[i] = temp;

            n = n - 1;
            heapify(items, n, 0, false);
        }
    } else if(descending == true){
        //MIN-HEAPIFY
        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(items, n, i, true);
        }

        for(int i = n - 1; i >= 1; i--) {
            Item temp = items[0];
            items[0] = items[i];
            items[i] = temp;

            n = n - 1;
            heapify(items, n, 0, true);
        }
    } else {
        std::cerr << "ERROR: Invalid ordering way.\n";
    }

    return items;

}
