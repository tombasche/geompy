import pytest
from geompy import coords_has_spike


class TestSpikes:

    @pytest.mark.parametrize('coords, has_spike, desc', [
        (
            [(151.2063151, -33.87253137), (151.20634256, -33.87253127), (151.20635629, -33.87253122)],
            False,
            'evaluates to less than -1'
        )
    ])
    def test_coords_has_spike(self, coords, has_spike, desc):
        assert coords_has_spike(coords) == has_spike, desc

