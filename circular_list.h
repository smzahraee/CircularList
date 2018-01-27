#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

template <class T, int LEN>
class CircularList {
 private:
  int_32 tail_, head_;  // indices
  T list_[LEN];         // buffer

 public:
  CircularList() { head_ = tail_ = 0; }

  ~CircularList(void) {}

  void clear() { head_ = tail_ = 0; }

  // Enqueue one element
  inline void push(const T &element) {
    // test for buffer full
    if (IsFull()) head_ = (head_ + 1) & (LEN - 1);
    list_[tail_] = element;
    tail_ = (tail_ + 1) & (LEN - 1);
  }

  void pushAll(const T element[], int_32 len) {
    for (int_32 i = 0; i < len; i++) push(element[i]);
  }

  // read top element or last enqueued element
  bool at(int_32 idx, T &element) const {
    // check for empty list
    if (getLength() <= idx) return false;

    int_32 _idx = (head_ + idx) % LEN;
    element = list_[_idx];

    return true;
  }

  // dequeue one element
  inline bool pop(T &element) {
    // check for empty list
    if (IsEmpty()) return false;
    element = list_[head_];
    head_ = (head_ + 1) & (LEN - 1);
    return true;
  }

  bool Top(T &element) {
    // check for empty list
    if (IsEmpty()) return false;

    element = list_[head_];
    return true;
  }

  int_32 getLength() const {
    if (IsEmpty()) return 0;
    return LEN - ((head_ - tail_) & (LEN - 1));
  }

  inline int_32 getCapacity() const { return (LEN - 1); }

  inline int_32 RemainingCapacity() const {
    return (getCapacity() - getLength());
  }

  bool IsEmpty() const { return (head_ == tail_); }

  inline bool IsFull() const { return (RemainingCapacity() <= 0); }
};

#endif  // !1
