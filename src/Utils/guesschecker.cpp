#include "guesschecker.h"
#include <string>
#include <iostream>
using namespace std;
namespace Utils
{
/** \brief Constructor
 */
GuessChecker::GuessChecker()
{
    this-> answer = "train"; // for testing purposes
}

/** \brief Will consume the user's guess and it will check to the degree of equality
 * to the answer.
 * \param userGuess const string&
 * \return int* -- the pointer to the beginning of the int array that's returned.
 *
 *  correctPosCorrectLetter = flag of 3
 *  correctLetterWrongPos   = flag of 2
 *  wrongLetter             = flag of 1
 */
int* GuessChecker::checkGuessAsCorrect(const string& userGuess)
{
    int* resultFlags = new int[5];
    for (std::string::size_type i = 0; i < userGuess.size(); i++)
    {

        char currentGuessLetter = userGuess[i];
        char currentAnswerLetter = this-> answer[i];
        if(this-> answer.find(currentGuessLetter) != std::string::npos)
        {
            resultFlags[i] = (currentAnswerLetter == currentGuessLetter) ? 3 : 2;
        }

        else
        {
            resultFlags[i] = 1;
        }

    }
    cout<<to_string(resultFlags[1]) + "" + to_string(resultFlags[2]) + "" + to_string(resultFlags[3]) + "" + to_string(resultFlags[4]) + "" + to_string(resultFlags[0]);
    return resultFlags;
}

/** \brief desctructor
 */
GuessChecker::~GuessChecker()
{
    //dtor
}
}
