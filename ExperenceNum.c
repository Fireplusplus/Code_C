/* 
 * 小易经常沉迷于网络游戏.有一次,他在玩一个打怪升级的游戏,
 * 他的角色的初始能力值为 a.在接下来的一段时间内,他将会依次遇见n个怪物,
 * 每个怪物的防御力为b1,b2,b3...bn. 如果遇到的怪物防御力bi小于等于小易的
 * 当前能力值c,那么他就能轻松打败怪物,并 且使得自己的能力值增加bi;
 * 如果bi大于c,那他也能打败怪物,但他的能力值只能增加bi 与c的最大公约数.
 * 那么问题来了,在一系列的锻炼后,小易的最终能力值为多少?
 * 输入描述:
 * 对于每组数据,第一行是两个整数n(1≤n<100000)表示怪物的数量和a表示小易
 * 的初始能力值.
 * 第二行n个整数,b1,b2...bn(1≤bi≤n)表示每个怪物的防御力
 */

#include <stdio.h>

int MaxDivNum(int c, int bi)
{
    if (c % bi == 0)
       	return bi;
    else
        return MaxDivNum(bi, c % bi);
}

void Call()
{
    int n, a;
    
    scanf("%d%d", &n, &a);
    
    while (n--)
    {
        int bi;
        scanf("%d", &bi);
        if (a >= bi)
            a += bi;
        else
            a += MaxDivNum(a, bi);
    }
    printf("%d\n", a);
}

int main()
{
    Call();
    
    return 0;
}
