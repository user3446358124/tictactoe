#include <iostream>
#include <limits>
using namespace std;

class Game {
private:
    int map[9] = {}; // 0�ǿո�1���ҷ���2�ǵз�
    int functiontime = 0; // �ڼ���ʹ�ã���������defend����ѡ������λ��

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
        while (i < 9) // ����Ϊ����ѭ������
        {
            cout << "���������ҷ����" << endl;
            if (cin >> x >> y) // �ҷ�����
            {
                if (map[(x - 1) * 3 + y - 1] == 0)
                    map[(x - 1) * 3 + y - 1] = 1;
                else
                    continue;
                show();
            }
            else {
                cout << "����!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (!judge())
                return true;

            cout << "�������ǶԷ����" << endl;

            defend();

            show();

            if (!judge())
                return true;
        }
        return false;
    }

    void nest(bool success) {
        if (success == true) {
            cout << "��ϲ�㣡";
        }
        else {
            cout << "̫�ź��ˣ�";
        }
    }

    void hello() {
        cout << "�ܺã������ǽ�������һ�����������Ϸ" << endl;
        cout << "����������Ϊԭ�㣨1��1�����±�Ϊy������������Ϊx��������" << endl;
        cout << "ÿ��һ�����һ������Ӧ�ĵط����м�һ" << endl;
        cout << "��Թ����˽����𣿽����������ǿ�ʼ��Ϸ��" << endl;

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
        int rate = 0;//��¼���ֵ
        int temp = 0;//��¼��ǰֵ

        for (int i = 0; i < 9; i++)
            if (map[i] == player)//����и�������Ӵ��ڣ�������ж�
            {
                if (i == 4)//���������������λ�ã���ֱ�ӷ������ֵ10
                    return temp = 10;

                if (i % 2 == 0)//����������ڽ���λ�ã��򷵻�8
                    temp = 8;

                else//���򷵻�5
                    temp = 5;

                if (temp > rate)//�����ǰֵ�������ֵ����������ֵ
                    rate = temp;
            }

        return rate;//�������ֵ����

    }

    bool judge() {
        // ���ÿһ��
        for (int i = 0; i < 3; i++) {
            if (map[i * 3] != 0 && map[i * 3] == map[i * 3 + 1] && map[i * 3 + 1] == map[i * 3 + 2])
                return false;
        }

        // ���ÿһ��
        for (int i = 0; i < 3; i++) {
            if (map[i] != 0 && map[i] == map[i + 3] && map[i + 3] == map[i + 6])
                return false;
        }

        // ���Խ���
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