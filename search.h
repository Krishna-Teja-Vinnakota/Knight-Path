#ifndef SEARCH_H
#define SEARCH_H
#include <functional>
#include <queue>
#include <list>
#include <state.h>

class Search
{
public:
    Search(std::pair<int,int> start, std::pair<int,int> goal);
    std::list<std::pair<int,int>> getPath();
    bool isGoal(const State &state);
    std::vector<State*> getSuccessors(State* state);

private:
    bool perform();
    float heuristic(int x1, int x2, int y1, int y2);
    bool isValidPos(int row, int col);
    int visited[8][8] {{0}};
    std::priority_queue<State*, std::vector<State*>, State::Compare> fringe;
    State *startState;
    State *endState;
    std::pair<int,int> startPos, goalPos;
    int rowDiff[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int colDiff[8] = { -1, 1, 1, -1, 2, -2, 2, -2 };
};

#endif // SEARCH_H
