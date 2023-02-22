template <typename T, int N>
class CyclicBuffer1 {
private:
    T buffer[N];
    int head;
    int tail;
public:
    CyclicBuffer1() : head(0), tail(0) {}
    void push(T value) {
        buffer[tail] = value;
        tail = (tail + 1) % N;
        if (tail == head) {
            head = (head + 1) % N;
        }
    }
    T pop() {
        if (head == tail) {
            throw std::runtime_error("Buffer is empty");
        }
        T value = buffer[head];
        head = (head + 1) % N;
        return value;
    }
    bool isEmpty() const {
        return head == tail;
    }
    bool isFull() const {
        return (tail + 1) % N == head;
    }
};
