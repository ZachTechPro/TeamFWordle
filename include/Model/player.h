#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
namespace model
{
class Player
{
public:
    string printPlayer();
    void setUserName(const string& userName);
    void setTotalGamesPlayed(int totalGames);
    void setWinPercentage(double winPercentage);
    void setcurrentWinStreak(int currWinStreak);
    void setMaxWinStreak(int winStreak);
    double getWinPercentage();
    string getUserName();
    int getTotalGamesPlayed();
    int getCurrentWinStreak();
    int getMaxWinStreak();
    int getOneTryWins();
    int getTwoTryWins();
    int getThreeTryWins();
    int getFourTryWins();
    int getFiveTryWins();
    int getSixTryWins();
    bool getIsOnWinStreak();
    void setWinStreakStatus(bool status);
    void setOneTryWins(int newWinNumber);
    void setTwoTryWins(int newWinNumber);
    void setThreeTryWins(int newWinNumber);
    void setFourTryWins(int newWinNumber);
    void setFiveTryWins(int newWinNumber);
    void setSixTryWins(int newWinNumber);
    void updateWinPercentage();
    void setIsOnWinStreak(bool isWinStreak);
    Player(const string& name, int totalGamesPlayed, double winPercentage, int currentWinStreak, int maxWinStreak, int winDistribution[6], bool isOnWinStreak);
    Player();
    virtual ~Player();

protected:

private:
    int* winDistribution;
    string userName;
    bool isOnWinStreak;
    double winPercentage;
    int totalGamesPlayed;
    int currentWinStreak;
    int maxWinStreak;
    int oneTry;
    int twoTry;
    int threeTry;
    int fourTry;
    int fiveTry;
    int sixTry;
};
}
#endif // PLAYER_H
