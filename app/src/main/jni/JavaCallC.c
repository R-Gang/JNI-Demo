//
// Created by 13739 on 2018/1/2.
//

#include "ethereum_test_jni_JavaCallC.h"
#include <string.h>
#include <stdlib.h>

/**
 * 把一个jstring转换成一个c语言的char*  类型
 * @param env
 * @param jstr
 * @return
 */
char *_Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");//转换成Cstring的GB2312，兼容ISO8859-1
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(jstr, mid,
                                                            strencode); //String.getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;            //"\0"
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}

/**
 * jint ：返回值
 * Java_全类名_方法名
 * JNIEvn *env ：java nativa interface 的别名
 * @param env
 * @param jobj
 * @param x
 * @param y
 * @return
 */
JNIEXPORT jint JNICALL Java_ethereum_test_jni_JavaCallC_sum
        (JNIEnv *env, jobject jobj, jint x, jint y) {
    return x + y;
};

/**
 *  从java传入字符串,C代码进行拼接
 */
JNIEXPORT jstring JNICALL Java_ethereum_test_jni_JavaCallC_sayHello
        (JNIEnv *env, jobject jobj, jstring jstr) {
    char *fromJava = _Jstring2CStr(env, jstr);
    //c:
    char *fromc = "add I Love You!!!";
    strcat(fromJava, fromc);//把拼接的结果放在第一个参数里面
    (*env)->NewStringUTF(env, fromJava);
};

/**
 *  让C代码给我们每个元素都加上88
 */
JNIEXPORT jintArray JNICALL Java_ethereum_test_jni_JavaCallC_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jarray) {
    //1.得到数组的长度 jsize  (*GetArrayLength)(JNIEnv*, jarray);
    int size = (*env)->GetArrayLength(env, jarray);
    //2.得到数组元素 jint*  (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    jint *intArray = (*env)->GetIntArrayElements(env, jarray, JNI_FALSE);
    //3.遍历数组,给每个元素加上88
    int i = 0;
    for (int i = 0; i < size; ++i) {
        *(intArray + i) += 88;
    }
    //4.返回结果
    return jarray;
};

/**
 * 应用：检查密码是否正确，如果正确返回200，否则返回400
 */
JNIEXPORT jint JNICALL Java_ethereum_test_jni_JavaCallC_checkPwd
        (JNIEnv *env, jobject jobj, jstring jstr) {
    //服务器的密码是123456
    char *origin = "123456";
    char fromUser = _Jstring2CStr(env, jstr);

    //函数比较字符串是否相同
    int code = strcmp(origin, fromUser);
    if (code == 0) {
        return 200;
    } else {
        return 400;
    }
};