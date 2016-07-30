/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/toy-factory
@Language: C++
@Datetime: 16-04-26 02:28
*/

/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
#include <cstdio>
class Toy {
public:
    virtual void talk() const=0;
};

class Dog: public Toy {
    // Write your code here
    void talk() const{
        printf("Wow\n");
    }
};

class Cat: public Toy {
    // Write your code here
    void talk() const {
        printf("Meow\n");
    }
};

class ToyFactory {
public:
    /**
     * @param type a string
     * @return Get object of the type
     */
    Toy* getToy(string& type) {
        // Write your code here
        if(type=="Dog"){
            return new Dog();
        }
        if(type=="Cat"){
            return new Cat();
        }else{
            return NULL;
        }
    }
};