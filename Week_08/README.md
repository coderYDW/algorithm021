# 学习笔记

## 总结

这周学习了位运算，布隆过滤器，LRU Cache，排序算法，感觉这周内容还是挺多的，排序的很多代码都没有完成，需要慢慢完善下。这周题目做的不多，还需要加油。

## 位运算

#### 基本的位运算

- 左移 >>  0011=>0110
- 右移 <<  0110=>0011

- 按位或 | 有一得一
- 按位与 & 有零得零
- 按位取反 ~ 一变零，零变一
- 按位异或 ^ 不同得一，相同得零

#### 异或常用操作

* x ^ 0 = x
* x ^ 1s = ~x  // 1s = ~0
* x ^ (~x) = 1s
* x ^ x = 0
* c = a ^ b => a ^ c = b , b ^ c = a // 交换两个数
* a ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c // associative

#### 指定位置的位运算

1. 将x最右边的n位清零：x & (~0 << n)
2. 获取x的第你位值（0或1）：(x >> n) & 1
3. 获取x的第n位幂值： x & (1 << n)
4. 仅将第n位置为1： x | (1 << n)
5. 仅将第n位置为0： x & (~(1 << n))
6. 将x的最高位到第n位清零： x & ((1 << n) - 1)

#### 实战运算要点

* 判断奇偶
    * x % 2 == 1  =>  x & 1 == 1
    * x % 2 == 0  =>  x & 1 == 0
* x >> 1 => x / 2
* x = x & (x - 1) //清零最低位的1
* x & (-x) //得到最低位的1
* x & ~x => 0

## 布隆过滤器 Bloom Filter

#### 介绍

* 作用：检索一个元素是否在一个集合中。
* 优点：空间效率和查询时间都远远超出一般算法。
* 缺点：有一定的误识别率和删除困难。

#### 案例

1. 比特币网络
2. 分布式系统
3. Redis缓存
4. 垃圾邮件、评论过滤

## LRU Cache

least recently used 最近最少使用

## 排序

#### 比较类排序
	
- 交换排序
	- 冒泡排序
	- 快速排序
- 插入排序
	- 简单插入排序
	- 希尔排序
- 选择排序
  	- 简单选择排序
	- 堆排序
- 归并排序
	- 二路归并排序
	- 多路归并排序

#### 非比较类排序

- 计数排序
- 桶排序
- 基数排序

#### 简单排序的代码

```
/*
 插入排序：
 1. 从第一个元素开始，该元素可以认为已经被排序
 2. 取出下一个元素，在已经排序的元素序列中从后向前扫描
 3. 如果该元素（已排序）大于新元素，将该元素移到下一位置
 4. 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
 5. 将新元素插入到该位置中
 6. 重复步骤2
 */
func insertSort(_ arr: inout [Int]) {
    for i in 1..<arr.count {
        let key = arr[i]
        var j = i - 1
        while j >= 0 && arr[j] > key {
            arr[j + 1] = arr[j]
            j -= 1
        }
        arr[j + 1] = key
    }
}
    
/*
 选择排序：
 1. 遍历数组，找到最小的元素，将其置于数组起始位置。
 2. 从上次最小元素存放的后一个元素开始遍历至数组尾，将最小的元素置于开始处。
 3. 重复上述过程，直到元素排序完毕。
 */
func selectionSort(_ arr: inout [Int]) {
    for i in 0..<arr.count {
        var min = i
        for j in i + 1..<arr.count {
            if arr[j] < arr[min] {
                min = j
            }
        }
        arr.swapAt(i, min)
    }
}
    
/*
 冒泡排序：
 1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个，直到把最大的元素放到数组尾部。
 2. 遍历长度减一，对剩下的元素从头重复以上的步骤。
 3. 直到没有任何一对数字需要比较时完成。
 */
func bubbleSort(_ arr: inout [Int]) {
    for i in 0 ..< arr.count {
        for j in 0 ..< arr.count - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swapAt(j, j + 1)
            }
        }
    }
}
```