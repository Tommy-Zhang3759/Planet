import matplotlib.pyplot as plt
import numpy as np

arr = np.loadtxt("field.out", delimiter=",")
print(arr)


fig, ax = plt.subplots()

X, Y, Z = arr[ : , 0], arr[ : , 1], arr[ : , 2]

Z = Z.reshape(1024, 1024)

x = np.arange(0, 1024, 1)  # len = 11
y = np.arange(0, 1024, 1)  # len = 7

ax.pcolormesh(x, y, Z)
ax.colorbar()
# ax.plot(y, x, marker = 'o')
# ax.set_xlabel("Times")
# ax.set_ylabel("number of coin")
# plt.savefig("figure.png", dpi = 600)
# plt.colorbar()
plt.show()
