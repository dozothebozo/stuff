class Node<T> {
  value: T | null;
  next: Node<unknown> | null;

  constructor(value: T | null = null) {
    this.value = value;
    this.next = null;
  }
}

const newNode = new Node<string>("hello world");
const emptyNode = new Node<string>(); 
const numberNode = new Node<number>(1);

newNode.next = emptyNode;
emptyNode.next = numberNode;

console.log(newNode);
console.log(emptyNode);


console.log(newNode)
console.log(emptyNode)