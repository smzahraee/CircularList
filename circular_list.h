#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

template <class T, uint32_t LEN>
class CircularList {
 private:
  uint32_t head_, tail_;  // indices
  T list_[LEN];           // buffer

 public:
  CircularList() noexcept : head_{0}, tail_{0} {
    static_assert((LEN > 0 && ((LEN & (LEN - 1)) == 0)) != 0,
                  "LIST IS NOT POWER OF TWO");
  }

  ~CircularList(void) noexcept {}

  void clear() noexcept { head_ = tail_ = 0; }

  // Enqueue one element
  inline void Push(const T &element) noexcept {
    // test for buffer full
    if (IsFull()) head_ = (head_ + 1) & (LEN - 1);
    list_[tail_] = element;
    tail_ = (tail_ + 1) & (LEN - 1);
  }

  inline void PushAll(const T element[], uint32_t len) noexcept {
    for (uint32_t i = 0; i < len; i++) Push(element[i]);
  }

  // read top element or last enqueued element
  bool At(uint32_t idx, T *element) const noexcept {
    // check for empty list
    if (Length() <= idx) return false;

    uint32_t _idx = (head_ + idx) & (LEN - 1);
    *element = list_[_idx];

    return true;
  }
  bool AtLast(uint32_t idx, T *element) const noexcept {
    // check for empty list
    if (Length() <= idx) return false;

    const auto _idx = (tail_ - 1 - idx + LEN) & (LEN - 1);
    *element = list_[_idx];

    return true;
  }

  // dequeue one element
  inline bool pop(T *element) noexcept {
    // check for empty list
    if (IsEmpty()) return false;
    *element = list_[head_];
    head_ = (head_ + 1) & (LEN - 1);
    return true;
  }

  bool Top(const T *element) const noexcept {
    // check for empty list
    if (IsEmpty()) return false;

    *element = list_[head_];
    return true;
  }

  uint32_t Length() const noexcept {
    if (IsEmpty()) return 0;
    return LEN - ((head_ - tail_) & (LEN - 1));
  }

  inline uint32_t Capacity() const noexcept { return (LEN - 1); }

  inline uint32_t RemainingCapacity() const noexcept {
    return (Capacity() - Length());
  }

  bool IsEmpty() const noexcept { return (head_ == tail_); }
  inline bool IsFull() const noexcept { return (RemainingCapacity() <= 0); }
};

#endif  // !1
