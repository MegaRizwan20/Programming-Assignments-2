#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

	public:

		/** define iterator as an aliased typename for BSTIterator<Data>. */
		typedef BSTIterator<Data> iterator;

		/** Default constructor.
		  Initialize an empty BST.
		  This is inlined because it is trivial.
		  */
		BST() : root(nullptr), isize(0) {}


		/** Default destructor.
		  Delete every node in this BST.
		  */
		~BST();

		/** Given a reference to a Data item, insert a copy of it in this BST.
		 *  Return a pair where the first element is an iterator 
		 *  pointing to either the newly inserted element or the element 
		 *  that was already in the BST, and the second element is true if the 
		 *  element was newly inserted or false if it was already in the BST.
		 * 
		 *  Note: This function should use only the '<' operator when comparing
		 *  Data items. (should not use ==, >, <=, >=)  
		 */
		std::pair<iterator, bool> insert(const Data& item);


		/** Find a Data item in the BST.
		 *  Return an iterator pointing to the item, or pointing past
		 *  the last node in the BST if not found.
		 *  Note: This function should use only the '<' operator when comparing
		 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
		 *  behind this, see the assignment writeup.
		 */
		iterator find(const Data& item) const;


		/** Return the number of items currently in the BST.
		*/ 
		unsigned int size() const;

		/** Return the height of the BST.
		  height of a tree starts with root at height 0
		  height of an empty tree is -1
		  */ 
		int height() const;

		/** Helper function for height function
		 *
		 */
		int heightHelper(BSTIterator<Data> nodePtr) const;


		/** Return true if the BST is empty, else false.
		*/ // TODO
		bool empty() const;

		/** Return an iterator pointing to the first (smallest) item in the BST.
		*/ 
		iterator begin() const;

		/** Return an iterator pointing past the last item in the BST.
		*/
		iterator end() const;


	private:

		/** Pointer to the root of this BST, or 0 if the BST is empty */
		BSTNode<Data>* root;

		/** Number of Data items stored in this BST. */
		unsigned int isize;

		/** Find the first element of the BST
		 * Helper function for the begin method above.
		 */ 
		static BSTNode<Data>* first(BSTNode<Data>* root);

		/** do a postorder traversal, deleting nodes
		*/
		static void deleteAll(BSTNode<Data>* n);
};


// ********** Function definitions ****************


/** Default destructor.
  Delete every node in this BST.
  */
template <typename Data>
BST<Data>::~BST() {
	deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either the newly inserted
 *  element or the element that was already in the BST, and the second element is true if the 
 *  element was newly inserted or false if it was already in the BST.
 * 
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
	// TODO
	// HINT: Copy code from your BSTInt class and change the return value
	// REPLACE THE LINE BELOW
	//return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(0), false);

	if (!root) { //!root
		root = new BSTNode<Data>(item);
		++isize;
		//	return true;
		return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);

	}
	/*edit*/
	else {
		BSTNode<Data>* curr = root;
		while (curr) {
			if (item < curr->data && curr->left != NULL) {
				curr = curr->left;
			}
			else if (curr->data < item && curr->right != NULL) {
				curr = curr->right;
			}

			else if( curr->data == item) {
				//return false;
				return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(curr), false);

			}
			break;	
		}

		// Ready to insert
		BSTNode<Data> *newNode =new BSTNode<Data>(item);
		if (item < curr->data) {
			/*	if(curr->left != NULL) { 
				while(curr != NULL) {
				curr = curr->left;}}*/
			curr->left = newNode;
			newNode->parent = curr;
		}
		else {
			/*	if(curr->right != NULL) { 
				while(curr != NULL) {
				curr = curr->right;}}*/
			curr->right = newNode;
			newNode->parent = curr;
		}
		++isize;
		//return true;
		return (std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), true));

	}
}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
	// TODO
	// HINT: Copy code from your BSTInt class and change the return value

	BSTNode<Data>* curr = root;
	while (true) {
		if (curr->data < item) {
			curr = curr->right;
		}
		else if (item < curr->data) {
			curr = curr->left;
		}
		else {
			return curr;
		}
	}

	return BSTIterator<Data>(nullptr);

}


/** Return the number of items currently in the BST.
*/ 
template <typename Data>
unsigned int BST<Data>::size() const
{
	return isize;
}

/** Return the height of the BST.
*/
template <typename Data> 
int BST<Data>::height() const
{

	// HINT: Copy code from your BSTInt class
	return heightHelper(root);
}

template <typename Data>
int BST<Data>::heightHelper(BSTIterator<Data> nodePtr) const {
	int leftHeight = 0;
	int rightHeight = 0;
	//	if (nodePtr == NULL)
	return 2;

	/*	else {
		leftHeight = heightHelper(nodePtr -> left);
		rightHeight = heightHelper(nodePtr -> right);
		}	
		leftHeight++;
		rightHeight++;

		if(leftHeight > rightHeight) {
		return leftHeight;
		}
		else
		return rightHeight;
		*/
}



/** Return true if the BST is empty, else false.
*/ 
template <typename Data>
bool BST<Data>::empty() const
{

	// HINT: Copy code form your BSTInt class
	if(root == NULL) {
		return true;
	} else {
		return false;
	}
}

/** Return an iterator pointing to the first (smallest) item in the BST.
*/ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
	return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
*/
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
	return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
	template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
	// TO DO

	if(root == NULL) {
		return NULL;
	}

	while(root.left != NULL) {
		root = root.left;
	}

	return root;
}

/** do a postorder traversal, deleting nodes
*/
	template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{

	// HINT: Copy code from your BSTInt class

	if (n == NULL)
		return;
	if(n->left != NULL) 
		(deleteAll(n->left));
	if(n->right != NULL)
		(deleteAll(n->right));

	delete n;
	//	n = nullptr;
	return;		
}



#endif //BST_HPP
