# Architecture and application insight

## Architecture

The ARXML describes four atomic software components inside `CPT_BatteryMonitoring`:

- `SWC_VoltageSensor` publishes `BatteryVoltage`.
- `SWC_BatteryMonitor` consumes voltage and publishes `BatteryLevel` and `LowBattery`.
- `SWC_LevelDisplay` consumes the level.
- `SWC_LowBatteryLamp` consumes the low-battery flag.

The components communicate only through typed sender-receiver interfaces and assembly connectors. Numeric constraints are explicit: voltage is 0..200 raw counts (0.0..20.0 V), and battery level is 0..100 percent.

## Decision logic

The reference mapping is linear:

`level_percent = floor(voltage_counts * 100 / 200)`

The warning decision is intentionally strict: `low_battery = level_percent < 20`. Therefore, exactly 20 percent is not classified as low.

## Timing and data flow

The sensor runnable is triggered every 100 ms. A received voltage activates the monitor runnable, which updates both outputs. The display and warning lamp are event-driven by received data. The model prevents re-entrant execution of each runnable.

## Applications

- Instrument-cluster battery gauge and warning indicator.
- Fleet/telematics state reporting.
- Charge-discharge trend monitoring when extended with filtering and history.
- A reusable AUTOSAR teaching and prototyping example for typed interfaces, RTE events, and composition.

## Engineering considerations

This model does not define ADC calibration, sensor plausibility checks, debounce/filtering, diagnostic trouble codes, NVM persistence, communication mappings, ECU deployment, or safety mechanisms. These are required before production deployment. A real battery-management application should also account for temperature, cell imbalance, sensor faults, hysteresis, and chemistry-specific state-of-charge estimation.
