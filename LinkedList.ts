class Node<T> {
  value: T | null;
  next: Node<T> | null;

  constructor(value: T | null = null) {
    this.value = value;
    this.next = null;
  }
}

const newNode = new Node<string>("hello world");
const emptyNode = new Node()

newNode.next = emptyNode

console.log(newNode)
console.log(emptyNode)