package ethereum.test.jni;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        JavaCallC jni = new JavaCallC();
        int sum = jni.sum(8, 2);
        String sayHello = jni.sayHello("haoruigang");
        int code = jni.checkPwd("123456");
        tv.setText("stringFromJNI：" + stringFromJNI() + "\nsayHello：" + sayHello() + "\nsum:" + sum + "\ncode:" + code + "sayHello:" + sayHello);
//        int[] array = new int[]{1, 2, 3, 4, 5, 6};
//        int[] arrayEles = jni.increaseArrayEles(array);
//        for (int i = 0; i < array.length; i++) {
//            Log.e(MainActivity.class.getSimpleName(), "array[%d]" + arrayEles[i]);
//        }

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    /**
     * 定义native方法
     * 调用C代码对应的方法
     *
     * @return
     */
    public native String sayHello();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("JavaCallC");
    }
}
