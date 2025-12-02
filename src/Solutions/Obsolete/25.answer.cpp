#include <bits/stdc++.h>
using namespace std;
int arr[4];//数组开在main外，默认初始化为0
int main()
{
int index;
char temp;
while (cin >> temp)//读⼊被赋值的变量
{
index = temp - 'a';//将变量转换为数组下标
cin >> temp;//读取：
cin >> temp;//读取=
cin >> temp;//读取赋值的变量
if (temp == 'a' || temp == 'b' || temp == 'c')//如果是拿来赋值的变量
{
arr[index] = arr[temp - 'a'];
}
else//直接赋值
{
arr[index] = (temp - '0');
}
cin >> temp;//读取;
}
cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
return 0;
}