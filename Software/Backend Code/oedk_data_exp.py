import pandas as pd
import matplotlib.pyplot as plt
 
# Give the location of the file
loc = ("E:/Rice/Rice S22/Intro to Engineering Design and Communication/Software/Backend Code/TeamTa-daData_VISITOR_DEMOGRAPHICS.xlsx")
 
# To open Workbook
wb = pd.read_excel(loc)
sheet = wb
loc = ("E:/Rice/Rice S22/Intro to Engineering Design and Communication/Software/Backend Code/cleaned_demographics.xlsx")
cleanwb = pd.read_excel(loc)

def isfloat(num):
    try:
        float(num)
        return True
    except ValueError:
        return False
 
# For row 0 and column 0
my_index = []
for i in range(0,len(sheet["Check below if your objective is to gain  ideas for building a similar facility or running a similar design program."])):
    if isfloat(sheet["Check below if your objective is to gain  ideas for building a similar facility or running a similar design program."][i]) == False:
        my_index.append(i)

for i in my_index:
    cleanwb["similar_facility"][i] = 1

visitors = sheet["Estimated Attendance"]
date_created = sheet["Date Created"]

data = {"Date": date_created,
        "Visitors": visitors}

df = pd.DataFrame(data)

print(df)

monthly_2015 = []
monthly_2016 = []
monthly_2017 = []
monthly_2018 = []
monthly_2019 = []
monthly_2020 = []
monthly_2021 = []
monthly_2022 = []
months1 = []
months2 = []
months3 = []
months4 = []
months5 = []
months6 = []
months7 = []
months8 = []

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2022:
        monthly_2022.append(df["Visitors"][i])
        months1.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2021:
        monthly_2021.append(df["Visitors"][i])
        months2.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2020:
        monthly_2020.append(df["Visitors"][i])
        months3.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2019:
        monthly_2019.append(df["Visitors"][i])
        months4.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2018:
        monthly_2018.append(df["Visitors"][i])
        months5.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2017:
        monthly_2017.append(df["Visitors"][i])
        months6.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2016:
        monthly_2016.append(df["Visitors"][i])
        months7.append(df["Date"][i].month)

for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2015:
        monthly_2015.append(df["Visitors"][i])
        months8.append(df["Date"][i].month)

fig, axes = plt.subplots(4, 2)
axes[0,0].bar(months8,monthly_2015)
axes[0,0].set_title("OEDK Visitors 2015")
axes[0,0].set_xlabel("Month")
axes[0,0].set_ylabel("Number of Visitors")

axes[0,1].bar(months7,monthly_2016)
axes[0,1].set_title("OEDK Visitors 2016")
axes[0,1].set_xlabel("Month")
axes[0,1].set_ylabel("Number of Visitors")

axes[1,0].bar(months6,monthly_2017)
axes[1,0].set_title("OEDK Visitors 2017")
axes[1,0].set_xlabel("Month")
axes[1,0].set_ylabel("Number of Visitors")

axes[1,1].bar(months5,monthly_2018)
axes[1,1].set_title("OEDK Visitors 2018")
axes[1,1].set_xlabel("Month")
axes[1,1].set_ylabel("Number of Visitors")

axes[2,0].bar(months4,monthly_2019)
axes[2,0].set_title("OEDK Visitors 2019")
axes[2,0].set_xlabel("Month")
axes[2,0].set_ylabel("Number of Visitors")

axes[2,1].bar(months3,monthly_2020)
axes[2,1].set_title("OEDK Visitors 2020")
axes[2,1].set_xlabel("Month")
axes[2,1].set_ylabel("Number of Visitors")

axes[3,0].bar(months2,monthly_2021)
axes[3,0].set_title("OEDK Visitors 2021")
axes[3,0].set_xlabel("Month")
axes[3,0].set_ylabel("Number of Visitors")

plt.tight_layout()
plt.show()

years = [2015, 2016, 2017, 2018, 2019,
        2020, 2021]
yearly_2015 = 0
yearly_2016 = 0
yearly_2017 = 0
yearly_2018 = 0
yearly_2019 = 0
yearly_2020 = 0
yearly_2021 = 0
for i in range(0,len(df["Date"])):
    if df["Date"][i].year == 2015:
        yearly_2015 += df["Visitors"][i]
    elif df["Date"][i].year == 2016:
        yearly_2016 += df["Visitors"][i]
    elif df["Date"][i].year == 2017:
        yearly_2017 += df["Visitors"][i]
    elif df["Date"][i].year == 2018:
        yearly_2018 += df["Visitors"][i]
    elif df["Date"][i].year == 2019:
        yearly_2019 += df["Visitors"][i]
    elif df["Date"][i].year == 2020:
        yearly_2020 += df["Visitors"][i]
    elif df["Date"][i].year == 2021:
        yearly_2021 += df["Visitors"][i]

yearly = [yearly_2015 , yearly_2016, yearly_2017, yearly_2018, yearly_2019, yearly_2020, yearly_2021]
print(yearly_2019.sum())

plt.bar(years, yearly)
plt.title("OEDK Visitors per Year")
plt.xlabel("Year")
plt.ylabel("Number of Visitors")
plt.show()

plt.plot_date(df["Date"], df["Visitors"])
plt.title("OEDK Visitors per Day")
plt.xlabel("Date")
plt.ylabel("Number of Visitors")
plt.show()