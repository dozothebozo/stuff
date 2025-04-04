class Node<T> {
  value: T;
  next: Node<T> | null;

  constructor(value: T) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList<T> {
  length: number;
  head: Node<T> | null;
  tail: Node<T> | null;

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

  push(value: T): number {
    const newNode = new Node<T>(value);
    if (!this.tail) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }
    this.length++;
    return this.length;
  }

  pop(): T | undefined {
    if (!this.head) return undefined;
    
    if (this.length === 1) {
      const temp = this.head;
      this.head = null;
      this.tail = null;
      this.length--;
      return temp.value;
    } else {
      let temp = this.head;
      let pre = temp;
      while (temp.next) {
        pre = temp;
        temp = temp.next;
      }
      this.tail = pre;
      this.tail.next = null;
      this.length--;
      return temp.value;
    }
  }
}

const myEmptyLinkedList = new LinkedList()
myEmptyLinkedList.push("x");
myEmptyLinkedList.push(1);
myEmptyLinkedList.push(false);

console.log(myEmptyLinkedList);