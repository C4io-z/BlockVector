#include <iostream>
#include <math.h>
#include <cstdlib>


template<class T>
class blockVector {
    public:

    blockVector(unsigned int block, unsigned int _block_size){
        if(block == 0)return;
        _blocks = block;
        block_size = _block_size;
        stack_size = 0;
        block_stack = 0;
        blocks = new T*[block];
        blocks[0] = new T[block_size];
    }
    ~blockVector(){
        clear();
        delete [] blocks;
    }

    T **blocks;
    int _blocks;
    int stack_size;
    int block_stack;
    int block_size;

    void push_back(T n){
        if(stack_size+1 > block_size){
             stack_size = 0;
             block_stack++;
             blocks[block_stack] = new T[block_size];
        }
        blocks[block_stack][stack_size] = n;
        stack_size++;
    }

    T *operator[](int n){
        if(abs(n) >= (block_stack*block_size)+stack_size)return 0;

        if(n < 0)n = size()+n;

        int Block = n/block_size;
        int Stack = n%block_size;
        return &blocks[Block][Stack];
    }

    void clear(){
        for(int i = 0; i < _blocks; i++){
            delete [] blocks[i];
        }
        stack_size = 0;
        block_stack = 0;
        blocks[0] = new T[block_size];
    }
    int memorySize(){
        int temp = (block_stack+1)*block_size*sizeof(T);
        temp += _blocks*8;
        return temp;
    }
    unsigned int size(){
        return (block_stack)*block_size + stack_size;
    }
    float eficiencia(){
        return size()/((float)memorySize()/(float)sizeof(T));
    }
    unsigned int max_size(){
        return _blocks*block_size;
    }
};
