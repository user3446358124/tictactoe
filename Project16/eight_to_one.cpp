#include <iostream>
#include <limits>
using namespace std;

class Game {
private:
    int map[9] = {}; // 0是空格，1是我方，2是敌方
    int functiontime = 0; // 第几次使用，用于主导defend主动选择中心位置

public:
    void show() {
        for (int i = 0; i < 3; i++) {
            cout << "\t" << map[i * 3] << "|" << map[i * 3 + 1] << "|" << map[i * 3 + 2] << endl;
            if (i != 2)
                cout << "\t- - -" << endl;
        }
    }

    bool opeartor() {
        int x, y;
        int i = 0;
        while (i < 9) // 就是为了能循环进行
        {
            cout << "接下来是我方输出" << endl;
            if (cin >> x >> y) // 我方输入
            {
                if (map[(x - 1) * 3 + y - 1] == 0)
                    map[(x - 1) * 3 + y - 1] = 1;
                else
                    continue;
                show();
            }
            else {
                cout << "错误!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (!judge())
                return true;

            cout << "接下来是对方输出" << endl;

            defend();

            show();

            if (!judge())
                return true;
        }
        return false;
    }

    void nest(bool success) {
        if (success == true) {
            cout << "恭喜你！";
        }
        else {
            cout << "太遗憾了！";
        }
    }

    void hello() {
        cout << "很好，让我们接下来玩一个井字棋的游戏" << endl;
        cout << "请你以左上为原点（1，1），下边为y轴正方向，右面为x轴正方向" << endl;
        cout << "每下一格或右一格在相应的地方进行加一" << endl;
        cout << "你对规则了解了吗？接下来让我们开始游戏吧" << endl;

        return;
    }

private:
    void defend() {
        int rec = 0;
        int a, b;

        a = success_rate(1);
        b = success_rate(2);

        if (!functiontime && map[4] == 0)
            rec = 4;
        else
            a > b ? rec = a : rec = b;

        *(map + rec) = 2;
        functiontime++;
        return;
    }

    int success_rate(int player) {
        int rate = 0;//记录最大值
        int temp = 0;//记录当前值

        for (int i = 0; i < 9; i++)
            if (map[i] == player)//如果有该玩家棋子存在，则进行判断
            {
                if (i == 4)//如果该棋子在中心位置，则直接返回最大值10
                    return temp = 10;

                if (i % 2 == 0)//如果该棋子在角落位置，则返回8
                    temp = 8;

                else//否则返回5
                    temp = 5;

                if (temp > rate)//如果当前值大于最大值，则更新最大值
                    rate = temp;
            }

        return rate;//返回最大值即可

    }

    bool judge() {
        // 检查每一行
        for (int i = 0; i < 3; i++) {
            if (map[i * 3] != 0 && map[i * 3] == map[i * 3 + 1] && map[i * 3 + 1] == map[i * 3 + 2])
                return false;
        }

        // 检查每一列
        for (int i = 0; i < 3; i++) {
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

};

int main() 
{
    Game game;
    game.hello();
    bool success = game.opeartor();
    game.nest(success);
    cout << "student" << endl;
    return 0;
}