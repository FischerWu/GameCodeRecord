#pragma once
#include <memory>
#include <vector>
#include "MapData.h"

/*
 * 给AI寻路使用的单例类，获得地图数据后进行A*导航。
 */

struct Node
{
    int x, y;
    int gValue, hValue;
    Node *parent;
    Node(int a, int b) :x(a), y(b), gValue(0), hValue(0), parent(nullptr){}
};

class NavigationMap
{
public:
    static NavigationMap* GetInstance();
    void setAiMap(MapData* mapData);
    std::vector<std::pair<int, int>> pathFinding(int startX, int startY, int endX, int endY) const;
    std::vector<std::pair<int, int>> getNavigationMap() const;
    int getMapWidth() const;
    int getMapHeight() const;
private:
    int mapWidth, mapHeight;
    // 供AI寻路使用
    std::vector<std::vector<int>> map;
    // 存储障碍物位置
    std::vector<std::pair<int, int>> navigationMap;
    static NavigationMap *sInstance;
    NavigationMap() = default;
};
