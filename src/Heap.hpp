#ifndef WEEK7_HEAP_H

template <class T>
class Heap {
private:
    T* array;
    size_t size;
    size_t capacity;
public:
    const T& getTop() {
        return this->array[0];
    }
    Heap() {

        this->array = new T[2];
        this->size = 0;
        this->capacity = 2;

    }
    
    size_t leftChild(size_t parent) { return 2 * parent + 1; }
    size_t rightChild(size_t parent) { return 2 * parent + 2; }
    size_t parentInd(size_t child) { return (child - 1) / 2; }

    bool hasLeftChild(size_t parent) { return leftChild(parent) < this->size; }
    bool hasRightChild(size_t parent) { return rightChild(parent) < this->size; }
    bool hasParent(size_t child) { return parentInd(child) >= 0; }


    void swap(size_t indOne, size_t indTwo) {
        size_t temp = array[indOne];
        array[indOne] = array[indTwo];
        array[indTwo] = temp;
    }
    void ensureSize() {
        if (this->size + 1 != this->capacity) {
            return;
        }

        T* newArr = new T[capacity * 2];

        for (size_t i = 0; i < size; i++)
        {
            newArr[i] = this->array[i];
        }
        delete this->array;
        this->capacity = capacity * 2;
        this->array = newArr;
    }
    void insert(T key) {
        ensureSize();
        this->array[size] = key;
        size_t ind = size;
        size++;
        while (hasParent(ind) && this->array[parentInd(ind)] > array[ind]) {
            swap(parentInd(ind), ind);
            ind = parentInd(ind);
        }
    }

    void removeTop() {
        swap(this->size - 1, 0);
        this->size--;
        size_t index = 0;

        while (hasLeftChild(index)) {
            size_t smallerChildInd = leftChild(index);

            if (hasRightChild(index) && array[smallerChildInd] > array[rightChild(index)]) {
                smallerChildInd = rightChild(index);
            }

            if (array[smallerChildInd] < array[index]) {

                swap(smallerChildInd, index);
                index = smallerChildInd;
                continue;
            }
            break;
        }
    };

    size_t getSize() {
        return this->size;
    }
    bool isEmpty() {
        return !this->size;
    };
    Heap& operator=(const Heap<T>& other) = delete;
    ~Heap() {};
};


template <class T>
class priority_queue {
    
private:
    Heap<T> Qheap;

public:

    T top() {
        Qheap.getTop();
    }

    bool empty() {
        Qheap.isEmpty();
    }

    size_t size() {
        Qheap.getSize();
    }

    void push(T el) {
        Qheap.insert(el);
    }

    void pop() {
        Qheap.removeTop();
    }
};

#define WEEK7_HEAP_H

#endif //WEEK7_HEAP_H
