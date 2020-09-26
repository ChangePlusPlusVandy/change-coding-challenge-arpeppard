//
// Created by Amanda Peppard
// I had some trouble accessing the Twitter API, but I included a file of 25 tweets from Kanye West and
// Elon Musk to show my logic. Thank you!

#include <string>
#include "Tweet.h"
#include <iostream>
#include <fstream>


const int MAX_NUM_TWEETS = 25;

//helper method that opens input file and verifies if it opened successfully
void openInputFile(std::ifstream &infile, const std::string &fname);

void processFile(const std::string &fname, Tweet twitterList[], std::string userName);


std::string getUserInput();

int main(){
std::string elonTweets = "tweets/elontweets";
std::string kanyeTweets = "tweets/kanyetweets";

Tweet elonTweetList[MAX_NUM_TWEETS];
Tweet kanyeTweetList[MAX_NUM_TWEETS];

std::ifstream infileElon;
openInputFile(infileElon, "/Users/amandapeppard/Desktop/elontweets.txt");
processFile("/Users/amandapeppard/Desktop/elontweets.txt", elonTweetList, "Elon");

std::ifstream infileKanye;
openInputFile(infileKanye, "/Users/amandapeppard/Desktop/kanyetweets.txt");
processFile("/Users/amandapeppard/Desktop/kanyetweets.txt", kanyeTweetList, "Kanye");

std::cout << "Welcome to Kanye Musk!" << std::endl;
std::cout << "You will be prompted with 10 tweets by either Elon Musk or Kanye West." << std::endl;
std::cout << "Can you guess who wrote the tweet - Elon or Kanye?" << std::endl;
std::cout << "Type \"Elon\" if you think it is by Elon Musk or \"Kanye\" if you think it is by Kanye West" << std::endl;
std::cout << "Ready? Begin!" << std::endl;
std::cout << std::endl;

uint32_t answerTrack = 0;

for(uint32_t i = 1; i <= 10; ++i){
    std::string randomTweet;
    std::string randomUserName;
    uint32_t elonOrKanye = rand() % 2;
    uint32_t tweetRand = rand() % 25;
    if(elonOrKanye == 0){
        randomTweet = elonTweetList[tweetRand].getTweet();
        randomUserName = "Elon";
        while(elonTweetList[tweetRand].isUsed()){
            tweetRand = rand() % 25;
            randomTweet = elonTweetList[tweetRand].getTweet();
        }
        elonTweetList[tweetRand].markUsed();
    }
    else {
        randomTweet = kanyeTweetList[tweetRand].getTweet();
        randomUserName = "Kanye";
        while(kanyeTweetList[tweetRand].isUsed()){
            tweetRand = rand() % 25;
            randomTweet = kanyeTweetList[tweetRand].getTweet();
        }
        kanyeTweetList[tweetRand].markUsed();
    }

    std::cout << "Tweet " << i << ": " << randomTweet << std::endl;
    std::cout << "Elon or Kanye?" << std::endl;
    std::string userInput = getUserInput();
    if(userInput == "Elon"){
        if(randomUserName == "Elon"){
            std::cout << "Correct! This tweet is by Elon Musk" << std::endl;
            std::cout << "+1 point!" << std::endl;
            ++answerTrack;
        }
        else {
            std::cout << "Oops! This tweet is by Kanye West" << std::endl;
        }
    }
    else {
        if(randomUserName == "Kanye"){
            std::cout << "Correct! This tweet is by Kanye West" << std::endl;
            std::cout << "+1 point!" << std::endl;
            ++answerTrack;
        }
        else {
            std::cout << "Oops! This tweet is by Elon Musk" << std::endl;
        }
    }
}
    std::cout << "Here are your statistics: " << std::endl;
    std::cout << "You guessed " << answerTrack << "/10 correctly." << std::endl;
    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}



void openInputFile(std::ifstream &infile, const std::string &fname){
    infile.open(fname.c_str());
    if(infile.fail()){
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }
}

void processFile(const std::string &fname, Tweet twitterList[], std::string userName) {
    //open desired file
    std::ifstream infile;
    openInputFile(infile, fname);
    //read and process tweets, putting them into twitterList array
    std::string readTweet;
    uint32_t i = 0;
    while (std::getline(infile, readTweet) && i < MAX_NUM_TWEETS) {
        twitterList[i].setTweet(readTweet);
        ++i;
        twitterList[i].setUserName(userName);
    }
    //close file
    infile.close();
}

std::string getUserInput(){
    std::string userInput;
    std::cin >> userInput;
    while(userInput != "Elon" && userInput!= "elon" && userInput != "Kanye" && userInput != "kanye"){
        std::cout << "Please enter Elon or Kanye";
        std::cin >> userInput;
    }
    if(userInput == "Elon" || userInput == "elon"){
        return "Elon";
    }
    return "Kanye";
}

