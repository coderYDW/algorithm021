//
//  ReverseWordInStringIII.swift
//  LeetCodeDemo
//
//  Created by Yangdongwu on 2021/1/30.
//

import Foundation

/*
 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

  

 示例：

 输入："Let's take LeetCode contest"
 输出："s'teL ekat edoCteeL tsetnoc"

  

 提示：

     在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


class ReverseWordInStringIII {
    
    func reverseWords(_ s: String) -> String {
        var s = Array(s)
        let n = s.count
        var i = 0
        while i < n {
            var start = i
            while i < n && s[i] != " " {
                i += 1
            }
            var end = i - 1
            while start < end {
                s.swapAt(start, end)
                start += 1
                end -= 1
            }
            while i < n && s[i] == " " {
                i += 1
            }
        }
        return String(s)
    }
    
    func reverseWords10(_ s: String) -> String {
        return String(s.split(separator: " ").map( { $0.reversed() }).joined(separator: " "))
    }
}
