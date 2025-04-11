#pragma once
#include <vector>
#include <string>

/*
 * 从文件中读取地图数据
*/
class MapData
{
public:
    bool loadFromFile(const std::string& fileName);
    bool save_to_file(const std::string& fileName) const;
    const std::vector<std::pair<int, int>>& getNavigationMap() const;
    const std::vector<std::vector<int>>& getMap() const;
    int getMapWidth() const;
    int getMapHeight() const;
    

    bool isValid(int x, int y) const;

private:
    std::vector<std::pair<int, int>> navigationMap;
    std::vector<std::vector<int>> map;
    int width = 0;
    int height = 0;
};
