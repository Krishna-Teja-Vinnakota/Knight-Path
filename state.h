#ifndef STATE_H
#define STATE_H


class State
{
public:
    State(int r, int c, int g, float h);
    int row;
    int col;
    int movesDone;
    float h;
    float cost;
    State *parent;
    class Compare
    {
    public:
        bool operator() (const State* a, const State* b) const;
    };
};

#endif // STATE_H
