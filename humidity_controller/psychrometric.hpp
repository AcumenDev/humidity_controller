#include <math.h>
#include <stdlib.h>

class PsychrometricAlgorithm
{
	public:
		static float computeHumidity(float dryT, float wetT);
	private:
		static float computeVaporPressure(float dryT, float wetT);
		static float computeSaturationPressure(float t);
};
