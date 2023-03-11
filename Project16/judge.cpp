#include "Class_type.h"

 bool judge(int* map)
{
    // 检查每一行
    for (int i = 0; i < 3; i++)
    {
        if (map[i * 3] != 0 && map[i * 3] == map[i * 3 + 1] && map[i * 3 + 1] == map[i * 3 + 2])
            return false;
    }

    // 检查每一列
    for (int i = 0; i < 3; i++)
    {
        if (map[i] != 0 && map[i] == map[i + 3] && map[i + 3] == map[i + 6])
            return false;
    }

    // 检查对角线
    if (map[0] != 0 && map[0] == map[4] && map[4] == map[8])
        return false;
    if (map[2] != 0 && map[2] == map[4] && map[4] == map[6])
        return false;

    return true;
}