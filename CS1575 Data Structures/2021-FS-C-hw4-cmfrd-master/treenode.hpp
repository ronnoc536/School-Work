template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode<T> * rNode, TreeNode<T> * lNode)
{
  m_data = data;
  m_right = rNode;
  m_left = lNode;
}

template<typename T>
TreeNode<T> :: ~TreeNode()
{
  if(m_right != NULL)
  {
    delete m_right;
    m_right = NULL;
  }
  if(m_left != NULL)
  {
    delete m_left;
    m_left = NULL;
  }
}

template <typename T>
static TreeNode<T>* clone(const TreeNode<T>* t)
{
  if (t == NULL)
  {
    return NULL;
  }
  else
  {
    return new TreeNode<T>(t->m_data,clone(t->m_right),clone(t->m_left));
  }
}