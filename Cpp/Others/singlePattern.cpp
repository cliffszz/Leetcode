//饿汉模式
//饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。
//是线程安全的
class singlePattern {
private:
    //构造函数为私有，不可继承
    singlePattern() {}
    //static变量为类共有，确保一个类只实例化一个对象
    static singlePattern* p;
public:
    //获取指向该类唯一实例化对象的指针
    static singlePattern* instance();
    //CG的默认构造函数先于singlePattern执行
    class CG {
        //析构singlePatten时要先析构CG
        ~CG() {
            //如果有唯一的实例，回收指针指向的内存，并重新指向nullptr
            if (singlePattern::p != nullptr) {
                delete singlePattern::p;
                singlePattern::p = nullptr;
            }
        }
    };
};
//初始化即实例化
singlePattern* singlePattern::p = new singlePattern();
singlePattern* singlePattern::instance() {
    return p;
}

//懒汉模式
//懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化。
//不是线程安全的
class singlePattern2 {
private:
    //构造函数为私有，不可继承
    singlePattern2() {}
    //static变量为类共有，确保一个类只实例化一个对象
    static singlePattern2* p;
public:
    //获取指向该类唯一实例化对象的指针
    static singlePattern2* instance();
    //CG的默认构造函数先于singlePattern执行
    class CG {
        //析构singlePatten时要先析构CG
        ~CG() {
            //如果有唯一的实例，回收指针指向的内存，并重新指向nullptr
            if (singlePattern2::p != nullptr) {
                delete singlePattern2::p;
                singlePattern2::p = nullptr;
            }
        }
    };
};

singlePattern2* singlePattern2::p = nullptr;
singlePattern2* singlePattern2::instance() {
    if (p == nullptr) {
        return new singlePattern2();
    }
    return p;
}
