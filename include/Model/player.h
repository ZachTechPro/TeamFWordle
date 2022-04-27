#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
namespace model
{
class Player
{
    public:
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

        Player();
        virtual ~Player();

    protected:

    private:
        string userName;
        double winPercentage;
        int totalGamesPlayed;
        int currentWinStreak;
        int maxWinStreak;
};
}
#endif // PLAYER_H
