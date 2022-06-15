#include "Game.hpp"
int const MAX_SCORE = 100;
int const MIN_HOME = 55;
int const MIN_AWAY = 50;
int const BONUS = 10;

namespace basketball{

    int Game::randomScore(int min, int max){
        return rand() % (max - min) + min;
    }

    Team * Game::getWinner(){
        int homeScore = randomScore(MIN_HOME, MAX_SCORE);
        int awayScore = randomScore(MIN_AWAY, MAX_SCORE);
        homeScore += (int)(homeTeam->getTalent() * BONUS);
        awayScore += (int)(awayTeam->getTalent() * BONUS);

        homeTeam->setScore(homeScore);
        awayTeam->setScore(awayScore);
        homeTeam->setScoreAgainst(awayScore);
        awayTeam->setScoreAgainst(homeScore);

        if (homeScore > awayScore){ //home team won
            homeTeam->win();
            homeTeam->setWinStreak(1);
            homeTeam->setLoseStreak(0);

            awayTeam->lose();
            awayTeam->setWinStreak(0);
            awayTeam->setLoseStreak(1);
            
            std::cout << homeTeam->getName() << " " << homeScore << " - " << awayScore << " " << awayTeam->getName() << std::endl;
            std::cout << "Winner: " << homeTeam->getName() << std::endl; 
            return homeTeam;
        }
        //away team won or tie game 
        homeTeam->lose();
        homeTeam->setWinStreak(0);
        homeTeam->setLoseStreak(1);

        awayTeam->win();
        awayTeam->setWinStreak(1);
        awayTeam->setLoseStreak(0);

        std::cout << homeTeam->getName() << " " << homeScore << " - " << awayScore << " " << awayTeam->getName() << std::endl;
        std::cout << "Winner: " << awayTeam->getName() << std::endl;
        return awayTeam;
    }

}