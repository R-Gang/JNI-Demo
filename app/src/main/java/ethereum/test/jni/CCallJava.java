package ethereum.test.jni;

import android.util.Log;

/**
 * Created by 13739 on 2018/1/3.
 */

public class CCallJava {

    /**
     * 当执行这个方法的时候，让C调用
     * public int add(int x, int y)
     */
    public native void callbackAdd();

    /**
     * 当执行这个方法的时候，让C调用
     * public void helloFromJava()
     */
    public native void callbackHelloFromJava();

    /**
     * 当执行这个方法的时候，让C调用
     * public void printString()
     */
    public native void callbackPrintString();

    /**
     * 当执行这个方法的时候，让C调用
     * public static void sayHello(String s)
     */
    public native void callbackSayHell();

    public int add(int x, int y) {
        Log.e("TAG", "add()x=" + x + "y=" + y);
        return x + y;
    }

    public void helloFromJava() {
        Log.e("TAG", "helloFromJava()");
    }

    public void printString(String s) {
        Log.e("TAG", "C中输入的：" + s);
    }

    public static void sayHello(String s) {
        Log.e("TAG", "我是java代码中的JNI.Java中的sayHello(String s)静态方法，我被调用了:" + s);
    }
}
