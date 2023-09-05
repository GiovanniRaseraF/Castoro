/*
Authors: 
+ Giovanni Rasera : c++ code
+ Lorenzo Mancini : database and specifications

Links:
+ https://github.com/GiovanniRaseraF
+ https://github.com/MancioLollo
*/

#pragma once

#include <dpp/dpp.h>
#include <boost/algorithm/string.hpp>

#include <vector>
#include <string>
#include <functional>
#include <map>
#include <chrono>
#include <future>
#include <tuple>
#include <set>
using namespace std::literals;

// typedefs
typedef const dpp::slashcommand_t slash_command;
typedef const dpp::form_submit_t form_submit;
typedef dpp::cluster cluster;
typedef std::function<void(cluster&, slash_command&)> slash_event_func;
typedef std::function<void(cluster&, form_submit&)> form_event_func;

#define MAX_DPP_TEXT_LEN 4000