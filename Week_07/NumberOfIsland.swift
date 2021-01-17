//
//  NumberOfIsland.swift
//  LeetCodeDemo
//
//  Created by Apple on 2020/12/25.
//

import Foundation

class NumberOfIsland {
    
    func numIslands(_ grid: [[Character]]) -> Int {
        guard grid.count > 0, grid[0].count > 0 else {
            return 0
        }
        var temp = grid, res = 0
        for i in 0..<temp.count {
            for j in 0..<temp[0].count {
                if temp[i][j] == "1" {
                    res += 1
                }
                dfs(i, j, grid.count, grid[0].count, &temp)
            }
        }
        return res
    }
    
    func dfs(_ row: Int, _ col: Int, _ m: Int, _ n: Int, _ temp: inout [[Character]]) {
        guard row >= 0, row < m, col >= 0, col < n, temp[row][col] == "1" else {
            return
        }
        temp[row][col] = "0"
        dfs(row - 1, col, m, n, &temp)
        dfs(row + 1, col, m, n, &temp)
        dfs(row, col - 1, m, n, &temp)
        dfs(row, col + 1, m, n, &temp)
    }
    
}
