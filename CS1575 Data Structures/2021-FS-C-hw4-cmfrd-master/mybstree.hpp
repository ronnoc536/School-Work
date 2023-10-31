template<typename T> // Default Constructor
MyBSTree<T>::MyBSTree() 
{
  m_root = NULL;
  m_size = 0;
}

template<typename T> // New Destructor 
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)
{
  m_root = NULL;
  m_size = 0;
  (*this) = rhs;
}


template<typename T> // Destructor
MyBSTree<T>::~MyBSTree()
{
  clear();
}

template<typename T> // gets size of tree
int MyBSTree<T>::size() const
{
  return m_size + 1;
}

template<typename T> // checks if tree is empty
bool MyBSTree<T>::isEmpty() const
{
  bool is_empty = false;
  if(m_size == 0)
    is_empty = true;
  return is_empty;
}

template<typename T> // calls height function
int MyBSTree<T>::height() const
{
  if (m_root==NULL) return 0;
  return height(m_root);
}

template<typename T> // recursive height function
int MyBSTree<T>::height(TreeNode<T> * t) const
{
  if(t == NULL)
      return 0;
  else
  {
    int DofLeft = height(t -> m_left);
    int DofRight = height(t -> m_right);
    if(DofLeft > DofRight)
      return(DofLeft + 1);
    else
      return(DofRight + 1);
  }
}

template<typename T> // get max but with oops
const T& MyBSTree<T>::getMax() const throw (Oops)
{
  if (m_root == NULL) throw Oops(""); // Throw Oops?
  TreeNode<T> * tmp = m_root;
  while (tmp->m_right != NULL)
    tmp = tmp->m_right;
  return tmp->m_data;
}

template<typename T> // get max recursive
const T& MyBSTree<T>::getMax(TreeNode<T> * t) const
{
  if (t->m_right != NULL)
    return getMax(t->m_right);
  return t->m_data; 
}

template<typename T>  // get min but with oops
const T& MyBSTree<T>::getMin() const throw (Oops)
{
  if (m_root == NULL) throw Oops("");
  return getMin(m_root);
}


template<typename T> // recursive get min
const T& MyBSTree<T>::getMin(TreeNode<T> * t) const
{
  if (t->m_left == NULL)
    return t->m_data;
  return getMin(t->m_left);
}


template<typename T> // finds a particular specified node based on data
int MyBSTree<T>::find(const T& x) const
{
  int level_counter = 1;
  bool node_found = false;
  TreeNode<T>* t = m_root;

  while((t != NULL) && (!node_found))
  {
    if(t->m_data == x)
      node_found = true;
    else if(t->m_data > x)
    {
      t = t->m_left;
      level_counter++;
    }
    else
    {
      t = t->m_right;
      level_counter++;
    }
  }
  return node_found ? level_counter : level_counter * -1;
}

template<typename T>
void MyBSTree<T>::clear()  // clears the tree
{
  if(m_root != NULL)
    delete m_root;
  m_root = NULL;
  m_size = 0;
}





template<typename T>
void MyBSTree<T>::insert(const T& x) // calls insert 
{
  if (m_root == NULL)
    m_root = new TreeNode<T>(x,NULL,NULL);
  else
  {
    insert(m_root, x); 
    m_size++;
  }

  return;
}

template<typename T> // recursive insert
void MyBSTree<T>::insert(TreeNode<T>* node, const T& x)
{
    
  if(x > node->m_data)
  {
    if(node->m_right == NULL)
      node->m_right = new TreeNode<T>(x,NULL,NULL);
    else
      insert(node->m_right, x);
  }
    
  else
  {
    if(node->m_left == NULL)
      node->m_left = new TreeNode<T>(x,NULL,NULL);
    else
      insert(node->m_left, x);
  }
}

template<typename T> // calls remove
void MyBSTree<T>::remove(const T& x)
{
  if(m_root == NULL) return;
  remove(m_root, x);
  return;
}

template<typename T> // remove but recursive
void MyBSTree<T>::remove(TreeNode<T> * &t, const T& x)
{
  if(t == NULL) return;
  
  if(x < t->m_data)
      remove(t->m_left, x);
  else if(x > t->m_data)
      remove(t->m_right, x);
	else // found x
  { 
    // NODE WITH NO CHILDREN
    if(t->m_left == NULL && t->m_right == NULL)
    {
      delete t;
      t = NULL;
    }

    // NODE WITH ONE CHILD
    else if(t->m_left == NULL || t->m_right == NULL)
    {
      TreeNode<T> * child = t->m_left;                
      if(child == NULL)
        child = t->m_right;
      t = child;
    }
     
    // NODE WITH TWO CHILDREN
    else
    {
      t->m_data = getMax(t->m_left);
      remove(t->m_left, t->m_data);
    }
  }
}

template<typename T>  // calls preorder
void MyBSTree<T>::printPreOrder() const
{
  printPreOrder(m_root);
}


template<typename T> // pretty print
void MyBSTree<T>::prettyPrint (const TreeNode<T>* t, int pad) const
{
  string s(pad, ' ');
  if (t == NULL)
    cout << endl;
  else
  {
  	prettyPrint(t->m_right, pad+4);
    cout << s << t->m_data << endl;
    prettyPrint(t->m_left, pad+4);
  }
  
	return;
}

template<typename T> // pre order but recursive 
void MyBSTree<T>::printPreOrder(TreeNode<T> * t) const
{
  if (t == NULL)
    return;
  cout << t->m_data << " ";
  printPreOrder(t->m_left);
  printPreOrder(t->m_right);
  return;
}

template<typename T> // calls post order
void MyBSTree<T>::printPostOrder() const
{
  printPostOrder(m_root);
}

template<typename T> // post order but recursive
void MyBSTree<T>::printPostOrder(TreeNode<T>* t) const
{
  if (t == NULL)
    return;
  printPostOrder(t->m_left);
  printPostOrder(t->m_right);
  cout << t->m_data << " ";
  return;
}

template<typename T> // calls pretty print
void MyBSTree<T>::print() const
{
  prettyPrint(m_root, 0);
}

template<typename T> // operator overload for =
MyBSTree<T>& MyBSTree<T>::operator= (const MyBSTree<T>& rhs)
{
  if (this != &rhs)
  {
    clear();
    m_root = clone(rhs.m_root);
    m_size = rhs.m_size;
  }
  return *this;
}





