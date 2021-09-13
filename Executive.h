#ifndef EXECUTIVE_H
#define EXECUTIVE_H

class Executive {
    public:
    Executive();
    ~Executive();
    void BeginGame();

    private:
    char col;
    int originRow;
    char direction;
    int shipsize;
    int originCol = 0;
    char colLetter = 'A';


};
#endif