#include "battery_monitor.h"

uint8_t battery_level_from_voltage(uint16_t voltage_counts)
{
    if (voltage_counts <= BATTERY_VOLTAGE_MIN_COUNTS) {
        return BATTERY_LEVEL_MIN_PERCENT;
    }

    if (voltage_counts >= BATTERY_VOLTAGE_MAX_COUNTS) {
        return BATTERY_LEVEL_MAX_PERCENT;
    }

    return (uint8_t)((voltage_counts * BATTERY_LEVEL_MAX_PERCENT) /
                     BATTERY_VOLTAGE_MAX_COUNTS);
}

bool battery_is_low(uint8_t level_percent)
{
    return level_percent < LOW_BATTERY_THRESHOLD_PERCENT;
}
