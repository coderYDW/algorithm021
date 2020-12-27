# 学习笔记

## 总结

这周的题目好难啊，尤其是单词接龙，看题解都有些搞不懂，对广度优先搜索和深度优先搜索还是要多联系，有些懵懵懂懂。

## 广度优先搜索和深度优先搜索

这两种搜索算法都是基于图的，大部分搜索场景都可以抽象成图。

### 广度优先搜索BFS

- 地毯式的层层推进搜索策略，从最近的开发一层层的往外扩散。
- 适合用来求最短路径。

##### 二叉树的搜索代码模板如下

``` java
// Java
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> allResults = new ArrayList<>();
    if (root == null) {
        return allResults;
    }
    Queue<TreeNode> nodes = new LinkedList<>();
    nodes.add(root);
    while (!nodes.isEmpty()) {
        int size = nodes.size();
        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            TreeNode node = nodes.poll();
            results.add(node.val);
            if (node.left != null) {
                nodes.add(node.left);
            }
            if (node.right != null) {
                nodes.add(node.right);
            }
        }
        allResults.add(results);
    }
    return allResults;
}

```

- 时间复杂度：O(E)，E表示边的个数
- 空间复杂度：O(E)，E表示边的个数

## 深度优先搜索DFS

是回溯思想的体现。

``` java
//Java
public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> allResults = new ArrayList<>();
    if(root==null){
        return allResults;
    }
    travel(root,0,allResults);
    return allResults;
}


private void travel(TreeNode root,int level,List<List<Integer>> results){
    if(results.size()==level){
        results.add(new ArrayList<>());
    }
    results.get(level).add(root.val);
    if(root.left!=null){
        travel(root.left,level+1,results);
    }
    if(root.right!=null){
        travel(root.right,level+1,results);
    }
}

```

- 时间复杂度：O(E)，E表示边的个数
- 空间复杂度：O(V)，V表示顶点的个数

## 贪心算法

总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，算法得到的是在某种意义上的局部最优解

## 二分查找

条件：

- 数组存储
- 有序数据
- 数据量太小不适合（没必要）
- 数据量太大也不适合（依赖于数组数据结构）
- 时间复杂度：O(logn)

代码模板如下：

``` java
// Java
public int binarySearch(int[] array, int target) {
    int left = 0, right = array.length - 1, mid;
    while (left <= right) {
    	//直接使用 (right+left) / 2 有溢出风险
        mid = (right - left) / 2 + left;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}
```

#### 扩展

在搜索旋转排序数组题目中，部分数据旋转，可以用mid值和left或者right值进行比较判断哪一边是有序的。

