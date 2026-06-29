#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class MaxHeap {
private:
    std::vector<T> data;
public:
    void push(const T& item);
    // Removes the largest element in the heap
    void pop();
    // Returns the largest element in the heap (but does not remove it)
    T const& top() const;
    std::size_t size() const;
};

template <typename T>
void MaxHeap<T>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / 2;
        T& current = data[index];
        T& parent = data[parent_index];
        if (current <= parent) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}

template <typename T>
void MaxHeap<T>::pop() {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }

    // TO BE COMPLETETED
    std::swap(data[0], data[data.size() - 1]);
    data.pop_back();

    std::size_t index = 0;

    while (true) 
    {
    std::size_t left = 2 * index + 1;
    std::size_t right = 2 * index + 2;
    std::size_t largest = index;

    if (left < data.size() && data[left] > data[largest]) 
    {
        largest = left;
    }

    if (right < data.size() && data[right] > data[largest]) 
    {
        largest = right;
    }

    if (largest == index)
    {
        break;
    }

    std::swap(data[index], data[largest]);
    index = largest;
}  
}

template <typename T>
T const& MaxHeap<T>::top() const {
    if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }
    return data[0];
}

template <typename T>
std::size_t MaxHeap<T>::size() const {
    return data.size();
}
