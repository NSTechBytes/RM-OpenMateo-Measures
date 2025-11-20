;=============================================================
;          7-Day Daily Weather Forecast from OpenMateo
;          Split into 3 parent measures to stay within 99 StringIndex limit
;=============================================================

;=============================================================
;          Parent Measure 1: Core Weather Data
;          Captures: weather_code, temps, precipitation, wind
;=============================================================
[Measure_Daily_Parent1]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&daily=weather_code,temperature_2m_max,temperature_2m_min,apparent_temperature_max,apparent_temperature_min,precipitation_sum,rain_sum,showers_sum,snowfall_sum,wind_speed_10m_max,wind_gusts_10m_max,wind_direction_10m_dominant&forecast_days=7&temperature_unit=#Temperature_Unit#&precipitation_unit=#Precipitation_Unit#&wind_speed_unit=#Wind_Speed_Unit#
Download=1
RegExp=(?si)"latitude":(-?[0-9]+\.?[0-9]*).*?"longitude":(-?[0-9]+\.?[0-9]*).*?"timezone":"([^"]*)".*?"timezone_abbreviation":"([^"]*)".*?"elevation":(-?[0-9]+\.?[0-9]*).*?"time":\["([^"]*)".*?"weather_code":\[([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+).*?"temperature_2m_max":\[(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+).*?"temperature_2m_min":\[(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+).*?"apparent_temperature_max":\[(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+).*?"apparent_temperature_min":\[(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+),(-?[0-9.]+).*?"precipitation_sum":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"rain_sum":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"showers_sum":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"snowfall_sum":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"wind_speed_10m_max":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"wind_gusts_10m_max":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*?"wind_direction_10m_dominant":\[([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+)
Debug=2
Debug2File=Debug\DailyWeatherDebug1.json

;=============================================================
;          Parent Measure 2: Sun & UV Data
;          Captures: sunrise, sunset, daylight, sunshine, UV
;=============================================================
[Measure_Daily_Parent2]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&daily=sunrise,sunset,daylight_duration,sunshine_duration,uv_index_max,uv_index_clear_sky_max,precipitation_hours,precipitation_probability_max&forecast_days=7&temperature_unit=#Temperature_Unit#&precipitation_unit=#Precipitation_Unit#&wind_speed_unit=#Wind_Speed_Unit#
Download=1
RegExp=(?siU)"sunrise":\["([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)".*"sunset":\["([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)","([^"]*)".*"daylight_duration":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"sunshine_duration":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"uv_index_max":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"uv_index_clear_sky_max":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"precipitation_hours":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"precipitation_probability_max":\[([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+),([0-9]+)
Debug=2
Debug2File=Debug\DailyWeatherDebug2.json

;=============================================================
;          Parent Measure 3: Radiation & Evapotranspiration
;          Captures: shortwave radiation, evapotranspiration
;=============================================================
[Measure_Daily_Parent3]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&daily=shortwave_radiation_sum,et0_fao_evapotranspiration&forecast_days=7&temperature_unit=#Temperature_Unit#&precipitation_unit=#Precipitation_Unit#&wind_speed_unit=#Wind_Speed_Unit#
Download=1
RegExp=(?siU)"shortwave_radiation_sum":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+).*"et0_fao_evapotranspiration":\[([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+),([0-9.]+)
Debug=2
Debug2File=Debug\DailyWeatherDebug3.json

;=============================================================
;          Location & Metadata Measures (from Parent 1)
;=============================================================
[Measure_Daily_Location_Latitude]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=1

[Measure_Daily_Location_Longitude]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=2

[Measure_Daily_Location_Timezone]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=3

[Measure_Daily_Location_Timezone_Abbr]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=4

[Measure_Daily_Location_Elevation]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=5

[Measure_Daily_Time_Day1]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=6

;=============================================================
;          Day 1 Measures
;=============================================================
; From Parent 1
[Measure_Day1_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=7

[Measure_Day1_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=14

[Measure_Day1_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=21

[Measure_Day1_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=28

[Measure_Day1_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=35

[Measure_Day1_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=42

[Measure_Day1_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=49

[Measure_Day1_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=56

[Measure_Day1_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=63

[Measure_Day1_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=70

[Measure_Day1_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=77

[Measure_Day1_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=84

; From Parent 2
[Measure_Day1_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=1

[Measure_Day1_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=8

[Measure_Day1_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=15

[Measure_Day1_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=22

[Measure_Day1_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=29

[Measure_Day1_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=36

[Measure_Day1_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=43

[Measure_Day1_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=50

; From Parent 3
[Measure_Day1_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=1

[Measure_Day1_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=8

;=============================================================
;          Day 2 Measures
;=============================================================
[Measure_Day2_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=8

[Measure_Day2_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=15

[Measure_Day2_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=22

[Measure_Day2_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=29

[Measure_Day2_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=36

[Measure_Day2_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=43

[Measure_Day2_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=50

[Measure_Day2_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=57

[Measure_Day2_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=64

[Measure_Day2_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=71

[Measure_Day2_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=78

[Measure_Day2_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=85

[Measure_Day2_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=2

[Measure_Day2_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=9

[Measure_Day2_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=16

[Measure_Day2_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=23

[Measure_Day2_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=30

[Measure_Day2_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=37

[Measure_Day2_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=44

[Measure_Day2_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=51

[Measure_Day2_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=2

[Measure_Day2_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=9

;=============================================================
;          Day 3 Measures
;=============================================================
[Measure_Day3_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=9

[Measure_Day3_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=16

[Measure_Day3_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=23

[Measure_Day3_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=30

[Measure_Day3_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=37

[Measure_Day3_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=44

[Measure_Day3_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=51

[Measure_Day3_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=58

[Measure_Day3_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=65

[Measure_Day3_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=72

[Measure_Day3_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=79

[Measure_Day3_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=86

[Measure_Day3_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=3

[Measure_Day3_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=10

[Measure_Day3_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=17

[Measure_Day3_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=24

[Measure_Day3_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=31

[Measure_Day3_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=38

[Measure_Day3_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=45

[Measure_Day3_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=52

[Measure_Day3_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=3

[Measure_Day3_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=10

;=============================================================
;          Day 4 Measures
;=============================================================
[Measure_Day4_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=10

[Measure_Day4_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=17

[Measure_Day4_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=24

[Measure_Day4_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=31

[Measure_Day4_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=38

[Measure_Day4_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=45

[Measure_Day4_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=52

[Measure_Day4_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=59

[Measure_Day4_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=66

[Measure_Day4_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=73

[Measure_Day4_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=80

[Measure_Day4_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=87

[Measure_Day4_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=4

[Measure_Day4_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=11

[Measure_Day4_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=18

[Measure_Day4_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=25

[Measure_Day4_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=32

[Measure_Day4_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=39

[Measure_Day4_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=46

[Measure_Day4_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=53

[Measure_Day4_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=4

[Measure_Day4_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=11

;=============================================================
;          Day 5 Measures
;=============================================================
[Measure_Day5_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=11

[Measure_Day5_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=18

[Measure_Day5_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=25

[Measure_Day5_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=32

[Measure_Day5_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=39

[Measure_Day5_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=46

[Measure_Day5_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=53

[Measure_Day5_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=60

[Measure_Day5_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=67

[Measure_Day5_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=74

[Measure_Day5_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=81

[Measure_Day5_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=88

[Measure_Day5_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=5

[Measure_Day5_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=12

[Measure_Day5_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=19

[Measure_Day5_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=26

[Measure_Day5_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=33

[Measure_Day5_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=40

[Measure_Day5_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=47

[Measure_Day5_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=54

[Measure_Day5_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=5

[Measure_Day5_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=12

;=============================================================
;          Day 6 Measures
;=============================================================
[Measure_Day6_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=12

[Measure_Day6_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=19

[Measure_Day6_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=26

[Measure_Day6_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=33

[Measure_Day6_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=40

[Measure_Day6_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=47

[Measure_Day6_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=54

[Measure_Day6_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=61

[Measure_Day6_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=68

[Measure_Day6_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=75

[Measure_Day6_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=82

[Measure_Day6_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=89

[Measure_Day6_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=6

[Measure_Day6_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=13

[Measure_Day6_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=20

[Measure_Day6_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=27

[Measure_Day6_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=34

[Measure_Day6_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=41

[Measure_Day6_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=48

[Measure_Day6_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=55

[Measure_Day6_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=6

[Measure_Day6_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=13

;=============================================================
;          Day 7 Measures
;=============================================================
[Measure_Day7_Weather_Code]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=13

[Measure_Day7_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=20

[Measure_Day7_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=27

[Measure_Day7_Apparent_Temperature_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=34

[Measure_Day7_Apparent_Temperature_Min]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=41

[Measure_Day7_Precipitation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=48

[Measure_Day7_Rain_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=55

[Measure_Day7_Showers_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=62

[Measure_Day7_Snowfall_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=69

[Measure_Day7_Wind_Speed_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=76

[Measure_Day7_Wind_Gusts_Max]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=83

[Measure_Day7_Wind_Direction_Dominant]
Measure=WebParser
URL=[Measure_Daily_Parent1]
StringIndex=90

[Measure_Day7_Sunrise]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=7

[Measure_Day7_Sunset]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=14

[Measure_Day7_Daylight_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=21

[Measure_Day7_Sunshine_Duration]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=28

[Measure_Day7_UV_Index_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=35

[Measure_Day7_UV_Index_Clear_Sky_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=42

[Measure_Day7_Precipitation_Hours]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=49

[Measure_Day7_Precipitation_Probability_Max]
Measure=WebParser
URL=[Measure_Daily_Parent2]
StringIndex=56

[Measure_Day7_Shortwave_Radiation_Sum]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=7

[Measure_Day7_ET0_FAO_Evapotranspiration]
Measure=WebParser
URL=[Measure_Daily_Parent3]
StringIndex=14
