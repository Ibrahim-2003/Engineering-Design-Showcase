from random import randrange
import pyperclip

res = ""

for i in range(8):
    num = randrange(1000,6000)
    year = i+2015
    res += f"{year},{num}\n"

print(res)
pyperclip.copy(res)

# Dataset #2
# 2015,5562 //53.7cm
# 2016,2378 //27.5cm
# 2017,2083 //24.4cm
# 2018,2686 //29.2cm
# 2019,1322 //18.4cm
# 2020,5689 //54.4cm
# 2021,5962 //54.7cm
# 2022,1128 //17.0cm

# Dataset #3
# 2015,1268 //17.8cm
# 2016,3146 //33.0cm
# 2017,1527 //19.7cm
# 2018,3228 //34.2cm
# 2019,5494 //53.2cm
# 2020,2049 //24.9cm
# 2021,4746 //47.0cm
# 2022,1327 //18.0cm

res = ""
for i in range(100):
    res += f"\tleds[{i}] = CRGB::White;\n"

pyperclip.copy(res)