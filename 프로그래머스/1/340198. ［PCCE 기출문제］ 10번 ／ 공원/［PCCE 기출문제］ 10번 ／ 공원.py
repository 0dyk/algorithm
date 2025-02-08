def solution(mats, park):
    n = len(park)
    m = len(park[0])
    dp = [[0] * m for _ in range(n)]
    max_square_size = 0
    
    # Calculate max square size at each position
    for i in range(n):
        for j in range(m):
            if park[i][j] == '-1':
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                max_square_size = max(max_square_size, dp[i][j])
    
    # Determine the largest mat size that can be placed
    max_mat_size = -1
    for mat in mats:
        if mat <= max_square_size:
            max_mat_size = max(max_mat_size, mat)
    
    return max_mat_size