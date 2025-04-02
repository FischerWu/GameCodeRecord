//
// Created by 曦沐鱼 on 2025/4/3.
//

#include "GameData.h"


bool GameData::Save(char *fileName)
{
    fileDescriptor = fopen(fileName, "wb");
    if(fileDescriptor)
    {
        fwrite(this, sizeof(GameData), 1, fileDescriptor);
        fclose(fileDescriptor);
        // 报告写文件成功
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool GameData::Load(char* fileName)
{
    fileDescriptor = fopen(fileName, "rb");
    if(fileDescriptor)
    {
        fread(this, sizeof(GameData), 1, fileDescriptor);
        fclose(fileDescriptor);
        // 报告读文件成功
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool GameData::BufferedLoad(char *fileName)
{
    // 确认读缓冲区有足够空间
    char* tempBuffer = new char(sizeof(GameData) + READ_GRANULARITY);
    if(!tempBuffer)
    {
        // 不能分配缓冲区，返回错误代码
        return FALSE;
    }
    fileDescriptor = fopen(fileName, "rb");
    if(fileDescriptor)
    {
        fread(tempBuffer, sizeof(GameData), 1, fileDescriptor);
        fclose(fileDescriptor);
        memcpy(this, tempBuffer, sizeof(GameData));
        delete tempBuffer;
        // 报告读文件成功
        return TRUE;
    }
    else
    {
        delete tempBuffer;
        // 报告读文件错误
        return FALSE;
    }
}