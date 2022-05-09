#include "search.h"
#include <cmath>

Search::Search(std::pair<int,int> start, std::pair<int,int> goal)
{
    startPos = start; goalPos = goal;
}

std::list<std::pair<int, int>> Search::getPath()
{
    std::list<std::pair<int,int>> path;
    perform();
    State* s = endState;

    while (s != nullptr) {
        path.push_front( std::make_pair(s->row, s->col) );
        s = s->parent;
    }

    return path;
}

bool Search::perform()
{
    int h = heuristic(startPos.first, goalPos.first, startPos.second, goalPos.second);
    startState = new State(startPos.first, startPos.second, 0, h);
    startState->parent = nullptr;
    fringe.push(startState);
    while(!fringe.empty()) {
        State* frontier = fringe.top(); fringe.pop();
        visited[frontier->row][frontier->col] = 1;
        if (isGoal(*frontier)) {
            endState = frontier;
            return true;
        }
        for (State* child : getSuccessors(frontier))
        {
            fringe.push(child);
        }
    }
    return false;
}

std::vector<State*> Search::getSuccessors(State *curState)
{
    std::vector<State*> children;
    int newRow, newCol;
    float h;
    for (int i=0; i<8; i++) {
        newRow = curState->row + rowDiff[i];
        newCol = curState->col + colDiff[i];
        if (isValidPos(newRow, newCol) && !visited[newRow][newCol])
        {
            h = heuristic(newRow, goalPos.first, newCol, goalPos.second);
            State* childState = new State(newRow, newCol, curState->movesDone+1, h);
            childState->parent = curState;
            children.push_back(childState);
        }
    }
    return children;
}

float Search::heuristic(int x1, int x2, int y1, int y2)
{
    return 0.33*(abs(x2-x1) + abs(y2-y1));
}

bool Search::isValidPos(int row, int col)
{
    return (row > -1) && (col > -1) && (row < 8) && (col < 8);
}

bool Search::isGoal(const State &state)
{
    return (state.row == goalPos.first) && (state.col == goalPos.second);
}
