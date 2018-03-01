#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_ethereum_test_jni_MainActivity_sayHello(JNIEnv *env, jobject /* this */) {
    // TODO
    // jstring (*NewStringUTF)(JNIEnv *, const char *);
    std::string text = "I Love You";
    return env->NewStringUTF(text.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_ethereum_test_jni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
