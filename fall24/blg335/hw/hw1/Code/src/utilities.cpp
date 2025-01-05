#include "tweet.h"
/**
 * SELİN YILMAZ
 * 150210100
 */

std::vector<Tweet> readTweetsFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "ERROR: Failed to open file.\n";
        return {};
    }

    //we need to put everything in a tweets vector.
    std::string line;
    getline(file, line);    //first line is the names of columns
    std::vector<Tweet> tweets; 

    while(getline(file, line)) {
        std::istringstream iss(line);
        std::string tweetIDStr, retweetCountStr, favoriteCountStr;
        int tweetID, retweet_count, favorite_count;

        if(getline(iss, tweetIDStr, ',') &&
            getline(iss, retweetCountStr, ',') &&
            getline(iss, favoriteCountStr)) {

            tweetID = std::stoi(tweetIDStr);
            retweet_count = std::stoi(retweetCountStr);
            favorite_count = std::stoi(favoriteCountStr);

            Tweet tweet;
            tweet.tweetID = tweetID;
            tweet.retweetCount = retweet_count;
            tweet.favoriteCount = favorite_count;

            tweets.push_back(tweet);
        } else {
            std::cerr << "ERROR: Failed to parse line: " << line << std::endl;
        }
    }
    file.close();

    return tweets;
}

void writeTweetsToFile(const std::string& filename, const std::vector<Tweet>& tweets) 
{
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Failed to open " << filename << std::endl;
        return;
    }
    //header line
    file << "tweetID,retweet_count,favorite_count\n";

    for(int i = 0; i < tweets.size(); i++) {
        file << tweets[i].tweetID << ','
            << tweets[i].retweetCount << ','
            << tweets[i].favoriteCount << '\n';
    }

    file.close();

    return;
}