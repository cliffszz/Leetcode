//https://leetcode-cn.com/problems/design-parking-system/
#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>

using namespace std;

class ParkingSystem {
public:
    pthread_mutex_t b;
    pthread_mutex_t m;
    pthread_mutex_t s;

public:
    ParkingSystem(int big, int medium, int small) {
        //park = {big, medium, small};
        b.__data.__count = big;
        m.__data.__count = medium;
        s.__data.__count = small;
    }
    
    bool addCar(int carType) {
        /*
        if(park[carType - 1] > 0) {
            park[carType - 1]--;
            return true;
        }
        return false;
        */
       bool ret = false;
       if(carType == 1) {
           pthread_mutex_lock(&b);
           if(b.__data.__count > 0) ret = true;
           else ret = false;
           b.__data.__count--;
       }
       else if(carType == 2) {
           pthread_mutex_lock(&m);
           if(m.__data.__count > 0) ret = true;
           else ret = false;
           m.__data.__count--;
       }
       else if(carType == 3) {
           pthread_mutex_lock(&s);
           if(s.__data.__count > 0) ret = true;
           else ret = false;
           s.__data.__count--;
       }
       return ret;
    }
private:
    //vector<int> park = {0, 0, 0};
};

int main(){

    ParkingSystem* parkingSystem = new ParkingSystem(1, 1, 0);
    cout << parkingSystem->addCar(1); 
    cout << parkingSystem->addCar(2);
    cout << parkingSystem->addCar(3);
    cout << parkingSystem->addCar(1); 

    return 0;
}


