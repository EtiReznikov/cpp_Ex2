/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  

    //Mytrees:
  ariel::Tree mytree1; 
  ariel::Tree mytree2; 
  //


  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  badkan::TestCase tc("Binary tree");
  tc
  
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())



   //Mytests:
  .CHECK_OK    (mytree1.insert(27))
  .CHECK_OK    (mytree1.insert(23))
  .CHECK_OK    (mytree1.insert(2))
  .CHECK_OK    (mytree1.insert(17))
  .CHECK_OK    (mytree1.insert(1))
  .CHECK_EQUAL (mytree1.size(), 5)
  .CHECK_THROWS(mytree1.parent(27))
  .CHECK_THROWS(mytree1.left(1))
  .CHECK_THROWS(mytree1.right(27))
  .CHECK_THROWS(mytree1.insert(23))
  .CHECK_EQUAL (mytree1.contains(10), false)
  .CHECK_THROWS(mytree1.remove(7))
  .CHECK_OK    (mytree1.remove(17))
  .CHECK_THROWS(mytree1.remove(17))
  .CHECK_EQUAL (mytree1.size(), 4)
  .CHECK_OK    (mytree1.remove(27))
  .CHECK_EQUAL (mytree1.root(), 23)


  .CHECK_THROWS(mytree2.print())
  .CHECK_THROWS(mytree2.root())


  .CHECK_OK    (mytree2.insert(2))
  .CHECK_OK    (mytree2.insert(11))
  .CHECK_OK    (mytree2.insert(18))
  .CHECK_OK    (mytree2.insert(17))
  .CHECK_OK    (mytree2.insert(20))
  .CHECK_OK    (mytree2.insert(15))
  .CHECK_OK    (mytree2.insert(1))
  .CHECK_OK    (mytree2.insert(9))
  .CHECK_OK    (mytree2.insert(5))
  .CHECK_OK    (mytree2.insert(4))
  .CHECK_THROWS(mytree2.insert(2))

  .CHECK_EQUAL (mytree2.size(), 10)

  .CHECK_EQUAL (mytree2.contains(2), true)
  .CHECK_EQUAL (mytree2.contains(11), true)
  .CHECK_EQUAL (mytree2.contains(18), true)
  .CHECK_EQUAL (mytree2.contains(17), true)
  .CHECK_EQUAL (mytree2.contains(20), true)
  .CHECK_EQUAL (mytree2.contains(15), true)
  .CHECK_EQUAL (mytree2.contains(1), true)
  .CHECK_EQUAL (mytree2.contains(9), true)
  .CHECK_EQUAL (mytree2.contains(5), true)
  .CHECK_EQUAL (mytree2.contains(4), true)

  .CHECK_OK    (mytree2.remove(17))
  .CHECK_EQUAL (mytree2.size(), 9)
  .CHECK_THROWS(mytree2.remove(17))

  .CHECK_EQUAL (mytree2.root(), 2)
  .CHECK_OK    (mytree2.remove(2))
  .CHECK_EQUAL (mytree2.size(), 8)
  .CHECK_EQUAL (mytree2.root(), 1)
  .CHECK_OK    (mytree2.remove(1))
  .CHECK_EQUAL (mytree2.size(), 7)
  .CHECK_EQUAL (mytree2.root(), 11)
  .CHECK_OK    (mytree2.remove(11))
  .CHECK_EQUAL (mytree2.size(), 6)
  .CHECK_EQUAL (mytree2.root(), 9)
  .CHECK_OK    (mytree2.remove(9))
  .CHECK_EQUAL (mytree2.size(), 5)
  .CHECK_EQUAL (mytree2.root(), 5)
  .CHECK_OK    (mytree2.remove(5))
  .CHECK_EQUAL (mytree2.size(), 4)
  .CHECK_EQUAL (mytree2.root(), 4)
  .CHECK_OK    (mytree2.remove(4))
  .CHECK_EQUAL (mytree2.size(), 3)
  .CHECK_EQUAL (mytree2.root(), 18)
  .CHECK_OK    (mytree2.remove(18))
  .CHECK_EQUAL (mytree2.size(), 2)
  .CHECK_EQUAL (mytree2.root(), 15)
  .CHECK_OK    (mytree2.remove(15))
  .CHECK_EQUAL (mytree2.size(), 1)
  .CHECK_EQUAL (mytree2.root(), 20)
  .CHECK_OK    (mytree2.remove(20))
  .CHECK_EQUAL (mytree2.size(), 0)


  .CHECK_EQUAL (mytree2.contains(2), false)
  .CHECK_EQUAL (mytree2.contains(11), false)
  .CHECK_EQUAL (mytree2.contains(18), false)
  .CHECK_EQUAL (mytree2.contains(17), false)
  .CHECK_EQUAL (mytree2.contains(20), false)
  .CHECK_EQUAL (mytree2.contains(15), false)
  .CHECK_EQUAL (mytree2.contains(1), false)
  .CHECK_EQUAL (mytree2.contains(9), false)
  .CHECK_EQUAL (mytree2.contains(5), false)
  .CHECK_EQUAL (mytree2.contains(4), false)




  



  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
