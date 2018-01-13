#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

template <class T>
class CirculaList {
 public:
  explicit CirculaList(int size) : size_(size) {
    buf_ = new T[size_];
    Clear();
  }

  inline int Count() { return (head_ - tail_) & (size_ - 1); }

  inline int RemainingCapacity() { return (tail_ - (head_ + 1)) & (size_ - 1); }

  inline bool IsEmpty() { return head_ == tail_; }

  inline void Clear() { head_ = tail_ = 0; }

  inline bool HasFreeSpace() { return RemainingCapacity() > 0; }

  inline bool Push(T element) {
    if (HasFreeSpace()) {
      buf_[head_] = element;
      head_ = (head_ + 1) & (size_ - 1);
      return true;
    } else
      return false;
  }

  inline bool Pop(T &element) {
    if (IsEmpty())
      return false;
    else {
      element = buf_[tail_];
      tail_ = (tail_ + 1) & (size_ - 1);
      return true;
    }
  }
  inline bool Top(T &element) {
    if (IsEmpty())
      return false;
    else {
      element = buf_[tail_];
    }
  }

  inline bool At(int index, T &element) {
    if (Count() <= index) return false;
    element = buf_[(head_ + index) & (size_ - 1)];
    return true;
  }

 private:
  T *buf_;
  int head_;
  int tail_;
  const int size_;
};

#endif  // !1