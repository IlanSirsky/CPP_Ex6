#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Game.hpp"
#include "Team.hpp"

namespace basketball
{
    class Schedule{
        private:
            std::vector <Team *> teams;
        
        public:
            Schedule(std::vector <Team *> const  &teams){
                this->teams = teams;
            }

            std::vector<Game *> createSchedule(){
                std::vector<Game *> schedule;
                for (u_int i = 0; i < this->teams.size(); ++i) {
                    for (u_int j = i; j < this->teams.size(); ++j) {
                        if(i==j){
                            continue;
                        }
                        schedule.push_back(new Game(this->teams.at(i), this->teams.at(j)));
                        schedule.push_back(new Game(this->teams.at(j), this->teams.at(i)));
                    }
                }
                return schedule;
            }
    };
}