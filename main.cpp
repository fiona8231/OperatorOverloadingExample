#include <iostream>

using namespace std;

class Box{
private:
    int width;
    int breadth;
    int length;
    string boxstr;
public:
    //constructor1
    Box(int w, int l, int b){
        width = w;
        length = l;
        breadth = b;
    }

    //constructor
    Box(){
        width = 1;
        length = 1;
        breadth = 1;
    }

    //return type + keyword"operator" + symbol
    // overloading ++
    // Will increment all values in the box by 1
    //return object
    //no parameter inside()
    // ++box
    Box& operator ++ (){
        width += 1;
        length += 1;
        breadth += 1;
        return  *this;
        }

   void display(){
        cout << "length: " << this->length << "witdth: " << this->width << "breadth: " << this->breadth << endl;
    }

// Let's add boxes
   // box1 + box2
  //return new object
  Box& operator + (const Box& b2){
        Box *newBox = new Box;
      newBox->breadth = breadth + b2.breadth;
      newBox->width =  width + b2.width;
      newBox->length = length + b2.length;
        return *newBox;

    }


   //cout << "Box Length : " << box[0] << "\n";

   int operator[] (const int index){
         if(index == 0){
             return length;
             } else if(index ==1){
           return  width;

         } else
         { return  0;}
    }
    // Check for box equality
//cout << "Are boxes equal : " << (box == box2) << "\n";
   bool operator== (const Box& box1){
        if(length == box1.length){ return true;
        } else{ return false; }
    }
    // Is box < box2
   //cout << "Is box < box2 : " << (box < box2) << "\n";

  bool operator< (const Box& newBox){
        int sumOfBox = newBox.length + newBox.width + newBox.breadth;
        if((length + width + breadth) > sumOfBox){
            return  false;
        } else if ((length + width + breadth) < sumOfBox){
            return true;
        }


    }

};


int main() {

    Box obj;
    ++obj;
    //obj.display(); //length: 2witdth: 2breadth: 2

    // Add boxes

    Box box1;
    Box box2 (2,3,4);
    Box box3 = box1 + box2;
    box3.display();

    // Access data with subscript operator
    cout << "Box Length : " << box1[0] << "Box width" << box2[0] << endl;
    // Check for box equality
    Box box4(2,3,4);
    cout << "Are boxes equal : " << (box2 == box4) << "\n"; //Are boxes equal : 1

    // Is box < box2
    cout << "Is box < box2 : " << (box1 < box2) << "\n";
}