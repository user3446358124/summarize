#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void generate_combinations(string str[], int n, int k, string prefix)
{
    if (k == 0) {
        // 打印所有字符串并添加换行符
        cout << prefix << endl;
        return;
    }

    // 从字符串中选择一个字符
    for (int i = 0; i < n; i++) {
        // 第一行和第四行必须保持不变
        if (k == n - 4 && i != 0) continue;
        if (k == n - 1 && i != 3) continue;

        // 递归生成下一级字符串
        generate_combinations(str, n, k - 1, prefix + str[i] + '\n');
    }
}

int main()
{
    string str[8];
    for (int i = 0; i < 8; i++) {
        getline(cin, str[i]);
    }

    // 排序以便剪枝
    sort(str, str + 8);

    // 生成所有可能的排列组合
    generate_combinations(str, 8, 8, "");

    return 0;
}