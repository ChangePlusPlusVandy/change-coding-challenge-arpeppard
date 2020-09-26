//
// Created by Amanda Peppard
//

#ifndef CHANGE_CODING_CHALLENGE_ARPEPPARD_TWEET_H
#define CHANGE_CODING_CHALLENGE_ARPEPPARD_TWEET_H

#include <string>
class Tweet {
public:
    //Constructor
    Tweet();

    //sets tweet text to string tweet
    void setTweet(std::string twitterInput);

    //accesses tweet text
    std::string getTweet();

    //marks bool used as true
    void markUsed();

    //if Tweet isUsed, it cannot be displayed again in the game

    bool isUsed();

    void setUserName(std::string name);

    std::string getUserName();

private:
    std::string tweet;
    bool used;
    std::string userName;
};


#endif //CHANGE_CODING_CHALLENGE_ARPEPPARD_TWEET_H
