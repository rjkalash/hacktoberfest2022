import java.util.*;

public class lruCatche {


    public static void main(String[] args) {
        LRU lru = new LRU(3);
        lru.put(1, 10);
        lru.put(2, 20);
        lru.put(3, 30);
        System.out.println( lru.get(1) );
        lru.put(1, 15);
        System.out.println( lru.get(1) );
        System.out.println( lru.get(2) );
        //System.out.println(lru.map.size());
        //System.out.println(lru.tail.prev.key);
        lru.put(4, 40);
        System.out.println( lru.get(3) );
        System.out.println( lru.get(4) );
    }
}
class Node{
    int data;
    int key;

    Node next;
    Node prev;

    Node(int key,int data){
        this.data =data;
        this.key =key;
        this.next = null;
        this.prev =null;
    }


}
class LRU{

    int capacity;

    Node head = new Node(-1, -1);
    Node tail = new Node(-1,-1);
      
    
    HashMap<Integer,Node> map = new HashMap<>();

    LRU(int cap){
       this.capacity = cap;
       head.next = tail;
       tail.prev = head; 
    }  

    int get(int key){
        if(map.containsKey(key)){
            Node node = map.get(key);
            deleteNode(node);
            insert(node);
            return map.get(key).data;
        }
        return -1;
    }
    void put(int key , int val){
        if(map.containsKey(key)){
            
            deleteNode(map.get(key));
            map.remove(key);
              
        }
        else if(map.size()==capacity){
            
            map.remove(tail.prev.key);
            deleteNode(tail.prev);
        }

        Node node = new Node(key, val);
        insert(node);
        map.put(key, node);

    }
    void insert(Node node){

        node.next = head.next;
        node.next.prev = node;
        head.next = node;
        node.prev = head;

    }
    void deleteNode(Node node){
        Node delN = node.next;
        Node delP = node.prev;

        delP.next = delN;
        delN.prev = delP;
    }

}
