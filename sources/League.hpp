#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Team.hpp"
#include "Game.hpp"
#include "Schedule.hpp"

namespace basketball
{
    class League
    {
        private:
            std::vector <Team *> teams;
            bool leagueOver;

        public:
            League();
            League(std::vector <Team *> const  &teams);

            ~League();

            std::vector<Team *> getTeams(){
                return teams;
            }
            void startLeague();

            void sortTeams();

            void statistics(int n);
            void leadingTeams(int n);
            Team * longestWinStreak();
            Team * longestLoseStreak();
            void morePoints();         
    };
}
