//Martha Winger- Bearskin
//Homework # 8
//maxHeap.hpp




//operator =
template <typename T>
const maxHeap<T> & maxHeap<T>::operator= (const maxHeap & rhs)
{
    if(this != &rhs)
    {
        delete [] m_data;
        m_data = new T[rhs.m_max];
        for (int i = 1; i < rhs.m_size; i++)
        {
            m_data[i]=rhs.m_data[i];
        }
    }
    
    return *this;
}

template <typename T>
bool maxHeap<T>::isEmpty() const
{
    if (m_size == 0)
        return true;
    else
        return false;
}

template <typename T>
int maxHeap<T>::size() const
{
    return m_size;
}

template <typename T>
const T& maxHeap<T>::top() const
{
    char error = 'E';
    if (m_size > 0)
        return m_data[1];
    else
        throw error;
}

template <typename T>
void maxHeap<T>::print() const
{
    prettyPrint( 1, 0);
}

template <typename T>
void maxHeap<T>::insert(const T& x)
{
    if (m_size == (m_max - 1))
    {
        T* tmp;
        tmp = new T[m_max*2];
        for(int i= 0; i <= m_size; i++)
            tmp[i]= m_data[i];
        delete [] m_data;
        m_data = tmp;
        m_max = (m_max*2);
    }
    m_size++;
    int hole = m_size;
    while(hole > 1 && m_data[hole/2] < x)
    {
        m_data[hole] = m_data[hole/2];
        hole = (hole/2);
    }
    m_data[hole] = x;
}

template <typename T>
void maxHeap<T>::clear()
{
    m_size = 0;
}

template <typename T>
void maxHeap<T>::remove()
{
    int hole = 1;
    T tmp = m_data[hole];
    m_size--;
    bool done = false;
    while(hole*2 < m_size && !done)
    {
        int child= (hole*2);
        if((child +1) < m_size && m_data[child] < m_data[child +1])
            child++;
        if(m_data[child] > tmp)
        {
            m_data[hole] = m_data[child];
            hole = child;
        }
        else
            done = true;
    }
    m_data[hole] = tmp;
}

template <typename T>
void maxHeap<T>::prettyPrint(int ix, int pad)const
{
    string s(pad, ' ');
    if (ix > m_size)
        cout << endl;
    else
    {
        prettyPrint((2*ix+1), pad+4);
        cout << s << m_data[ix] << endl;
        prettyPrint((2*ix), pad+4);
    }  
}





