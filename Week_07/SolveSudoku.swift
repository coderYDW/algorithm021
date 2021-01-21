//
//  SolveSudoku.swift
//  LeetCodeDemo
//
//  Created by Yangdongwu on 2021/1/20.
//

import Foundation

class SolveSudoku {
    
    //第一种方式
    func solveSudoku10(_ board: inout [[Character]]) {
        guard board.count > 0, board[0].count > 0 else {
            return
        }
        solve(&board)
    }
    
    @discardableResult
    func solve(_ board: inout [[Character]]) -> Bool {
        for i in 0..<9 {
            for j in 0..<9 {
                if board[i][j] == "." {
                    for c in "123456789" {
                        if isValid(board, i, j, c) {
                            board[i][j] = c
                            if solve(&board) {
                                return true
                            } else {
                                board[i][j] = "."
                            }
                        }
                    }
                    return false
                }
            }
        }
        return true
    }
    
    func isValid(_ board: [[Character]], _ i: Int, _ j: Int, _ c: Character) -> Bool {
        for k in 0..<9 {
            if board[i][k] == c {
                return false
            }
            if board[k][j] == c {
                return false
            }
            if board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c {
                return false
            }
        }
        return true
    }
    
    func test() {
        var a: [[Character]] = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
        solveSudoku10(&a)
        print(a)
    }

}


