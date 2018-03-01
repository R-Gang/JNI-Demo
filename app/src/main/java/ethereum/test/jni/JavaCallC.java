package ethereum.test.jni;

/**
 * Created by 13739 on 2018/1/3.
 */

public class JavaCallC {
    /**
     * 让C代码做加法运算，把结果返回
     * @param x
     * @param y
     * @return
     */
    public native int sum(int x,int y);

    /**
     * 从java传入字符串,C代码进行拼接
     * @param s haoruigang
     * @return haoruigang add I Love You
     */
    public native String sayHello(String s);

    /**
     * 让C代码给我们每个元素都加上88
     * @param intArray
     * @return
     */
    public native int[] increaseArrayEles(int[] intArray);

    /**
     * 应用：检查密码是否正确，如果正确返回200，否则返回400
     * @param pwd
     * @return
     */
    public native int checkPwd(String pwd);
}
