/* 
 * 有一楼梯共m级，刚开始时你在第一级，若每次只能跨上一级或者二级，
 * 要走上m级，共有多少走法？注：规定从一级到一级有0种走法。
 * 给定一个正整数int n，请返回一个数，代表上楼的方式数。
 * 保证n小于等于100。为了防止溢出，请返回结果Mod 1000000007的值。
 */
class GoUpstairs {
public:
    int countWays(int n) {
        // write code here
        long long n1 = 0, n2 = 1;
        int i, tmp;
        
        for (i = 0; i < n; i++)
        {
            tmp = n2;
            n2 = n1 + n2;
            n1 = tmp;
        }
        
        return n2 % 1000000007;
    }
};
