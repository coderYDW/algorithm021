# 学习笔记

## 总结

第三周的学习有些不太好，递归逻辑老是梳理不对，搞不懂分治和回溯咋回事，好难！！！

刷题代码好难懂啊！！！

## 递归
#### 一、什么是递归？
1. 递归是一种非常高效、简洁的编码技巧，一种应用非常广泛的算法，比如DFS深度优先搜索、前中后序二叉树遍历等都是使用递归。
2. 方法或函数调用自身的方式称为递归调用，调用称为递，返回称为归。
3. 基本上，所有的递归问题都可以用递推公式来表示，比如
f(n) = f(n-1) + 1; 
f(n) = f(n-1) + f(n-2);
f(n)=n*f(n-1);

#### 二、为什么使用递归？递归的优缺点？
1. 优点：代码的表达力很强，写起来简洁。
2. 缺点：空间复杂度高、有堆栈溢出风险、存在重复计算、过多的函数调用会耗时较多等问题。


#### 三、什么样的问题可以用递归解决呢？
1. 问题的解可以分解为几个子问题的解。何为子问题？就是数据规模更小的问题。
2. 问题与子问题，除了数据规模不同，求解思路完全一样
3. 存在递归终止条件


#### 四、如何实现递归？

##### 递归的代码模板
1. 递归终止条件 recursion terminator
2. 处理当前层 process logic in current level
3. 下探到下一层 drill down
4. 清理当前层 reverse the current level status if needed


##### 递归思维要点

1. 抵制人肉递归
2. 找最近重复性
3. 数学归纳法思维


#### 五、递归常见问题及解决方案
1. 警惕堆栈溢出：可以声明一个全局变量来控制递归的深度，从而避免堆栈溢出。
2. 警惕重复计算：通过某种数据结构来保存已经求解过的值，从而避免重复计算。


#### 六、如何将递归改写为非递归代码？
笼统的讲，所有的递归代码都可以改写为迭代循环的非递归写法。如何做？抽象出递推公式、初始值和边界条件，然后用迭代循环实现。

## 分治（分而治之）

##### 分治的代码模板
1. 递归终止条件 recursion terminator
2. 准备数据拆分问题 prepare data
3. 递归处理子问题 conquer subproblems
4. 合并子结果	process and generate the final result
5. 清理当前层 reverse the current level status

分治是一种处理问题的思想，多适合用递归来实现。

* 分解：将原问题分解成一系列子问题；
* 解决：递归地求解各个子问题，若子问题足够小，则直接求解；
* 合并：将子问题的结果合并成原问题。

分治算法能解决的问题，一般需要满足下面这几个条件：

* 原问题与分解成的小问题具有相同的模式；
* 原问题分解成的子问题可以独立求解，子问题之间没有相关性；
* 具有分解终止条件，也就是说，当问题足够小时，可以直接求解；
* 可以将子问题合并成原问题，而这个合并操作的复杂度不能太高，否则就起不到减小算法总体复杂度的效果了。

## 回溯

回溯算法的思想非常简单，大部分情况下，都是用来解决广义的搜索问题，也就是，从一组可能的解中，选择出一个满足要求的解。回溯算法非常适合用递归来实现，在实现的过程中，剪枝操作是提高回溯效率的一种技巧。利用剪枝，我们并不需要穷举搜索所有的情况，从而提高搜索效率。