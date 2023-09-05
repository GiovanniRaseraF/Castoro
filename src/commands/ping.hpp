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

struct ping /*: public command*/ {
    // slash command
    static std::string command;

    // description
    static std::string description;

    // func
    static void on_event(cluster &bot, slash_command &event){
        auto fu = std::async(std::launch::async, [](){
            std::this_thread::sleep_for(500ms);

            return "ping come classe separata";
        });
        fu.wait();
        auto ret = fu.get();

        event.reply(ret);
    }

    static void on_form(cluster &bot, form_submit& event){ 
        std::cerr << "non ci sono form per ping" << std::endl;
    }
};

// init
std::string ping::command{"ping"};
std::string ping::description{"Fai un test di ping"};