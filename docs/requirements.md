# Requirements

## Functional requirements

| ID | Requirement |
| --- | --- |
| FR-001 | Acquire a battery-voltage sample in the range `0.0..20.0 V` at `0.1 V` resolution. |
| FR-002 | Publish the voltage sample periodically with a 100 ms period. |
| FR-003 | Convert the voltage sample to a battery level in the range `0..100%`. |
| FR-004 | Deliver the calculated level to the level-display component. |
| FR-005 | Set `LowBattery` to `TRUE` when the level is below 20%; otherwise set it to `FALSE`. |
| FR-006 | Deliver the low-battery status to the warning-lamp component. |

## Structural requirements

| ID | Requirement |
| --- | --- |
| NFR-001 | Components communicate through typed ports and assembly connectors. |
| NFR-002 | Numeric signals have explicit valid-range constraints. |
| NFR-003 | Ports define initial values. |
| NFR-004 | Runnables are not concurrently re-entered. |
| NFR-005 | The model conforms to the AUTOSAR R4.0 exchange format. |
