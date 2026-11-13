#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <stdbool.h>
#include <stdint.h>

#define BATTERY_VOLTAGE_MIN_COUNTS ((uint16_t)0U)
#define BATTERY_VOLTAGE_MAX_COUNTS ((uint16_t)200U)
#define BATTERY_LEVEL_MIN_PERCENT ((uint8_t)0U)
#define BATTERY_LEVEL_MAX_PERCENT ((uint8_t)100U)
#define LOW_BATTERY_THRESHOLD_PERCENT ((uint8_t)20U)

uint8_t battery_level_from_voltage(uint16_t voltage_counts);
bool battery_is_low(uint8_t level_percent);

#endif
