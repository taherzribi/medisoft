import matplotlib.pyplot as plt
import matplotlib as mpl

mpl.style.use('fivethirtyeight')

avg_heart = [80, 88, 85, 88, 90, 80, 88, 95, 100]
avg_h = [50, 44, 5, 8, 9, 8, 8, 5, 10]

days = [i+1 for i in range(len(avg_heart))]
print(days)

plt.plot(days, avg_heart, color='blue', linestyle='dashed')
#plt.plot(days, avg_h, color='red', linestyle='dashed')
plt.legend(['Heart beat over time'])
plt.grid(b=True)
plt.show()
