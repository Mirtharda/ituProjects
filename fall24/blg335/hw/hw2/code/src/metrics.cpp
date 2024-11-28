#include "methods.h"
/**
 * SELİN YILMAZ
 * 150210100
 */

int getMax(std::vector<Item>& items, const std::string& attribute)
{
    int max = 0;
    //if(attribute == "age") {
        for(int i = 0; i < items.size(); i++) {
            if(items[i].age > max) {
                max = items[i].age;
            }
        }
    //}     
    return max;

}
// The range for calculation should also be [item-window_size, item+window_size].

// min = age - ageWindow
// max = age + ageWindow
// rarityScore = (1 - probability) * (1 + item.age/ageMax)
//Prob = similar/total if total > 0
void calculateRarityScores(std::vector<Item>& items, int ageWindow)
{
    if (items.empty() == true){
        return;
    } 
    //std::vector<Item> sorted_items = countingSort(items, "age", true);

    for(int i = 0; i < items.size(); i++) {
        float countTotal = 0;
        float countSimilar = 0;

        int minAge = items[i].age - ageWindow;
        if(minAge < 0) {
            minAge = 0;
        }
        int maxAge = items[i].age + ageWindow;
        float probablity = 0.0;

        for(int j = 0; j < items.size(); j++) {
            if(items[j].age >= minAge && items[j].age <= maxAge) {
                countTotal++;

                if(items[j].type == items[i].type &&
                    items[j].origin == items[i].origin) {
                        
                    countSimilar++;
                }
            }
        }

        //PROBABLITY
        if(countTotal != 0) {
            probablity = countSimilar / countTotal;
        } else {
            probablity = 0.0;
        }

        //RARITY
        int ageMax = getMax(items, "age");
        items[i].rarityScore = (1 - probablity) * (1 + items[i].age / ageMax);
    }

    return;
}
