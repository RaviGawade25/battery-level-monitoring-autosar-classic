import unittest


def battery_level_from_voltage(voltage_counts: int) -> int:
    voltage_counts = max(0, min(200, voltage_counts))
    return (voltage_counts * 100) // 200


def battery_is_low(level_percent: int) -> bool:
    return level_percent < 20


class BatteryMonitorTests(unittest.TestCase):
    def test_voltage_boundaries(self):
        self.assertEqual(battery_level_from_voltage(0), 0)
        self.assertEqual(battery_level_from_voltage(200), 100)

    def test_representative_levels(self):
        self.assertEqual(battery_level_from_voltage(40), 20)
        self.assertEqual(battery_level_from_voltage(100), 50)
        self.assertEqual(battery_level_from_voltage(160), 80)

    def test_out_of_range_inputs_are_clamped(self):
        self.assertEqual(battery_level_from_voltage(-1), 0)
        self.assertEqual(battery_level_from_voltage(201), 100)

    def test_low_battery_threshold_is_strict(self):
        self.assertTrue(battery_is_low(19))
        self.assertFalse(battery_is_low(20))


if __name__ == '__main__':
    unittest.main()
