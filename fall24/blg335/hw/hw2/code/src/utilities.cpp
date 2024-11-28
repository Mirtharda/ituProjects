#include "methods.h"
/**
 * SELİN YILMAZ
 * 150210100
 */

std::vector<Item> readItemsFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
        return{};
    }

    std::string line;
    getline(file, line);
    std::vector<Item> items;

    while(getline(file, line)) {
        std::istringstream iss(line);
        std::string ageStr, typeStr, originStr, rarityStr;
        int age, type, origin;
        float rarity;

        if(getline(iss, ageStr, ',') &&
            getline(iss, typeStr, ',') &&
            getline(iss, originStr, ',') &&
            getline(iss, rarityStr)) {
            
            age = std::stoi(ageStr);
            type = std::stoi(typeStr);
            origin = std::stoi(originStr);
            rarity = std::stof(rarityStr);

            Item item;
            item.age = age;
            item.type = type;
            item.origin = origin;
            item.rarityScore = rarity;

            items.push_back(item);
        } else {
            std::cerr << "ERROR: Failed to parse line: " << line << std::endl;
        }
    }
    file.close();

    return items;

}

void writeItemsToFile(const std::string& filename, const std::vector<Item>& items) 
{
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cerr << "ERROR: Failed to open " << filename << std::endl;
        return;
    }
    //header line
    file << "age,type,origin,rarity\n";

    for(int i = 0; i < items.size(); i++) {
        file << items[i].age << ','
            << items[i].type << ','
            << items[i].origin << ','
            << items[i].rarityScore << '\n';
    }
    file.close();
    return;

}
