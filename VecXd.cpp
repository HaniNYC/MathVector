#include "VecXd.h"

template <class T>
VecXd<T>::VecXd(){                      // initializing an empty vector
                     index=0;
                     array=NULL;
                     }
 //--------------------------------------------------------------------------
 template <class T>                     // to construct a vector if index is giving
VecXd<T>::VecXd( int i)
{
                 index=i;
                 array = new T[i];
                 }
 //---------------------------------------------------------------------------


template <class T>
VecXd<T>::~VecXd(){
                      delete [] array;
                      }
//------------------------------------------------------------------------------

template <class T>                            // return data at an index, iff within vector range, else throw an error
T& VecXd<T>::operator [] ( int indexP) const{
                      if (indexP >= index ){
                      throw -1;
                      cout<<" out of range "<<endl;}
                      return array[index];
}
//----------------------------------------------------------------------------------------
//                                       // inserting data at specific array index
template <class T>
void VecXd<T>::insert(T&  newItem)  {
                     array[index]=newItem;

                     }
//-----------------------------------------------------------------------------------
//                                        // start a new vector if size is known
template <class T>
void VecXd<T>::newVector( int size){
     array = new T [ size ];
     }

//----------------------------------------------------------------------------------
//                                          // return the vector index
template <class T>
int VecXd<T>::getIndex() const{
    return index;
    }

 //-----------------------------------------------------------------------
 //                             // copy constructor//
template <class T>
const VecXd<T> & VecXd<T>::operator=( const VecXd<T> & rhs )
{
    if( this != &rhs )                     // if not  pointing to the same thing
    {
        delete [ ] array;                   // delete old array
        index= rhs.getIndex( );             // assign rhs index to vector index

        array = new T [ getIndex( ) ];       // construct a new array
        for( int k = 0; k < getIndex( ); k++ ) // copy
            array[ k ] = rhs.array[ k ];
    }
    return *this;
}
//------------------------------------------------------------------------------

//                                // adding one vector to another // precondition ( index1== index2)
template <class T>
 VecXd<T>& VecXd<T>::operator+=(const VecXd<T> &vector){
  if(index != vector.index){                                   // if index1 != index2
    cerr << " size mismatch: " <<
    index << " " << " != " << vector.index << "\n";            // mismatch error
     throw 3;
  }
  for(int i = 0; i < index; i++)                              // else add rhs to lhs and return this
      array[i] += vector.array[i];
  return *this;
}
//----------------------------------------------------------
// using a different class U to prevent class overshadow// adding two vectors together // preconditions ( index1 == index2)
template <class U>
 VecXd<U> operator+(const VecXd<U> &v1, const VecXd<U> &v2){
  if(v1.index != v2.index){                                   // if index1 != index2
    cerr << " size mismatch: ";
    cerr << v1.index << " " << " != " << v2.index << "\n";     // throw error
    throw 3;
  }                                                     // else

  VecXd<U> temp(v1.index);                          // Construct a temporary VecX<T> to hold the sum
  for(int i = 0; i < v1.index; i++)
    temp.array[i] = v1.array[i] + v2.array[i];      // add two vectors into a temporary vector and return it
  return temp;
}
//---------------------------------------------------------
// using a different class U to prevent class overshadow// takes inputs from istream and assign it to a vector
template <class U>
 istream& operator >> (istream& in, VecXd<U>& vector){
           int size;
           cout<<" please enter vector index, then press 'Enter'"<<endl;
           in >> size;
           vector.newVector(size);                    // begin a new array of that size
           cout << " index : " << size <<endl;
           cout <<" enter " << size << " entries. " << endl;
           U newItem;
           for ( int i =0; i< size ; i++){
               in >> newItem;
               vector.insert(newItem);                 // insert item
               vector.index++;                         // increment vector index ( update it)
               }
               cout << " vector index :"<< vector.getIndex() <<endl;  // to make sure it is correct
               return in;
       }
 //------------------------------------------------------------------------------------
// sing a different class U to prevent class overshadow// takes a vector and output it
  template <class U>
  ostream& operator  << (ostream& out, const VecXd<U>& vector){
            for (int i=0; i< vector.getIndex(); i++){
                out<< vector.array[i]<<" | " ;

                }
                out<<endl;
             return out;
       }

//-------------------------------------------------------------
// extra functions ////
template <class U>
 VecXd<U> operator-(const VecXd<U> &v1, const VecXd<U> &v2)   //substraction overloading
{
  if(v1.index != v2.index){                                   // if index1 != index2
    cerr << " size mismatch: ";
    cerr << v1.index << " " << " != " << v2.index << "\n";     // throw error
    throw 3;
  }                                                     // else

  VecXd<U> temp(v1.index);                          // Construct a temporary VecX<T> to hold the sum
  for(int i = 0; i < v1.index; i++)
    temp.array[i] = v1.array[i] - v2.array[i];      // substract two vectors into a temporary vector and return it
  return temp;
}
