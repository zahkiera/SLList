public class SLLNode<T> {
    public SLLNode(final T data, SLLNode<T> next) {
      this.data = data;
      this.next = next;
    }
    public SLLNode(T data) { // must be overloaded since java doesn't allow default parameters
      this.data = data;
      this.next = null;
    }
    
    T data;
    SLLNode<T> next;
  }