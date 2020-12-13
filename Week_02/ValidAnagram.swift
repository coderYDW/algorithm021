//
//  ValidAnagram.swift
//  LeetCodeDemo
//
//  Created by Yangdongwu on 2020/12/12.
//

import Foundation

class ValidAnagram {
    /// 有效异位词
    func isAnagram(_ s: String, _ t: String) -> Bool {
        guard s.count == t.count else {
            return false
        }
        if s.sorted() == t.sorted() {
            return true
        } else {
            return false
        }
    }
    
    // 数组方式
    func isAnagram01(_ s: String, _ t: String) -> Bool {
        guard s.count == t.count else {
            return false
        }
        var arr = [Int](repeating: 0, count: 26)
        for c in s {
            let i = numFromCharacter(c) - numFromCharacter("a")
            arr[i] += 1
        }
        for c in t {
            let i = numFromCharacter(c) - numFromCharacter("a")
            arr[i] -= 1
            if arr[i] < 0 {
                return false
            }
        }
        return true
    }
    
    func numFromCharacter(_ char: Character) -> Int {
        let str = String(char)
        var number: Int = 0
        for code in str.unicodeScalars {
            number = Int(code.value)
        }
        return number
    }
    
    //字典方式
    func isAnagram02(_ s: String, _ t: String) -> Bool {
        guard s.count == t.count else {
            return false
        }
        var hashMap = [Character: Int]()
        for c in s {
            if hashMap[c] == nil {
                hashMap[c] = 0
            }
            hashMap[c]! += 1
        }
        for c in t {
            if hashMap[c] == nil {
                return false
            }
            hashMap[c]! -= 1
            if hashMap[c]! < 0 {
                return false
            }
        }
        return true
    }
}
