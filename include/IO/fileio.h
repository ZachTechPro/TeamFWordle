#ifndef FILEIO_H
#define FILEIO_H
#include <string>

using namespace std;

namespace IO
{

class FileIo
{
    public:
        string loadWords();
        FileIo();
        virtual ~FileIo();

    protected:

    private:
};
}
#endif // FILEIO_H
