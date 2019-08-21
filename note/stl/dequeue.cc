Deque 简介

    deque是“double—ended queue”的缩写，和vector一样都是STL的容器，deque 是双端数组，而 vector 是单端的。

    deque 在接口上和 vector 非常相似，在许多操作的地方可以直接替换。

    deque 可以随机存取元素（支持索引值直接存取，用[]操作符或at()方法，这个等下会详讲）。

    deque 头部和尾部添加或移除元素都非常快速。但是在中部安插元素或移除元素比较费时。


Deque 实现原理

  deque 的中控器

    deque是连续空间（至少逻辑上看来如此），连续线性空间总令我们联想到array或vector。array无法成长，vectors 可成长，却只能向尾端成长，
    而且其所谓的成长原是个假象，事实上是
    1 : 另觅更大空间；
    2 : 将原数据复制过去；
    3 : 释放原空间三部曲。
    如果不是vector每次配置新空间时都有留下一些余裕，其成长假象所带来的代价将是相当高昂。

    deque系由一段一段的定量连续空间构成。一旦有必要在deque的前端或尾端增加新空间，便配置一段定量连续空间，串接在整个deque的头端或尾端。
    deque的最大任务，便是在这些分段的定量连续空间上，维护其整体连续的假象，并提供随机存取的接口。避开了“重新配置、复制、释放”的轮回，代价则是复杂的迭代器架构。

    受到分段连续线性空间的字面影响，我们可能以为deque的实现复杂度和vector相比虽不中亦不远矣，其实不然。
    主要因为，既是分段连续线性空间，就必须有中央控制，而为了维持整体连续的假象，数据结构的设计及迭代器前进后退等操作都颇为繁琐。deque的实现代码分量远比vector或list都多得多。

    deque采用一块所谓的map（注意，不是STL的map容器）作为主控。这里所谓map是一小块连续空间，其中每个元素（此处称为一个节点，node）都是指针，指向另一段（较大的）连续线性空间，称为缓冲区。缓冲区才是deque的储存空间主体。
    STL 允许我们指定缓冲区大小，默认值0表示将使用512 bytes 缓冲区。

    deque的整体架构如下图所示：

           ------
           |    |                                                                                                               
           |   ----------------------------------------------------------------------------> -------                                                                                                              
           |    |                                                                            |     |                              
           ------                                                                            |     |                                  
           |    |                                                                            |     |                              
           |  -------------------------------------------------------->-------               |     |                              
           |    |                                                      |     |               |     |                              
           ------                                                      |     |               |     |                                  
           |    |                                                      |     |               |     |                              
           |  -------------------------------------->-------           |     |               |     |                              
           |    |                                    |     |           |     |               |     |                              
           ------                                    |     |           |     |               |     |                                  
           |    |                                    |     |           |     |               |     |                              
           |    |                                    |     |           |     |               |     |                              
           |    |                                    |     |           |     |               |     |                                              
           ------                                    |     |           |     |               |     |                                  
                                                     |     |           |     |               |     |                                
                                                     |     |           |     |               |     |              
                                                     |     |           |     |               |     |             
                                                     |     |           |     |               -------                
                                                     |     |           |     |          
                                                     |     |           |     |          
                                                     |     |           |     |          
                                                     |     |           |     |          
                                                     |     |           |     |          
                                                     |     |           |     |          
                                                     |     |           -------               
                                                     |     |                            
                                                     |     |                            
                                                     |     |                            
                                                     |     |                            
                                                     |     |                            
                                                     -------                            



  deque 的迭代器

    迭代器结构如下图所示：

      --------------------------------------
      |       |         |         |        |                                
      |  node |   curr  |  first  |  last  |                                                 
      |       |         |         |        |                                
      --------------------------------------

    

    在上面介绍中我们大致了解了deque 的基本概念和实现原理，现在我就开始介绍如何使用 deque。

deque 对象的默认构造

    deque 采用模板类实现，deque 对象的默认构造形式：deque<T> dequeT；   

==>>> template 

deque<int> deqInt;          
deque<float> deqFloat;    
deque<string> deqString;  


==>>> add and remove data of deque

deque.push_back(elem);      
deque.push_front(elem);   
deque.pop_back();             
deque.pop_front();          


==>>> access data of deque   

deque.at(idx);    
deque[idx];      
deque.front(); 
deque.back(); 

==>>> iterator of deque   

deque.begin();  
deque.end();  
deque.rbegin(); 
deque.rend();  

==>>> deque construction 

deque(beg, end);   
deque(n, elem);  
deque(const deque &deq); 

==>>> deque assignment 

deque.assign(beg,end);   
deque.assign(n,elem); 
deque& operator=(const deque &deq); 
deque.swap(deq);  

==>>> deque size 

deque.size();     
deque.empty();    
 
deque.resize(num); 
deque.resize(num, elem);

==>>> deque inseration

deque.insert(pos,elem);  
deque.insert(pos,n,elem); 
deque.insert(pos,beg,end); 

==>>> deque deleration   

deque.clear(); 
deque.erase(beg,end); 
deque.erase(pos); 
deqInt.clear();         


// https://blog.csdn.net/baidu_28312631/article/details/48000123

