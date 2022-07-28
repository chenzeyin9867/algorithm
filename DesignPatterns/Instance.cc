#include "head.h"
/*  This class is a tutorial to implement a Single Instance,
    which could only be initialized once.
    -1、We mark the operator new as private as user won't call
        it to initialize a new object.
    -2、 

*/

class Singleton{
private:
    static Singleton* m_instance_;
    static std::mutex m_mutex_;
    std::string m_value_;
private:
    Singleton(const std::string val): m_value_(val){
    }
    ~Singleton(){}
    /** We have to forbiden the copy and assignment operator. */
public:
    Singleton(const Singleton&)=delete;
    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static Singleton *GetInstance(const std::string& value);
    string string(){
        return m_value_;
    }
}; 

/**
 * Static methods should be defined outside the class.
 */

Singleton* Singleton::m_instance_{nullptr};
std::mutex Singleton::m_mutex_;

/**
 * The first time we call GetInstance we will lock the storage location
 *      and then we make sure again that the variable is null and then we
 *      set the value. RU:
 */
Singleton *Singleton::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(m_mutex_);
    if (m_instance_ == nullptr)
    {
        m_instance_ = new Singleton(value);
    }
    return m_instance_;
}

void func(string str){
    Singleton* obj = Singleton::GetInstance(str);
    cout << "Get Value: " << obj->string() << endl;
    return;
}

int main(){
    std::thread thd1 = std::thread(func, "Hello World 1");
    std::thread thd2 = std::thread(func, "Hello World 2");
    thd1.join();
    thd2.join();
    return 0;
}