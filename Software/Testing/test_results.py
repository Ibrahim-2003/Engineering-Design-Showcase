from operator import index
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

#  Prominent Arduino map function :)
def _map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

def percentage_error(experimental, theoretical):
    errors = []
    for i in range(len(experimental)):
        difference = np.abs(experimental[i] - theoretical[i])/theoretical[i] * 100
        errors.append(difference)
    return np.mean(errors)

z = ""

rocket_data = [2.45, 3.50, 3.20, 0.98, 2.34, 0.74, 0.23, 0]
raw_data = [2552, 5212, 5821, 5319, 5819, 644, 107, 45]
true_dist = [_map(i,0,6000,0,500) for i in raw_data]
perc_dev = [rocket_data[i]/true_dist[i]*100 for i in range(len(rocket_data))]
rocket_data1 = np.array([rocket_data]) + np.array([true_dist])
years = [i+2015 for i in range(8)]

true_dist = np.array([true_dist])
rocket_data = np.array([rocket_data])
nominal_dist = true_dist + rocket_data


error1 = percentage_error(nominal_dist, true_dist)

df = pd.DataFrame({'True Position': rocket_data1.flatten(),
                  'Expected Position': true_dist.flatten()}
                  ,index=years)

colors = ['#d62d20', 'k', 'y', 'pink','orange','cyan','darkgrey']
ax = df.plot(kind='bar', color=colors, legend=False, rot=0)

ax.legend()
plt.title("Hardware-Software Integration Accuracy Test")
plt.suptitle(f"Sample Dataset #1 ({error1:.2f}% Error)",fontweight="bold")
plt.xlabel("Year Data Point")
plt.ylabel("Motor Deviation (mm)")
plt.show()

# fig = plt.figure()
# plt.bar(years, rocket_data)
# fig.text(.6,.7,f"Mean Error: {np.mean(rocket_data):.2f}mm",color="r")
# plt.title("Nominal Motor Deviation Over 21,000 Uses")
# plt.suptitle("Accelerated Usage Test")
# plt.xlabel("Year Data Point")
# plt.ylabel("Motor Deviation (mm)")
# plt.show()

# fig = plt.figure()
# plt.bar(years, perc_dev)
# fig.text(.3,.5,f"Mean Error: {np.mean(perc_dev):.2f}%",color="r")
# plt.title("Percent Motor Deviation Over 21,000 Uses")
# plt.suptitle("Accelerated Usage Test")
# plt.xlabel("Year Data Point")
# plt.ylabel("Motor Deviation (%)")
# plt.show()



# fig = plt.figure()
# plt.plot(years, nominal_dist.T,'.-',label="True Distance")
# plt.plot(years, true_dist.T,'.-',label="Calculated Distance")
# fig.text(.3,.5,f"Mean Error: {np.mean(perc_dev):.2f}%",color="r")
# plt.title("Hardware-Software Integration Accuracy Test")
# plt.xlabel("Year Data Point")
# plt.ylabel("Motor Movement (mm)")
# plt.legend()
# plt.show()

X = [f'{i+2015}' for i in range(8)]
Ytrue = nominal_dist.T
Zexpec = true_dist.T
  
X_axis = np.arange(len(X))

Ytrue = nominal_dist.T
Zexpec = true_dist.T

# plt.figure()

# plt.title("Hardware-Software Integration Accuracy Test")
# error = percentage_error(nominal_dist, true_dist)
# plt.suptitle(f"Sample Dataset #1 ({error:.2f}% Error)",fontweight="bold")
# plt.legend()
# plt.show()

rocket_data2 = [467.1, 203.2, 169.6, 224.4, 112.2, 470.3, 500.2, 96.5]
raw_data2 = [5562, 2378, 2083, 2686, 1322, 5689, 5962, 1128]
true_dist2 = [_map(i,0,6000,0,500) for i in raw_data2]

print(true_dist)

true_dist2 = np.array([true_dist2])
rocket_data2 = np.array([rocket_data2])
nominal_dist2 = rocket_data2

error2 = percentage_error(rocket_data2, true_dist2)

Ytrue = nominal_dist2.T
Zexpec = true_dist2.T

df = pd.DataFrame({"True Values": [467.1, 203.2, 169.6, 224.4, 112.2, 470.3, 500.2, 96.5],
                    "Expected Values": [_map(i,0,6000,0,500) for i in raw_data2]},index=years)
ax = df.plot(kind='bar', color=colors, legend=False, rot=0)

ax.legend()

plt.title("Hardware-Software Integration Accuracy Test")
error = percentage_error(rocket_data2, true_dist2)
plt.suptitle(f"Sample Dataset #2 ({error:.2f}% Error)",fontweight="bold")
plt.legend()
plt.xlabel("Year Data Point")
plt.ylabel("Motor Deviation (mm)")
plt.show()

# Dataset #3
# 2015,1268 //17.8cm
# 2016,3146 //33.0cm
# 2017,1527 //19.7cm
# 2018,3228 //34.2cm
# 2019,5494 //53.2cm
# 2020,2049 //24.9cm
# 2021,4746 //47.0cm
# 2022,1327 //18.0cm

rocket_data3 = [107.8, 263.0, 128.7, 271.2, 457.0, 175.0, 397.3, 111.3]
raw_data3 = [1268, 3146, 1527, 3228, 5494, 2049, 4746, 1327]
true_dist3 = [_map(i,0,6000,0,500) for i in raw_data3]



true_dist3 = np.array([true_dist3])
rocket_data3 = np.array([rocket_data3])
nominal_dist3 = rocket_data3
error3 = percentage_error(rocket_data3, true_dist3)


true1 = nominal_dist.T
expec1 = true_dist.T


true2 = nominal_dist2.T
expec2 = true_dist2.T

true3 = nominal_dist3.T
expec3 = true_dist3.T

print("TRUE 1:")
print(true1.flatten())
print("EXPECT 1:")
print(expec1.flatten())

print("\nTRUE 2:")
print(true2.flatten())
print("EXPECT 2:")
print(expec2.flatten())

print("\nTRUE 3:")
print(true3.flatten())
print("EXPECT 3:")
print(expec3.flatten())

df = pd.DataFrame({"True Values": [107.8, 263.0, 128.7, 271.2, 457.0, 175.0, 397.3, 111.3],
                    "Expected Values": [_map(i,0,6000,0,500) for i in raw_data3]},index=years)
ax = df.plot(kind='bar', color=colors, legend=False, rot=0)

ax.legend()


plt.title("Hardware-Software Integration Accuracy Test")
plt.suptitle(f"Sample Dataset #3 ({error3:.2f}% Error)",fontweight="bold")
plt.legend()
plt.xlabel("Year Data Point")
plt.ylabel("Motor Deviation (mm)")
plt.show()