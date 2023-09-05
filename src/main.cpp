/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#include <dpp/dpp.h>

#include <boost/process.hpp>

#include <fstream>
#include <iostream>
#include <future>

#include "castoro.hpp"
#include "commands/ping.hpp"
#include "commands/new.hpp"

namespace proc = boost::process;
using namespace std::literals;

// castoro
castoro mycastoro;

int main(){
    // load key
    std::ifstream keyfile{"../privatekey.key"};
    
    if(!keyfile.is_open()){
        std::cerr << "file not presente" << std::endl;
        
        return 1;
    }

    // estract key
    std::string key;
    std::getline(keyfile, key);

    // init bot
    dpp::cluster bot(key);

    // commands
    mycastoro.advanced_bind<ping>();
    mycastoro.advanced_bind<new_story>();
 
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        mycastoro.handle(bot, event);
    });

    bot.on_ready([&](const dpp::ready_t & event) {
        mycastoro.advertise(bot);
    });

    /* Start bot */
    bot.start(dpp::st_wait);
};