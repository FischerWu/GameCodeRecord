#include "MapData.h"
#include <fstream>
#include <sstream>

bool MapData::loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    int y = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int x = 0, value;
        while (iss >> value) {
            // 存储障碍物坐标
            if (value == 1) navigationMap.emplace_back(x, y); 
            x++;
        }
        width = std::max(width, x);
        y++;
    }
    height = y;
    return true;
}

bool MapData::save_to_file(const std::string& fileName) const
{
    return false;
}

const std::vector<std::pair<int, int>>& MapData::getNavigationMap() const
{
    return navigationMap;
}

const std::vector<std::vector<int>>& MapData::getMap() const
{
    return map;
}

int MapData::getMapWidth() const
{
    return width;
}

int MapData::getMapHeight() const
{
    return height;
}

bool MapData::isValid(int x, int y) const
{
    return x > 0 && y > 0 && x < width && y < height;
}


