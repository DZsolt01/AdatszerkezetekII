//
// Created by Adek on 2022. 03. 10..
//

#ifndef ADATSZERKEZETEKII_LABOR_H
#define ADATSZERKEZETEKII_LABOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

typedef struct{
    int color = 0;
    int father = 0;
    int distance = INT_MAX;
    vector<int> neighbors;
}POINT;

vector<POINT> readFromFile(const char filename[50]);
void printVector(const vector<POINT> &mPoints);
void printVectorInt(const vector<int> &mPoints);
vector<int> DFS(vector<POINT> mPoints);
void dfsRun(vector<POINT> &mPoints, int current, vector<int> &dfs);
vector<int> BFS(vector<POINT> &mPoints, int startingPoint);

#endif //ADATSZERKEZETEKII_LABOR_H
