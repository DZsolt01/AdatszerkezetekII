//
// Created by Adek on 2022. 03. 10..
//
#include "labor.h"

int main(){
    vector<POINT> mPoints = readFromFile("dfs.txt");
    printVector(mPoints);

    cout << "Melysegi bejaras:";
    printVectorInt(DFS(mPoints));
    cout << "Szelessegi bejaras:";
    printVectorInt(BFS(mPoints, 1));
    printFatherAndDistance(mPoints);
}