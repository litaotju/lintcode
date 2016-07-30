/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/shape-factory
@Language: C++
@Datetime: 16-04-26 02:13
*/

/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 */
#include <cstdio>
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    // Write your code here
    void draw() const{
        printf(" ---- \n");
        printf("|    |\n");
        printf(" ---- \n");
    }
};

class Square: public Shape {
    // Write your code here
    void draw() const{
        printf(" ---- \n");
        printf("|    |\n");
        printf("|    |\n");
        printf(" ---- \n");
    }
};

class Triangle: public Shape {
    // Write your code here
    void draw() const{
        printf("  /\\\n");
        printf(" /  \\\n");
        printf("/____\\\n");
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(string& shapeType) {
        if(shapeType=="Square"){
            return new Square();
        }
        if(shapeType=="Triangle"){
            return new Triangle();
        }
        if(shapeType=="Rectangle"){
            return new Rectangle();
        }
        else{
            return NULL;
        }
    }
};




