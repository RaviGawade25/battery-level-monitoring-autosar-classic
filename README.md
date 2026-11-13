# Battery Level Monitoring using AUTOSAR Classic

![AUTOSAR](https://img.shields.io/badge/AUTOSAR-Classic%20Platform-blue)
![Standard](https://img.shields.io/badge/ARXML-R4.0-informational)
![CI](https://github.com/RaviGawade25/battery-level-monitoring-autosar-classic/actions/workflows/ci.yml/badge.svg)

An industry-aligned reference architecture for monitoring battery voltage with the AUTOSAR Classic Platform. The project demonstrates typed sender-receiver communication, software-component separation, runnable activation, timing, and a low-battery decision path.

## Scope

The repository covers the application-layer design and a small, testable reference implementation:

- AUTOSAR R4.0 ARXML model for the battery-monitoring composition
- Voltage-to-state-of-charge percentage mapping
- Low-battery threshold decision
- Requirements, verification cases, and application considerations
- Automated Python tests and CI

It intentionally does not claim production, safety, or ECU-specific readiness. Production integration requires calibration, diagnostics, communication mapping, ECU configuration, target validation, and the applicable functional-safety process.

## Architecture

```text
Voltage Sensor --> Battery Monitor --> Level Display
                         |
                         +----------> Low-Battery Warning Lamp
```

The ARXML composition contains four atomic software components:

| Component | Responsibility |
| --- | --- |
| `SWC_VoltageSensor` | Publishes a voltage sample every 100 ms |
| `SWC_BatteryMonitor` | Converts voltage to level and evaluates the warning threshold |
| `SWC_LevelDisplay` | Consumes the calculated level |
| `SWC_LowBatteryLamp` | Consumes the low-battery flag |

## Signal contract

| Signal | Representation | Physical meaning |
| --- | --- | --- |
| `BatteryVoltage` | `0..200` counts | `0.0..20.0 V`, resolution `0.1 V` |
| `BatteryLevel` | `0..100` percent | Calculated battery level |
| `LowBattery` | Boolean | `TRUE` when level is below `20%` |

## Repository layout

```text
model/      AUTOSAR ARXML model
src/        C reference implementation
tests/      Executable behavioral tests
docs/       Architecture, requirements, verification, and privacy notes
.github/    Continuous integration workflow
```

## Run locally

```text
python -m unittest discover -s tests -v
```

The ARXML can be imported into an AUTOSAR-compatible modeling tool. Schema validation requires the corresponding AUTOSAR schema package, which is not redistributed here.

## Engineering insight and applications

Separating sensing, decision, and presentation allows the monitor logic to be reused across ECUs and hardware variants. The same typed outputs can support an instrument-cluster gauge, a warning indicator, telematics reporting, or a charging-control policy without coupling the decision logic to a display or hardware driver.

For a production-grade battery-management function, extend the design with ADC calibration, plausibility checks, filtering and hysteresis, temperature compensation, cell-level estimation, diagnostics, non-volatile state handling, communication mapping, and safety mechanisms.

## Privacy

This public repository contains only generalized technical content. Personal names, roll numbers, institution details, supervisor details, and source-report metadata are intentionally excluded.

## License

Released under the MIT License. See `LICENSE`.
