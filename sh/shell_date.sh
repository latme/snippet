#!/bin/bash


# 19901231
echo $(date "+%Y%m%d")

# 19901231_235859
echo $(date "+%Y%m%d_%H%M%S")


# 1990/12/31 23:58:59
echo $(date "+%Y/%m/%d %H:%M:%S")

# 1990#07.1
echo $(date "+%Y#%U.%w")


#  %Y   year
#  %m   month (01..12)
#  %d   day of month (e.g., 01)
#  %H   hour (00..23)
#  %M   minute (00..59)
#  %S   second (00..60)
## %N   nanoseconds (000000000..999999999)

#  %w   day of week (0..6); 0 is Sunday
#  %U   week number of year, with Sunday as first day of week (00..53)
## %u   day of week (1..7); 1 is Monday
## %W   week number of year, with Monday as first day of week (00..53)

#  %b   locale's abbreviated month name (e.g., Jan)
#  %a   locale's abbreviated weekday name (e.g., Sun)
## %B   locale's full month name (e.g., January)
## %A   locale's full weekday name (e.g., Sunday)

## %j   day of year (001..366)
## %q   quarter of year (1..4)
## %T   time; same as %H:%M:%S
## %s   seconds since 1970-01-01 00:00:00 UTC

