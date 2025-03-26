class Node<T> {
  value: T | null;
  next: Node<unknown> | null;

  constructor(value: T | null = null) {
    this.value = value;
    this.next = null;
  }
}
class LinkedList<T> {
  length: number;
  head: Node<unknown> | null;
  tail: Node<unknown> | null;

  constructor(value: T | null = null) {
    this.length = 0;
    if (value === null || value === undefined) {
      this.head = null;
      this.tail = null;
    } else {
      const newNode = new Node<T>(value);
      this.head = newNode;
      this.tail = newNode;
      this.length++;
    }
  }
}

const myEmptyLinkedList = new LinkedList()
const myLinkedList = new LinkedList<number>(5)


console.log(myEmptyLinkedList);
console.log(myLinkedList);
