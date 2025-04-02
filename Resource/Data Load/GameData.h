//
// Created by 曦沐鱼 on 2025/4/3.
//

#ifndef GAMECODERECORD_GAMEDATA_H
#define GAMECODERECORD_GAMEDATA_H
#include <stdio.h>
#define READ_GRANULARITY 2048

class GameData {
public:
    bool Save(char* fileName);
    bool Load(char* fileName);
    bool BufferedLoad(char* fileName);
private:
    // 一次只打开一个文件
    static FILE *fileDescriptor;
    // 游戏数据
    int data[1000]; // 使用自己的数据格式替换
};


#endif //GAMECODERECORD_GAMEDATA_H
