import time
import random
# matrixA = [
#     [1, 2, 3, 4],
#     [4, 5, 6, 1],
#     [7, 8, 9, 5],
# ]

# matrixB = [
#     [9, 8, 7],
#     [6, 5, 4],
#     [3, 2, 1],
#     [0, 1, 2],
# ]

matrixA = [
    [random.randint(1, 10) for _ in range(12)] for _ in range(6)
]

matrixB = [
    [random.randint(1, 10) for _ in range(16)] for _ in range(12)
]

print("Matrix A:")
for row in matrixA:
    print(row)
    
print("Matrix B:")
for row in matrixB:
    print(row)
print(" ")

def matmul1(mat1, mat2):
    r = len(mat1)
    m = len(mat1[0])
    c = len(mat2[0])
    
    # Initialize the result matrix with zeros
    result = [[0 for _ in range(c)] for _ in range(r)]
    
    for i in range(r):
        for j in range(c):
            for k in range(m):
                result[i][j] += mat1[i][k] *mat2[k][j]
                
    return result

def matmul2(mat1, mat2):
    r = len(mat1)
    m = len(mat1[0])
    c = len(mat2[0])
    
    # Initialize the result matrix with zeros
    result = [[0 for _ in range(c)] for _ in range(r)]
    
    for k in range(m):
        for i in range(r):
            for j in range(c):
                result[i][j] += mat1[i][k] *mat2[k][j]
                
    return result

start_time = time.time()
result = matmul1(matrixA, matrixB)
end_time = time.time()
print("Time taken for matmul1: ", end_time - start_time)
print("Result of matrix multiplication:")
for row in result:
    print(row)
print(' ')

start_time = time.time()
result = matmul2(matrixA, matrixB)
end_time = time.time()
print("Time taken for matmul2: ", end_time - start_time)
print("Result of matrix multiplication:")
for row in result:
    print(row)
    