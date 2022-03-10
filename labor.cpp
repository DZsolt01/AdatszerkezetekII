//
// Created by Adek on 2022. 03. 10..
//

#include "labor.h"

vector<POINT> readFromFile(const char* filename){
    ifstream fin(filename);
    int nrPoints, nrEdges;
    fin >> nrPoints >> nrEdges;
    vector<POINT> mPoints(nrPoints);
    for (int i = 0; i < nrEdges; ++i) {
        int from, to;
        fin >> from >> to;
        mPoints[from-1].neighbors.emplace_back(to);
        mPoints[to-1].neighbors.emplace_back(from);
    }
    return mPoints;
}
void printVector(const vector<POINT> &mPoints){
    for (int i = 0; i < mPoints.size(); ++i) {
        cout << "Index" << i+1 << endl;
        cout << "color " << mPoints[i].color << endl;
        cout << "father " << mPoints[i].father << endl;
        cout << "neighbours:";
        for (int neighbor : mPoints[i].neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
void printVectorInt(const vector<int> &mPoints){
    for (int i = 0; i < mPoints.size(); ++i) {
        cout << mPoints[i] << " ";
    }
    cout << endl;
}

vector<int> DFS(vector<POINT> mPoints){
    vector<int> dfs;
    for (int i = 0; i < mPoints.size(); ++i) {
        if(mPoints[i].color == 0){
            dfsRun(mPoints, i, dfs);
        }
    }
    return dfs;
}
void dfsRun(vector<POINT> &mPoints, int current, vector<int> &dfs){
    dfs.emplace_back(current+1);
    mPoints[current].color = 1;
    for (int v = 0; v < mPoints[current].neighbors.size(); ++v) {
        if(mPoints[mPoints[current].neighbors[v]-1].color == 0){
            mPoints[mPoints[current].neighbors[v]-1].father = current;
            dfsRun(mPoints, mPoints[current].neighbors[v]-1,dfs);
        }
    }
    mPoints[current].color = 2;
}

vector<int> BFS(vector<POINT> &mPoints, int startingPoint){
    vector<int> bfs;
    startingPoint -= 1;
    mPoints[startingPoint].color =1;
    mPoints[startingPoint].distance = 0;
    queue<int> mQueue;
    mQueue.push(startingPoint);
    while( !mQueue.empty()){
        int u = mQueue.front();
        bfs.emplace_back(u+1);
        for (int i = 0; i < mPoints[u].neighbors.size(); ++i) {
            if(mPoints[mPoints[u].neighbors[i]-1].color == 0){
                mPoints[mPoints[u].neighbors[i]-1].color = 1;
                mPoints[mPoints[u].neighbors[i]-1].distance = mPoints[u].distance +1;
                mPoints[mPoints[u].neighbors[i]-1].father = u + 1;
                mQueue.push(mPoints[u].neighbors[i]-1);
            }
        }
        mQueue.pop();
        mPoints[u].color = 2;
    }
    return bfs;
}
void printFatherAndDistance(const vector<POINT> &mPoints){
    for (const auto& point : mPoints) {
        cout << "Father:" << point.father+1 << endl;
        cout << "Distance:" << point.distance+1 << endl;
    }
}