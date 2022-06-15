#include "League.hpp"

int const MAX_TEAMS = 20;
using namespace std;
namespace basketball{

    double randomTalent(){
        return (double)rand() / RAND_MAX;
    }

    League::League(){
        leagueOver = false;

        for (int i = 0; i < MAX_TEAMS; i++){
            this->teams.emplace_back(new Team(to_string(i), randomTalent()));
        }
    }

    League::League(vector <Team *> const &teams){
        if (teams.size() > MAX_TEAMS){
            throw invalid_argument("Too many teams\n");
        }

        leagueOver = false;
        this->teams = teams;
        for (u_int i = teams.size(); i < MAX_TEAMS; i++){
            this->teams.emplace_back(new Team(to_string(i), randomTalent()));
        }
    }

    League::~League(){
        for (Team * team : teams){
            delete team;
        }
    }

    void League::startLeague(){
        if (leagueOver){
            throw invalid_argument("League is over\n");
        }
        Schedule schedule(this->teams);
        vector <Game *> games = schedule.createSchedule();
        for (Game * game : games){
            game->getWinner();
        }
        leagueOver = true;
        sortTeams();

    }

    void League::sortTeams(){
        sort(teams.begin(), teams.end(), [](Team * a, Team * b){
            return (a->getWins() > b->getWins()) && (a->getLoses() < b->getLoses());
        });
    }

    void League::statistics(int n){
        if (!leagueOver){
            throw invalid_argument("League is not over\n");
        }
        if (n > teams.size()){
            throw invalid_argument("Too many teams\n");
        }
        leadingTeams(n);
        Team * winStreak = longestWinStreak();
        Team * loseStreak = longestLoseStreak();
        cout << "Longest win streak: " << winStreak->getName() << " with " << winStreak->getMaxWinStreak() << " wins in a row" << endl;
        cout << "Longest lose streak: " << loseStreak->getName() << " with " << loseStreak->getMaxLoseStreak() << " loses in a row" << endl;
        cout << endl;

        morePoints();
    }

    void League::leadingTeams(int n){
        if (!leagueOver){
            throw invalid_argument("League is not over\n");
        }
        cout << "The top teams are:" << endl;
        for (u_int i = 0; i < n; i++){
            cout << i+1 << ") " << teams.at(i)->getName() << ": " << teams.at(i)->getWins() << " wins, " << teams.at(i)->getLoses() << " loses."
            << " Score: " << teams.at(i)->getScore() << " points, " << teams.at(i)->getScoreAgainst() << " points against"
            << " Score difference: " << teams.at(i)->getScoreDiffernce() << endl;
        }
        cout << endl;
    }

    Team * League::longestWinStreak(){
        if (!leagueOver){
            throw invalid_argument("League is not over\n");
        }
        int max = 0;
        Team * longestWinStreak = teams[0];
        for (Team * team : teams){
            if (team->getMaxWinStreak() > max){
                max = team->getMaxWinStreak();
                longestWinStreak = team;
            }
        }
        return longestWinStreak;
    }

    Team * League::longestLoseStreak(){
        if (!leagueOver){
            throw invalid_argument("League is not over\n");
        }
        int max = 0;
        Team * longestLoseStreak = teams[0];
        for (Team * team : teams){
            if (team->getMaxLoseStreak() > max){
                max = team->getMaxLoseStreak();
                longestLoseStreak = team;
            }
        }
        return longestLoseStreak;
    }

    void League::morePoints(){
        if (!leagueOver){
            throw invalid_argument("League is not over\n");
        }
        cout << "Teams that scored more than they suffered:" << endl;
        for (Team * team : teams){
            if (team->getScoreDiffernce() > 0){
                cout << team->getName() << "'s ratio is: " << team->getScore() << " - " << team->getScoreAgainst() << endl;
            }
        }
        cout << endl;
    }

}