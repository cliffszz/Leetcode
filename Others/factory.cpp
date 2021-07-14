//简单工厂模式
#include <iostream>
using namespace std;

typedef enum productType {
    TypeA,
    TypeB,
    TypeC
} productTypeTag;

class Product {
public:
    //基类函数为纯虚函数，要求派生类一定要重载
    virtual void show() = 0;
    virtual ~Product() = 0;
};

class ProductA : public Product {
public:
    void show() {
        cout << "ProductA" << endl;
    }
    ~ProductA() {
        cout << "~ProductA" << endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        cout << "ProductB" << endl;
    }
    ~ProductB() {
        cout << "~ProductB" << endl;
    }
};

class ProductC : public Product {
public:
    void show() {
        cout << "ProductC" << endl;
    }
    ~ProductC() {
        cout << "~ProductC" << endl;
    }
};

class Factory {
public: 
    Product* createProduct(productType type) {
        switch (type) {
            case TypeA: return new ProductA;
            case TypeB: return new ProductB;
            case TypeC: return new ProductC;
            default: return nullptr;
        }
    }
};