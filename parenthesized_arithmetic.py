def eval_expr(expr):
    return eval("".join(expr))

def solve(expr):
    expr = expr.split()

    n = len(expr)

    dp = [[0 for i in range(n)] for j in range(n)]

    for i in range(n):
        if expr[i].isnumeric():
            dp[i][i] = int(expr[i])
    
    for d in range(2, n, 2):
        for i in range(0, n - d, 2):
            j = i + d

            dp[i][j] = eval_expr(expr[i:j + 1])

            for k in range(i, j + 1):
                if not expr[k].isnumeric():
                    temp_expr = str(dp[i][k - 1]) + expr[k] + str(dp[k + 1][j])
                    dp[i][j] = max(dp[i][j], eval(temp_expr))

    return dp[0][-1]

def main():
    expr = "2 + 4 + 13 - 3 - 9 + 11 + 2"
    print(solve(expr))

if __name__ == "__main__":
    main()