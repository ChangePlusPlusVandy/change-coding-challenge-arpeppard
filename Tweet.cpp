//
// Created by Amanda Peppard
//

#include "Tweet.h"

Tweet::Tweet() :tweet(""), used(false), userName(""){
}


void Tweet::setTweet(std::string twitterInput){
    tweet = twitterInput;
}

std::string Tweet::getTweet() {
    return tweet;
}

void Tweet::markUsed() {
    if(!used){
        used = true;
    }
}

bool Tweet::isUsed() {
    return used;
}

void Tweet::setUserName(std::string name) {
    userName = name;
}

std::string Tweet::getUserName(){
    return userName;
};