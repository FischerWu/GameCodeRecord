//
// Created by 曦沐鱼 on 2025/4/10.
//

#ifndef GAMECODERECORD_NAVIGATIONMANAGER_H
#define GAMECODERECORD_NAVIGATIONMANAGER_H

#pragma once
#include <vector>
#include "Scene.h"

using namespace std;

class NavigationManager
{
    int **map; // 二维地图
    int mapWidth, mapHeight; // 表示地图的宽度和高度
    vector<pair<int, int>> navigableGrids; // 存储地图上可通行坐标的vector容器
    static NavigationManager* instance; // 静态成员变量
    NavigationManager();
public:
    static NavigationManager* getInstance();
    void setMap(Scene *s); // 根据Scene对象设置地图信息
    vector<pair<int, int>> pathFinding(int startX, int startY, int endX, int endY) const;
    vector<pair<int, int>> getNavigableGridList() const { return navigableGrids; }
};
#endif //GAMECODERECORD_NAVIGATIONMANAGER_H
