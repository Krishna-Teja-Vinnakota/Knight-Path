#include "search.h"
#include <cmath>
#include <QDebug>

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
    int ex = 0;
    int h = heuristic(startPos.first, goalPos.first, startPos.second, goalPos.second);
    startState = new State(startPos.first, startPos.second, 0, h);
    startState->parent = nullptr;
    fringe.push(startState);
    while(!fringe.empty()) {
        State* frontier = fringe.top(); fringe.pop();
        if (isGoal(*frontier)) {
            endState = frontier;
            qDebug() << "\nexpanding (" << frontier->row << "," << frontier->col << ") ... g ="
                     << frontier->movesDone << ", h =" << frontier->h; ex++;
            if (frontier->parent != nullptr)
                qDebug() << "child of (" << frontier->parent->row << "," << frontier->parent->col << ")\n";
                qDebug() << "GOAL!\n";
                qDebug() << "\nNodes Expanded: " << ex ;
            return true;
        }
        if (visited[frontier->row][frontier->col] == 0)
        {
            visited[frontier->row][frontier->col] = 1;
            qDebug() << "\nexpanding (" << frontier->row << "," << frontier->col << ") ... g ="
                     << frontier->movesDone << ", h =" << frontier->h; ex++;
            if (frontier->parent != nullptr)
                qDebug() << "child of (" << frontier->parent->row << "," << frontier->parent->col << ")";
            qDebug() << "";
            for (State* child : getSuccessors(frontier)) {
                qDebug() << "    " << child->row << "," << child->col << "\n";
                fringe.push(child);
            }
        }
    }
    return false;
}

std::vector<State*> Search::getSuccessors(State *curState)
{
    std::vector<State*> children;
    int newRow, newCol, g;
    float h;
    for (int i=0; i<8; i++) {
        newRow = curState->row + rowDiff[i];
        newCol = curState->col + colDiff[i];
        if (isValidPos(newRow, newCol) && !visited[newRow][newCol])
        {
            h = heuristic(newRow, goalPos.first, newCol, goalPos.second);
            g = curState->movesDone + 1;
            State* childState = new State(newRow, newCol, g, h);
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
