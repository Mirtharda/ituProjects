#include "methods.h"
#include <chrono>   //to measure execution time

int main() 
{
  //TABLE 1.1
  //------------------COUNTING SORT----------------------------
  std::cout << "------------------COUNTING SORT----------------------------\n";  
  std::vector<Item> items_l = readItemsFromFile("data/items_l.csv");

  //std::cout << "age: " << items[1].age << " " 
  //                    << items[1].origin << " " 
  //                    << items[1].type << " " 
  //                    << items[1].rarityScore << std::endl;

  auto start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_la = countingSort(items_l, "age", true);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;
  std::cout << "items_l.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_la_sorted.csv", sorted_la);

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_ld = countingSort(items_l, "age", false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_l.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ld_sorted.csv", sorted_ld);


  std::vector<Item> items_m = readItemsFromFile("data/items_m.csv");

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_ma = countingSort(items_m, "age", true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_m.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ma_sorted.csv", sorted_ma);

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_md = countingSort(items_m, "age", false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_m.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_md_sorted.csv", sorted_md);


  std::vector<Item> items_s = readItemsFromFile("data/items_s.csv");

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_sa = countingSort(items_s, "age", true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_s.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sa_sorted.csv", sorted_sa);

  start = std::chrono::high_resolution_clock::now();
  std::vector<Item> sorted_sd = countingSort(items_s, "age", false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_s.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sd_sorted.csv", sorted_sd);


  //TABLE 2.1
  //------------------CALCULATE RARITY----------------------------
  std::cout << "------------------CALCULATE RARITY----------------------------\n";
  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_la, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_l.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_la_rarity.csv", sorted_la);

  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_ld, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_l.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ld_rarity.csv", sorted_ld);


  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_ma, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_m.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ma_rarity.csv", sorted_ma);

  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_md, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_m.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_md_rarity.csv", sorted_md);

  
  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_sa, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_s.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sa_rarity.csv", sorted_sa);

  start = std::chrono::high_resolution_clock::now();
  calculateRarityScores(sorted_sd, 50);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_s.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sd_rarity.csv", sorted_sd);


  //TABLE 3.1
  //------------------HEAP SORT----------------------------
  std::cout << "------------------HEAP SORT----------------------------\n";
  start = std::chrono::high_resolution_clock::now();
  sorted_la = heapSortByRarity(sorted_la, false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_la.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_la_rarity.csv", sorted_la);
  
  start = std::chrono::high_resolution_clock::now();
  sorted_ld = heapSortByRarity(sorted_ld, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_ld.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ld_rarity.csv", sorted_ld);

  
  start = std::chrono::high_resolution_clock::now();
  sorted_ma = heapSortByRarity(sorted_ma, false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_ma.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_ma_rarity.csv", sorted_ma);
  
  start = std::chrono::high_resolution_clock::now();
  sorted_md = heapSortByRarity(sorted_md, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_md.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_md_rarity.csv", sorted_md);


  start = std::chrono::high_resolution_clock::now();
  sorted_sa = heapSortByRarity(sorted_sa, false);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_sa.csv in ascending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sa_rarity.csv", sorted_sa);
  
  start = std::chrono::high_resolution_clock::now();
  sorted_sd = heapSortByRarity(sorted_sd, true);
  end = std::chrono::high_resolution_clock::now();
  duration = end - start;
  std::cout << "items_sd.csv in descending" << duration.count() << std::endl;
  writeItemsToFile("data/items_sd_rarity.csv", sorted_sd);

  return 0;
}