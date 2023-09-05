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
    mycastoro.bind_command("ping", "Fai un test di ping", [&](cluster& bot, slash_command& event){
        auto fu = std::async(std::launch::async, [](){
            std::this_thread::sleep_for(2s);

            return "test di sottoprocesso max 2 secondi";
        });
        fu.wait();
        auto ret = fu.get();

        event.reply(ret);
    });
 
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