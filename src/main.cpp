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
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>

#include <fstream>
#include <iostream>
#include <future>

#include "castoro.hpp"
#include "commands/ping.hpp"
#include "commands/new.hpp"
#include "commands/getbros.hpp"

namespace proc = boost::process;
using namespace std::literals;
using namespace boost;
using namespace boost::program_options;

// castoro
castoro mycastoro;

int main(int argc , char **argv){
    // creating menus
    options_description desc("Castoro Bot");

    // add command line options
    desc.add_options()
        ("help,h", "Print all available commands.")
        ("key,k", value<std::string>(), "File name where api key is stored.");

    // parse aguments
    variables_map vm;
    try
    {
        store(command_line_parser(
        argc, argv).options(desc).run(), vm);
        notify(vm);
    } catch (std::exception &e)
    {
        std::cout << std::endl << e.what() << std::endl;
        std::cout << desc << std::endl;
    }
    // help
    if(vm.count("help")){
        std::cout << desc << std::endl;
    }

    // insert key
    std::string key;
    if(vm.count("key")){
        // load key
        std::ifstream keyfile{vm["key"].as<std::string>()};
    
        if(!keyfile.is_open()){
            std::cerr << "file not presente" << std::endl;
        
            return 1;
        }

        // estract key
        std::getline(keyfile, key);
    }else{
        std::cerr << "No key specified" << std::endl;
        std::cerr << "Exiting !" << std::endl;
        exit(1);
    }

    // init bot
    dpp::cluster bot(key);

    // commands
    mycastoro.advanced_bind<getbros>();
    mycastoro.advanced_bind<new_story>();
    mycastoro.advanced_bind<ping>();
 
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        mycastoro.handle(bot, event);
    });

    bot.on_form_submit([&](const dpp::form_submit_t & event) {
        mycastoro.on_form_handle(bot, event);
    });

    bot.on_ready([&](const dpp::ready_t & event) {
        mycastoro.advertise(bot);
    });

    /* Start bot */
    bot.start(dpp::st_wait);
};