#include "tweet.h"
/**
 * SELİN YILMAZ
 * 150210100
 */


int binarySearch(const std::vector<Tweet>& tweets, long long key, const std::string& sortBy)
{
    //Find a tweet with exactly that amount of retweets/favs
    //"key" is the aimed number
    //sortBy for the aimed area
    int ikey = key;
    int max = tweets.size() - 1;
    int min = 0;
    int index;

    while(max >= min) {
        index = (max + min) / 2;
        if((sortBy == "tweetID" && tweets[index].tweetID == ikey) ||
            (sortBy == "retweetCount" && tweets[index].retweetCount == ikey) ||
            (sortBy == "favoriteCount" && tweets[index].favoriteCount == ikey)) {
            //found the target
            return index;
        } else if((sortBy == "tweetID" && tweets[index].tweetID > ikey) ||
                (sortBy == "retweetCount" && tweets[index].retweetCount > ikey) ||
                (sortBy == "favoriteCount" && tweets[index].favoriteCount > ikey)) {
            max = index - 1;
        } else {
            min = index + 1;
        }
    }
    std::cerr << "ERROR: invalid number. " << key << " could not find.\n";
    return -1;
}

int countAboveThreshold(const std::vector<Tweet>& tweets, const std::string& metric, int threshold) 
{
    //Count how many tweets has more retweets/favs than the given treshold
    //metric is sortBy actually

    int count = 0;
    if(metric == "tweetID") {
        for(int k = 0; k < tweets.size(); k++) {
            if(tweets[k].tweetID > threshold) { count++; }
        }
    } else if(metric == "retweetCount") {
        for(int i = 0; i < tweets.size(); i++) {
            if(tweets[i].retweetCount > threshold) { count++; }
        }
    } else if(metric == "favoriteCount") {
        for(int j = 0; j < tweets.size(); j++) {
            if(tweets[j].favoriteCount > threshold) { count++; }
        }
    } else {
        std::cerr << "ERROR: invalid metric.\n";
        return -1;
    }

    return count;

}
