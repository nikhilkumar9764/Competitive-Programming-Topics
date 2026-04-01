/*
Write a Java method rotateArray(int[] arr, int k) that rotates the elements
of the array to the left by k positions.


Example:
rotateArray(new int[]{1,2,3,4,5}, 1) -> [2,3,4,5,1]
rotateArray(new int[]{1,2,3,4,5}, 2) -> [3,4,5,1,2]
rotateArray(new int[]{1,2,3,4,5}, 3) -> [4,5,1,2,3]


Your solution should:
 - return the rotated array
 - work for any non-negative k
 - handle cases where k is larger than the array length
 - avoid modifying the original input array
*/


import java.util.Arrays;


public class Main {


    public static int[] rotateArray(int[] arr, int k) {
        // to be implemented 
        int[] res= new int[arr.length];
      
        if(k>arr.length && arr.length>0)
        {
          int mul = k/arr.length;
           k = k-mul*arr.length;
        }
        
        if(k>=0 && arr.length>0)
        {
          int idx = 0;
          for(int i=k;i<arr.length;i++)
          {
             res[idx] = arr[i];
             idx++;
          }
          for(int j=0;j<k;j++)
          {
             res[idx] = arr[j];
             idx++;
          }
        }
    
        return res;
    }


    public static void test(int[] arr, int k, int[] expected) {
        int[] original = (arr == null) ? null : Arrays.copyOf(arr, arr.length);
        int[] actual = rotateArray(arr, k);


        boolean correct = Arrays.equals(actual, expected);
        boolean unmodified = Arrays.equals(arr, original);


        System.out.println(
            ((correct && unmodified) ? "PASS" : "FAIL") +
            " | rotateArray(" + Arrays.toString(arr) + ", " + k + ")" +
            " => " + Arrays.toString(actual) +
            " | expected: " + Arrays.toString(expected) +
            " | inputUnmodified: " + unmodified
        );
    }


    public static void main(String[] args) {
        // required behavior
        test(new int[]{1,2,3,4,5}, 1, new int[]{2,3,4,5,1});
        test(new int[]{1,2,3,4,5}, 2, new int[]{3,4,5,1,2});
        test(new int[]{1,2,3,4,5}, 3, new int[]{4,5,1,2,3});
        test(new int[]{1,2,3,4,5}, 0, new int[]{1,2,3,4,5});
        test(new int[]{1,2,3,4,5}, 5, new int[]{1,2,3,4,5});
        test(new int[]{1,2,3,4,5}, 7, new int[]{3,4,5,1,2});
        test(new int[]{9}, 3, new int[]{9});
        test(new int[]{}, 2, new int[]{});
    }
}


SQL query based question : Given three tables 
Table customers {
  customer_id integer [primary key]
  first_name varchar(100)
  last_name varchar(100)
  age integer
  country varchar(100)
}


Table orders {
  order_id integer [primary key]
  item varchar(100)
  amount integer
  customer_id integer
}


Table shippings {
  shipping_id integer [primary key]
  status varchar(50)
  customer integer
}


-- Write an SQL query to find the top 3 customers with the highest total order amount
-- among customers whose shipping status is 'Pending'.
--
-- Your query should:
-- - join the Customers, Orders, and Shippings tables
-- - match Orders.customer_id with Customers.customer_id
-- - match Shippings.customer with Customers.customer_id
-- - include customers even if they have no orders, as long as their shipping status is 'Pending'
-- - calculate each customer’s total spent as the sum of all their order amounts
-- - show total_spent as 0 for customers with no orders
-- - calculate the total number of orders placed by each customer
-- - show total_orders as 0 for customers with no orders
-- - return: customer_id, first_name, last_name, country, total_spent, total_orders
-- - sort the results by total_spent in descending order
-- - limit the output to the top 3 customers


Ans : SELECT c.first_name , c.last_name, c.country, COALESCE(SUM(o.amount),0) AS total_amt , COUNT(o.order_id) AS total_orders FROM customers c LEFT JOIN orders o ON c.customer_id = o.customer_id LEFT JOIN shipping s ON c.customer_id = s.customer WHERE s.status = ‘Pending’ GROUP BY c.first_name , c.last_name, c.country,
ORDER BY total_amt DESC LIMIT 3 ; 
