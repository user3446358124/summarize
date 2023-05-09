#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void generate_combinations(string str[], int n, int k, string prefix)
{
    if (k == 0) {
        // ��ӡ�����ַ�������ӻ��з�
        cout << prefix << endl;
        return;
    }

    // ���ַ�����ѡ��һ���ַ�
    for (int i = 0; i < n; i++) {
        // ��һ�к͵����б��뱣�ֲ���
        if (k == n - 4 && i != 0) continue;
        if (k == n - 1 && i != 3) continue;

        // �ݹ�������һ���ַ���
        generate_combinations(str, n, k - 1, prefix + str[i] + '\n');
    }
}

int main()
{
    string str[8];
    for (int i = 0; i < 8; i++) {
        getline(cin, str[i]);
    }

    // �����Ա��֦
    sort(str, str + 8);

    // �������п��ܵ��������
    generate_combinations(str, 8, 8, "");

    return 0;
}