#include <iostream>
#include "image_menu.h"
#include <string>



std::string getString( ActionData& action_data, const std::string& prompt ) {
    std::string response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;    }

int getInteger( ActionData& action_data, const std::string& prompt ) {
    int response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;    }

double getDouble( ActionData& action_data, const std::string& prompt ) {
    double response;
    action_data.getOS() << prompt;
    action_data.getIS() >> response;
    return response;    }

int askQuestions3(ActionData& action_data) {
    std::string color = getString( action_data, "What is your favorite color? ") ;
    int integer = getInteger( action_data, "What is your favorite integer? " );
    double dwble = getDouble( action_data, "What is your favorite number? " );
    for (int i = 0; i < integer; i++) {
        action_data.getOS() << i+1 << " " << color << " " << dwble << std::endl;    }
    return integer;   }

std::string getChoice( ActionData& action_data ) {
    std::string choice = getString( action_data, "Choice? " );
    return choice;
}

void commentLine( ActionData& action_data ) {
/*
    char c = 0;
    action_data.getIS().read((char*)&c, sizeof(c));
    if (action_data.getIS().good() && c != 10)
        commentLine( action_data );
*/
    char c = 0;
    while ( action_data.getIS().good() && c != '\n' ) {
        action_data.getIS().read(&c, 1);
    }}
  

void quit(ActionData& action_data) {
    action_data.setDone();
}

