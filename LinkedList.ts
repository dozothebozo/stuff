class Node<T> {
  value: T;
  next: Node<unknown> | null;

  constructor(value: T) {
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

  push<Y>(value: Y): number {
    const newNode = new Node<Y>(value);
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
}

const myEmptyLinkedList = new LinkedList()
myEmptyLinkedList.push("x");
myEmptyLinkedList.push(1);
myEmptyLinkedList.push(false);

console.log(myEmptyLinkedList);