
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
  Delete every node in this BST.
  */
BSTInt::~BSTInt() {
	deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
	if (!root) { //!root
		root = new BSTNodeInt(item);
		++isize;
		return true;
	}
	else {

		BSTNodeInt* curr = root;
		//	BSTNodeInt* curr_parr;
		//	while (!curr) {
		while (curr->left && curr->right) {
			if (item < curr->data/* && curr->left != NULL*/) {
				//			curr_parr = curr;
				curr = curr->left;
			}
			else if (curr->data < item/* && curr->right != NULL*/) {
				//			curr_parr = curr;
				curr = curr->right;
			}
			else {
				return false;
			}
		}


		// Ready to insert
		BSTNodeInt* newNode = new BSTNodeInt(item);
		if (item < curr->data) {
			/*	if(curr->left != NULL) { 
				while(curr != NULL) {
				curr = curr->left;
				}
				}*/

			curr->left = newNode;
			newNode->parent = curr;
		}
		else {
			/*	if(curr->right != NULL) { 
				while(curr != NULL) {
				curr = curr->right;
				}
				}*/
			curr->right = newNode;
			newNode->parent = curr;
		}

		++isize;
		return true;

	}
	}


	/** Find a Data item in the BST.
	 *  Return true if the item is in the BST or false otherwise
	 *  Note: This function should use only the '<' operator when comparing
	 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
	 *  behind this, see the assignment writeup.
	 */
	bool BSTInt::find(int item) const
	{
		BSTNodeInt* curr = root;
		while (curr) {
			if (curr->data < item) {
				curr = curr->right;
			}
			else if (item < curr->data) {
				curr = curr->left;
			}
			else {
				return true;
			}
		}
		return false;
	}


	/** Return the number of items currently in the BST.
	*/
	unsigned int BSTInt::size() const 
	{
		return isize;
	}


	/** Return the height of the BST.
	  Height of tree with just root node is 0
	  */
	int BSTInt::height() const
	{
		return (heightHelper(root));		
	}

	int BSTInt::heightHelper(BSTNodeInt* nodePtr) const {
		int leftHeight = 0;
		int rightHeight = 0;
		if (nodePtr == NULL)
			return 0;

		else {
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

	}


	/** Return true if the BST is empty, else false. 
	*/
	bool BSTInt::empty() const 
	{
		if(root == NULL) {
			return true;
		} else {  
			return false;
		}
	}




	/** do a postorder traversal, deleting nodes
	 * This is a helper for the destructor
	 * This method is static because it acts on BSTNodeInts
	 *   and not on the BSTInt object directly.
	 */
	void BSTInt::deleteAll(BSTNodeInt* n)
	{
		// TODO


	}

