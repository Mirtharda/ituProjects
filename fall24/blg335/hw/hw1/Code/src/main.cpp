#include "tweet.h"
#include <chrono>   //measure execution time
/**
 * SELİN YILMAZ
 * 150210100
 */


int main(int argc, char* argv[]) 
{

    // TABLE 1.1
    //--------------------------BUBBLE SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------BUBBLE SORT-------------------------\n";
        std::vector<Tweet> BS_tweets = readTweetsFromFile("data/permutations/tweets.csv");
            //Test if the files are read properly
                int i = 0;
                while(i < 5) {
                    std::cout << "Tweet ID: " << BS_tweets[i].tweetID 
                                << " Retweet Count: " << BS_tweets[i].retweetCount
                                << " Favorite Count: " << BS_tweets[i].favoriteCount
                                << std::endl;
                    i++;
                }
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_tweets, "retweetCount", true);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "BS_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> BS_tweetsSA = readTweetsFromFile("data/permutations/tweetsSA.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_tweetsSA, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_tweetsSA - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> BS_tweetsSD = readTweetsFromFile("data/permutations/tweetsSD.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_tweetsSD, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_tweetsSD - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> BS_tweetsNS = readTweetsFromFile("data/permutations/tweetsNS.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_tweetsNS, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_tweetsNS - retweetCount: " << duration.count() << std::endl;


    //--------------------------INSERTION SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------INSERTION SORT-------------------------\n";
        std::vector<Tweet> IS_tweets = readTweetsFromFile("data/permutations/tweets.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> IS_tweetsSA = readTweetsFromFile("data/permutations/tweetsSA.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_tweetsSA, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_tweetsSA - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> IS_tweetsSD = readTweetsFromFile("data/permutations/tweetsSD.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_tweetsSD, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_tweetsSD - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> IS_tweetsNS = readTweetsFromFile("data/permutations/tweetsNS.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_tweetsNS, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_tweetsNS - retweetCount: " << duration.count() << std::endl;

    //--------------------------MERGE SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------MERGE SORT-------------------------\n";
        std::vector<Tweet> MS_tweets = readTweetsFromFile("data/permutations/tweets.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_tweets, 0, MS_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> MS_tweetsSA = readTweetsFromFile("data/permutations/tweetsSA.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_tweetsSA, 0, MS_tweetsSA.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_tweetsSA - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> MS_tweetsSD = readTweetsFromFile("data/permutations/tweetsSD.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_tweetsSD, 0, MS_tweetsSD.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_tweetsSD - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> MS_tweetsNS = readTweetsFromFile("data/permutations/tweetsNS.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_tweetsNS, 0, MS_tweetsNS.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_tweetsNS - retweetCount: " << duration.count() << std::endl;

/*
// TABLE 1.2
    //--------------------------BUBBLE SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------BUBBLE SORT-------------------------\n";
        std::vector<Tweet> BS_5K_tweets = readTweetsFromFile("data/sizes/tweets5k.csv");
            //Test if the files are read properly
                int i = 0;
                while(i < 5) {
                    std::cout << "Tweet ID: " << BS_5K_tweets[i].tweetID 
                                << " Retweet Count: " << BS_5K_tweets[i].retweetCount
                                << " Favorite Count: " << BS_5K_tweets[i].favoriteCount
                                << std::endl;
                    i++;
                }
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_5K_tweets, "retweetCount", true);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "BS_5K_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> BS_10K_tweets = readTweetsFromFile("data/sizes/tweets10k.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_10K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_10K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> BS_20K_tweets = readTweetsFromFile("data/sizes/tweets20k.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_20K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_20K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> BS_30K_tweets = readTweetsFromFile("data/sizes/tweets30k.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_30K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_30K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> BS_50K_tweets = readTweetsFromFile("data/sizes/tweets50k.csv");
        start = std::chrono::high_resolution_clock::now();
        bubbleSort(BS_50K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_50K_tweets - retweetCount: " << duration.count() << std::endl;


    //--------------------------INSERTION SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------INSERTION SORT-------------------------\n";
        std::vector<Tweet> IS_5K_tweets = readTweetsFromFile("data/sizes/tweets5k.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_5K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_5K_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> IS_10K_tweets = readTweetsFromFile("data/sizes/tweets10k.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_10K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_10K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> IS_20K_tweets = readTweetsFromFile("data/sizes/tweets20k.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_20K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_20K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> IS_30K_tweets = readTweetsFromFile("data/sizes/tweets30k.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_30K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_30K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> IS_50K_tweets = readTweetsFromFile("data/sizes/tweets50k.csv");
        start = std::chrono::high_resolution_clock::now();
        insertionSort(IS_50K_tweets, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_50K_tweets - retweetCount: " << duration.count() << std::endl;

    //--------------------------MERGE SORT-----------------------------------------------------------------------//
        std::cout << "-----------------------------MERGE SORT-------------------------\n";
        std::vector<Tweet> MS_5K_tweets = readTweetsFromFile("data/sizes/tweets5k.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_5K_tweets, 0, MS_5K_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_5K_tweets - retweetCount: " << duration.count() << std::endl;


        std::vector<Tweet> MS_10K_tweets = readTweetsFromFile("data/sizes/tweets10k.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_10K_tweets, 0, MS_10K_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_10K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> MS_20K_tweets = readTweetsFromFile("data/sizes/tweets20k.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_20K_tweets, 0, MS_20K_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_20K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> MS_30K_tweets = readTweetsFromFile("data/sizes/tweets30k.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_30K_tweets, 0, MS_30K_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_30K_tweets - retweetCount: " << duration.count() << std::endl;

        std::vector<Tweet> MS_50K_tweets = readTweetsFromFile("data/sizes/tweets50k.csv");
        start = std::chrono::high_resolution_clock::now();
        mergeSort(MS_50K_tweets, 0, MS_50K_tweets.size() - 1, "retweetCount", true);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "MS_50K_tweets - retweetCount: " << duration.count() << std::endl;
*/
/*
//TABLE 1.3
    //--------------------------BINARY SEARCH-----------------------------------------------------------------------//
        std::cout << "-----------------------------BINARY SEARCH-------------------------\n";
        std::vector<Tweet> BS_5K_tweets = readTweetsFromFile("data/sizes/tweets5k.csv");
        mergeSort(BS_5K_tweets, 0, BS_5K_tweets.size() - 1, "tweetID", true);
        auto start = std::chrono::high_resolution_clock::now();
        binarySearch(BS_5K_tweets, 1773335, "tweetID");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "BS_5K_tweets - tweetID: " << duration.count() << std::endl;


        std::vector<Tweet> BS_10K_tweets = readTweetsFromFile("data/sizes/tweets10k.csv");
        mergeSort(BS_10K_tweets, 0, BS_10K_tweets.size() - 1, "tweetID", true);
        start = std::chrono::high_resolution_clock::now();
        binarySearch(BS_10K_tweets, 1773335, "tweetID");
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_10K_tweets - tweetID: " << duration.count() << std::endl;

        std::vector<Tweet> BS_20K_tweets = readTweetsFromFile("data/sizes/tweets20k.csv");
        mergeSort(BS_20K_tweets, 0, BS_20K_tweets.size() - 1, "tweetID", true);
        start = std::chrono::high_resolution_clock::now();
        binarySearch(BS_20K_tweets, 1773335, "tweetID");
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_20K_tweets - tweetID: " << duration.count() << std::endl;

        std::vector<Tweet> BS_30K_tweets = readTweetsFromFile("data/sizes/tweets30k.csv");
        mergeSort(BS_30K_tweets, 0, BS_30K_tweets.size() - 1, "tweetID", true);
        start = std::chrono::high_resolution_clock::now();
        binarySearch(BS_30K_tweets, 1773335, "tweetID");
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_30K_tweets - tweetID: " << duration.count() << std::endl;

        std::vector<Tweet> BS_50K_tweets = readTweetsFromFile("data/sizes/tweets50k.csv");
        mergeSort(BS_50K_tweets, 0, BS_50K_tweets.size() - 1, "tweetID", true);
        start = std::chrono::high_resolution_clock::now();
        binarySearch(BS_50K_tweets, 1773335, "tweetID");
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "BS_50K_tweets - tweetID: " << duration.count() << std::endl;


    //--------------------------THRESHOLD-----------------------------------------------------------------------//
        std::cout << "-----------------------------THRESHOLD-------------------------\n";
        std::vector<Tweet> TH_5K_tweets = readTweetsFromFile("data/sizes/tweets5k.csv");
        mergeSort(TH_5K_tweets, 0, TH_5K_tweets.size() - 1, "favoriteCount", true);
        start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(TH_5K_tweets, "favoriteCount", 250);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "TH_5K_tweets - favoriteCount: " << duration.count() << std::endl;


        std::vector<Tweet> TH_10K_tweets = readTweetsFromFile("data/sizes/tweets10k.csv");
        mergeSort(TH_10K_tweets, 0, TH_10K_tweets.size() - 1, "favoriteCount", true);
        start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(TH_10K_tweets, "favoriteCount", 250);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "TH_10K_tweets - favoriteCount: " << duration.count() << std::endl;

        std::vector<Tweet> TH_20K_tweets = readTweetsFromFile("data/sizes/tweets20k.csv");
        mergeSort(TH_20K_tweets, 0, TH_20K_tweets.size() - 1, "favoriteCount", true);
        start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(TH_20K_tweets, "favoriteCount", 250);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "TH_20K_tweets - favoriteCount: " << duration.count() << std::endl;

        std::vector<Tweet> TH_30K_tweets = readTweetsFromFile("data/sizes/tweets30k.csv");
        mergeSort(TH_30K_tweets, 0, TH_30K_tweets.size() - 1, "favoriteCount", true);
        start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(TH_30K_tweets, "favoriteCount", 250);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "IS_30K_tweets - favoriteCount: " << duration.count() << std::endl;

        std::vector<Tweet> TH_50K_tweets = readTweetsFromFile("data/sizes/tweets50k.csv");
        mergeSort(TH_50K_tweets, 0, TH_50K_tweets.size() - 1, "favoriteCount", true);
        start = std::chrono::high_resolution_clock::now();
        countAboveThreshold(TH_50K_tweets, "favoriteCount", 250);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "TH_50K_tweets - favoriteCount: " << duration.count() << std::endl;
*/
    return 0;
}
