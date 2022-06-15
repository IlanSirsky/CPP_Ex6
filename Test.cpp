#include "doctest.h"
#include "sources/League.hpp"
using namespace basketball;
using namespace std;

TEST_CASE("Teams"){
    vector<Team*> teams;
    CHECK_THROWS(teams.emplace_back(new Team("", 0)));
    CHECK_THROWS(teams.emplace_back(new Team("", -1)));
    CHECK_THROWS(teams.emplace_back(new Team("", 1.5)));
    CHECK_THROWS(teams.emplace_back(new Team("", -1.5)));
    CHECK_THROWS(teams.emplace_back(new Team("\t", 0.5)));
    CHECK_THROWS(teams.emplace_back(new Team("\n", 0.5)));
    CHECK_THROWS(teams.emplace_back(new Team("\r", 0.5)));
    CHECK_THROWS(teams.emplace_back(new Team(" ", 0.5)));
    CHECK_THROWS(teams.emplace_back(new Team("\t\n\r ", 0.5)));

    CHECK_NOTHROW(teams.emplace_back(new Team("team1", 0.5)));
    CHECK_NOTHROW(teams.emplace_back(new Team("team2", 0.2)));
    CHECK_NOTHROW(teams.emplace_back(new Team("team3", 0.99)));
    CHECK_NOTHROW(teams.emplace_back(new Team("team4", 0.01)));
    CHECK_NOTHROW(teams.emplace_back(new Team("team5", 1)));
}

TEST_CASE("League"){
    League * league = new League();
    CHECK_THROWS(league->statistics(5));
    CHECK_THROWS(league->leadingTeams(5));
    CHECK_THROWS(league->longestWinStreak());
    CHECK_THROWS(league->longestLoseStreak());
    CHECK_THROWS(league->morePoints());
    CHECK_NOTHROW(league->startLeague());
    CHECK_NOTHROW(league->statistics(5));
    CHECK_NOTHROW(league->leadingTeams(5));
    CHECK_NOTHROW(league->longestWinStreak());
    CHECK_NOTHROW(league->longestLoseStreak());
    CHECK_NOTHROW(league->morePoints());
    CHECK_THROWS(league->startLeague());
}