# Verification

## Behavioral test cases

| ID | Input | Expected result |
| --- | --- | --- |
| VT-001 | 0 counts | 0% and low battery |
| VT-002 | 40 counts | 20% and not low battery |
| VT-003 | 100 counts | 50% and not low battery |
| VT-004 | 160 counts | 80% and not low battery |
| VT-005 | 200 counts | 100% and not low battery |
| VT-006 | Below-range input | Clamped to 0% |
| VT-007 | Above-range input | Clamped to 100% |

The 20% boundary is intentionally non-low because the requirement uses a strict less-than comparison.

## Validation status

- Python unit tests: automated in CI.
- C reference implementation: compile-ready and independent of generated RTE code.
- ARXML schema validation: requires an external AUTOSAR R4.0 schema package.
- ECU integration and hardware validation: out of scope for this reference repository.
