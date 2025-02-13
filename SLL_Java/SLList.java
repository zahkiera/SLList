public class SLList<T> {
    private SLLNode<T> head;
    private SLLNode<T> tail;
    long listSize;
    
    public SLList() {
      head = tail = null;
      listSize = 0;
    }
    public SLList(final SLList<T> other) {
      head = tail = null;
      listSize = 0;
      SLLNode<T> cur = other.head;
      while (cur != null) {
        push_back(cur.data);
        cur = cur.next;
      }
  }
  
    
    public boolean empty() {
      return head == null;
    }
  
    public void push_front(T val) {
      head = new SLLNode<T>(val, head);
      listSize++;
      if (listSize == 1) {
        tail = head;
      }
    }
  
    public void push_back(T val) {
      if (empty()) {
        push_front(val);
      }
      else {
        tail.next = new SLLNode<T>(val);
        tail = tail.next;
        listSize++;
      }
    }
  
    // Note: no pointer is need to delete the head, you just shift it over and set it to null if the list is empty + decrement listSize
    public void pop_front() {
      if (empty()) {
        return;
      }
      head = head.next;
      if (head == null) { // if list is empty
        tail = null;
      }
      listSize--;
    }
  
    public void pop_back() {
      if (empty()) {
        return;
      }
      if (listSize == 1) {
        pop_front();
      }
      SLLNode<T> cur = head;
      while (cur.next != null && cur.next.next != null) {
        cur = cur.next;
      }
      cur.next = null;
      tail = cur;
      listSize--;
    }
  
    public void print() {
      if (listSize == 0) {
        System.out.println("Empty list");
        return;
      }
      SLLNode<T> cur = head;
      for (int i = 0; i < listSize; i++) {
        System.out.print(cur.data + " ");
        cur = cur.next;
      }
    }
  
    public void clear() {
      if (empty()) {
        return;
      }
      while (!empty()) {
        pop_front();
      }
    }
    public void insert(long pos, final T value, long n) {
      if (pos > listSize ||
          pos < 0) {
      System.out.println("Invalid position, cannot insert");
        return;
          }
      else if(pos == listSize) {
        for (int i = 0; i < listSize; i++) {
          push_back(value);
        }
      }
      else if (pos == 0) {
        for (int i = 0; i < n; i++) {
        push_front(value);
      }
      }
      else {
        SLLNode<T> cur = head;
        for (int i = 0; i < pos-1; i++) {
          cur = cur.next;
        }
        for (int j = 0; j < n; j++) {
          cur.next = new SLLNode<T>(value, cur.next);
          listSize++;
        }
      }
    }
    public void erase(long pos) {
      if (empty()) {
        System.out.println("Empty list");
        return;
      }
      else if (pos >= listSize || pos < 0) {
        System.out.println("Invalid position, cannot erase");
        return;
      }
      else if (pos == 0) {
        pop_front();
      }
      else if (pos == listSize - 1) {
        pop_back();
      }
      else {
        SLLNode<T> cur = head;
        for (int i = 0; i < pos - 1; i++) {
          cur = cur.next;
        }
        cur.next = cur.next.next;
        listSize--;
      }
    }
  
    public void remove(final T val) {
      if (empty()) {
        System.out.println("Empty list");
        return;
      }
    else {
      SLLNode<T> cur = head;
      SLLNode<T> prev = null;
      while (cur != null) {
        if (cur.data == val) {
          if (cur == head) {
            pop_front();
            cur = head;
          }
          else if (cur.data == tail) {
            pop_back();
            cur = tail;
          }
          else {
            prev.next = cur.next;
            cur = prev.next;
            listSize--;
          }
        }
        else {
          prev = cur;
          cur = cur.next;
        }
      }
    }
  }
    public void rotate_right(long k) {
      if (empty()) {
        System.out.println("Empty list");
        return;
      }
      else if (k == 0) {
        return;
      }
      else {
        for (int i = 0; i < k; i++) {
          push_front(tail.data);
          pop_back();      
        }
      }
    }
  }
  