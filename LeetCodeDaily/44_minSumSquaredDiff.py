# 2333. Minimum Sum of Squared Difference
import heapq

# LC 2333: Minimum Sum of Squared Difference


# APPROACH 1: BRUTE FORCE (MAX HEAP)
def solve_brute(nums1, nums2, k1, k2):
    K = k1 + k2

    # Python min heap -> simulate max heap using negative values
    pq = [-abs(a - b) for a, b in zip(nums1, nums2)]
    heapq.heapify(pq)

    while K > 0 and pq:
        largest_diff = -heapq.heappop(pq)

        if largest_diff == 0:
            break

        largest_diff -= 1
        K -= 1

        heapq.heappush(pq, -largest_diff)

    result = 0

    while pq:
        d = -heapq.heappop(pq)
        result += d * d

    return result


# APPROACH 2: OPTIMAL (FREQUENCY COUNTING)
def solve_optimal(nums1, nums2, k1, k2):
    K = k1 + k2

    MAX_DIFF = 100000
    diff = [0] * (MAX_DIFF + 1)

    # Count the frequency of each absolute difference
    for a, b in zip(nums1, nums2):
        d = abs(a - b)
        diff[d] += 1

    # Reduce differences from largest to smallest
    for i in range(MAX_DIFF, 0, -1):
        if K == 0:
            break

        count_op = min(K, diff[i])

        diff[i] -= count_op
        diff[i - 1] += count_op

        K -= count_op

    # Calculate sum of squared differences
    result = 0

    for d in range(1, MAX_DIFF + 1):
        result += diff[d] * d * d

    return result


# MAIN: INPUT / OUTPUT
if __name__ == "__main__":
    n1 = int(input())
    nums1 = list(map(int, input().split()))

    n2 = int(input())
    nums2 = list(map(int, input().split()))

    k1 = int(input())
    k2 = int(input())

    # Choose the approach:
    print(solve_optimal(nums1, nums2, k1, k2))

    # For brute force, use:
    # print(solve_brute(nums1, nums2, k1, k2))
