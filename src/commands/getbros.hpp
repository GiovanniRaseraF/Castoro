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
        pqxx::result bros_pqres = castorodb::list_bros_raw();
        std::string tosend{};

        for(auto bro : bros_pqres){
            std::string n = (bro["nome"].as<std::string>());
            std::string c = (bro["cognome"].as<std::string>());
            std::string ls = (bro["lista_soprannomi"].as<std::string>());

            tosend += n + " " + c + " [" + ls + "]\n";
        }

        event.reply(tosend);
    }

    static void on_form(cluster &bot, form_submit& event){
        
    }
};

// init
std::string getbros::command{"bros"};
std::string getbros::description{"Stampa la lista dei bro"};