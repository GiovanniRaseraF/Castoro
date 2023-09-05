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

struct new_story {
    // slash command
    static std::string command;

    // description
    static std::string description;

    // func
    static void on_event(cluster &bot, slash_command &event){
        auto ret = "Vuoi creare una storia! bravo!";

        event.reply(ret);
    }
};

// init
std::string new_story::command{"new"};
std::string new_story::description{"Crea una nuova storia"};