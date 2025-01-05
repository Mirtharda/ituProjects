#include "tweet.h"
/**
 * SELİN YILMAZ 
 * 150210100
 */


void bubbleSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) 
{
    //decide which field to sort by
    if(sortBy == "tweetID") {
        //sort by tweetID
        for(int i = 0; i < tweets.size() - 1; i++) {
            //bool swapped = false;

            for(int j = 0; j < tweets.size() - i - 1; j++) {
                //compare based on ascending || decending order
                if((ascending == true && tweets[j].tweetID > tweets[j + 1].tweetID) ||
                 (ascending != true && tweets[j].tweetID < tweets[j + 1].tweetID)) {
                    Tweet temp = tweets[j];
                    tweets[j] = tweets[j + 1];
                    tweets[j + 1] = temp;

                    //swapped = true; 
                 }
            }
        }
    } else if(sortBy == "retweetCount") {
        //sort by retwet_count
        for(int i = 0; i < tweets.size() - 1; i++) {
            //bool swapped = false;

            for(int j = 0; j < tweets.size() - i - 1; j++) {
                //compare based on ascending || decending order
                if((ascending == true && tweets[j].retweetCount > tweets[j + 1].retweetCount) ||
                 (ascending != true && tweets[j].retweetCount < tweets[j + 1].retweetCount)) {
                    Tweet temp = tweets[j];
                    tweets[j] = tweets[j + 1];
                    tweets[j + 1] = temp;

                    //swapped = true; 
                 }
            }
        }        
    } else if(sortBy == "favoriteCount") {
        //sort by favorite count
        for(int i = 0; i < tweets.size() - 1; i++) {
        //bool swapped = false;

            for(int j = 0; j < tweets.size() - i - 1; j++) {
                //compare based on ascending || decending order
                if((ascending == true && tweets[j].favoriteCount > tweets[j + 1].favoriteCount) ||
                 (ascending != true && tweets[j].favoriteCount < tweets[j + 1].favoriteCount)) {
                    Tweet temp = tweets[j];
                    tweets[j] = tweets[j + 1];
                    tweets[j + 1] = temp;

                    //swapped = true; 
                 }
            }
        }
    } else {
        std::cerr << "ERROR: No such sorting type!\n";
    }
}

void insertionSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending)
{
    //decide which field to sort by
    if(sortBy == "tweetID") {
        //sort by tweetID
        for(int i = 1; i < tweets.size(); i++) {
            //i = 0 is counted as already sorted
            Tweet temp = tweets[i];
            int j = i - 1;

            while((j >= 0 && ascending == true && tweets[j].tweetID > temp.tweetID) ||
            (j >= 0 && ascending == false && tweets[j].tweetID < temp.tweetID)) {
                tweets[j + 1] = tweets[j];
                j = j - 1;
            }
            tweets[j + 1] = temp;
        }
    } else if (sortBy == "retweetCount") {
        for(int i = 1; i < tweets.size(); i++) {
            //i=0 is counted as already sorted
            Tweet temp = tweets[i];
            int j = i - 1;

            while(j >= 0 && ((ascending == true && tweets[j].retweetCount > temp.retweetCount) ||
            (ascending != true && tweets[j].retweetCount < temp.retweetCount))) {
                tweets[j + 1] = tweets[j];
                j = j - 1;
            }
            tweets[j + 1] = temp;
        }
    } else if (sortBy == "favoriteCount") {
        for(int i = 1; i < tweets.size(); i++) {
            //i=0 is counted as already sorted
            Tweet temp = tweets[i];
            int j = i - 1;

            while(j >= 0 && ((ascending == true && tweets[j].favoriteCount > temp.favoriteCount) ||
            (ascending != true && tweets[j].favoriteCount < temp.favoriteCount))) {
                tweets[j + 1] = tweets[j];
                j = j - 1;
            }
            tweets[j + 1] = temp;
        }
    } else {
        std::cerr << "ERROR: No such sorting type!\n";
    }
}

void merge(std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //Temporary vectors
    std::vector<Tweet> L(n1), R(n2);

    //Copy data to temp vectors
    for(int i = 0; i < n1; i++) {
        L[i] = tweets[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = tweets[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;

    if(sortBy == "tweetID") {
        //sort by tweetID
        while(ascending == true && i < n1 && j < n2) {
            //ascending order
            if(L[i].tweetID <= R[j].tweetID) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }

        while(ascending != true && i < n1 && j < n2) {
            //descending order
            if(L[i].tweetID >= R[j].tweetID) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }

    } else if(sortBy == "retweetCount") {
        //sort by tweetID
        while(ascending == true && i < n1 && j < n2) {
            //ascending order
            if(L[i].retweetCount <= R[j].retweetCount) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }

        while(ascending != true && i < n1 && j < n2) {
            //descending order
            if(L[i].retweetCount >= R[j].retweetCount) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }

    } else if(sortBy == "favoriteCount") {
        //sort by tweetID
        while(ascending == true && i < n1 && j < n2) {
            //ascending order
            if(L[i].favoriteCount <= R[j].favoriteCount) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }

        while(ascending != true && i < n1 && j < n2) {
            //descending order
            if(L[i].favoriteCount >= R[j].favoriteCount) {
                tweets[k] = L[i];
                i++;
            } else {
                tweets[k] = R[j];
                j++;
            }
            k++;
        }
    } else {
        std::cerr << "ERROR: No such sorting type!\n";
    }

    //Copy the remaining element of temp arrays in here
    while(i < n1) {
        tweets[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        tweets[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) 
{
    if(left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(tweets, left, mid, sortBy, ascending);
    mergeSort(tweets, mid + 1, right, sortBy, ascending);
    merge(tweets, left, mid, right, sortBy, ascending);
}