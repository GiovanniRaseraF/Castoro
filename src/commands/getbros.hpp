/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#pragma once

#include "./command.hpp"
#include "../castorodb.hpp"

struct getbros {
    // slash command
    static std::string command;

    // description
    static std::string description;

    // func
    static void on_event(cluster &bot, slash_command &event){
        std::vector<std::string> bros = castorodb::list_bros();
        std::string tosend{};

        for(auto bro : bros) tosend += bro + "\n";

        event.reply(tosend);
    }

    static void on_form(cluster &bot, form_submit& event){
        
    }
};

// init
std::string getbros::command{"getbros"};
std::string getbros::description{"Stampa la lista dei bro"};