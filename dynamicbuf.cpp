template <typename T>
class CyclicBuffer2 {
private:
    std::vector<T> buffer;
    size_t head;
    size_t tail;
public:
    CyclicBuffer2(size_t capacity) : buffer(capacity), head(0), tail(0) {}
    void push(T value) {
        buffer[tail] = value;
        tail = (tail + 1) % buffer.size();
        if (tail == head) {
            head = (head + 1) % buffer.size();
        }
    }
    T pop() {
        if (head == tail) {
            throw std::runtime_error("Buffer is empty");
        }
        T value = buffer[head];
        head = (head + 1) % buffer.size();
        return value;
    }
    bool isEmpty() const {
        return head == tail;
    }
    bool isFull() const {
        return (tail + 1) % buffer.size() == head;
    }
};
