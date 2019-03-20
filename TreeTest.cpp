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
  ariel::Tree mytree; 
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
  .CHECK_OK    (mytree.insert(27))
  .CHECK_OK    (mytree.insert(23))
  .CHECK_OK    (mytree.insert(2))
  .CHECK_OK    (mytree.insert(17))
  .CHECK_OK    (mytree.insert(1))
  .CHECK_EQUAL (mytree.size(), 5)
  .CHECK_THROWS(mytree.parent(27))
  .CHECK_THROWS(mytree.left(1))
  .CHECK_THROWS(mytree.right(27))
  .CHECK_THROWS(mytree.insert(23))
  .CHECK_EQUAL (mytree.contains(10), false)
  .CHECK_THROWS(mytree.remove(7))
  .CHECK_OK    (mytree.remove(17))
  .CHECK_THROWS(mytree.remove(17))
  .CHECK_EQUAL (mytree.size(), 4)
  .CHECK_OK    (mytree.remove(27))
  .CHECK_EQUAL (mytree.root(), 23)

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
