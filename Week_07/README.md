# 学习笔记

## 总结

时间过得好快啊，开始下半学期的学习了，上学期的东西感觉还有好多没有掌握，还要加油啊，还好这周的题目好几个都是以前做过的，比较熟悉，拍拍我的小心脏，缓缓气。加油！！！

## Trie 树

别名：字典树，单词查找树或键树
### 基本结构
- 它是一个树形结构。
- 它是一种专门处理字符串匹配的数据结构，用来解决在一组字符串集合中快速查找某个字符串的问题。
- 典型应用是用于统计和排序大量的字符串（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计
- 优点，最大限度地减少无谓的字符串比较，查询效率比哈希表高。

### 基本性质
- 节点不存完整单词
    - 字符（也可以通过数组位置对应得到）
    - 下一个字符对应的节点列表
    - 是否是最后一个字符（到此是否可以组成单词）
- 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串； 
- 每个结点的所有子结点路径代表的字符都不相同。

### 核心思想
- Trie 树的核心思想是空间换时间。
- 利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

### 时间复杂度：
- 插入：O(n)，n是所有插入字符串的长度和
- 查找：O(k)，k是查找单词的字符长度

### 代码

``` swift

class TrieTreeNode {
    public var next = [Character: TrieTreeNode]()
    public var end: Bool
    
    public init() {
        self.end = false
    }
}

class Trie {

    var root: TrieTreeNode

    /** Initialize your data structure here. */
    init() {
        root = TrieTreeNode()
    }
    
    /** Inserts a word into the trie. */
    func insert(_ word: String) {
        var node = root
        for c in word {
            if node.next[c] == nil {
                node.next[c] = TrieTreeNode()
            }
            node = node.next[c]!
        }
        node.end = true
    }
    
    /** Returns if the word is in the trie. */
    func search(_ word: String) -> Bool {
        return findWord(word)?.end ?? false
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    func startsWith(_ prefix: String) -> Bool {
        return findWord(prefix) != nil
    }
    
    func findWord(_ word: String) -> TrieTreeNode? {
        var node = root
        for c in word {
            if let next = node.next[c] {
                node = next
            } else {
                return nil
            }
        }
        return node
    }
}

```

## 高级搜索

- 朴素搜索
- 优化方式：
    - 不重复，利用缓存
    - 剪枝，剪掉不必要的分支
- 搜索方向
    - 广度优先搜索 DFS
    - 深度优先搜索 BFS
- 双向搜索
    - 首尾同时扩散
    - 避免减少搜索访问数量
- 启发式搜索 Heuristic Search (A*)
    - 估价函数 
    - 优先级搜索

启发式函数：h(n)，它用来评价哪些结点最有希望的是一个我们要找的结点，h(n) 会返回一个非负实数,也可以认为是从结点n的目标结点路径的估计成本。
启发式函数是一种告知搜索方向的方法。它提供了一种明智的方法来猜测哪个邻居结点会导向一个目标。

## 二叉树

### 二叉树的遍历
- 前序遍历Pre-order：根左右
- 中序遍历In-order：左根右
- 后序遍历Post-order：左右根

### 二叉搜索树(Binary Search Tree)
别名：有序二叉树，排序二叉树（Sorted Binary Tree），有序二叉树
- 左子树所有结点的值均小于根节点的值，右子树所有结点的值均大于根结点的值
- 依次类推，左右子树也为二叉搜索树（这就是重复性）
- 中序遍历是升序排列的
- 空树也是二叉搜索树

#### 问题
当二叉树的结构趋于一个链表的时候，查找时间复杂的退化为O(n)，保证性能的关键是保证二维维度。

## 平衡二叉搜索树

#### AVL树

- 左右两个子树的高度差的绝对值不超过1
- 左右两个子树都是一棵平衡二叉树

#### 平衡因子
- 结点的左子树与右子树的高度(深度)差即为该结点的平衡因子（BF,Balance Factor）。
- 平衡二叉树上所有结点的平衡因子只可能是 -1，0 或 1

#### 添加节点
- 添加节点会破坏平衡
- 通过旋转操作进行平衡（左旋，右旋，左右旋，右左旋）

#### 红黑树

### 红黑树

红黑树是一种近似平衡的二叉搜索树（Binary Search Tree），它能够确保任何一
个结点的左右子树的高度差小于两倍。

- 每个结点要么是红色，要么是黑色
- 根节点是黑色的；
- 每个叶子节点都是黑色的空节点（NIL），也就是说，叶子节点不存储数据；
- 任何相邻的节点都不能同时为红色，也就是说，红色节点是被黑色节点隔开的；
- 每个节点，从该节点到达其可达叶子节点的所有路径，都包含相同数目的黑色节点；

### 红黑树

红黑树是一种近似平衡的二叉搜索树（Binary Search Tree），它能够确保任何一
个结点的左右子树的高度差小于两倍。

- 每个结点要么是红色，要么是黑色
- 根节点是黑色的；
- 每个叶子节点都是黑色的空节点（NIL），也就是说，叶子节点不存储数据；
- 任何相邻的节点都不能同时为红色，也就是说，红色节点是被黑色节点隔开的；
- 每个节点，从该节点到达其可达叶子节点的所有路径，都包含相同数目的黑色节点；

### AVL树和红黑树的区别
- AVL树是严格平衡，红黑树是近似平衡
- 红黑树的查询性能略微逊色于AVL树；
- 红黑树在插入和删除上优于AVL树，AVL树每次插入删除会进行大量的平衡度计算；
- 实际应用中，若搜索的次数远远大于插入和删除，那么选择AVL，如果搜索，插入删除次数几乎差不多，应该选择红黑树。