#ifndef GUESSCHECKER_H
#define GUESSCHECKER_H
#include <string>
using namespace std;
namespace Utils
{

class GuessChecker
{
    public:
        void setWordleAnswer(const string& userGuess);
        int* checkGuessAsCorrect(const string& userGuess);
        GuessChecker();
        virtual ~GuessChecker();

    protected:

    private:
        string answer;
};
}

#endif // GUESSCHECKER_H
