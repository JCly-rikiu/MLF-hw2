import sys
import numpy as np
import matplotlib.pyplot as plt

# setup title and lables
case = int(sys.argv[1])
if case == 7:
    plt.title('Histogram of Problem 7')
    plt.xlabel('Ein - Eout')
elif case == 8:
    plt.title('Histogram of Problem 8')
    plt.xlabel('Ein - Eout')
else:
    pass
plt.ylabel('Count')

# retrieve data by stdin
data = np.fromstring(input(), dtype=float, sep=' ')
plt.hist(data, bins=50, rwidth=0.8)

# plot average line
plt.axvline(data.mean(), color='k', linestyle='dashed', linewidth=1)
min_ylim, max_ylim = plt.ylim()
plt.text(data.mean() * 1.1, max_ylim * 0.9, 'Mean: {:.2f}'.format(data.mean()))

# save as png
plt.savefig('histogram.png')
