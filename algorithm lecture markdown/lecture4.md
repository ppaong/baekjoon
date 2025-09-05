# Lecture4

4. * ### Tree
   * Heap
   * Priority Queue
   * Bineary Search Tree(BST)

> 정말 중요한 자료구조인 tree와 heap, BST를 배웁니다.


## Tree

### Tree property





## Tree Traversal

### Preorder

### Inorder

### Postorder





## Heap

### Heap property


### Insertion in Heap


### Searching in Heap


### Deletion in Heap


### Minimum or Maximum in Heap



## Heap Implementation(이거 시간상 생략 고려)

### heapify-down


### heapify-up



## Priority Queue
heap을 응용하면 아주 유용한 자료구조들을 만들수 있는데, 그 중 하나가 Priority Queue입니다.   
Heap property에 따르면 heap의 top은 항상 최소원소가 위치하는것을 알수있습니다.   
따라서 어떤 sqeuence를 가지고 heap을 만든다면





## Heap sort
Priority Queue를 이용해서 계속해서 원소를 뽑아낸다면 오름차순으로 정렬할수있는 사실은 자명합니다. 이 방식으로 수열을 정렬하는것을 Heap sort라고 부릅니다.





## Binary Search Tree(BST)

### L-R Order property(딱히 명칭이 없어서 그냥 지었습니다.)
BST에는 left Subtree와 Right Subtree 에 순서 성질이 있습니다. quick sort비슷 하게 


솔직히 다 필요없고 이거 하나만 기억하면 됩니다.
"유지되는 성질"
이게 본질이에요.


### Insertion in BST


### Searching in BST


### Deletion in BST


### Minimum and Maximum in BST



힙과 다르게 BST의 순서 성질에 따라 최소원소와 최대원소를 항상 $O(\log n)$ 안에 찾을 수 있습니다.





힙은 heap property, BST는 순서 성질

merge sort와 비슷합니다.