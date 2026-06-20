import matplotlib.pyplot as plt
import numpy as np

# Data Points
n_values = np.array([10, 100, 500, 1000, 5000, 10000, 50000, 100000])
linear_times = n_values * 0.0000003  # Approx. O(n)
binary_times = np.log2(n_values) * 0.0000003  # Approx. O(log n)

plt.figure(figsize=(10, 6))
plt.plot(n_values, linear_times, label="Linear Search (O(n))", marker='o')
plt.plot(n_values, binary_times, label="Binary Search (O(log n))", marker='s', linestyle="dashed")

plt.xlabel("Array Size (n)")
plt.ylabel("Time (sec)")
plt.title("Search Algorithms: Time Complexity")
plt.legend()
plt.grid()
plt.show()
