;=============================================================
;          Current Weather from OpenMateo
;=============================================================
[Measure_OpenMateo_Current_Weather_Parent]
Measure=WebParser
URL=https://api.open-meteo.com/v1/forecast?latitude=#Latitude#&longitude=#Longitude#&current=temperature_2m,relative_humidity_2m,apparent_temperature,is_day,precipitation,rain,showers,snowfall,weather_code,cloud_cover,pressure_msl,surface_pressure,wind_speed_10m,wind_direction_10m,wind_gusts_10m
Download=1
RegExp=(?siU)"latitude":\s*(-?\d+(?:\.\d+)?).*?"longitude":\s*(-?\d+(?:\.\d+)?).*?"timezone":\s*"([^"]*)".*?"timezone_abbreviation":\s*"([^"]*)".*?"elevation":\s*(-?\d+(?:\.\d+)?).*?"current":\s*\{.*?"time":\s*"([^"]*)".*?"interval":\s*(-?\d+).*?"temperature_2m":\s*(-?\d+(?:\.\d+)?).*?"relative_humidity_2m":\s*(-?\d+).*?"apparent_temperature":\s*(-?\d+(?:\.\d+)?).*?"is_day":\s*(-?\d+).*?"precipitation":\s*(-?\d+(?:\.\d+)?).*?"rain":\s*(-?\d+(?:\.\d+)?).*?"showers":\s*(-?\d+(?:\.\d+)?).*?"snowfall":\s*(-?\d+(?:\.\d+)?).*?"weather_code":\s*(-?\d+).*?"cloud_cover":\s*(-?\d+).*?"pressure_msl":\s*(-?\d+(?:\.\d+)?).*?"surface_pressure":\s*(-?\d+(?:\.\d+)?).*?"wind_speed_10m":\s*(-?\d+(?:\.\d+)?).*?"wind_direction_10m":\s*(-?\d+).*?"wind_gusts_10m":\s*(-?\d+(?:\.\d+)?)
Debug=2
Debug2File=Debug\CurrentWeatherDebug.json

;=============================================================
;          Location & Metadata Measures
;=============================================================
[Measure_Location_Latitude]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=1

[Measure_Location_Longitude]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=2

[Measure_Location_Timezone]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=3

[Measure_Location_Timezone_Abbr]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=4

[Measure_Location_Elevation]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=5

[Measure_Current_Time]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=6

[Measure_Current_Interval]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=7

;=============================================================
;          Current Weather Measures
;=============================================================

[Measure_Current_Temperature]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=8

[Measure_Current_Relative_Humidity]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=9

[Measure_Current_Apparent_Temperature]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=10

[Measure_Current_Is_Day]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=11

[Measure_Current_Precipitation]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=12

[Measure_Current_Rain]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=13

[Measure_Current_Showers]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=14

[Measure_Current_Snowfall]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=15

[Measure_Current_Weather_Code]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=16

[Measure_Current_Cloud_Cover]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=17

[Measure_Current_Pressure_MSL]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=18

[Measure_Current_Surface_Pressure]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=19

[Measure_Current_Wind_Speed]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=20

[Measure_Current_Wind_Direction]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=21

[Measure_Current_Wind_Gusts]
Measure=WebParser
URL=[Measure_OpenMateo_Current_Weather_Parent]
StringIndex=22