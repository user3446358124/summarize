### 康托展开简介：

**官方简介：**

**康托展开**是一个[全排列](https://so.csdn.net/so/search?q=%E5%85%A8%E6%8E%92%E5%88%97&spm=1001.2101.3001.7020)到一个[自然数](https://baike.baidu.com/item/%E8%87%AA%E7%84%B6%E6%95%B0 "自然数")的[双射](https://baike.baidu.com/item/%E5%8F%8C%E5%B0%84 "双射")，常用于构建[哈希表](https://baike.baidu.com/item/%E5%93%88%E5%B8%8C%E8%A1%A8 "哈希表")时的空间压缩。 康托展开的实质是计算当前排列在所有由小到大全排列中的顺序，因此是可逆的。

**通俗简介：**

康托展开可以求解一个排列的序号，比如：12345 序号为 1  ，12354序号为2，按字典序增加编号递增，依次类推。  
康托逆展开可以求解一个序号它对应的排列是什么。

### 康托展开解释：

先给出康托展开的公式：

![](https://img-blog.csdnimg.cn/20190219113343503.png)

先对这个公式里变量进行解释，大家不理解这个公式没关系，慢慢往后看，很简单的。  
![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9nc3MzLmJkc3RhdGljLmNvbS83UG8zZFNhZ194STRraEdrcG9XSzFIRjZoaHkvYmFpa2UvcyUzRDEyL3NpZ249N2NlMGY3ZmFkODA3MzVmYTk1ZjA0YWJiOWM1MTQ4ZmEvMGRmM2Q3Y2E3YmNiMGE0NjI1ZTdkZWQ4Njc2M2Y2MjQ2YTYwYWYwZS5qcGc?x-oss-process=image/format,png) 的意思是从右往左数第 i 位这个数是这个数前未出现的数，第![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9nc3MzLmJkc3RhdGljLmNvbS83UG8zZFNhZ194STRraEdrcG9XSzFIRjZoaHkvYmFpa2UvcyUzRDEyL3NpZ249N2NlMGY3ZmFkODA3MzVmYTk1ZjA0YWJiOWM1MTQ4ZmEvMGRmM2Q3Y2E3YmNiMGE0NjI1ZTdkZWQ4Njc2M2Y2MjQ2YTYwYWYwZS5qcGc?x-oss-process=image/format,png) 大。举个例子就明白这个公式了：

注意：计算的时候 12345 序列应视为第0个序列，后面会解释为什么。

拿52413举例子：

1、首先看第一个数 5，不管第一位是什么数，后面都有四位数，那么这四位数全排列的方式有 4！种，而如果第一位是 1 或 2 或 3 或 4 都会比5开头的字典序要小，所以可以令1，2，3，4分别作为开头，这样的话就会有 4 \* 4！种排法要比  52413这种排法的字典序要小。

那么第一个数是1，2，3，4时候的字典序的个数数完了是 4 \* 4！ 种，且这些字典序都要比52413的字典序要小。

还有其他的排列方式比52413的字典序要小的吗？

2、那么就可以固定第一位5，找下一位2，这时5已经用过了，所以从剩下的 1，2，3，4 里挑选比2小的数，一共1个，后面还剩三位，也就是3！种排列方式，那么这时候比 52413 字典序要小的又有  1 \* 3！种，也就是当5在第一位，1在第二位的时候。

3、再看第三位4，这时5，2都用了，所以从剩下的 1，3，4三个数中找比4小的数的个数，有两个比4小原理同上，所以这时候也可以有 2 \* 2!种排列方式的字典序小于 52413

4、再看第四位1，这时候会有 0 \* 1！种

5、再看第五位3，这时候会有0 \* 0！种

综上所述：  
对于序列： 52413 该序列展开后为： 4 \* 4! + 1 \* 3! + 2 \* 2! + 0 \* 1! + 0 \* 0! ，计算结果是： 106   
由于是从0开始计数的，所以最后 52413 的编号为 107

为什么从0开始计数？  
可以这样看：我现在让你求12345的康托展开值，也就是：0\*4！+ 0\*3！+ 0\*2！+ 0\*1！+0\*0！ =  0 所以明白了吧~~  
康托公式最小字典序的编号就是0。

### 康托展开代码：

```
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int f[20];
void jie_cheng(int n)
{    
f[0] = f[1] = 1; 
for(int i = 2; i <= n; i++) 
f[i] = f[i - 1] * i;
}

string str;int kangtuo()
{
int ans = 1;  
int len = str.length();
for(int i = 0; i < len; i++)
{
int tmp = 0;
for(int j = i + 1; j < len; j++)
{
if(str[i] > str[j]) 
tmp++;        
}        

ans += tmp * f[len - i - 1];    
}
return ans;
}

int main()
{
jie_cheng(10);    
string str = "52413";    
cout<<kangtuo()<<endl;
}
```

### 康托逆展开解释：


如果初始序列是12345（第一个），让你求第107个序列是什么。（按字典序递增）

这样计算：

先把107减1，因为康托展开里的初始序列编号为0  
然后计算下后缀积：  
  1      2      3    4    5  
  5！  4！  3！ 2！1！ 0！  
120   24     6    2    1     1

106 /  4! = 4 ······ 10 有4个比它小的所以因该是5   从（1，2，3，4，5）里选  
10   /  3!  = 1 ······ 4  有1个比它小的所以因该是2   从（1， 2， 3， 4）里选  
 4    /  2!  = 2 ······ 0  有2个比它小的所以因该是4   从（1， 3， 4）里选  
 0    /  1!  = 0 ······ 0  有0个比它小的所以因该是1   从（1，3）里选  
 0    /  0!  = 0 ······ 0  有0个比它小的所以因该是3   从（3）里选

所以编号107的是 52413

### 康托逆展开代码：

```
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int f[20];
int x, num;

void jie_cheng(int n)
{    
f[0] = f[1] = 1; 
for(int i = 2; i <= n; i++) 
f[i] = f[i - 1] * i;
}

vector<char> vec; 

void rev_kangtuo(int k) 
{
int n = vec.size(), len = 0;    
string ans = "";    
k--;

for(int i = 1; i <= n; i++)
{
int t = k / f[n - i];         
k %= f[n - i];                
ans += vec[t] ;         
vec.erase(vec.begin() + t);     
}    
cout << ans << '\n';
}

int main()
{
jie_cheng(10); 
scanf("%d", &x); 
for(int i = 1; i <= 10; i++)    
{
if(x / f[i] == 0)     
{    
num = i;break;    
}    
}
for(int i = 1; i <= num; i++) 
vec.push_back(i + '0'); 
rev_kangtuo(x);
}
```