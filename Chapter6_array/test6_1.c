//用筛选法求100之内的素数
/*筛选法：又称为筛法。先把N个自然数按次序排列起来。
1不是质数，也不是合数，要划去。第二个数2是质数留下来，
把2后面所有能被2整除的数都划去。2后面第一个没划去的数是3，
把3留下，再把3后面所有能被3整除的数都划去。3后面第一个没划去的数是5，
把5留下，再把5后面所有能被5整除的数都划去。....
这样一直做下去，就会把不超过N的全部合数都筛掉，留下的就是不超过N的全部质数。
————————————————
版权声明：本文为CSDN博主「月已满西楼」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/gjggj/article/details/92393687 */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //先定义一个整型数据，长度为100，给数据赋值1~100
    int str[100];
    for (int i = 0; i < 100; i++)
    {
        str[i]=i+1;
    }
   
    str[0]=0; //因为1不是质数也不是合数，用0标记后面去掉
    for (int i = 0; i < 99; i++)// 最后一个位置数字是100，100不是素数，因此循环可以少循环一次
    {
        // 用a[i]位置的数字去模i位置之后的所有数据
		// 如果能够整除则一定不是素数，该位置据用0填充
        for (int j=i+1; j <100; j++)
        {
            if(str[i]!=0 && str[j]!=0)
            if(str[j]%str[i]==0)//判断后面的数能否整除str[i]处的数据
            str[j]=0;//把不是素数的都赋值为0，即去掉能整除str[i]的数
        } 
    }
    printf("筛选法求出100以内的素数为：\n");
    for (int i = 0; i < 100; i++)
    {
        //输出str数组中不为0的数
        if(str[i]!=0)
        printf("%d ",str[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}