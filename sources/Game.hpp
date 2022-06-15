#pragma once

#include <iostream>
#include <string>

#include "Team.hpp"

namespace basketball
{
    class Game
    {
        private:
            Team * homeTeam;
            Team * awayTeam;
        
        public:
            Game(Team * homeTeam, Team * awayTeam){
                this->homeTeam = homeTeam;
                this->awayTeam = awayTeam;
            }

            Team * getHomeTeam(){
                return homeTeam;
            }
            Team * getAwayTeam(){
                return awayTeam;
            }

            static int randomScore(int min, int max);

            Team * getWinner();        
    };
}