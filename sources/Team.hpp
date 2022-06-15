#pragma once
#include <iostream>
#include <string>

namespace basketball
{
    class Team
    {
    private:
        std::string name;
        double talent;

        int wins = 0;
        int loses = 0;

        int score = 0;
        int scoreAgainst = 0;
        int scoreDiffernce = 0;

        int currWinStreak = 0;
        int currLoseStreak = 0;
        int maxWinStreak = 0;
        int maxLoseStreak = 0;

    public:
        Team(std::string const &name, double talent)
        {
            if (name.find("\t") != std::string::npos || name.find("\n") != std::string::npos || name.empty() || name == " " || name.find("\r") != std::string::npos)
            {
                throw std::invalid_argument("Invalid team name\n");
            }
            if (talent < 0 || talent > 1)
            {
                throw std::invalid_argument("Invalid talent need to be in range [0,1]\n");
            }
            this->name = name;
            this->talent = talent;
        }

        std::string getName()
        {
            return name;
        }
        double getTalent() const
        {
            return talent;
        }

        int getWins() const
        {
            return wins;
        }
        int getLoses() const
        {
            return loses;
        }

        void win()
        {
            wins++;
        }

        void lose()
        {
            loses++;
        }

        int getScore() const
        {
            return score;
        }
        int getScoreAgainst() const
        {
            return scoreAgainst;
        }
        void setScore(int score) 
        {
            this->score += score;
        }
        void setScoreAgainst(int scoreAgainst)
        {
            this->scoreAgainst += scoreAgainst;
        }
        int getScoreDiffernce()
        {
            scoreDiffernce = score - scoreAgainst;
            return scoreDiffernce;
        }

        int getWinStreak() const
        {
            return currWinStreak;
        }
        int getLoseStreak() const
        {
            return currLoseStreak;
        }
        void setWinStreak(int num)
        {
            if (num == 0){
                currWinStreak = 0;
            }
            else{
                currWinStreak += num;
                if (currWinStreak > maxWinStreak)
                {
                    maxWinStreak = currWinStreak;
                }
            }
            
        }
        void setLoseStreak(int num)
        {
            if (num == 0){
                currLoseStreak = 0;
            }
            else{
                currLoseStreak += num;
                if (currLoseStreak > maxLoseStreak)
                {
                    maxLoseStreak = currLoseStreak;
                }
            }
        }

        int getMaxWinStreak() const
        {
            return maxWinStreak;
        }
        int getMaxLoseStreak() const
        {
            return maxLoseStreak;
        }
    };
}
