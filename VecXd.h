/*  Project: VEXCD                  Description : A mathmatical vector class
NAME: Hani Aboudeshisha
      Hunter college, CSci335 , First Assignment
      09/17/2013
Discription:
-----------
*   This vector contains the big three, copy constructor, destructor ,  operator overloading
**  This vector class will assign, preform some mathmatical operations like +,-,*,=,+= and will return the results
***the class has two constructors, default and explicit, six member functions { [],+=, newVector,insert,setSize,getsize}
    and five friend functions { << , >> , + , - , * }

## The Used Method : the class contains only two private data memebers, size of the vector (int), and a pointer to an
   array that will hold the data entered by user.
   When object of the class is created, its size is initialized into 0 , and its array pointer points to Null.
   The user is asked to enter the vector index (size) that will be assigned to class Index, then a new array of this size is
   created.
   the user then asked to enter excatly a number of data equal to the array index- done automatically if "enter" is used .
## Some of the mathmatical operation ( +, - , * ) will check if index of both vectors are simillar, if not, it will throw an error.
## for the assigning (=) operation, if target index != rhs index, the target index will be set to rhs index.


*/

#ifndef VECXD_H
#define VECXD_H

#include<iostream>
#include<sstream>
#include<cassert>


using namespace std;

template <class T>
class VecXd{

      public:
             VecXd();                          // defualt constructor
            ~VecXd();
             explicit VecXd( int i);            // explict constructor
             T& operator[] (int indexP) const;
             VecXd<T>& operator+= (const VecXd<T>& vector); // for adding and assigning to operation
             void insert (T& newItem);                      // insert new items into the array
             void newVector( int size);                     // uses an index user entered to start an array of same size
             int getIndex() const;                          // return vector index
             const VecXd<T> & operator=( const VecXd<T> & rhs );  // copy constructor and assigning operator
    private:
             int index; // number of items on array
             T *array;  // pointr to an array that hold the entries

             template <class U> friend VecXd<U> operator+(const VecXd<U> &v1, const VecXd<U> &v2);// friend function to preform the
                                                                                        // the + operation,, checks if index1==index2
             template <class U> friend istream& operator >> (istream& in, VecXd<U>& vector); //  taking inputs from user
                                        // will assign first input to vector index, then equal entries to index
                                                       //into array

          /*{
           int size;
           cout<<" please enter vector index, then press 'Enter'"<<endl;
           in >> size;
           vector.newVector(size);
           cout << " index : " << size <<endl;
           cout <<" enter " << size << " entries. " << endl;
           T newItem;
           for ( int i =0; i< size ; i++){
               in >> newItem;
               vector.insert(newItem);
               vector.index++;
               }
               cout << " vector index :"<< vector.getIndex() <<endl;
               return in;
           } */

           template<class U> friend  ostream& operator  << (ostream& out, const VecXd<U>& vector);
                                                                    // a friend function to out put results


           /*{
            for (int i=0; i< vector.getIndex(); i++){
                out<< vector.array[i]<<" | " ;

                }
                out<<endl;
             return out;
             }*/
             //////////// EXTRAS  /////////////////////////////////////////////////
           template <class U> friend VecXd<U> operator-(const VecXd<U> &v1, const VecXd<U> &v2);
  };

#endif // VECXD_H


