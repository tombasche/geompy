import pytest
from geompy import line_string_has_duplicate_vertex


class TestDuplicates:

    @pytest.mark.parametrize('coords, has_duplicate, desc', [
        (
            [(151.2063151, -33.87253137), (151.20634256, -33.87253127), (151.20634256, -33.87253127), (151.20635629, -33.87253122)],
            True,
            'Middle 2 vertices are duplicates'
        ),
        (
            [(151.2063151, -33.87253137), (151.2063151, -33.87253137), (151.20635629, -33.87253122)],
            False,
            'has a duplicate, but in first coord'
        ),
        (
            [(151.2063151, -33.87253137), (151.20635629, -33.87253122), (151.2063151, -33.87253137)],
            False,
            'has a duplicate, but in last coord'
        ),
        (
            [(151.2063151, -33.87253137), (151.2063151, -33.87253137)],
            True,
            'duplicate points'
        )
    ])
    def test_coords_has_duplicate(self, coords, has_duplicate, desc):
        assert line_string_has_duplicate_vertex(coords) == has_duplicate, desc
