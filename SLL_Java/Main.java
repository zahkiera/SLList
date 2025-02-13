
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);

      SLList<Integer> k = new SLList<Integer>();
      System.out.println("Enter 4 numbers");

      int i1 = scanner.nextInt();
      int i2 = scanner.nextInt();
      int i3 = scanner.nextInt();
      int i4 = scanner.nextInt();

      System.out.println("Push back first two, push front last two ");
      k.push_back(i1);
      k.push_back(i2);
      k.push_front(i3);
      k.push_front(i4);

      k.print();
      System.out.println("");

  
      k.pop_back();
      System.out.println("Pop back utilized");
      k.print();
      System.out.println("");

      System.out.println("Insert utilized");
      k.insert(2,2,1);
      k.print();
      System.out.println("");


      System.out.println("Erase position 3");
      k.erase(3);
      k.print();
  
      System.out.println("");
  
      System.out.println("Remove value of i2");

      k.remove(i2);
      k.print();
  
      System.out.println("");

      System.out.println("Rotate right utilized");
      k.rotate_right(1);
      k.print();

      scanner.close();
    }
  
  }