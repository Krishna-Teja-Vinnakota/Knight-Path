#include "state.h"

State::State(int r, int c, int g, float hx)
{
    row = r;
    col = c;
    movesDone = g;
    h = hx;

    parent = nullptr;
    cost = movesDone + h;
}

bool State::Compare::operator()(const State *a, const State *b) const
{
    return a->movesDone > b->movesDone;
}
