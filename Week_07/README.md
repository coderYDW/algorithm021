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

