if(root == NULL) {
  return false;
}
else {
  for(int i = 0; i < word.length(); i++) {
    while(true) {
      if(curr = word[i]) {
        curr = curr->middle;
        break;
      }
      else if (curr < word[i]) {
        if ( curr -> left != NULL) {
          curr = curr-> left;
          break;
        }
        else {
          return false;
        }
      }
      else {
        if ( curr -> right != NULL) {
          curr = curr-> right;
          break;
        }
        else {
          return false;
        }
      }
    }
  }
  return true;
}
