# Lecture11





## Minimum Spanning Tree(MST)
무방향 그래프 에서

### Spanning Tree
여기에 만약 이전에 강의 안했다면 넣어야 하는 내용

여러가지 정의가 있습니다.
> edge의 weight를 고려할때, graph 에서 최소의 weight를 가지는 

> graph의 edge중 n-1개를 선택해서 모든 node를 연결하는 tree

### MST의 기본 성질
* Tree의 기본 성질을 따릅니다.
    * Spanning Tree의 부분집합이므로 자명합니다.
* MST는 항상 존재하지만 유일하진 않습니다. (여러개 존재할 수 있습니다.)
    * 귀류법으로 유일하다 가정하고, 반례로 모든 weight가 같은 graph를 보여 증명할 수 있습니다.
* 

Graph에서 MST가 가지는 중요한 성질은 Cut property와 Cycle property 이렇게 2가지가 있습니다.   
그리고 각각의 성질을 활용해서 MST를 구성하는 알고리즘이 바로 Prim Algorithm과 Kruskal Algorithm입니다.

### Cut property

우선 Cut은 Graph를 2개 이상의 Graph로 분리시킬수있는 edge의 부분집합입니다.   
ex)

Cut property는 "그래프 cut중에 어떤 edge가 다른 모든 edge보다 작다면 그 edge를 포함하는 MST가 반드시 존재한다." 라는 성질입니다.
<=>   
다르게 말하면 최소비용의 edge는 무조건 선택되어야 한다. 라고 볼수있습니다.


### Cycle property

다르게 말하면 그래프에세 구성할수있는 사이클 C를 찾았을때, MST는 최대비용 edge를 절대 포함하지 않는다는 성질 입니다.





## Prim Algorithm
Cut porperty를 사용해서 MST를 찾는 Algorithm

특정 시작 노드를 선택하고 나머지 노드까지의 최단거리를 구할때 유용합니다.

```
def Prim:
    
```

> plus, Dijkstra Algorithm과 거의 같습니다. 참고.





## Kruskal Algorithm
Cycle property를 사용해서 MST를 만드는 Algorithm
```

```